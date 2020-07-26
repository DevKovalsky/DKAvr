#include "SerialPort/SerialPort.h"

#include <QtSerialPort/QSerialPortInfo>

bool SerialPort::connectToCom(std::string port, uint32_t baudRate)
{
	mPort = port;
	mBaudRate = baudRate;
	mSerialPort.setPort(QSerialPortInfo(QString::fromStdString(port)));
	mSerialPort.setBaudRate(baudRate);
	mIsConnected = mSerialPort.open(QIODevice::ReadWrite);
	//log error
	//this->error();
	return mIsConnected;
}
