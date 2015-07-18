#include "pmclient.h"
#include <QtNetwork/QTcpSocket>

PMClient::PMClient(QObject *parent) :
    QObject(parent)
{
    m_userName = "Anonymous";
    m_pcName = "Unknown";

    //QThreadPool::globalInstance()->setMaxThreadCount(15);
}

void PMClient::setSocket(int Descriptor)
{
    socket = new QTcpSocket(this);

    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket,SIGNAL(readyRead()), this, SLOT(readyRead()));

    socket->setSocketDescriptor(Descriptor);
    //qDebug() << "SET SOCK " << Descriptor;

    //qDebug() << "client connected";
}


void PMClient::connected()
{
    //qDebug() << "client connected event";
}

void PMClient::disconnected()
{
    //qDebug() << "client disconnected";
    emit(sockDisconnected());
}



void PMClient::readyRead()
{



}

void PMClient::writeOut(QByteArray buffer)
{
    socket->write(buffer);
    socket->flush();
    socket->waitForBytesWritten();
}
