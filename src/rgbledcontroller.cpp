#include "rgbledcontroller.h"
#include <QSerialPortInfo>
#include <QDebug>

RGBLedController::RGBLedController(QObject *parent) :
    QObject(parent)
{
    serialPort = new QSerialPort;
    portName = "";
    arduinoConnected = false;

    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()){
            if (serialPortInfo.vendorIdentifier() == arduinoUNOVendorId) {
                if (serialPortInfo.productIdentifier() == arduinoUNOProductId) {
                    portName = serialPortInfo.portName();
                    arduinoConnected = true;
                }
            }
        }
    }

    if (arduinoConnected) {
        serialPort->setPortName(portName);
        serialPort->open(QSerialPort::WriteOnly);
        serialPort->setBaudRate(QSerialPort::Baud9600);
        serialPort->setDataBits(QSerialPort::Data8);
        serialPort->setParity(QSerialPort::NoParity);
        serialPort->setStopBits(QSerialPort::OneStop);
        serialPort->setFlowControl(QSerialPort::NoFlowControl);
    } else {
        qWarning() << ("Arduino board not connected to serial");
    }
}

RGBLedController::~RGBLedController()
{
    if (serialPort->isOpen()) {
        serialPort->close();
    }
}

void RGBLedController::setRedColor(int value)
{
    RGBLedController::updateRGBColors(QString("r%1").arg(value));
}

void RGBLedController::setGreenColor(int value)
{
    RGBLedController::updateRGBColors(QString("g%1").arg(value));
}

void RGBLedController::setBlueColor(int value)
{
    RGBLedController::updateRGBColors(QString("b%1").arg(value));
}

void RGBLedController::updateRGBColors(QString value) {
    if (serialPort->isWritable()) {
        serialPort->write(value.toStdString().c_str());
    } else {
        qWarning() << "Error writting to serial";
    }
}
