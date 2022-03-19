#ifndef REP_H
#define REP_H


#include <QString>
#include "string"
#include <iostream>
using namespace std;


class rep
{
public:
    rep();

    string nombre;
    string path;
    string id;
    string ruta;
    int root =0;
    void CrearRep(rep *rep);
};

#endif // REP_H
