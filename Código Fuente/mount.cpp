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
                        nodoMount *aux3 = ListaM->primero;
                        while(aux3 != nullptr){
                            cout<<aux3->ruta<<"|"<<aux3->nombre<<"|"<<aux3->id<<"\n";
                            aux3 = aux3->sig;
                            //aux = aux->siguiente;
                        }
                    }else{
                        nodoMount *nuevo = ListaM->primero;
                        while(nuevo->sig != nullptr){
                            nuevo = nuevo->sig;
                        }

                        int letra = -1;
                        bool falg = true;
                        int busqueda= 'a';
                        nodoMount *aux = ListaM->primero;
                        while(aux !=nullptr){
                            if((aux->nombre==nombre)&&(aux->ruta==ruta)){
                                letra= -1;
                                falg = false;
                            }else{
                                if(aux->ruta==ruta){
                                    busqueda = (aux->letra)+1;
                                }
                            }
                            aux = aux->sig;
                        }
                        if(falg){
                            letra = busqueda;
                        }

                        if (letra != -1){
                            int num = -1;
                            bool falg2 = true;
                            int busqueda2= 1;
                            nodoMount *aux = ListaM->primero;
                            while(aux !=nullptr){
                                if (aux->ruta == ruta){
                                    num = aux->numero;
                                    falg2 = false;
                                }else if (aux->ruta != ruta && aux->numero == busqueda2){
                                    busqueda2++;
                                }
                                aux=aux->sig;
                            }
                            if(falg2){
                                num = busqueda2;
                            }
                            char letraC = static_cast<char>(letra);
                            string id = "63" + to_string(num)+ letraC;
                            nodoMount *aux1 = new nodoMount(id, montar->ruta, montar->nombre, num, letraC);
                            nuevo->sig = aux1;
                            nodoMount *aux3 = ListaM->primero;
                            while(aux3 != nullptr){
                                cout<<aux3->ruta<<"|"<<aux3->nombre<<"|"<<aux3->id<<"\n";
                                aux3 = aux3->sig;
                                //aux = aux->siguiente;
                            }
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
                                nodoMount *aux3 = ListaM->primero;
                                while(aux3 != nullptr){
                                    cout<<aux3->ruta<<"|"<<aux3->nombre<<"|"<<aux3->id<<"\n";
                                    aux3 = aux3->sig;
                                    //aux = aux->siguiente;
                                }

                            }else{
                                nodoMount *nuevo = ListaM->primero;
                                while(nuevo->sig != nullptr){
                                    nuevo = nuevo->sig;
                                }

                                int letra = -1;
                                bool falg = true;
                                int busqueda= 'a';
                                nodoMount *aux = ListaM->primero;
                                while(aux !=nullptr){
                                    if((aux->nombre==nombre)&&(aux->ruta==ruta)){
                                        letra= -1;
                                        falg = false;
                                    }else{
                                        if(aux->ruta==ruta){
                                            busqueda = (aux->letra)+1;
                                        }
                                    }
                                    aux = aux->sig;
                                }
                                if(falg){
                                    letra = busqueda;
                                }

                                if (letra != -1){
                                    int num = -1;
                                    bool falg2 = true;
                                    int busqueda2= 1;
                                    nodoMount *aux = ListaM->primero;
                                    while(aux !=nullptr){
                                        if (aux->ruta == ruta){
                                            num = aux->numero;
                                            falg2 = false;
                                        }else if (aux->ruta != ruta && aux->numero == busqueda2){
                                            busqueda2++;
                                        }
                                        aux=aux->sig;
                                    }
                                    if(falg2){
                                        num = busqueda2;
                                    }
                                    char letraC = static_cast<char>(letra);
                                    string id = "63" + to_string(num)+ letraC;
                                    nodoMount *aux1 = new nodoMount(id, montar->ruta, montar->nombre, num, letraC);
                                    nuevo->sig = aux1;
                                    nodoMount *aux2 = ListaM->primero;
                                    while(aux2 != nullptr){
                                        cout<<aux2->ruta<<"|"<<aux2->nombre<<"|"<<aux2->id<<"\n";
                                        aux2 = aux2->sig;
                                        //aux = aux->siguiente;
                                    }
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

