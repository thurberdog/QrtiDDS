#include <QApplication>
#include <QQmlApplicationEngine>
#include "qrtiddshandler.h"
#include <QtQml>
#include <QIcon>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    qmlRegisterType<QrtiDDShandler>("org.QrtiDDS", 1, 0, "QrtiDDShandler");
    QQmlApplicationEngine engine;
    QIcon icon = QIcon(":/surfdog.bmp");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    app.setWindowIcon(icon);
    return app.exec();
}
