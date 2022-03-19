#include "fdisk.h"
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>

#include "estructura.h"
#include "rep.cpp"

fdisk::fdisk()
{

}


bool existeParticion(string ruta, string nombre){
    FILE *archivo;
    int extendida = -1;
    if (archivo = fopen(ruta.c_str(), "rb+")){
        Disco master;
        fseek(archivo, 0, SEEK_SET);
        fread(&master, sizeof(Disco), 1, archivo);
        for (int i = 0; i < 4; ++i) {
            if((strcmp(nombre.c_str(), master.particiones[i].p_nombre))==0 ){
                fclose(archivo);
                return true;
            }else if (master.particiones[i].p_type='E'){
                extendida = i;
            }
        }
        if(extendida != -1){
            fseek(archivo,master.particiones[extendida].p_comienzo, SEEK_SET);
            ext sub;
            while((fread(&sub, sizeof(ext),1, archivo))!=0 && (ftell(archivo)<(master.particiones[extendida].p_tam + master.particiones[extendida].p_comienzo))){
                if(strcmp(sub.e_nombre, nombre.c_str())==0){
                    fclose(archivo);
                    return true;
                }
                if(sub.e_siguiente==-1){
                    fclose(archivo);
                    return false;
                }
            }
        }
    }
    fclose(archivo);
    return false;
}


void ParticionPrimaria(string nombre, string ruta, int sizeByte, char ajuste){
    FILE *archivo;
    Disco master;

    char buffer = '1';
    if (archivo = fopen(ruta.c_str(), "rb+")){
        bool Cparticion = false;
        int NParticion = 0;
        fseek(archivo, 0, SEEK_SET);
        fread(&master, sizeof(Disco), 1, archivo);
        for (int i = 0; i < 4; i++) {
            //printf("%d\n", master.particiones[i].p_comienzo);
            if(master.particiones[i].p_comienzo == -1|| (master.particiones[i].p_estado == '1'&&master.particiones[i].p_tam >= sizeByte)){
                Cparticion = true;
                NParticion = i;
                break;
            }
        }
        if (Cparticion){
            int EspacioUse=0;//Kilobyte
            for (int i = 0; i < 4; i++) {
                if (master.particiones[i].p_estado != '1'){
                    EspacioUse += master.particiones[i].p_tam;
                }
            }
            EspacioUse += (int)sizeof(Disco);
            if((master.d_tam-EspacioUse)>=sizeByte){
                if(! existeParticion(ruta, nombre)){
                    if (master.p_tipo == 'F'){
                        master.particiones[NParticion].p_type = 'P';
                        master.particiones[NParticion].p_tipo = ajuste;
                        if(NParticion == 0){
                            master.particiones[NParticion].p_comienzo = sizeof(master);
                        }else{
                            master.particiones[NParticion].p_comienzo = master.particiones[NParticion-1].p_comienzo + master.particiones[NParticion-1].p_tam;
                        }
                        master.particiones[NParticion].p_tam = sizeByte;
                        master.particiones[NParticion].p_estado = '0';
                        strcpy(master.particiones[NParticion].p_nombre,nombre.c_str());
                        fseek(archivo, 0, SEEK_SET);
                        fwrite(&master, sizeof(Disco), 1, archivo);
                        fseek(archivo, master.particiones[NParticion].p_comienzo, SEEK_SET);
                        for (int i = 0; i < sizeByte; i++) {
                            fwrite(&buffer, 1,1,archivo);
                        }
                        printf("Se creo correctamente la particion primaria\n");
                    }else if (master.p_tipo == 'B'){
                        int mejor = NParticion;
                        for (int i = 0; i < 4; i++) {
                            if((master.particiones[i].p_estado == '1' && master.particiones[i].p_tam>=sizeByte)||master.particiones[i].p_comienzo == -1){
                                if(i!=NParticion){
                                    if (master.particiones[i].p_tam< master.particiones[mejor].p_tam){
                                        mejor = i;
                                    }
                                }
                            }
                        }
                        master.particiones[mejor].p_type = 'P';
                        master.particiones[mejor].p_tipo = ajuste;
                        if(mejor == 0){
                            master.particiones[mejor].p_comienzo = sizeof(master);
                        }else{
                            master.particiones[mejor].p_comienzo = master.particiones[mejor-1].p_comienzo + master.particiones[mejor-1].p_tam;
                        }
                        master.particiones[mejor].p_tam = sizeByte;
                        master.particiones[mejor].p_estado = '0';
                        strcpy(master.particiones[mejor].p_nombre,nombre.c_str());
                        fseek(archivo, 0, SEEK_SET);
                        fwrite(&master, sizeof(Disco), 1, archivo);
                        fseek(archivo, master.particiones[mejor].p_comienzo, SEEK_SET);
                        for (int i = 0; i < sizeByte; i++) {
                            fwrite(&buffer, 1,1,archivo);
                        }
                        printf("Se creo correctamente la particion primaria\n");
                    }else if (master.p_tipo=='W'){
                        int peor = NParticion;
                        for (int i = 0; i < 4; i++) {
                            if((master.particiones[i].p_estado == '1' && master.particiones[i].p_tam>=sizeByte)||master.particiones[i].p_comienzo == -1){
                                if(i!=NParticion){
                                    if (master.particiones[i].p_tam > master.particiones[peor].p_tam){
                                        peor = i;
                                    }
                                }
                            }
                        }
                        master.particiones[peor].p_type = 'P';
                        master.particiones[peor].p_tipo =ajuste;
                        if(peor == 0){
                            master.particiones[peor].p_comienzo = sizeof(master);
                        }else{
                            master.particiones[peor].p_comienzo = master.particiones[peor-1].p_comienzo + master.particiones[peor-1].p_tam;
                        }
                        master.particiones[peor].p_tam = sizeByte;
                        master.particiones[peor].p_estado = '0';
                        strcpy(master.particiones[peor].p_nombre,nombre.c_str());
                        fseek(archivo, 0, SEEK_SET);
                        fwrite(&master, sizeof(Disco), 1, archivo);
                        fseek(archivo, master.particiones[peor].p_comienzo, SEEK_SET);
                        for (int i = 0; i < sizeByte; i++) {
                            fwrite(&buffer, 1,1,archivo);
                        }
                        printf("Se creo correctamente la particion primaria\n");
                    }

                }else{
                    printf("Error ya hay un particion con el mismo nombre\n");
                }
            }else{
                printf("Error no hay suficiente espacio libre\n");
            }
        }else{
            bool comprobar =false;
            for (int i = 0; i < 4; i++) {
                if((master.particiones[i].p_estado == '1'&&master.particiones[i].p_tam < sizeByte)){
                    comprobar = true;
                    break;
                }
            }
            if(comprobar){
                printf("Error no hay suficiente espacio libre\n");
            }else{
                printf("Error ya hay 4 particiones creadas en el disco\n");
            }
        }
    fclose(archivo);
    }else{
        printf("Error no se encontro el disco\n");
    }
}

