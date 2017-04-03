#ifndef QRTIDDSLISTENER_H
#define QRTIDDSLISTENER_H
#define MAX_STRING_SIZE         1024

#include <QObject>
#include <QDebug>
#include <QString>
#include <QTimer>
#include "ndds/ndds_cpp.h"

class QrtiDDSlistener : public QObject, public DDSDataReaderListener
{
    Q_OBJECT
public:
    QrtiDDSlistener(QObject *parent);

signals:
    void newData(QString data);

public slots:

private:
    void on_data_available(DDSDataReader *reader);
};

#endif // QRTIDDSLISTENER_H
