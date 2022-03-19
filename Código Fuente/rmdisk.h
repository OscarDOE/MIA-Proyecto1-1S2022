#ifndef RMDISK_H
#define RMDISK_H

#include <QString>
#include "string"
#include <iostream>
using namespace std;

class rmdisk
{
public:
    rmdisk();

    string path="";
    void EliminarDisco(rmdisk *disco);
};

#endif // RMDISK_H