void ParticionExtendida(string nombre, string ruta, int sizeByte, char ajuste){
    FILE *archivo;
    Disco master;
    char buffer = '1';
    if(archivo=fopen(ruta.c_str(), "rb+")){
        bool Cparticion = false;
        bool ExparticionE = false;
        int NParticion = 0;
        fseek(archivo, 0, SEEK_SET);
        fread(&master, sizeof(Disco), 1, archivo);
        for (int i = 0; i < 4; i++) {
            if(master.particiones[i].p_type == 'E'){
                ExparticionE = true;
                break;
            }
        }
        if(!ExparticionE){
            for (int i = 0; i < 4; i++) {
                if(master.particiones[i].p_comienzo == -1||(master.particiones[i].p_estado == '1'&&master.particiones[i].p_tam >= sizeByte)){
                    Cparticion = true;
                    NParticion = i;
                    break;
                }
            }
            if(Cparticion){
                int EspacioUse = 0;
                for (int i = 0; i < 4; i++) {
                    if(master.particiones[i].p_estado != '1'){
                        EspacioUse += master.particiones[i].p_tam;
                    }
                }
                EspacioUse += (int)sizeof(Disco);
                if((master.d_tam-EspacioUse)>=sizeByte){
                    if(!existeParticion(ruta, nombre)){
                        if(master.p_tipo == 'F'){
                            master.particiones[NParticion].p_type = 'E';
                            master.particiones[NParticion].p_tipo = ajuste;
                            if(NParticion==0){
                                master.particiones[NParticion].p_comienzo = sizeof(master);
                            }else{
                                master.particiones[NParticion].p_comienzo = master.particiones[NParticion-1].p_comienzo + master.particiones[NParticion-1].p_tam;
                            }
                            master.particiones[NParticion].p_tam = sizeByte;
                            master.particiones[NParticion].p_estado = '0';
                            strcpy(master.particiones[NParticion].p_nombre,nombre.c_str());
                            fseek(archivo, 0, SEEK_SET);
                            fwrite(&master, sizeof(Disco), 1, archivo);
                            fseek(archivo, master.particiones[NParticion].p_comienzo, SEEK_SET);
                            ext Extendida;
                            Extendida.e_tipo =ajuste;
                            Extendida.e_comienzo = master.particiones[NParticion].p_comienzo;
                            Extendida.e_estado = '0';
                            Extendida.e_siguiente = -1;
                            Extendida.e_tam = 0;
                            strcpy(Extendida.e_nombre, "");
                            fwrite(&Extendida, sizeof(ext),1,archivo);
                            for (int i = 0; i < (sizeByte-(int)sizeof(ext)); i++) {
                                fwrite(&buffer,1,1,archivo);
                            }
                            printf("Se creo correctamente la particion extendida\n");
                        }else if (master.p_tipo = 'B'){
                            int mejor = NParticion;
                            for (int i = 0; i < 4; i++) {
                                if((master.particiones[i].p_estado == '1' && master.particiones[i].p_tam>=sizeByte)||master.particiones[i].p_comienzo == -1){
                                    if(i!=NParticion){
                                        if (master.particiones[i].p_tam< master.particiones[mejor].p_tam){
                                            mejor = i;
                                        }
                                    }
                                }
                            }
                            master.particiones[mejor].p_type = 'E';
                            master.particiones[mejor].p_tipo = ajuste;
                            if(mejor==0){
                                master.particiones[mejor].p_comienzo = sizeof(master);
                            }else{
                                master.particiones[mejor].p_comienzo = master.particiones[mejor-1].p_comienzo + master.particiones[mejor-1].p_tam;
                            }
                            master.particiones[mejor].p_tam = sizeByte;
                            master.particiones[mejor].p_estado = '0';
                            strcpy(master.particiones[mejor].p_nombre,nombre.c_str());
                            fseek(archivo, 0, SEEK_SET);
                            fwrite(&master, sizeof(Disco), 1, archivo);
                            fseek(archivo, master.particiones[mejor].p_comienzo, SEEK_SET);
                            ext Extendida;
                            Extendida.e_tipo = ajuste;
                            Extendida.e_comienzo = master.particiones[mejor].p_comienzo;
                            Extendida.e_estado = '0';
                            Extendida.e_siguiente = -1;
                            Extendida.e_tam = 0;
                            strcpy(Extendida.e_nombre, "");
                            fwrite(&Extendida, sizeof(ext),1,archivo);
                            for (int i = 0; i < (sizeByte-(int)sizeof(ext)); i++) {
                                fwrite(&buffer,1,1,archivo);
                            }
                            printf("Se creo correctamente la particion extendida\n");
                        }else if (master.p_tipo == 'W'){
                            int peor = NParticion;
                            for (int i = 0; i < 4; i++) {
                                if((master.particiones[i].p_estado == '1' && master.particiones[i].p_tam>=sizeByte)||master.particiones[i].p_comienzo == -1){
                                    if(i!=NParticion){
                                        if (master.particiones[i].p_tam> master.particiones[peor].p_tam){
                                            peor = i;
                                        }
                                    }
                                }
                            }
                            master.particiones[peor].p_type = 'E';
                            master.particiones[peor].p_tipo = ajuste;
                            if(peor==0){
                                master.particiones[peor].p_comienzo = sizeof(master);
                            }else{
                                master.particiones[peor].p_comienzo = master.particiones[peor-1].p_comienzo + master.particiones[peor-1].p_tam;
                            }
                            master.particiones[peor].p_tam = sizeByte;
                            master.particiones[peor].p_estado = '0';
                            strcpy(master.particiones[peor].p_nombre,nombre.c_str());
                            fseek(archivo, 0, SEEK_SET);
                            fwrite(&master, sizeof(Disco), 1, archivo);
                            fseek(archivo, master.particiones[peor].p_comienzo, SEEK_SET);
                            ext Extendida;
                            Extendida.e_tipo = ajuste;
                            Extendida.e_comienzo = master.particiones[peor].p_comienzo;
                            Extendida.e_estado = '0';
                            Extendida.e_siguiente = -1;
                            Extendida.e_tam = 0;
                            strcpy(Extendida.e_nombre, "");
                            fwrite(&Extendida, sizeof(ext),1,archivo);
                            for (int i = 0; i < (sizeByte-(int)sizeof(ext)); i++) {
                                fwrite(&buffer,1,1,archivo);
                            }
                            printf("Se creo correctamente la particion extendida\n");
                        }

                    }else{
                        printf("Error ya hay un particion con el mismo nombre\n");
                    }
                }else{
                    printf("Error no hay suficiente espacio libre\n");
                }
            }else{
                bool comprobar =false;
                for (int i = 0; i < 4; i++) {
                    if((master.particiones[i].p_estado == '1'&&master.particiones[i].p_tam < sizeByte)){
                        comprobar = true;
                        break;
                    }
                }
                if(comprobar){
                    printf("Error no hay suficiente espacio libre\n");
                }else{
                    printf("Error ya hay 4 particiones creadas en el disco\n");
                }
            }
        }else{
            printf("Error ya hay una particio extendida en el disco\n");
        }
    fclose(archivo);
    }else{
        printf("Error no se encontro el disco\n");
    }
}

