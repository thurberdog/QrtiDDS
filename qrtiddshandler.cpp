#include "qrtiddshandler.h"
#include "qrtiddslistener.h"
#include "qrtidds.h"
QrtiDDShandler::QrtiDDShandler(QObject *parent) : QObject(parent)
{
   setUp_rtiDDS_handler();
}

QrtiDDShandler::~QrtiDDShandler()
{

}

/**
 * @brief QrtiDDShandler::setupCommsHandler
 */
void QrtiDDShandler::setUp_rtiDDS_handler()
{
    rtiDDSlistener = new QrtiDDSlistener(this);
    rtiDDS = new QrtiDDS(this, rtiDDSlistener);
    connect(rtiDDSlistener, SIGNAL(newData(QString)),
            this, SLOT(readListenerData(QString)),
            Qt::QueuedConnection);
}

/**
 * @brief QrtiDDShandler::readData
 * @return
 */
QString QrtiDDShandler::readData(){
    return rtiDDSrcvBuffer;
}

/**
 * @brief QrtiDDShandler::writeData
 * @param data
 */
void QrtiDDShandler::writeData(QString data){
    emit newSendDataAvailable(data);
}

/**
 * @brief QrtiDDShandler::readListenerData
 * @param data
 */
void QrtiDDShandler::readListenerData(QString data){
    qDebug()<<__FUNCTION__<<__LINE__  << this << "recieved: " << data;
    rtiDDSrcvBuffer = data;
    emit newRcvdDataAvailable(data);
}
