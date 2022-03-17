#ifndef LOGIN_H
#define LOGIN_H

#include <QString>
#include "string"
#include <iostream>
using namespace std;




class login
{
public:
    login();
    string user="";
    string pwd="";
    string id="";
    void Login(login *usuario);
    void Logout();
};


#endif // LOGIN_H