void ParticionLogica(string nombre, string ruta, int sizeByte, char ajuste){
    FILE *archivo;
    Disco master;
    char buffer = '1';
    if(archivo=fopen(ruta.c_str(), "rb+")){
        bool ExparticionE = false;
        int NParticion = 0;
        fseek(archivo, 0, SEEK_SET);
        fread(&master, sizeof(Disco), 1, archivo);
        for (int i = 0; i < 4; i++) {
            if(master.particiones[i].p_type == 'E'){
                ExparticionE = true;
                NParticion = i;
                break;
            }
        }
        if(ExparticionE){
            if(!existeParticion(ruta, nombre)){
                ext Extenida;
                int contador = master.particiones[NParticion].p_comienzo;
                fseek(archivo, contador, SEEK_SET);
                fread(&Extenida, sizeof(ext), 1, archivo);
                if(Extenida.e_tam == 0){
                    if(master.particiones[NParticion].p_tam > sizeByte){
                        Extenida.e_tam = sizeByte;
                        Extenida.e_comienzo = ftell(archivo) - sizeof(ext);
                        Extenida.e_estado = '0';
                        Extenida.e_siguiente = -1;
                        Extenida.e_tipo = ajuste;
                        strcpy(Extenida.e_nombre, nombre.c_str());
                        fseek(archivo, master.particiones[NParticion].p_comienzo, SEEK_SET);
                        fwrite(&Extenida, sizeof(ext), 1, archivo);
                        printf("Se creo correctamente la particion logica\n");
                    }else{
                        printf("Error no hay suficiente espacion\n");
                    }
                }else{
                    bool estado1 = false;
                    while((master.particiones[NParticion].p_comienzo + master.particiones[NParticion].p_tam >ftell(archivo))&&(Extenida.e_siguiente != -1|| Extenida.e_estado=='1')){
                        fseek(archivo, Extenida.e_siguiente, SEEK_SET);
                        fread(&Extenida, sizeof(ext), 1, archivo);
                        if(Extenida.e_estado =='1'){
                            if (Extenida.e_tam>= sizeByte){
                                estado1 = true;
                                break;
                            }
                        }
                        if(Extenida.e_siguiente == -1){
                            break;
                        }
                    }
                    if (estado1){
                        if (master.particiones[NParticion].p_tipo == 'F'){
                            Extenida.e_estado = '0';
                            Extenida.e_tam = sizeByte;
                            Extenida.e_tipo = ajuste;
                            strcpy(Extenida.e_nombre, nombre.c_str());
                            fseek(archivo, ftell(archivo)-sizeof(ext), SEEK_SET);
                            fwrite(&Extenida, sizeof(ext), 1, archivo);
                            printf("Se creo correctamente la particion logica\n");
                        }else if (master.particiones[NParticion].p_tipo == 'B'){
                            ext aux = Extenida;
                            while((master.particiones[NParticion].p_comienzo + master.particiones[NParticion].p_tam >ftell(archivo))&&(Extenida.e_siguiente != -1|| Extenida.e_estado=='1')){
                                fseek(archivo, Extenida.e_siguiente, SEEK_SET);
                                fread(&Extenida, sizeof(ext), 1, archivo);
                                if(Extenida.e_estado =='1'){
                                    if (Extenida.e_tam<aux.e_tam){
                                        break;
                                    }
                                }
                                if(Extenida.e_siguiente == -1){
                                    break;
                                }
                            }
                            Extenida.e_estado = '0';
                            Extenida.e_tam = sizeByte;
                            Extenida.e_tipo = ajuste;
                            strcpy(Extenida.e_nombre, nombre.c_str());
                            fseek(archivo, ftell(archivo)-sizeof(ext), SEEK_SET);
                            fwrite(&Extenida, sizeof(ext), 1, archivo);
                            printf("Se creo correctamente la particion logica\n");
                        }else if (master. particiones[NParticion].p_tipo == 'W'){
                            ext aux = Extenida;
                            while((master.particiones[NParticion].p_comienzo + master.particiones[NParticion].p_tam >ftell(archivo))&&(Extenida.e_siguiente != -1|| Extenida.e_estado=='1')){
                                fseek(archivo, Extenida.e_siguiente, SEEK_SET);
                                fread(&Extenida, sizeof(ext), 1, archivo);
                                if(Extenida.e_estado =='1'){
                                    if (Extenida.e_tam>aux.e_tam){
                                        break;
                                    }
                                }
                                if(Extenida.e_siguiente == -1){
                                    break;
                                }
                            }
                            Extenida.e_estado = '0';
                            Extenida.e_tam = sizeByte;
                            Extenida.e_tipo = ajuste;
                            strcpy(Extenida.e_nombre, nombre.c_str());
                            fseek(archivo, ftell(archivo)-sizeof(ext), SEEK_SET);
                            fwrite(&Extenida, sizeof(ext), 1, archivo);
                            printf("Se creo correctamente la particion logica\n");
                        }
                    }else{
                        int useEspacio = Extenida.e_tam + Extenida.e_comienzo + sizeByte;
                        if((master.particiones[NParticion].p_tam+master.particiones[NParticion].p_comienzo)>= useEspacio){
                            Extenida.e_siguiente = Extenida.e_comienzo + Extenida.e_tam;
                            fseek(archivo, ftell(archivo)-sizeof(ext), SEEK_SET);
                            fwrite(&Extenida, sizeof(ext), 1, archivo);
                            fseek(archivo, Extenida.e_comienzo+Extenida.e_tam, SEEK_SET);
                            Extenida.e_tam = sizeByte;
                            Extenida.e_comienzo = ftell(archivo);
                            Extenida.e_estado = '0';
                            Extenida.e_siguiente = -1;
                            Extenida.e_tipo = ajuste;
                            strcpy(Extenida.e_nombre, nombre.c_str());
                            fwrite(&Extenida, sizeof(ext), 1, archivo);
                            printf("Se creo correctamente la particion logica\n");
                        }else{
                            printf("Error no hay espacio suficiente\n");
                        }
                    }
                   /* bool recorrer = true;
                    while(recorrer){
                        bool estado1 = false;
                        while((master.particiones[NParticion].p_comienzo + master.particiones[NParticion].p_tam >ftell(archivo))&&(Extenida.e_siguiente != -1|| Extenida.e_estado=='1')){
                            fseek(archivo, Extenida.e_siguiente, SEEK_SET);
                            fread(&Extenida, sizeof(ext), 1, archivo);
                            if(Extenida.e_estado =='1'){
                                estado1 = true;
                                break;
                            }
                            if(Extenida.e_siguiente == -1){
                                break;
                            }
                        }
                        if (master.particiones[NParticion].p_tipo == 'F'){
                            if (estado1){
                                if (Extenida.e_tam>= sizeByte){
                                    Extenida.e_estado = '0';
                                    Extenida.e_tam = sizeByte;
                                    Extenida.e_tipo = ajuste;
                                    strcpy(Extenida.e_nombre, nombre.c_str());
                                    fseek(archivo, ftell(archivo)-sizeof(ext), SEEK_SET);
                                    fwrite(&Extenida, sizeof(ext), 1, archivo);
                                    recorrer = false;
                                    printf("Se creo correctamente la particion logica\n");
                                }else{
                                    estado1 = false;
                                }
                            }else{
                                int useEspacio = Extenida.e_tam + Extenida.e_comienzo + sizeByte;
                                if((master.particiones[NParticion].p_tam+master.particiones[NParticion].p_comienzo)>= useEspacio){
                                    Extenida.e_siguiente = Extenida.e_comienzo + Extenida.e_tam;
                                    fseek(archivo, ftell(archivo)-sizeof(ext), SEEK_SET);
                                    fwrite(&Extenida, sizeof(ext), 1, archivo);
                                    fseek(archivo, Extenida.e_comienzo+Extenida.e_tam, SEEK_SET);
                                    Extenida.e_tam = sizeByte;
                                    Extenida.e_comienzo = ftell(archivo);
                                    Extenida.e_estado = '0';
                                    Extenida.e_siguiente = -1;
                                    Extenida.e_tipo = ajuste;
                                    strcpy(Extenida.e_nombre, nombre.c_str());
                                    fwrite(&Extenida, sizeof(ext), 1, archivo);
                                    recorrer = false;
                                    printf("Se creo correctamente la particion logica\n");
                                }else{
                                    if(!recorrer){
                                        printf("Error no hay espacio suficiente\n");
                                    }
                                }
                            }
                        }else if (master.particiones[NParticion].p_tipo=='B'){

                        }else if (master.particiones[NParticion].p_tipo == 'W'){

                        }
                    }*/

                }
            }else{
                printf("Error ya hay un particion con el mismo nombre\n");
            }
        }else{
            printf("Error no existe una particion extendida en el disco\n");
        }
    fclose(archivo);
    }else{
        printf("Error no se encontro el disco\n");
    }
}

