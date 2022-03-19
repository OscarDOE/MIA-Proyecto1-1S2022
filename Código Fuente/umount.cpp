#include "umount.h"
#include<stdio.h>

#include "nodomount.h"
#include "listamount.h"
#include "mount.cpp"

umount::umount()
{

}

void umount:: DesmontarParticion(umount *unmontar){
    //cout<<unmontar->id<<endl;

    char ca = (unmontar->id).back();
    if(ca == '"'){
        string aux;
        for (int i = 0; i < (unmontar->id).size(); i++) {
            if((unmontar->id)[i]!='"'){
                aux += (unmontar->id)[i];
            }
        }
        unmontar->id = aux;
    }

    bool comprobar = false;
    nodoMount *aux = ListaM->primero;
    if (aux->id == unmontar->id){
        comprobar = true;
        aux = aux->sig;
        free(aux);
        printf("Se desmonto correctamente\n");
    }else{
        nodoMount *aux2 = nullptr;
        while (aux != nullptr){
            if (aux->id == unmontar->id){
                comprobar = true;
                aux2->sig = aux->sig;
                printf("Se desmonto correctamente\n");
                break;
            }
            aux2 = aux;
            aux = aux->sig;
        }
    }
    if(!comprobar){
        printf("Error no se encontro un mismo id montada\n");
    }
}
