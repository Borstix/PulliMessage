#include <QCoreApplication>
#include "pmservercore.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Starting the main server
    PMServerCore pmserver;

    return a.exec();
}