void AgregarParticion(string ruta, string nombre, int sizebyte){
    FILE *archivo;
    Disco master;

    string tipo = "Nulo";
    if(sizebyte > 0){
        tipo = "agregar";
    }

    if(archivo=fopen(ruta.c_str(), "rb+")){
        bool montado = ListaMontado(ruta, nombre);
        if(!montado){
            bool Exparticion = false;
            int NParticion = -1;
            int NParticionE = -1;
            fseek(archivo, 0, SEEK_SET);
            fread(&master, sizeof(Disco),1 , archivo);
            for (int i = 0; i < 4; i++) {
                //cout << master.particiones[i].p_type<<endl;
                if(strcmp(master.particiones[i].p_nombre,nombre.c_str())==0){
                    if(master.particiones[i].p_type=='E'){
                        Exparticion = true;
                    }
                    NParticion = i;
                    break;
                }else if(master.particiones[i].p_type =='E'){
                    Exparticion = true;
                    NParticionE = i;
                }
            }
            if(NParticion != -1){
                if(!Exparticion){
                    if (tipo == "agregar"){
                        if(NParticion != 3){
                            int comprobar = master.particiones[NParticion+1].p_comienzo - (master.particiones[NParticion].p_comienzo + master.particiones[NParticion].p_tam);
                            if(comprobar != 0){
                                if(comprobar>=sizebyte){
                                    master.particiones[NParticion].p_tam = master.particiones[NParticion].p_tam + sizebyte;
                                    fseek(archivo, 0, SEEK_SET);
                                    fwrite(&master, sizeof(Disco), 1, archivo);
                                    printf("Se agrego mas memoria al la particion\n");
                                }else if(master.particiones[NParticion+1].p_estado == '0' && master.particiones[NParticion+1].p_tam == 0){
                                    if(sizebyte<= (master.d_tam-(master.particiones[NParticion].p_tam+master.particiones[NParticion].p_comienzo))){
                                        master.particiones[NParticion].p_tam = master.particiones[NParticion].p_tam + sizebyte;
                                        fseek(archivo, 0, SEEK_SET);
                                        fwrite(&master, sizeof(Disco), 1, archivo);
                                        printf("Se agrego mas memoria al la particion\n");
                                    }else{
                                        printf("Error no hay suficiente espacio a la derecha\n");
                                    }
                                }else{
                                    printf("Error no hay suficiente espacio a la derecha\n");
                                }
                            }else{
                                if(master.particiones[NParticion+1].p_estado == '1'){
                                    if(sizebyte<= master.particiones[NParticion+1].p_tam){
                                        master.particiones[NParticion].p_tam = master.particiones[NParticion].p_tam + sizebyte;
                                        master.particiones[NParticion+1].p_comienzo =master.particiones[NParticion+1].p_comienzo + sizebyte;
                                        master.particiones[NParticion+1].p_tam = master.particiones[NParticion+1].p_tam - sizebyte;
                                        fseek(archivo, 0, SEEK_SET);
                                        fwrite(&master, sizeof(Disco), 1, archivo);
                                        printf("Se agrego mas memoria al la particion\n");
                                    }else{
                                        printf("Error no hay suficiente espacio a la derecha\n");
                                    }
                                }else{
                                    printf("Error no hay suficiente espacio a la derecha\n");
                                }

                            }
                        }else{
                            int comprobar =  (master.d_tam + (int)sizeof(Disco)) - (master.particiones[NParticion].p_tam+master.particiones[NParticion].p_comienzo);
                            if (comprobar!=0){
                                if(comprobar>= sizebyte){
                                    master.particiones[NParticion].p_tam = (master.particiones[NParticion].p_tam - sizebyte);
                                    fseek(archivo, 0, SEEK_SET);
                                    fwrite(&master, sizeof(Disco), 1 , archivo);
                                    printf("Se agrego mas memoria al la particion\n");
                                }else{
                                    printf("Error no hay suficiente espacio a la derecha\n");
                                }
                            }else{
                                printf("Error no hay suficiente espacio a la derecha\n");
                            }
                        }
                    }else{
                        if(-(sizebyte) >= master.particiones[NParticion].p_tam){
                            printf("Error la cantidad que desea quitar excede al size de la particion\n");
                        }else{
                            master.particiones[NParticion].p_tam = (master.particiones[NParticion].p_tam + sizebyte);
                            fseek(archivo, 0, SEEK_SET);
                            fwrite(&master, sizeof(Disco), 1, archivo);
                            printf("Se quito memoria al la particion\n");
                        }
                    }
                }else{
                    if(tipo == "agregar"){
                        if(NParticion !=3){
                            int comprobar = master.particiones[NParticion+1].p_comienzo - (master.particiones[NParticion].p_comienzo+master.particiones[NParticionE].p_tam);
                            if(comprobar !=0){
                                if (comprobar>= sizebyte){
                                    master.particiones[NParticion].p_tam= master.particiones[NParticion].p_tam + sizebyte;
                                    fseek(archivo, 0, SEEK_SET);
                                    fwrite(&master, sizeof(Disco), 1, archivo);
                                    printf("Se agrego mas memoria al la particion\n");
                                }else if(master.particiones[NParticion+1].p_estado == '0' && master.particiones[NParticion+1].p_tam == 0){
                                    if(sizebyte<= (master.d_tam-(master.particiones[NParticion].p_tam+master.particiones[NParticion].p_comienzo))){
                                        master.particiones[NParticion].p_tam = master.particiones[NParticion].p_tam + sizebyte;
                                        fseek(archivo, 0, SEEK_SET);
                                        fwrite(&master, sizeof(Disco), 1, archivo);
                                        printf("Se agrego mas memoria al la particion\n");
                                    }else{
                                        printf("Error no hay suficiente espacio a la derecha\n");
                                    }
                                }else{
                                    printf("Error no hay suficiente espacio a la derecha\n");
                                }
                            }else{
                                if(master.particiones[NParticion+1].p_estado =='1'){
                                    if(sizebyte<=master.particiones[NParticion+1].p_tam){
                                        master.particiones[NParticion].p_tam = master.particiones[NParticion].p_tam + sizebyte;
                                        master.particiones[NParticion+1].p_comienzo = master.particiones[NParticion+1].p_comienzo + sizebyte;
                                        master.particiones[NParticion+1].p_tam = master.particiones[NParticion+1].p_tam - sizebyte;
                                        fseek(archivo,0, SEEK_SET);
                                        fwrite(&master, sizeof(Disco), 1, archivo);
                                        printf("Se agrego mas memoria al la particion\n");
                                    }else{
                                        printf("Error no hay suficiente espacio a la derecha\n");
                                    }
                                }else{
                                    printf("Error no hay suficiente espacio a la derecha\n");
                                }
                            }
                        }else{
                            int comprobar = (master.d_tam + (int)sizeof(Disco)) - (master.particiones[NParticion].p_tam+master.particiones[NParticion].p_comienzo);
                            if (comprobar !=0){
                                if(comprobar >= sizebyte){
                                    master.particiones[NParticion].p_tam = master.particiones[NParticion].p_tam + sizebyte;
                                    fseek(archivo, 0, SEEK_SET);
                                    fwrite(&master, sizeof(Disco), 1 , archivo);
                                    printf("Se agrego mas memoria al la particion\n");
                                }else{
                                    printf("Error no hay suficiente espacio a la derecha\n");
                                }
                            }else{
                                printf("Error no hay suficiente espacio a la derecha\n");
                            }
                        }
                    }else{
                        if (sizebyte >= master.particiones[NParticionE].p_tam){
                            printf("Error la cantidad que desea quitar excede al size de la particion\n");
                        }else{
                            ext Extendida;
                            fseek(archivo, master.particiones[NParticion].p_comienzo, SEEK_SET);
                            fread(&Extendida, sizeof(ext), 1 , archivo);
                            while((ftell(archivo)<master.particiones[NParticion].p_tam+master.particiones[NParticion].p_comienzo)&&Extendida.e_siguiente !=-1){
                                fseek(archivo, Extendida.e_siguiente, SEEK_SET);
                                fread(&Extendida, sizeof(ext), 1 , archivo);
                            }
                            int comprobar = (master.particiones[NParticion].p_comienzo+master.particiones[NParticion].p_tam) + sizebyte;
                            if(comprobar>(Extendida.e_comienzo+Extendida.e_tam)){
                                master.particiones[NParticion].p_tam = master.particiones[NParticion].p_tam + sizebyte;
                                fseek(archivo,0, SEEK_SET);
                                fwrite(&master, sizeof(Disco), 1, archivo);
                                printf("Se quito memoria al la particion\n");
                            }else{
                                printf("Error porque la particion logica se corromperia\n");
                            }
                        }
                    }
                }
            }else{
                if(NParticionE != -1){
                    int buscar = -1;
                    FILE *archivoa;
                    Disco master2;
                    if(archivoa = fopen(ruta.c_str(),"rb+")){
                        int NParticionE = -1;
                        fseek(archivoa, 0, SEEK_SET);
                        fread(&master2, sizeof(Disco), 1, archivoa);
                        for (int i = 0; i < 4; i++) {
                            if (master2.particiones[i].p_type == 'E'){
                                NParticionE = i;
                                break;
                            }
                        }
                        if(NParticionE != -1){
                            ext Extendida;
                            fseek(archivoa, master2.particiones[NParticionE].p_comienzo, SEEK_SET);
                            fread(&Extendida, sizeof(ext), 1 , archivoa);
                            while ((ftell(archivoa)<master2.particiones[NParticionE].p_tam + master2.particiones[NParticionE].p_comienzo)) {
                                if (strcmp(Extendida.e_nombre,nombre.c_str())==0){
                                    //cout<<Extendida.e_comienzo;
                                    buscar = (ftell(archivoa)-sizeof(ext));
                                }
                                if(Extendida.e_siguiente == -1){
                                    break;
                                }
                                fseek(archivoa, Extendida.e_siguiente, SEEK_SET);
                                fread(&Extendida, sizeof(ext), 1 , archivoa);
                            }
                        }
                        fclose(archivoa);
                    }

                    //int total = tamLogica(nombre, ruta);
                    int total = -1;
                    FILE *archivob;
                    Disco master3;
                    if(archivob = fopen(ruta.c_str(),"rb+")){
                        int NParticionE = -1;
                        fseek(archivob, 0, SEEK_SET);
                        fread(&master3, sizeof(Disco), 1, archivob);
                        for (int i = 0; i < 4; i++) {
                            if (master3.particiones[i].p_type == 'E'){
                                NParticionE = i;
                                break;
                            }
                        }
                        if(NParticionE != -1){
                            ext Extendida;
                            int tam =0;
                            fseek(archivob, master3.particiones[NParticionE].p_comienzo, SEEK_SET);
                            fread(&Extendida, sizeof(ext), 1 , archivob);
                            while ((ftell(archivob)<master3.particiones[NParticionE].p_tam + master3.particiones[NParticionE].p_comienzo)) {
                                tam += Extendida.e_tam;
                                if(Extendida.e_siguiente == -1){
                                    total = tam;
                                }
                                fseek(archivob, Extendida.e_siguiente, SEEK_SET);
                                fread(&Extendida, sizeof(ext), 1 , archivob);
                            }
                        }
                        fclose(archivob);
                    }

                    if(buscar != -1){
                        if (tipo == "agregar"){
                            ext Extendida;
                            fseek(archivo,buscar, SEEK_SET);
                            fread(&Extendida, sizeof(ext), 1, archivo);
                            //cout<< master.particiones[NParticionE].p_tam<<endl;
                            if(Extendida.e_siguiente == -1 && master.particiones[NParticionE].p_tam >= (total+sizebyte)){
                                Extendida.e_tam = Extendida.e_tam + sizebyte;
                                fseek(archivo, buscar, SEEK_SET);
                                fwrite(&Extendida, sizeof(ext), 1, archivo);
                                printf("Se agrego mas memoria al la particion\n");

                            }else if ((Extendida.e_siguiente-(Extendida.e_comienzo+Extendida.e_tam))>= sizebyte && Extendida.e_siguiente != -1){
                                Extendida.e_tam = Extendida.e_tam + sizebyte;
                                fseek(archivo, buscar, SEEK_SET);
                                fwrite(&Extendida, sizeof(ext), 1, archivo);
                                printf("Se agrego mas memoria al la particion\n");
                            }else{
                                printf("Error no hay suficiente espacio a la derecha\n");
                            }
                        }else{
                            ext Extendida;
                            fseek(archivo,buscar, SEEK_SET);
                            fread(&Extendida, sizeof(ext), 1, archivo);
                            if (-(sizebyte) >= Extendida.e_tam){
                                printf("Error porque la particion logica se corromperia\n");
                            }else{
                                //cout<< Extendida.e_tam<<endl;
                                Extendida.e_tam = Extendida.e_tam + sizebyte;
                                fseek(archivo, buscar, SEEK_SET);
                                fwrite(&Extendida, sizeof(ext), 1, archivo);
                                printf("Se quito memoria al la particion\n");
                            }
                        }
                    }else{
                        printf("Error no se encontro la particion con el mismo nombre\n");
                    }
                }else{
                    printf("Error no se encontro la particion con el mismo nombre\n");
                }
            }
        }else{
            printf("Error la particion se encuentra montada\n");
        }
        fclose(archivo);
    }else{
        printf("Error no se encontro el disco\n");
    }

}

