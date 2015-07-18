#ifndef PMNETWORKING_H
#define PMNETWORKING_H

#include <QObject>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QHostAddress>
#include "pmclient.h"

class PMNetworking : public QTcpServer
{
    Q_OBJECT
public:
    explicit PMNetworking(QObject *parent = 0);
private:
    void startServer();

    QTcpSocket *tcpSocket;
    QList<PMClient *> clientConnections;


protected:
    void incomingConnection(qintptr socketDescriptor);

signals:

public slots:
};

#endif // PMNETWORKING_H
