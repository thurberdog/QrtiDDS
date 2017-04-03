#ifndef QRTIDDS_H
#define QRTIDDS_H
#include <QDebug>
#include <QObject>
#include <string>
#include <ndds/ndds_cpp.h>
#include <ndds/ndds_namespace_cpp.h>
#include <QString>
#include "qrtiddslistener.h"

class QrtiDDS : public QObject
{
    Q_OBJECT
public:
    explicit QrtiDDS(QObject *parent = 0);
    QrtiDDS(QObject *parent, QrtiDDSlistener *rtiDDSlistener);
    ~QrtiDDS();

    DDSDomainParticipant *  participant;
    DDSTopic *              topic;
    DDSDataWriter *         data_writer;
    DDSDataReader *         data_reader;
    DDSStringDataWriter *   string_writer;
    DDS_ReturnCode_t        retcode;
    QrtiDDSlistener *         rtiDDSlistener;
    char                    sample[MAX_STRING_SIZE];
    int                     main_result;

public slots:
    void sendData(QString data);

private:
    int setupQrtiDDS();

};

#endif // QRTIDDS_H
