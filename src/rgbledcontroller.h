#ifndef RGBLEDCONTROLLER_H
#define RGBLEDCONTROLLER_H
#include <QObject>
#include <QSerialPort>

class RGBLedController : public QObject
{
    Q_OBJECT

public:
    explicit RGBLedController(QObject *parent = 0);
    ~RGBLedController();

    Q_INVOKABLE void setRedColor(int value);

    Q_INVOKABLE void setGreenColor(int value);

    Q_INVOKABLE void setBlueColor(int value);

    void updateRGBColors(QString);

private:
    QSerialPort *serialPort;
    QString portName;
    bool arduinoConnected;
    static const quint16 arduinoUNOVendorId = 9025;
    static const quint16 arduinoUNOProductId = 67;
};

#endif // RGBLEDCONTROLLER_H
