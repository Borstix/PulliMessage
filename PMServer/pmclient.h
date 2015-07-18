#ifndef PMCLIENT_H
#define PMCLIENT_H

#include <QObject>
#include <QtNetwork/QTcpSocket>
#include <QDebug>
#include <QThreadPool>

class PMClient : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString m_userName READ userName WRITE setUserName)
    Q_PROPERTY(QString m_pcName READ pcName WRITE setPcName)


public:
    explicit PMClient(QObject *parent = 0);
    void setSocket(int Descriptor);
    void writeOut(QByteArray buffer);

    QString userName() const
    { return m_userName; }

    QString pcName() const
    { return m_pcName; }

    void setUserName(QString userName)
    {
        m_userName = userName;
    }

    void setPcName(QString pcName)
    {
        m_pcName = pcName;
    }

signals:
    void sockDisconnected();

public slots:
    void connected();
    void disconnected();
    void readyRead();

private:
    QTcpSocket *socket;
    QString m_userName, m_pcName;

};

#endif // PMCLIENT_H
