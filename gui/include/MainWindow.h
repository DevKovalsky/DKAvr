#pragma once

#include <QMainWindow>
#include <memory>

#include "SerialPort/SerialPort.h"

namespace Ui
{
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();

public slots:
	void onBtnConnectClicked();

private:
	Ui::MainWindow* ui;
	std::unique_ptr<SerialPort> mSerialPort{};
	bool isSerialPortConnected{};
};