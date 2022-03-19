#ifndef MKGRP_H
#define MKGRP_H

#include <QString>
#include "string"
#include <iostream>
using namespace std;

class mkgrp
{
public:
    mkgrp();

    string nombre;
    void crearGrupo(mkgrp *grupo);
    void eliminarGrupo(mkgrp *grupo);
};

#endif // MKGRP_H
