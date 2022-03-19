#include "loss.h"

#include "chgrp.cpp"
#include "nodomount.h"

loss::loss()
{

}


void loss::lossPart(loss *Part){
    char ca = (Part->id).back();
    if(ca == '"'){
        string aux;
        for (int i = 0; i < (Part->id).size(); i++) {
            if((Part->id)[i]!='"'){
                aux += (Part->id)[i];
            }
        }
        Part->id = aux;
    }
    char buffer = '\0';
    bool comprobar =false;
    nodoMount *aux = ListaM->primero;
    while (aux!= nullptr){
        if (aux->id == Part->id){
            comprobar = true;
            break;
        }
        aux = aux->sig;
    }
    if (comprobar){
        FILE *archivo = fopen((aux->ruta).c_str(), "rb+");
        Disco master;
        fseek(archivo, 0 , SEEK_SET);
        fread(&master, sizeof(Disco), 1, archivo);
        int NParticion = -1;
        int NParticionE = -1;
        for (int i = 0; i < 4; i++) {
            if(strcmp(master.particiones[i].p_nombre, (aux->nombre).c_str())==0){
                NParticion = i;
                break;
            }
            if(master.particiones[i].p_type == 'E'){
                NParticionE = i;
            }
        }
        if(NParticion != -1){
            fseek(archivo, master.particiones[NParticion].p_comienzo, SEEK_SET);
            fwrite(&buffer, 1, master.particiones[NParticion].p_tam,archivo);
            fseek(archivo, 0, SEEK_SET);
            fwrite(&master, sizeof(Disco),1, archivo);
            printf("Se realizo la perdida de sistema correctamente\n");
        }else{
            if(NParticionE != -1){
                ext Extendida;
                fseek(archivo, master.particiones[NParticionE].p_comienzo, SEEK_SET);
                fread(&Extendida, sizeof(ext), 1, archivo);
                bool comprobar = false;
                while ((ftell(archivo)<master.particiones[NParticionE].p_tam + master.particiones[NParticionE].p_comienzo)) {
                    if (strcmp(Extendida.e_nombre, (aux->nombre).c_str())==0){
                        comprobar = true;
                        break;
                    }
                    if(Extendida.e_siguiente == -1){
                        break;
                    }
                    fseek(archivo, Extendida.e_siguiente, SEEK_SET);
                    fread(&Extendida, sizeof(ext), 1 , archivo);
                }
                if (comprobar){
                    fseek(archivo,Extendida.e_comienzo, SEEK_SET);
                    fwrite(&buffer, 1, Extendida.e_tam,archivo);
                    fseek(archivo, 0, SEEK_SET);
                    fwrite(&master, sizeof(Disco),1, archivo);
                    printf("Se realizo la perdida de sistema correctamente\n");
                }else{
                    printf("Error no se encontro el disco\n");
                }
            fclose(archivo);

            }else{
                printf("Error no se encontro el disco\n");
            }
        }
    }else{
        printf("Error no se encontro el mismo id montado\n");
    }
}
