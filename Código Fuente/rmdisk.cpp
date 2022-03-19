#include "rmdisk.h"
#include<stdio.h>



rmdisk::rmdisk()
{

}

void rmdisk::EliminarDisco(rmdisk *disco){
    string au = (disco->path).substr(0, (disco->path).size()-1);
    char ca1 = au.back();
    char ca = (disco->path).back();
    if(ca1 == '\''){
        disco->path = (disco->path).substr(0, (disco->path).size()-1);
        disco->path = (disco->path).substr(0, (disco->path).size()-1);
    }else if(ca == '"'){
        string aux;
        for (int i = 0; i < (disco->path).size(); i++) {
            if((disco->path)[i]!='"'){
                aux += (disco->path)[i];
            }
        }
        disco->path = aux;
    }else if(ca == ' '){
        disco->path = (disco->path).substr(0, (disco->path).size()-1);
    }else if(ca == '\''){
        disco->path = (disco->path).substr(0, (disco->path).size()-1);
    }

    const char * ruta = disco->path.c_str();
    cout << "Estas seguro de eliminar el disco S/N ";
    string confirmacion;
    getline(cin, confirmacion);
    if (confirmacion == "S" | confirmacion == "s"){
        FILE *file;
        if (file = fopen(ruta, "r")){
            fclose(file);
            remove(ruta);
            printf("Se elimino el disco exitosamente\n");
        }else{
            printf("El disco o la ruta no existe\n");
        }
    }else if (confirmacion == "N" || confirmacion == "n"){
        printf("Se cancelo la eliminacion de disco\n");
    }else{
        printf("Error no se ingreso S/N\n");
    }
}
