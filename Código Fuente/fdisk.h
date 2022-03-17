#ifndef FDISK_H
#define FDISK_H


#include <QString>
#include "string"
#include <iostream>
using namespace std;


class fdisk
{
public:
    fdisk();

    int size=0;
    int agregar=0;
    string ruta="";
    string ajuste="";
    string unidad="";
    string tipo="";
    string eliminar="";
    string nombre="";

    void AdmiDisco(fdisk *disco);

};

#endif // FDISK_H
