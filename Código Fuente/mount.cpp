#include "mount.h"
#include<stdio.h>


#include "estructura.h"
#include "listamount.h"
#include "nodomount.h"


listaMount *ListaM = new listaMount;

mount::mount()
{
}

bool ListaMontado(string ruta, string nombre){
    nodoMount *aux =ListaM->primero;
    while (aux != nullptr) {
        if (aux->ruta == ruta && aux->nombre == nombre){
            return true;
        }
        aux = aux->sig;
    }
    return false;
}


int buscarLetra(listaMount *list, string nombre, string ruta){
    int busqueda= 'a';
    nodoMount *aux = list->primero;
    while(aux !=nullptr){
        if((aux->nombre==nombre)&&(aux->ruta==ruta)){
            return -1;
        }else{
            if(aux->ruta==ruta){
                busqueda = (aux->letra)+1;
            }
        }
        aux = aux->sig;
    }
    return busqueda;
}

int buscarNumero(listaMount *list, string nombre, string ruta){
    int busqueda= 1;
    nodoMount *aux = list->primero;
    while(aux !=nullptr){
        if (aux->ruta == ruta){
            return aux->numero;
        }else if (aux->ruta != ruta && aux->numero == busqueda){
            busqueda++;
        }
        aux=aux->sig;
    }
    return busqueda;
}

void mostrarList(listaMount *list){
    nodoMount *aux = list->primero;
    while(aux != nullptr){
        cout<<aux->ruta<<"|"<<aux->nombre<<"|"<<aux->id<<"\n";
        aux = aux->sig;
        //aux = aux->siguiente;
    }
}


void mount:: MontarParticion(mount *montar){
    string aux = (montar->ruta).substr(0, (montar->ruta).size()-1);
    char ca1 = aux.back();
    char ca = (montar->ruta).back();
    if(ca1 == '\''){
        montar->ruta = (montar->ruta).substr(0, (montar->ruta).size()-1);
        montar->ruta = (montar->ruta).substr(0, (montar->ruta).size()-1);
    }else if(ca == '"'){
        string aux1;
        for (int i = 0; i < (montar->ruta).size(); i++) {
            if((montar->ruta)[i]!='"'){
                aux1 += (montar->ruta)[i];
            }
        }
        montar->ruta = aux1;

    }else if(ca == ' '){
        montar->ruta = (montar->ruta).substr(0, (montar->ruta).size()-1);
    }
    ca = (montar->nombre).back();
    if(ca == '"'){
        string aux1;
        for (int i = 0; i < (montar->nombre).size(); i++) {
            if((montar->nombre)[i]!='"'){
                aux1 += (montar->nombre)[i];
            }
        }
        montar->nombre = aux1;
    }

    FILE *archivo;
    Disco master;

    if (montar->nombre != ""){
        if(montar->ruta != ""){
            if((archivo=fopen(ruta.c_str(),"rb+"))){
                fseek(archivo, 0, SEEK_SET);
                fread(&master, sizeof(Disco), 1, archivo);
                int Nparticion = -1;
                int NparticionE = -1;
                bool Exparticion = false;
                for (int i = 0; i < 4; i++) {
                    //cout<<master.particiones[i].p_nombre<<endl;
                    //cout<<montar->name<<endl;
                    if (strcmp(master.particiones[i].p_nombre,(montar->nombre).c_str())==0){
                        Nparticion = i;
                        break;
                    }
                    if (master.particiones[i].p_type == 'E'){
                        NparticionE = i;
                        Exparticion = true;
                    }
                }
                if(Nparticion !=-1){
                    master.particiones[Nparticion].p_estado = '2';
                    fseek(archivo,0, SEEK_SET);
                    fwrite(&master, sizeof(Disco), 1, archivo);
                    if(ListaM->primero == nullptr ){
                        nodoMount *nuevo = new nodoMount("631a", montar->ruta, montar->nombre, 1, 'a');
                        ListaM->primero = nuevo;
                        mostrarList(ListaM);
                    }else{
                        nodoMount *nuevo = ListaM->primero;
                        while(nuevo->sig != nullptr){
                            nuevo = nuevo->sig;
                        }

                        int letra = buscarLetra(ListaM,montar->nombre, montar->ruta);
                        if (letra != -1){
                            int num = buscarNumero(ListaM,montar->nombre, montar->ruta);
                            char letraC = static_cast<char>(letra);
                            string id = "63" + to_string(num)+ letraC;
                            nodoMount *aux1 = new nodoMount(id, montar->ruta, montar->nombre, num, letraC);
                            nuevo->sig = aux1;
                            mostrarList(ListaM);
                        }else{
                            printf("La particion ya esta montada\n");
                        }
                    }
                }else{
                    if (Exparticion && NparticionE != -1){
                        //cout<<NparticionE<<endl;
                        ext Extendida;
                        bool comprobar = false;
                        //cout<<master.particiones[NparticionE].p_comienzo<<endl;
                        fseek(archivo, master.particiones[NparticionE].p_comienzo, SEEK_SET);
                        fread(&Extendida, sizeof(ext), 1, archivo);
                        while ((ftell(archivo)<master.particiones[NparticionE].p_tam + master.particiones[NparticionE].p_comienzo)) {

                            if(strcmp(Extendida.e_nombre, (montar->nombre).c_str())==0){
                               comprobar = true;
                               break;
                           }
                           if(Extendida.e_siguiente == -1){
                                break;
                            }
                            fseek(archivo, Extendida.e_siguiente, SEEK_SET);
                            fread(&Extendida, sizeof(ext), 1 , archivo);
                        }
                        int index = Extendida.e_comienzo;
                        if(comprobar){
                            Extendida.e_estado = '2';
                            fseek(archivo, index, SEEK_SET);
                            fwrite(&Extendida, sizeof(ext), 1, archivo);

                            if(ListaM->primero == nullptr ){
                                nodoMount *nuevo = new nodoMount("631a", montar->ruta, montar->nombre, 1, 'a');
                                ListaM->primero = nuevo;
                                mostrarList(ListaM);
                            }else{
                                nodoMount *nuevo = ListaM->primero;
                                while(nuevo->sig != nullptr){
                                    nuevo = nuevo->sig;
                                }

                                int letra = buscarLetra(ListaM,montar->nombre, montar->ruta);
                                if (letra != -1){
                                    int num = buscarNumero(ListaM,montar->nombre, montar->ruta);
                                    char letraC = static_cast<char>(letra);
                                    string id = "63" + to_string(num)+ letraC;
                                    nodoMount *aux1 = new nodoMount(id, montar->ruta, montar->nombre, num, letraC);
                                    nuevo->sig = aux1;
                                    mostrarList(ListaM);
                                }else{
                                    printf("La particion ya esta montada\n");
                                }
                            }

                        }else{
                            printf("Error no se encontro el disco\n");
                        }
                    }else{
                        printf("Error no se encontro el disco\n");
                    }

                }
                fclose(archivo);
            }else{
                printf("Error no se encontro el disco\n");
            }
        }else{
            printf("Error no se ingreso el parametro ruta\n");
        }
    }else{
        printf("Error no se ingreso el parametro name\n");
    }

}

