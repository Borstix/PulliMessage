#include "pmnetworking.h"

PMNetworking::PMNetworking(QObject *parent) : QTcpServer()
{
       startServer();
}

void PMNetworking::startServer()
{
    QHostAddress address;
    address = QHostAddress::AnyIPv4;

    if(!listen(address, 7777)) {
        qDebug() << "Could not start server!";
    } else {
        qDebug() << "Server is listening!";
    }

}

void PMNetworking::incomingConnection(qintptr socketDescriptor)
{
    PMClient *client = new PMClient(this);
    clientConnections.append(client);

    client->setSocket(socketDescriptor);

}
