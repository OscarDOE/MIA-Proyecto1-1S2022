#ifndef MKDISK_H
#define MKDISK_H

#include <QString>
#include "string"
#include <iostream>
using namespace std;

class mkdisk
{
public:
    mkdisk();
    int size=0;
    string ruta="";
    string ajuste="";
    string unidad="";
    void CrearMkdisk(mkdisk *disco);

};

#endif // MKDISK_H
