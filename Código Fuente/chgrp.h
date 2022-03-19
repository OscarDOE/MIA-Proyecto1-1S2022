#ifndef CHGRP_H
#define CHGRP_H

#include <QString>
#include "string"
#include <iostream>
using namespace std;

class chgrp
{
public:
    chgrp();

    string usr;
    string grp;
    void cambiarGrupo(chgrp *grupo);

};

#endif // CHGRP_H
