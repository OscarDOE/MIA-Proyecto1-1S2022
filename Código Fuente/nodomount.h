#ifndef NODOMOUNT_H
#define NODOMOUNT_H

#include <QString>
#include "string"
#include <iostream>
using namespace std;

class nodoMount
{
public:
    nodoMount(string, string, string, int, char);
    string id;
    string nombre;
    int numero;
    char letra;
    string ruta;
    nodoMount *sig;
};

#endif // NODOMOUNT_H
