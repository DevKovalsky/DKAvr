#include "ui_MainWindow.h"
#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	connect(ui->btnConnect, &QPushButton::clicked, this, &MainWindow::onBtnConnectClicked);
	mSerialPort = std::make_unique<SerialPort>();
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::onBtnConnectClicked()
{
	if(!isSerialPortConnected)
	{
		const auto strPort = ui->comboBoxPort->currentText();
		const auto strBaudRate = ui->comboBoxBaudRate->currentText();
		const auto baudRate = strBaudRate.toInt();

		if (mSerialPort->isConnect())
			return;

		if (mSerialPort->connectToCom(strPort.toStdString(), baudRate))
		{
			ui->btnConnect->setText("Disconnect");
			isSerialPortConnected = true;
		}
	}
	else
	{
		mSerialPort->disconnect();
		ui->btnConnect->setText("Connect");
		isSerialPortConnected = false;
	}

}
