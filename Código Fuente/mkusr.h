#ifndef MKUSR_H
#define MKUSR_H

#include <QString>
#include "string"
#include <iostream>
using namespace std;

class mkusr
{
public:
    mkusr();

    string usr;
    string pwd;
    string grp;
    void crearUsuario(mkusr *usuario);
    void eliminarUsuario(mkusr *usuario);
};

#endif // MKUSR_H
