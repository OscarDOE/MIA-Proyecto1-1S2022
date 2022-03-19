#ifndef LOSS_H
#define LOSS_H

#include <QString>
#include "string"
#include <iostream>
using namespace std;

class loss
{
public:
    loss();

    string id;
    void lossPart(loss *Part);
};

#endif // LOSS_H