void EliminarParticion(string ruta, string nombre, string tipo){
    FILE *archivo;
    Disco master;

    if(archivo = fopen(ruta.c_str(),"rb+")){
        bool montado = ListaMontado(ruta, nombre);
        if(!montado){
            int NParticion = -1;
            int NParticionE = -1;
            char buffer = '\0';
            bool Exparticion = false;
            fseek(archivo, 0, SEEK_SET);
            fread(&master, sizeof(Disco), 1, archivo);
            for (int i = 0; i < 4; i++) {
                if(strcmp(master.particiones[i].p_nombre,nombre.c_str())==0){
                    NParticion = i;
                    if(master.particiones[i].p_type=='E'){
                        Exparticion = true;
                    }
                    break;
                }else if (master.particiones[i].p_type == 'E'){
                    NParticionE = i;
                }
            }

            cout << "Estas seguro de eliminar la particion S/N ";
            string confirmacion;
            getline(cin, confirmacion);
            if (confirmacion == "S" | confirmacion == "s"){
                if (NParticion != -1){
                    if(!Exparticion){
                        if (tipo == "FAST"){
                            master.particiones[NParticion].p_estado = '1';
                            strcpy(master.particiones[NParticion].p_nombre, "");
                            fseek(archivo, 0, SEEK_SET);
                            fwrite(&master, sizeof(Disco), 1, archivo);
                            printf("Se elimino correctamente la particion primaria\n");
                        }else{
                            master.particiones[NParticion].p_estado = '1';
                            strcpy(master.particiones[NParticion].p_nombre, "");

                            fseek(archivo, master.particiones[NParticion].p_comienzo, SEEK_SET);
                            fwrite(&buffer, 1, master.particiones[NParticion].p_tam,archivo);

                            fseek(archivo, 0, SEEK_SET);
                            fwrite(&master, sizeof(Disco),1, archivo);


                            printf("Se elimino correctamente la particion primaria\n");
                        }
                    }else{
                        if(tipo=="FAST"){
                            master.particiones[NParticion].p_estado = '1';
                            master.particiones[NParticion].p_type='0';
                            strcpy(master.particiones[NParticion].p_nombre, "");
                            fseek(archivo, 0, SEEK_SET);
                            fwrite(&master, sizeof(Disco), 1, archivo);
                            printf("Se elimino correctamente la particion extendida\n");
                        }else{
                            master.particiones[NParticion].p_estado = '1';
                            master.particiones[NParticion].p_type='0';
                            strcpy(master.particiones[NParticion].p_nombre, "");

                            fseek(archivo, master.particiones[NParticion].p_comienzo, SEEK_SET);
                            fwrite(&buffer, 1, master.particiones[NParticion].p_tam,archivo);

                            fseek(archivo, 0, SEEK_SET);
                            fwrite(&master, sizeof(Disco),1, archivo);

                            printf("Se elimino correctamente la particion extendida\n");
                        }
                    }
                }else{
                    if(NParticionE != -1){
                        bool comprobar = false;
                        ext Extendida;
                        fseek(archivo, master.particiones[NParticionE].p_comienzo, SEEK_SET);
                        fread(&Extendida, sizeof(ext), 1 , archivo);
                        if (Extendida.e_tam != 0){
                            while ((ftell(archivo)<master.particiones[NParticionE].p_tam + master.particiones[NParticionE].p_comienzo)) {
                                if (strcmp(Extendida.e_nombre,nombre.c_str())==0){
                                    comprobar = true;
                                    break;
                                }
                                if(Extendida.e_siguiente == -1){
                                    break;
                                }
                                fseek(archivo, Extendida.e_siguiente, SEEK_SET);
                                fread(&Extendida, sizeof(ext), 1 , archivo);
                            }
                        }
                        if (comprobar){
                            if(tipo=="FAST"){
                                Extendida.e_estado = '1';
                                strcpy(Extendida.e_nombre, "");

                                //cout<<Extendida.e_siguiente<<endl;

                                fseek(archivo, ftell(archivo)-sizeof(ext), SEEK_SET);
                                fwrite(&Extendida, sizeof(ext), 1, archivo);
                                //cout<<Extendida.e_tam<<endl;

                                printf("Se elimino correctamente la particion logica\n");
                            }else{
                                Extendida.e_estado = '1';
                                strcpy(Extendida.e_nombre, "");

                                fseek(archivo, ftell(archivo)-sizeof(ext), SEEK_SET);
                                fwrite(&buffer, sizeof(ext), 1, archivo);

                                fseek(archivo, ftell(archivo)-sizeof(ext), SEEK_SET);
                                fwrite(&Extendida, sizeof(ext), 1, archivo);

                                printf("Se elimino correctamente la particion extendida\n");
                            }
                        }else{
                            printf("Error no se encontro la particion con el mismo nombre\n");
                        }
                    }else{
                        printf("Error no se encontro la particion con el mismo nombre\n");
                    }
                }
            }else{
                printf("Se cancelo la eliminacion de la parcicion\n");
            }
        }else{
            printf("Error la particion se encuentra montada\n");
        }
        fclose(archivo);
    }else{
        printf("Error no se encontro el disco\n");
    }
}


