#ifndef MOUNT_H
#define MOUNT_H

#include <QString>
#include "string"
#include <iostream>
#include "listamount.h"
using namespace std;


class mount
{
    //listaMount obtenerLista();
public:
    mount();
    string ruta="";
    string nombre="";
    void MontarParticion(mount *montar);
};




#endif // MOUNT_H
