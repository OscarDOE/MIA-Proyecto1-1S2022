#ifndef UMOUNT_H
#define UMOUNT_H

#include <QString>
#include "string"
#include <iostream>
using namespace std;

class umount
{
public:
    umount();
    string id="";
    void DesmontarParticion(umount *umontar);
};

#endif // UNMOUNT_H
