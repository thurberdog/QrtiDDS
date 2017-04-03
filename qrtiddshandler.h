#ifndef QRTIDDSHANDLER_H
#define QRTIDDSHANDLER_H

#include <QObject>
#include <iostream>
#include <ndds/ndds_cpp.h>
#include <string>
#include <QString>
#include <qrtiddslistener.h>
#include <qrtidds.h>

class QrtiDDShandler : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString dataAccess WRITE writeData READ readData NOTIFY newRcvdDataAvailable)

    void setUp_rtiDDS_handler();
public:
    explicit QrtiDDShandler(QObject *parent = 0);
   ~QrtiDDShandler();
    QString readData();

signals:
    void newRcvdDataAvailable(QString data);
    void newSendDataAvailable(QString data);
public slots:
    void writeData(QString data);
    void readListenerData(QString data);

private:
    QrtiDDS              * rtiDDS;
    QrtiDDSlistener      * rtiDDSlistener;
    QString              rtiDDSrcvBuffer;
};

#endif // QRTIDDSHANDLER_H
