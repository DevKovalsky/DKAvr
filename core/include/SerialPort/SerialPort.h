#pragma once
#include <QObject>
#include <QtSerialPort/QSerialPort>

class SerialPort
{
	Q_OBJECT
public:
	SerialPort() = default;
	virtual ~SerialPort() = default;

	bool connectToCom(std::string port, uint32_t baudRate);
	void disconnect() { mSerialPort.close(); }
	bool isConnect() const { return mIsConnected; }

private:
	QSerialPort mSerialPort{};
	bool mIsConnected{};
	std::string mPort{};
	uint32_t mBaudRate{};
};