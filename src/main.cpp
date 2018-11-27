#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "rgbledcontroller.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    RGBLedController rgbLedController;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("RGBLedController", &rgbLedController);
    engine.load(QUrl(QLatin1String("main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
