#include "mkdisk.h"
#include<stdio.h>
#include<stdlib.h>
#include <stddef.h>
#include <QDir>
#include <ctime>

#include <iostream>

#include "estructura.h"

mkdisk::mkdisk()
{

}
//mkdisk *TodoDisk;

void formato(FILE *archivo, int size){
    char buffer[1000];
        for(int i = 0; i<1000; i++) buffer[i]='\0';
        for( int i = 0; i < size; i++)
            fwrite(&buffer,1000,1,archivo);
}


void crearDisco(string path, int size, Disco master){
    /*time_t aux = time(0);
    tm* ahora = localtime(&aux);
    master.creacion = ahora;*/
    master.creacion = time(nullptr);
    master.asignacion = (int)time(nullptr);
    for (int i = 0; i < 4; i++) {
        master.particiones[i].p_estado='0';
        master.particiones[i].p_tam = 0;
        master.particiones[i].p_type = '0';
        master.particiones[i].p_comienzo = -1;
        master.particiones[i].p_tipo = '0';
        strcpy(master.particiones[i].p_nombre,"");
    }

     const char * ruta = path.c_str();
     //printf(ruta);
     bool comprobar = true;
     string Carpeta = path;
     while(comprobar){
         Carpeta = Carpeta.substr(0, Carpeta.size()-1);
         char aux = Carpeta.back();
         if (aux=='/'){
             Carpeta = Carpeta.substr(0, Carpeta.size()-1);
             comprobar = false;
         }
     }
     const char * rutaCarpeta = Carpeta.c_str();
     QDir dir(rutaCarpeta);
     //cout <<rutaCarpeta;
     if (!dir.exists()) {
         dir.mkpath(".");
     }
     FILE *archivo = fopen(ruta, "wb");
     if(archivo!=NULL){
         fseek(archivo, 0, SEEK_SET);
         formato(archivo, size);
         fclose(archivo);
     }
     FILE *archivo2 = fopen(ruta, "rb+");
     if(archivo2!=NULL){
         fseek(archivo2, 0, SEEK_SET);
         fwrite(&master, sizeof(Disco),1, archivo2);
         printf("Se creo correctamente el Disco\n");
         //cout << TodoDisk;
         fclose(archivo2);
     }
}


void mkdisk::CrearMkdisk(mkdisk *disco){
    Disco master;
    bool error = false;
    string au = (disco->ruta).substr(0, (disco->ruta).size()-1);

    char ca1 = au.back();
    char ca = (disco->ruta).back();
    if(ca1 == '\''){
        disco->ruta = (disco->ruta).substr(0, (disco->ruta).size()-1);
        disco->ruta = (disco->ruta).substr(0, (disco->ruta).size()-1);
    }else if(ca == '"'){
        string aux;
        for (int i = 0; i < (disco->ruta).size(); i++) {
            if((disco->ruta)[i]!='"'){
                aux += (disco->ruta)[i];
            }
        }
        disco->ruta = aux;
    }else if(ca == ' '){
        disco->ruta = (disco->ruta).substr(0, (disco->ruta).size()-1);
    }else if(ca == '\''){
        disco->ruta = (disco->ruta).substr(0, (disco->ruta).size()-1);
    }


    if (disco->ajuste=="BF"){
        master.p_tipo = 'B';
    }else if (disco->ajuste=="FF"){
        master.p_tipo = 'F';
    }else if (disco->ajuste=="WF"){
        master.p_tipo = 'W';
    }else if (disco->ajuste==""){
        master.p_tipo = 'F';
    }else{
        error = true;
        printf("Error el valor de -f no es permitido");
    }
    if(disco->ruta!="" && error == false){
        if(disco->size>0){
            if (disco->unidad == "k" || disco->unidad == "K" ){
                master.d_tam = disco->size;
                crearDisco(disco->ruta, disco->size, master);
            }else if (disco->unidad == "m" ||disco->unidad == "M"){
                master.d_tam = disco->size*1000;
                crearDisco(disco->ruta, disco->size*1000, master);
            }else if(disco->unidad == ""){
                master.d_tam = disco->size*1000;
                crearDisco(disco->ruta, disco->size*1000, master);
            }else{
                printf("Error la unidad ingresada no es permitida\n");
            }
        }else{
            printf("El valor de size ingresado no es mayor que 0 o no se ingreso el parametro size\n");
        }
    }else{
        printf("Error no se ingreso el parametro path\n");
    }
}
