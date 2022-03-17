#ifndef MKFS_H
#define MKFS_H

#include <QString>
#include "string"
#include <iostream>
using namespace std;

class mkfs
{
public:
    mkfs();

    string id="";
    string tipo="";
    string fs = "";

    void FormatoMkfs(mkfs *Disco);

};

#endif // MKFS_H
