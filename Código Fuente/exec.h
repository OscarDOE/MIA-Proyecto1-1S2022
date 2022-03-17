#ifndef EXEC_H
#define EXEC_H


#include <QString>
#include "string"
#include <iostream>
using namespace std;

class exec
{
public:
    exec();

    string contenido="";
    void ejecutar(exec *archivo);
};

#endif // EXEC_H