void fdisk::AdmiDisco(fdisk *disco){
    //cout<<disco->ruta;
    //cout<<disco->nombre;

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

    ca = (disco->nombre).back();
    if(ca == '"'){
        string aux;
        for (int i = 0; i < (disco->nombre).size(); i++) {
            if((disco->nombre)[i]!='"'){
                aux += (disco->nombre)[i];
            }
        }
        disco->nombre = aux;
    }
    bool error = false;
    int espacioByte=0;
    int espacioByteAdd = 0;
    if (disco->unidad == "B"){
        espacioByte = disco->size/1000;
        espacioByteAdd = disco->agregar/1000;
    }else if (disco->unidad=="K"){
        espacioByte = disco->size;
        espacioByteAdd = disco->agregar;
    }else if (disco->unidad=="M"){
        espacioByte = disco->size*1000;
        espacioByteAdd = disco->agregar*1000;
    }else if (disco->unidad ==""){
        espacioByte = disco->size;
        espacioByteAdd = disco->agregar;
    }else{
        error = true;
        printf("Error el valor de -u no es permitido\n");
    }
    char tipoAjuste ;
    if (disco->ajuste == "BF"){
        tipoAjuste = 'B';
    }else if (disco->ajuste == "FF"){
        tipoAjuste = 'F';
    }else if (disco->ajuste == "WF"){
        tipoAjuste = 'W';
    }else if (disco->ajuste == ""){
        tipoAjuste = 'W';
    }else{
        error = true;
        printf("Error el valor de -f no es permitido\n");
    }

    if (disco->ruta != ""){
        if (disco->nombre != ""){
            if (disco->size !=0){
                if(disco->agregar !=0 && disco->eliminar == ""){
                   AgregarParticion(disco->ruta, disco->nombre, espacioByteAdd);

                }else if(disco->eliminar != "" && disco->agregar==0){
                    EliminarParticion(disco->ruta, disco->nombre, disco->eliminar);
                }else{
                    if (disco->agregar!=0 && disco->eliminar != ""){
                        printf("Error parametros incompatible add y delete\n");
                    }else{
                        if (!error){
                            if (disco->tipo == "P"){
                                ParticionPrimaria(disco->nombre, disco->ruta, espacioByte, tipoAjuste);
                            }else if (disco->tipo == "E"){
                                ParticionExtendida(disco->nombre, disco->ruta, espacioByte, tipoAjuste);
                            }else if (disco->tipo == "L"){
                                ParticionLogica(disco->nombre, disco->ruta, espacioByte, tipoAjuste);
                            }else if (disco->tipo == ""){
                                ParticionPrimaria(disco->nombre, disco->ruta, espacioByte, tipoAjuste);
                            }else{
                                printf("Error el valor de type no es permitido\n");
                            }
                        }
                    }
                }
            }else{
                if(disco->agregar !=0 && disco->eliminar == ""){
                    AgregarParticion(disco->ruta, disco->nombre, espacioByteAdd);
                }else if(disco->eliminar != "" && disco->agregar==0){
                    EliminarParticion(disco->ruta, disco->nombre, disco->eliminar);
                }else{
                    printf("Error parametros incompatible add y delete\n");
                }
            }
        }else{
            printf("Error no se ingreso el parametro name\n");
        }
    }else{
        printf("Error no se ingreso el parametro ruta\n");
    }
}
