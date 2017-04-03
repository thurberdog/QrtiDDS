#include "qrtidds.h"

QrtiDDS::QrtiDDS(QObject *parent, QrtiDDSlistener *listener) : QObject(parent)
{
    // Typically, you will only need to create one DomainParticipant
    // per DDS domain per application.
    // Although unusual,
    // you can create multiple DomainParticipants for the same DDS domain in an application.)
    //
    // To create a DomainParticipant,
    // use the DomainParticipantFactory’s create_participant() or
    // create_participant_with_profile() operation:

    DDSDomainParticipant *  participant = NULL;
    DDSTopic *              topic = NULL;
    DDSDataWriter *         data_writer = NULL;
    DDSDataReader *         data_reader = NULL;
    DDSStringDataWriter *   string_writer = NULL;

    rtiDDSlistener = listener;

    int success = setupQrtiDDS();
    if (success != 0)
    {
        qDebug()<<__FUNCTION__<<__LINE__  << "Couldn't setup DDS Objects";
    }
}
QrtiDDS::~QrtiDDS()
{
    if (QrtiDDS::participant != NULL) {
        retcode = participant->delete_contained_entities();
        if (retcode != DDS_RETCODE_OK) {
            qDebug()<<__FUNCTION__<<__LINE__  << "Deletion failed";
        }
        retcode = DDSDomainParticipantFactory::get_instance()->
                delete_participant(participant);
        if (retcode != DDS_RETCODE_OK) {
            qDebug()<<__FUNCTION__<<__LINE__  << "Deletion failed.";
        }
    }
}

/**
 * @brief QrtiDDS::setupQrtiDDS
 * @return
 */
int QrtiDDS::setupQrtiDDS()
{
    participant = DDSDomainParticipantFactory::get_instance()->
            create_participant(
                0,                              /* Domain ID */
                DDS_PARTICIPANT_QOS_DEFAULT,    /* QoS */
                NULL,                           /* Listener */
                DDS_STATUS_MASK_NONE);
    if (participant == NULL) {
        qDebug()<<__FUNCTION__<<__LINE__  << "Unable to create domain participant.";
        return 1;
    }

    /* Create the topic "Hello, World" for the String type */
    topic = participant->create_topic(
                "Hello, World",                          /* Topic name*/
                DDSStringTypeSupport::get_type_name(), /* Type name */
                DDS_TOPIC_QOS_DEFAULT,                 /* Topic QoS */
                NULL,                                  /* Listener  */
                DDS_STATUS_MASK_NONE);
    if (topic == NULL) {
        qDebug()<<__FUNCTION__<<__LINE__  << "Unable to create topic." ;
        return 1;
    }

    /* Create the data writer using the default publisher */
    data_writer = participant->create_datawriter(
                topic,
                DDS_DATAWRITER_QOS_DEFAULT,     /* QoS */
                NULL,                           /* Listener */
                DDS_STATUS_MASK_NONE);
    if (data_writer == NULL) {
        qDebug()<<__FUNCTION__<<__LINE__ << "Unable to create data writer.";
        return 1;
    }

    data_reader = participant->create_datareader(
                topic,
                DDS_DATAREADER_QOS_DEFAULT,    /* QoS */
                listener,                      /* Listener */
                DDS_DATA_AVAILABLE_STATUS);
    if (data_reader == NULL) {
        qDebug()<<__FUNCTION__<<__LINE__  << "Unable to create data reader.";
        return 1;
    }

    string_writer = DDSStringDataWriter::narrow(data_writer);
    if (string_writer == NULL) {
        /* In this specific case, this will never fail */
        qDebug()<<__FUNCTION__<<__LINE__  << "DDS_StringDataWriter_narrow failed.";
    }
    connect(parent(), SIGNAL(newSendDataAvailable(QString)), this, SLOT(sendData(QString)));

    return 0;
}
void QrtiDDS::sendData(QString data){
    string_writer->write(data.toUtf8().constData(), DDS_HANDLE_NIL);
    qDebug()<<__FUNCTION__<<__LINE__  << this << "sent: " << data;
}
