#ifndef PMSERVERCORE_H
#define PMSERVERCORE_H

#include <QObject>
#include "pmnetworking.h"

class PMServerCore
{
public:
    PMServerCore();
private:
    PMNetworking *networking;
};

#endif // PMSERVERCORE_H
