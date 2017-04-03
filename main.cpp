#include <QApplication>
#include <QQmlApplicationEngine>
#include "rtiddshandler.h"
#include <QtQml>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    qmlRegisterType<RtiDDShandler>("org.rtidds", 1, 0, "RtiDDShandler");
    QQmlApplicationEngine engine;

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
