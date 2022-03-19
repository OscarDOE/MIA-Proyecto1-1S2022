#include "rep.h"

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <QDir>
#include <math.h>
#include <time.h>
#include "estructura.h"
#include "nodomount.h"
#include "umount.cpp"
#include <iomanip>

rep::rep()
{

}
string obtenerFecha(time_t creacion){
    string hora = "";
    struct tm *tm;
    char fecha[100];
    tm = localtime(&creacion);
    strftime(fecha,100,"%d/%m/%y %H:%S",tm);
    hora = fecha;
    return hora;
}

void comprobarRuta(string path){
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
}

string comprobarExtension(string path){
    string Carpeta = path;
    string ext ="";
    while(true){
        char aux = Carpeta.back();
        if (aux=='.'){
            break;
        }

        ext = Carpeta.back() + ext;
        Carpeta = Carpeta.substr(0, Carpeta.size()-1);
    }

    return ext;
}

int contarLogica(string path, int NParticionE){
    int contar = 0;
    FILE *archivo;
    Disco master;
    archivo = fopen(path.c_str(), "rb+");
    fseek(archivo, 0 ,SEEK_SET);
    fread(&master, sizeof(Disco), 1, archivo);
    ext Extendida;
    fseek(archivo, master.particiones[NParticionE].p_comienzo, SEEK_SET);
    fread(&Extendida, sizeof(ext), 1, archivo);
    if(Extendida.e_siguiente != -1){
        while ((ftell(archivo)<master.particiones[NParticionE].p_tam + master.particiones[NParticionE].p_comienzo)) {
            contar++;
            contar++;
            if(Extendida.e_siguiente == -1){
                 break;
            }
            fseek(archivo, Extendida.e_siguiente, SEEK_SET);
            fread(&Extendida, sizeof(ext), 1 , archivo);
        }
    }
    return contar;
}

void crearMBR(string path, string id){
    bool comprobar = false;
    nodoMount *aux = ListaM->primero;
    if (aux->id == id){
        comprobar = true;
    }else{
        while (aux != nullptr){
            if (aux->id == id){
                comprobar = true;
                break;
            }
            aux = aux->sig;
        }
    }
    if(comprobar){
        FILE *archivo;
        Disco master;
        if(archivo = fopen((aux->ruta).c_str(),"rb+")){
            fseek(archivo, 0, SEEK_SET);
            fread(&master, sizeof(Disco), 1, archivo);

            ofstream file;
            comprobarRuta(path);
            file.open("reporte.dot",ios::out);
            if(file.fail()){
                cout<<"Error no se pudo abrir el archivo";
                exit(1);
            }
            file<<"digraph G{\n"<<"node[shape=plaintext]\n"<<"concentrate=true\n"<<"ReporteMBR[label=<\n";
            file<<"<TABLE BORDER=\"0\" CELLBORDER=\"1\" CELLSPACING=\"0\" >\n";
            file<<"<TR>\n"<<"<TD COLSPAN=\"2\" BORDER = \"1\">Nombre</TD>\n"<<"<TD COLSPAN=\"2\" BORDER =\"1\">Valor</TD>\n"<<"</TR>\n";
            file<<"<TR>\n"<<"<TD COLSPAN=\"2\" BORDER = \"1\">mbr_size</TD>\n"<<"<TD COLSPAN=\"2\" BORDER =\"1\">"+to_string(master.d_tam)+"</TD>\n"<<"</TR>\n";

            file<<"<TR>\n"<<"<TD COLSPAN=\"2\" BORDER = \"1\">mbr_fecha_creacion</TD>\n"<<"<TD COLSPAN=\"2\" BORDER =\"1\">"+obtenerFecha(master.creacion)+"</TD>\n"<<"</TR>\n";
            file<<"<TR>\n"<<"<TD COLSPAN=\"2\" BORDER = \"1\">mbr_disk_signature</TD>\n"<<"<TD COLSPAN=\"2\" BORDER =\"1\">"+to_string(master.asignacion)+"</TD>\n"<<"</TR>\n";
            string disk_fit;
            disk_fit = (master.p_tipo);
            file<<"<TR>\n"<<"<TD COLSPAN=\"2\" BORDER = \"1\">Disk_fit</TD>\n"<<"<TD COLSPAN=\"2\" BORDER =\"1\">"+disk_fit+"</TD>\n"<<"</TR>\n";

            int NParticionE = -1;
            for (int i = 0; i < 4; i++) {
                //cout<<master.particiones[i].p_tipo<<endl;
                if(master.particiones[i].p_comienzo != -1){
                    string status="";
                    status = (master.particiones[i].p_estado);
                    string type="";
                    type = (master.particiones[i].p_type);
                    string fit;
                    fit =(master.particiones[i].p_tipo);
                    string name(master.particiones[i].p_nombre);
                    file<<"<TR>\n"<<"<TD COLSPAN=\"2\" BORDER = \"1\">part_status_"+to_string(i+1)+"</TD>\n"<<"<TD COLSPAN=\"2\" BORDER =\"1\">"+status+"</TD>\n"<<"</TR>\n";
                    file<<"<TR>\n"<<"<TD COLSPAN=\"2\" BORDER = \"1\">part_type_"+to_string(i+1)+"</TD>\n"<<"<TD COLSPAN=\"2\" BORDER =\"1\">"+type+"</TD>\n"<<"</TR>\n";
                    file<<"<TR>\n"<<"<TD COLSPAN=\"2\" BORDER = \"1\">part_fit_"+to_string(i+1)+"</TD>\n"<<"<TD COLSPAN=\"2\" BORDER =\"1\">"+fit+"</TD>\n"<<"</TR>\n";
                    file<<"<TR>\n"<<"<TD COLSPAN=\"2\" BORDER = \"1\">part_start_"+to_string(i+1)+"</TD>\n"<<"<TD COLSPAN=\"2\" BORDER =\"1\">"+to_string(master.particiones[i].p_comienzo)+"</TD>\n"<<"</TR>\n";
                    file<<"<TR>\n"<<"<TD COLSPAN=\"2\" BORDER = \"1\">part_size_"+to_string(i+1)+"</TD>\n"<<"<TD COLSPAN=\"2\" BORDER =\"1\">"+to_string(master.particiones[i].p_tam)+"</TD>\n"<<"</TR>\n";
                    file<<"<TR>\n"<<"<TD COLSPAN=\"2\" BORDER = \"1\">part_name_"+to_string(i+1)+"</TD>\n"<<"<TD COLSPAN=\"2\" BORDER =\"1\">"+name+"</TD>\n"<<"</TR>\n";
                }
                if (master.particiones[i].p_type == 'E'){
                    NParticionE = i;
                }
            }
            file<<"</TABLE>>]\n";

            if (NParticionE!= -1){
                ext Extendida;
                fseek(archivo, master.particiones[NParticionE].p_comienzo, SEEK_SET);
                fread(&Extendida, sizeof(ext), 1, archivo);
                int i = 1;
                if (Extendida.e_siguiente != -1){
                    while ((ftell(archivo)<(master.particiones[NParticionE].p_tam + master.particiones[NParticionE].p_comienzo))) {

                        //cout<<Extendida.e_nombre<<endl;


                        int comprobar = Extendida.e_siguiente - (Extendida.e_comienzo+Extendida.e_tam);
                        if (comprobar > 0){
                            string status="";
                            status = (Extendida.e_estado);
                            string fit;
                            fit =(Extendida.e_tipo);
                            string name(Extendida.e_nombre);
                            file<<"ebr_"+to_string(i)+"[label=<\n";
                            file<<"<TABLE BORDER=\"0\" CELLBORDER=\"1\" CELLSPACING=\"0\" >\n";
                            file<<"<TR>\n"<<"<TD COLSPAN=\"2\" BORDER = \"1\">Nombre</TD>\n"<<"<TD COLSPAN=\"2\" BORDER =\"1\">Valor</TD>\n"<<"</TR>\n";
                            file<<"<TR>\n"<<"<TD COLSPAN=\"2\" BORDER = \"1\">part_status_"+to_string(i)+"</TD>\n"<<"<TD COLSPAN=\"2\" BORDER =\"1\">"+status+"</TD>\n"<<"</TR>\n";
                            file<<"<TR>\n"<<"<TD COLSPAN=\"2\" BORDER = \"1\">part_fit_"+to_string(i)+"</TD>\n"<<"<TD COLSPAN=\"2\" BORDER =\"1\">"+fit+"</TD>\n"<<"</TR>\n";
                            file<<"<TR>\n"<<"<TD COLSPAN=\"2\" BORDER = \"1\">part_start_"+to_string(i)+"</TD>\n"<<"<TD COLSPAN=\"2\" BORDER =\"1\">"+to_string(Extendida.e_comienzo)+"</TD>\n"<<"</TR>\n";
                            file<<"<TR>\n"<<"<TD COLSPAN=\"2\" BORDER = \"1\">part_size_"+to_string(i)+"</TD>\n"<<"<TD COLSPAN=\"2\" BORDER =\"1\">"+to_string(Extendida.e_tam)+"</TD>\n"<<"</TR>\n";
                            file<<"<TR>\n"<<"<TD COLSPAN=\"2\" BORDER = \"1\">part_next_"+to_string(i)+"</TD>\n"<<"<TD COLSPAN=\"2\" BORDER =\"1\">"+to_string(Extendida.e_siguiente-comprobar)+"</TD>\n"<<"</TR>\n";
                            file<<"<TR>\n"<<"<TD COLSPAN=\"2\" BORDER = \"1\">part_name_"+to_string(i)+"</TD>\n"<<"<TD COLSPAN=\"2\" BORDER =\"1\">"+name+"</TD>\n"<<"</TR>\n";
                            file<<"</TABLE>>]\n";
                            i++;
                            string fits;
                            fits =(Extendida.e_tipo);
                            file<<"ebr_"+to_string(i)+"[label=<\n";
                            file<<"<TABLE BORDER=\"0\" CELLBORDER=\"1\" CELLSPACING=\"0\" >\n";
                            file<<"<TR>\n"<<"<TD COLSPAN=\"2\" BORDER = \"1\">Nombre</TD>\n"<<"<TD COLSPAN=\"2\" BORDER =\"1\">Valor</TD>\n"<<"</TR>\n";
                            file<<"<TR>\n"<<"<TD COLSPAN=\"2\" BORDER = \"1\">part_status_"+to_string(i)+"</TD>\n"<<"<TD COLSPAN=\"2\" BORDER =\"1\">1</TD>\n"<<"</TR>\n";
                            file<<"<TR>\n"<<"<TD COLSPAN=\"2\" BORDER = \"1\">part_fit_"+to_string(i)+"</TD>\n"<<"<TD COLSPAN=\"2\" BORDER =\"1\">"+fits+"</TD>\n"<<"</TR>\n";
                            file<<"<TR>\n"<<"<TD COLSPAN=\"2\" BORDER = \"1\">part_start_"+to_string(i)+"</TD>\n"<<"<TD COLSPAN=\"2\" BORDER =\"1\">"+to_string(Extendida.e_siguiente-Extendida.e_tam)+"</TD>\n"<<"</TR>\n";
                            file<<"<TR>\n"<<"<TD COLSPAN=\"2\" BORDER = \"1\">part_size_"+to_string(i)+"</TD>\n"<<"<TD COLSPAN=\"2\" BORDER =\"1\">"+to_string(comprobar)+"</TD>\n"<<"</TR>\n";
                            file<<"<TR>\n"<<"<TD COLSPAN=\"2\" BORDER = \"1\">part_next_"+to_string(i)+"</TD>\n"<<"<TD COLSPAN=\"2\" BORDER =\"1\">"+to_string(Extendida.e_siguiente)+"</TD>\n"<<"</TR>\n";
                            file<<"<TR>\n"<<"<TD COLSPAN=\"2\" BORDER = \"1\">part_name_"+to_string(i)+"</TD>\n"<<"<TD COLSPAN=\"2\" BORDER =\"1\"></TD>\n"<<"</TR>\n";
                            file<<"</TABLE>>]\n";

                        }else{
                            string status="";
                            status = (Extendida.e_estado);
                            string fit;
                            fit =(Extendida.e_tipo);
                            string name(Extendida.e_nombre);
                            file<<"ebr_"+to_string(i)+"[label=<\n";
                            file<<"<TABLE BORDER=\"0\" CELLBORDER=\"1\" CELLSPACING=\"0\" >\n";
                            file<<"<TR>\n"<<"<TD COLSPAN=\"2\" BORDER = \"1\">Nombre</TD>\n"<<"<TD COLSPAN=\"2\" BORDER =\"1\">Valor</TD>\n"<<"</TR>\n";
                            file<<"<TR>\n"<<"<TD COLSPAN=\"2\" BORDER = \"1\">part_status_"+to_string(i)+"</TD>\n"<<"<TD COLSPAN=\"2\" BORDER =\"1\">"+status+"</TD>\n"<<"</TR>\n";
                            file<<"<TR>\n"<<"<TD COLSPAN=\"2\" BORDER = \"1\">part_fit_"+to_string(i)+"</TD>\n"<<"<TD COLSPAN=\"2\" BORDER =\"1\">"+fit+"</TD>\n"<<"</TR>\n";
                            file<<"<TR>\n"<<"<TD COLSPAN=\"2\" BORDER = \"1\">part_start_"+to_string(i)+"</TD>\n"<<"<TD COLSPAN=\"2\" BORDER =\"1\">"+to_string(Extendida.e_comienzo)+"</TD>\n"<<"</TR>\n";
                            file<<"<TR>\n"<<"<TD COLSPAN=\"2\" BORDER = \"1\">part_size_"+to_string(i)+"</TD>\n"<<"<TD COLSPAN=\"2\" BORDER =\"1\">"+to_string(Extendida.e_tam)+"</TD>\n"<<"</TR>\n";
                            file<<"<TR>\n"<<"<TD COLSPAN=\"2\" BORDER = \"1\">part_next_"+to_string(i)+"</TD>\n"<<"<TD COLSPAN=\"2\" BORDER =\"1\">"+to_string(Extendida.e_siguiente)+"</TD>\n"<<"</TR>\n";
                            file<<"<TR>\n"<<"<TD COLSPAN=\"2\" BORDER = \"1\">part_name_"+to_string(i)+"</TD>\n"<<"<TD COLSPAN=\"2\" BORDER =\"1\">"+name+"</TD>\n"<<"</TR>\n";
                            file<<"</TABLE>>]\n";
                        }
                        if(Extendida.e_siguiente == -1){
                             break;
                        }
                        i++;
                        fseek(archivo, Extendida.e_siguiente, SEEK_SET);
                        fread(&Extendida, sizeof(ext), 1 , archivo);
                    }
                }

            }
            file<<"}";
            file.close();
            string extension = "dot -T"+comprobarExtension(path)+ " reporte.dot -o "+path;
            system(extension.c_str());
            fclose(archivo);

            if(archivo= fopen(path.c_str(), "rb+")){
                printf("Se creo correctamente el reporte mbr\n");
                fclose(archivo);
            }else{
                printf("Error al crear el reporte mbr\n");
            }

        }else{
            printf("Error no se encontro el disco\n");
        }
    }else{
        printf("Error no se encontro el mismo id montada\n");
    }

}

string DosDecimal(double num){
    string aux = to_string(num);
    char back = aux.back();
    while(back == '0'){
       aux = (aux).substr(0, (aux).size()-1);
       back = aux.back();
    }
    return aux;
}

void crearDISK(string ruta, string id){
    bool comprobar = false;
    nodoMount *aux = ListaM->primero;
    if (aux->id == id){
        comprobar = true;
    }else{
        while (aux != nullptr){
            if (aux->id == id){
                comprobar = true;
                break;
            }
            aux = aux->sig;
        }
    }
    if(comprobar){
        FILE *archivo;
        Disco master;
        if(archivo = fopen((aux->ruta).c_str(), "rb+")){
            fseek(archivo, 0, SEEK_SET);
            fread(&master, sizeof(Disco), 1, archivo);

            ofstream file;
            comprobarRuta(ruta);
            file.open("reporte2.dot",ios::out);
            if(file.fail()){
                cout<<"Error no se pudo abrir el archivo";
                exit(1);
            }
            file<<"digraph G{\n"<<"node[shape=plaintext]\n"<<"concentrate=true\n"<<"ReporteDISK[label=<\n";
            file<<"<TABLE BORDER=\"2\" CELLBORDER=\"1\" CELLSPACING=\"2\" >\n";
            file<<"<TR>\n<TD COLSPAN=\"1\" ROWSPAN = \"2\" BORDER = \"1\">MBR</TD>\n";
            int NParticionE = -1;
            int tamTotal = 0;
            for (int i = 0; i < 4; i++) {
                if (master.particiones[i].p_type == 'P'){
                    tamTotal += master.particiones[i].p_tam;
                    double sizePrimaria = ((master.particiones[i].p_tam)*100)/master.d_tam;
                    file<<"<TD COLSPAN=\"1\" ROWSPAN = \"2\" BORDER = \"1\">PRIMARIA <BR/> "+DosDecimal(sizePrimaria)+"%</TD>\n";
                    if(i!=3){
                        double comprobar = master.particiones[i+1].p_comienzo - (master.particiones[i].p_tam+master.particiones[i].p_comienzo);
                        if (comprobar > 0){
                            double sizeLibre = (comprobar*100)/master.d_tam;
                            file<<"<TD COLSPAN=\"1\" ROWSPAN = \"2\" BORDER = \"1\">LIBRE <BR/> "+DosDecimal(sizeLibre)+"%</TD>\n";
                        }
                    }else{
                        double comprobar = (master.d_tam+sizeof(Disco)) - (master.particiones[i].p_tam+master.particiones[i].p_comienzo);
                        if(comprobar >0){
                            double libre = comprobar;
                            double sizeLibre = (libre*100)/master.d_tam;
                            file<<"<TD COLSPAN=\"1\" ROWSPAN = \"2\" BORDER = \"1\">LIBRE <BR/> "+DosDecimal(sizeLibre)+"%</TD>\n";
                        }
                    }
                }else if (master.particiones[i].p_type == 'E'){
                    tamTotal += master.particiones[i].p_tam;
                     int cont = contarLogica(aux->ruta, i);
                     if (cont == 0){
                         double sizeExtendida = ((master.particiones[i].p_tam)*100)/master.d_tam;
                         file<<"<TD COLSPAN=\"1\" ROWSPAN = \"2\" BORDER = \"1\">EXTENDIDA <BR/> "+DosDecimal(sizeExtendida)+"%</TD>\n";
                     }else{
                        file<<"<TD COLSPAN=\""+to_string(cont+1)+"\" ROWSPAN = \"1\" BORDER = \"1\">EXTENDIDA</TD>\n";
                        NParticionE = i;
                     }
                     if(i!=3){
                         double comprobar = master.particiones[i+1].p_comienzo - (master.particiones[i].p_tam+master.particiones[i].p_comienzo);
                         if (comprobar > 0){
                             double sizeLibre = (comprobar*100)/master.d_tam;
                             file<<"<TD COLSPAN=\"1\" ROWSPAN = \"2\" BORDER = \"1\">LIBRE <BR/> "+DosDecimal(sizeLibre)+"%</TD>\n";
                         }
                     }else{
                         double comprobar = (master.d_tam+sizeof(Disco)) - (master.particiones[i].p_tam+master.particiones[i].p_comienzo);

                         if(comprobar >0){
                             double libre = comprobar;
                             double sizeLibre = (libre*100)/master.d_tam;
                             file<<"<TD COLSPAN=\"1\" ROWSPAN = \"2\" BORDER = \"1\">LIBRE <BR/> "+DosDecimal(sizeLibre)+"%</TD>\n";
                         }
                     }
                }


            }
             file<<"</TR>\n";
            if (NParticionE != -1){
                file<<"<TR>\n";
                ext Extendida;
                int total = master.d_tam;
                int totalEx = master.particiones[NParticionE].p_tam;
                fseek(archivo, master.particiones[NParticionE].p_comienzo, SEEK_SET);
                fread(&Extendida, sizeof(ext), 1, archivo);
                double totalLogic = 0;
                if (Extendida.e_siguiente != -1){
                     while ((ftell(archivo)<master.particiones[NParticionE].p_tam + master.particiones[NParticionE].p_comienzo)) {
                        totalLogic += double(Extendida.e_tam);
                         if(Extendida.e_estado == '1'){
                            double sizeLibre = double(Extendida.e_tam*100)/total;
                            file<<"<TD>LIBRE <BR/> "+DosDecimal(sizeLibre)+"%</TD>\n";
                        }else{
                             file<<"<TD>EBR</TD>\n";
                             double sizeLogica = double(Extendida.e_tam*100)/total;
                             file<<"<TD>LOGICA <BR/> "+DosDecimal(sizeLogica)+"%</TD>\n";
                        }
                        if(Extendida.e_siguiente == -1){
                              break;
                        }
                        double aux = Extendida.e_siguiente - (Extendida.e_comienzo + Extendida.e_tam);
                        if (aux > 0){
                            double sizeLibre = (aux*100)/total;
                            file<<"<TD>LIBRE <BR/> "+DosDecimal(sizeLibre)+"%</TD>\n";
                        }

                        fseek(archivo, Extendida.e_siguiente, SEEK_SET);
                        fread(&Extendida, sizeof(ext), 1 , archivo);
                     }
                 }
                double comprobar = double(totalEx) - totalLogic;
                if(comprobar>0){
                    double sizeLibre = (comprobar*100)/(total);

                    file<<"<TD>LIBRE <BR/>"+DosDecimal(sizeLibre)+"%</TD>\n";
                }
                file<<"</TR>\n";
            }
            file<<"</TABLE>>]\n}";
            file.close();
            string extension = "dot -T"+comprobarExtension(ruta)+ " reporte2.dot -o "+ruta;
            system(extension.c_str());
            fclose(archivo);

            if(archivo= fopen(ruta.c_str(), "rb+")){
                printf("Se creo correctamente el reporte disk\n");
                fclose(archivo);
            }else{
                printf("Error al crear el reporte disk\n");
            }

        }else{
            printf("Error no se encontro el disco\n");
        }
    }else{
        printf("Error no se encontro el mismo id montada\n");
    }
}


void crearINODE(string ruta, string id){
    //cout<<ruta<<endl;
    //cout<<id<<endl;
    bool comprobar =false;
    nodoMount *aux = ListaM->primero;
    if (aux->id == id){
        comprobar = true;
    }else{
        while (aux != nullptr){
            if (aux->id == id){
                comprobar = true;
                break;
            }
            aux = aux->sig;
        }
    }
    if (comprobar){
        FILE *archivo;
        if(archivo =fopen((aux->ruta).c_str(),"rb+")){
            Disco master;
            int NParticion = -1;
            fseek(archivo, 0, SEEK_SET);
            fread(&master, sizeof(Disco), 1, archivo);

            ofstream file;
            comprobarRuta(ruta);
            file.open("reporte3.dot",ios::out);
            if(file.fail()){
                cout<<"Error no se pudo abrir el archivo";
                exit(1);
            }


            for (int i = 0; i < 4; i++) {
                if (strcmp(master.particiones[i].p_nombre, (aux->nombre).c_str())==0){
                    NParticion = i;
                    break;
                }
            }
            if(NParticion != -1){
                file<<"digraph G{\n"<<"node[shape=plaintext]\n"<<"concentrate=true\n"<<"ReporteINODE[label=<\n";
                file<<"<TABLE BORDER=\"2\" CELLBORDER=\"1\" CELLSPACING=\"2\" >\n";
                file<<"<TR>\n"<<"<TD COLSPAN=\"2\" BORDER = \"1\">Index</TD>\n"<<"<TD COLSPAN=\"2\" BORDER =\"1\">Tipo</TD>\n"<<"<TD COLSPAN=\"2\" BORDER =\"1\">Nombre</TD>\n"<<"</TR>\n";

                SuperBloque super;
                BloqueCarpeta block;
                TablaInodo inodo;
                fseek(archivo, master.particiones[NParticion].p_comienzo, SEEK_SET);
                fread(&super, sizeof(TablaInodo), 1, archivo);

                fseek(archivo, super.s_bloque_init, SEEK_SET);
                fread(&block, sizeof(BloqueCarpeta), 1, archivo);
                fseek(archivo, super.s_inodo_init, SEEK_SET);
                fread(&inodo, sizeof(TablaInodo), 1, archivo);
                int n = 0;
                int inodeS = super.s_inodo_init;
                string tipo = "";
                while(block.b_folder[n+1].b_inodo!=-1){
                    //cout<<block.b_content[n].b_inodo<<endl;
                    //cout<<block.b_content[n].b_name<<endl;
                    if (inodo.i_tipo == '0'){
                        tipo = "Carpeta";
                    }else if (inodo.i_tipo== '1'){
                        tipo = "Archivo";
                    }
                    string nombre = "";
                    nombre = block.b_folder[n+1].b_nombre;
                    if (nombre == ".."){
                        nombre = "";
                    }
                    file<<"<TR>\n"<<"<TD COLSPAN=\"2\" BORDER = \"1\">"+to_string(block.b_folder[n+1].b_inodo)+"</TD>\n"<<"<TD COLSPAN=\"2\" BORDER =\"1\">"+tipo+"</TD>\n"<<"<TD COLSPAN=\"2\" BORDER =\"1\">/"+nombre+"</TD>\n"<<"</TR>\n";
                    inodeS += int(sizeof(TablaInodo));
                    fseek(archivo, inodeS, SEEK_SET);
                    fread(&inodo, sizeof(TablaInodo), 1, archivo);
                    n++;
                }
                file<<"</TABLE>>]\n}";
                file.close();

                string extension = "dot -T"+comprobarExtension(ruta)+ " reporte3.dot -o "+ruta;
                system(extension.c_str());
                fclose(archivo);

                if(archivo= fopen(ruta.c_str(), "rb+")){
                    printf("Se creo correctamente el reporte Inode\n");
                    fclose(archivo);
                }else{
                    printf("Error al crear el reporte Inode\n");
                }

            }else{
                printf("Error no se encontro la particion\n");
            }
        }else{
            printf("Error no se encontro el disco\n");
        }
    }else{
        printf("Error no se encontro el mismo id montada\n");
    }
}

void crearBLOCK(string ruta, string id){

    bool comprobar =false;
    nodoMount *aux = ListaM->primero;
    if (aux->id == id){
        comprobar = true;
    }else{
        while (aux != nullptr){
            if (aux->id == id){
                comprobar = true;
                break;
            }
            aux = aux->sig;
        }
    }

    if (comprobar){
        FILE *archivo;
        if(archivo =fopen((aux->ruta).c_str(),"rb+")){
            Disco master;
            int NParticion = -1;
            int NParticionE = -1;
            fseek(archivo, 0, SEEK_SET);
            fread(&master, sizeof(Disco), 1, archivo);

            ofstream file;
            comprobarRuta(ruta);
            file.open("reporte4.dot",ios::out);
            if(file.fail()){
                cout<<"Error no se pudo abrir el archivo";
                exit(1);
            }
            for (int i = 0; i < 4; i++) {
                if (strcmp(master.particiones[i].p_nombre, (aux->nombre).c_str())==0){
                    NParticion = i;
                    break;
                }
                if (master.particiones[i].p_type =='E'){
                    NParticionE = i;
                }
            }
            if(NParticion != -1){
                file<<"digraph G{\n"<<"node[shape=box]\n"<<"concentrate=true\n"<<"rankdir=\"LR\"\n";
                BloqueArchivo blockFile;
                BloqueCarpeta blockCarpet;
                SuperBloque super;
                fseek(archivo, master.particiones[NParticion].p_comienzo, SEEK_SET);
                fread(&super, sizeof(SuperBloque), 1, archivo);


                int contador = 0;
                int aux = super.s_bm_bloque_init;
                char buffer;

                while(aux<super.s_inodo_init){
                    fseek(archivo, super.s_bm_bloque_init+contador, SEEK_SET);
                    buffer = char(fgetc(archivo));
                    aux++;

                    if(buffer== '1'){
                        fseek(archivo, super.s_bloque_init+64*contador, SEEK_SET);
                        fread(&blockCarpet, 64, 1 , archivo);
                        file<< "nodo"+to_string(contador)+"[label=<\n<TABLE BORDER =\"0\">\n";
                        file<<"<TR>\n<TD COLSPAN=\"2\">Bloque Carpeta "+to_string(contador)+"</TD>\n</TR>\n";
                        file<<"<TR>\n<TD>b_name</TD><TD>b_inodo</TD>\n</TR>\n";
                        /*for (int i = 0; i < 4; i++) {
                            file<<
                        }*/
                        int n = 0;
                        while(blockCarpet.b_folder[n].b_inodo != -1){
                            string nombre = "";
                            nombre = blockCarpet.b_folder[n].b_nombre;
                            //cout<<nombre<<endl;
                            file<<"<TR>\n<TD>"+nombre+"</TD><TD>"+to_string(blockCarpet.b_folder[n].b_inodo)+"</TD>\n</TR>\n";
                            n++;
                        }
                        contador++;
                        file<<"</TABLE>>]";
                    }else if(buffer =='2'){
                        fseek(archivo, super.s_bloque_init+64*contador,SEEK_SET);
                        fread(&blockFile, 64, 1, archivo);
                        string contenido ="";
                        contenido = blockFile.b_archivo;
                        file<<"nodo"+to_string(contador)+"[label=\"Bloque Archivo "+to_string(contador)+" \\n "+contenido+"\"]\n";
                        contador++;

                    }

                }

                for (int i = 0; i+1 < contador; i++) {
                    file << "nodo"+to_string(i)+"->nodo"+to_string(i+1)+"\n";
                }
                file<< "}";
                file.close();

                string extension = "dot -T"+comprobarExtension(ruta)+ " reporte4.dot -o "+ruta;
                system(extension.c_str());
                fclose(archivo);

                if(archivo= fopen(ruta.c_str(), "rb+")){
                    printf("Se creo correctamente el reporte block\n");
                    fclose(archivo);
                }else{
                    printf("Error al crear el reporte block\n");
                }

            }else{
                if(NParticionE != -1){
                    ext Extendida;
                    fseek(archivo, master.particiones[NParticionE].p_comienzo, SEEK_SET);
                    fread(&Extendida, sizeof(ext), 1, archivo);
                    bool comprobar2 = false;
                    while ((ftell(archivo)<master.particiones[NParticionE].p_tam + master.particiones[NParticionE].p_comienzo)) {
                        if (strcmp(Extendida.e_nombre, (aux->nombre).c_str())==0){
                            comprobar2 = true;
                            break;
                        }
                        if(Extendida.e_siguiente == -1){
                            break;
                        }
                        fseek(archivo, Extendida.e_siguiente, SEEK_SET);
                        fread(&Extendida, sizeof(ext), 1 , archivo);
                    }
                    if (comprobar2){
                        file<<"digraph G{\n"<<"node[shape=box]\n"<<"concentrate=true\n"<<"rankdir=\"LR\"\n";
                        BloqueArchivo blockFile;
                        BloqueCarpeta blockCarpet;
                        SuperBloque super;
                        fseek(archivo, Extendida.e_comienzo, SEEK_SET);
                        fread(&super, sizeof(SuperBloque), 1, archivo);


                        int contador = 0;
                        int aux = super.s_bm_bloque_init;
                        char buffer;

                        while(aux<super.s_inodo_init){
                            fseek(archivo, super.s_bm_bloque_init+contador, SEEK_SET);
                            buffer = char(fgetc(archivo));
                            aux++;

                            if(buffer== '1'){
                                fseek(archivo, super.s_bloque_init+64*contador, SEEK_SET);
                                fread(&blockCarpet, 64, 1 , archivo);
                                file<< "nodo"+to_string(contador)+"[label=<\n<TABLE BORDER =\"0\">\n";
                                file<<"<TR>\n<TD COLSPAN=\"2\">Bloque Carpeta "+to_string(contador)+"</TD>\n</TR>\n";
                                file<<"<TR>\n<TD>b_name</TD><TD>b_inodo</TD>\n</TR>\n";
                                int n = 0;
                                while(blockCarpet.b_folder[n].b_inodo != -1){
                                    string nombre = "";
                                    nombre = blockCarpet.b_folder[n].b_nombre;
                                    //cout<<nombre<<endl;
                                    file<<"<TR>\n<TD>"+nombre+"</TD><TD>"+to_string(blockCarpet.b_folder[n].b_inodo)+"</TD>\n</TR>\n";
                                    n++;
                                }
                                contador++;
                                file<<"</TABLE>>]";
                            }else if(buffer =='2'){
                                fseek(archivo, super.s_bloque_init+64*contador,SEEK_SET);
                                fread(&blockFile, 64, 1, archivo);
                                string contenido ="";
                                contenido = blockFile.b_archivo;
                                file<<"nodo"+to_string(contador)+"[label=\"Bloque Archivo "+to_string(contador)+" \\n "+contenido+"\"]\n";
                                contador++;

                            }

                        }

                        for (int i = 0; i+1 < contador; i++) {
                            file << "nodo"+to_string(i)+"->nodo"+to_string(i+1)+"\n";
                        }
                        file<< "}";
                        file.close();

                        string extension = "dot -T"+comprobarExtension(ruta)+ " reporte4.dot -o "+ruta;
                        system(extension.c_str());
                        fclose(archivo);

                        if(archivo= fopen(ruta.c_str(), "rb+")){
                            printf("Se creo correctamente el reporte block\n");
                            fclose(archivo);
                        }else{
                            printf("Error al crear el reporte block\n");
                        }
                    }else{
                        printf("Error no se encontro la particion\n");
                    }

                }else{
                    printf("Error no se encontro la particion\n");
                }
            }
       }else{
            printf("Error no se encontro el disco\n");
        }
    }else{
        printf("Error no se encontro el mismo id montada\n");
    }
}

void crearSB(string ruta, string id){
    bool comprobar =false;
    nodoMount *aux = ListaM->primero;
    if (aux->id == id){
        comprobar = true;
    }else{
        while (aux != nullptr){
            if (aux->id == id){
                comprobar = true;
                break;
            }
            aux = aux->sig;
        }
    }
    if(comprobar){
        FILE *archivo;
        if(archivo =fopen((aux->ruta).c_str(),"rb+")){
            Disco master;
            int NParticion = -1;
            int NParticionE = -1;
            fseek(archivo, 0, SEEK_SET);
            fread(&master, sizeof(Disco), 1, archivo);

            ofstream file;
            comprobarRuta(ruta);
            file.open("reporte5.dot",ios::out);
            if(file.fail()){
                cout<<"Error no se pudo abrir el archivo";
                exit(1);
            }
            for (int i = 0; i < 4; i++) {
                if (strcmp(master.particiones[i].p_nombre, (aux->nombre).c_str())==0){
                    NParticion = i;
                    break;
                }
                if (master.particiones[i].p_type == 'E'){
                    NParticionE = i;
                }
            }
            if(NParticion!=-1){
                file<<"digraph G{\n"<<"node[shape=box]\n"<<"concentrate=true\n";
                file<<"ReporteSB[label=<<TABLE BORDER=\"2\" CELLBORDER=\"1\" CELLSPACING=\"1\">\n";
                file<<"<TR>\n<TD>NOMBRE</TD>\n<TD>VALOR</TD>\n</TR>";
                SuperBloque super;
                fseek(archivo, master.particiones[NParticion].p_comienzo, SEEK_SET);
                fread(&super, sizeof(super), 1, archivo);
                file<<"<TR>\n<TD>s_inodes_count</TD>\n<TD>"+to_string(super.s_inodos_cont)+"</TD>\n</TR>";
                file<<"<TR>\n<TD>s_blocks_count</TD>\n<TD>"+to_string(super.s_bloque_cont)+"</TD>\n</TR>";
                file<<"<TR>\n<TD>s_free_blocks_count</TD>\n<TD>"+to_string(super.s_free_blocks_count)+"</TD>\n</TR>";
                file<<"<TR>\n<TD>s_free_inodes_count</TD>\n<TD>"+to_string(super.s_free_inodes_count)+"</TD>\n</TR>";
                file<<"<TR>\n<TD>s_mtime</TD>\n<TD>"+obtenerFecha(super.s_mtime)+"</TD>\n</TR>";
                file<<"<TR>\n<TD>s_umtime</TD>\n<TD>"+obtenerFecha(super.s_unmtime)+"</TD>\n</TR>";
                file<<"<TR>\n<TD>s_mnt_count</TD>\n<TD>"+to_string(super.s_bloque_cont)+"</TD>\n</TR>";
                file<<"<TR>\n<TD>s_magic</TD>\n<TD>"+to_string(super.s_magic)+"</TD>\n</TR>";
                file<<"<TR>\n<TD>s_inode_size</TD>\n<TD>"+to_string(super.s_inode_size)+"</TD>\n</TR>";
                file<<"<TR>\n<TD>s_block_size</TD>\n<TD>"+to_string(super.s_block_size)+"</TD>\n</TR>";
                file<<"<TR>\n<TD>s_first_ino</TD>\n<TD>"+to_string(super.s_first_inode)+"</TD>\n</TR>";
                file<<"<TR>\n<TD>s_first_blo</TD>\n<TD>"+to_string(super.s_first_block)+"</TD>\n</TR>";
                file<<"<TR>\n<TD>s_bm_inode_start</TD>\n<TD>"+to_string(super.s_bm_inodo_init)+"</TD>\n</TR>";
                file<<"<TR>\n<TD>s_bm_block_start</TD>\n<TD>"+to_string(super.s_bm_bloque_init)+"</TD>\n</TR>";
                file<<"<TR>\n<TD>s_inode_start</TD>\n<TD>"+to_string(super.s_inodo_init)+"</TD>\n</TR>";
                file<<"<TR>\n<TD>s_block_start</TD>\n<TD>"+to_string(super.s_bloque_init)+"</TD>\n</TR>";
                file<<"</TABLE>>]\n}";
                file.close();
                string extension = "dot -T"+comprobarExtension(ruta)+ " reporte5.dot -o "+ruta;
                system(extension.c_str());
                fclose(archivo);

                if(archivo= fopen(ruta.c_str(), "rb+")){
                    printf("Se creo correctamente el reporte sb\n");
                    fclose(archivo);
                }else{
                    printf("Error al crear el reporte sb\n");
                }
            }else{
                if(NParticionE != -1){
                    ext Extendida;
                    fseek(archivo, master.particiones[NParticionE].p_comienzo, SEEK_SET);
                    fread(&Extendida, sizeof(ext), 1, archivo);
                    bool comprobar2 = false;
                    while ((ftell(archivo)<master.particiones[NParticionE].p_tam + master.particiones[NParticionE].p_comienzo)) {
                        if (strcmp(Extendida.e_nombre, (aux->nombre).c_str())==0){
                            comprobar2 = true;
                            break;
                        }
                        if(Extendida.e_siguiente == -1){
                            break;
                        }
                        fseek(archivo, Extendida.e_siguiente, SEEK_SET);
                        fread(&Extendida, sizeof(ext), 1 , archivo);
                    }
                    if (comprobar2){
                        file<<"digraph G{\n"<<"node[shape=box]\n"<<"concentrate=true\n";
                        file<<"ReporteSB[label=<<TABLE BORDER=\"2\" CELLBORDER=\"1\" CELLSPACING=\"1\">\n";
                        file<<"<TR>\n<TD>NOMBRE</TD>\n<TD>VALOR</TD>\n</TR>";
                        SuperBloque super;
                        fseek(archivo, Extendida.e_comienzo, SEEK_SET);
                        fread(&super, sizeof(super), 1, archivo);
                        file<<"<TR>\n<TD>s_inodes_count</TD>\n<TD>"+to_string(super.s_inodos_cont)+"</TD>\n</TR>";
                        file<<"<TR>\n<TD>s_blocks_count</TD>\n<TD>"+to_string(super.s_bloque_cont)+"</TD>\n</TR>";
                        file<<"<TR>\n<TD>s_free_blocks_count</TD>\n<TD>"+to_string(super.s_free_blocks_count)+"</TD>\n</TR>";
                        file<<"<TR>\n<TD>s_free_inodes_count</TD>\n<TD>"+to_string(super.s_free_inodes_count)+"</TD>\n</TR>";
                        file<<"<TR>\n<TD>s_mtime</TD>\n<TD>"+obtenerFecha(super.s_mtime)+"</TD>\n</TR>";
                        file<<"<TR>\n<TD>s_umtime</TD>\n<TD>"+obtenerFecha(super.s_unmtime)+"</TD>\n</TR>";
                        file<<"<TR>\n<TD>s_mnt_count</TD>\n<TD>"+to_string(super.s_bloque_cont)+"</TD>\n</TR>";
                        file<<"<TR>\n<TD>s_magic</TD>\n<TD>"+to_string(super.s_magic)+"</TD>\n</TR>";
                        file<<"<TR>\n<TD>s_inode_size</TD>\n<TD>"+to_string(super.s_inode_size)+"</TD>\n</TR>";
                        file<<"<TR>\n<TD>s_block_size</TD>\n<TD>"+to_string(super.s_block_size)+"</TD>\n</TR>";
                        file<<"<TR>\n<TD>s_first_ino</TD>\n<TD>"+to_string(super.s_first_inode)+"</TD>\n</TR>";
                        file<<"<TR>\n<TD>s_first_blo</TD>\n<TD>"+to_string(super.s_first_block)+"</TD>\n</TR>";
                        file<<"<TR>\n<TD>s_bm_inode_start</TD>\n<TD>"+to_string(super.s_bm_inodo_init)+"</TD>\n</TR>";
                        file<<"<TR>\n<TD>s_bm_block_start</TD>\n<TD>"+to_string(super.s_bm_bloque_init)+"</TD>\n</TR>";
                        file<<"<TR>\n<TD>s_inode_start</TD>\n<TD>"+to_string(super.s_inodo_init)+"</TD>\n</TR>";
                        file<<"<TR>\n<TD>s_block_start</TD>\n<TD>"+to_string(super.s_bloque_init)+"</TD>\n</TR>";
                        file<<"</TABLE>>]\n}";
                        file.close();
                        string extension = "dot -T"+comprobarExtension(ruta)+ " reporte5.dot -o "+ruta;
                        system(extension.c_str());
                        fclose(archivo);

                        if(archivo= fopen(ruta.c_str(), "rb+")){
                            printf("Se creo correctamente el reporte sb\n");
                            fclose(archivo);
                        }else{
                            printf("Error al crear el reporte sb\n");
                        }
                    }else{
                        printf("Error no se encontro el disco\n");
                    }
                }else{
                    printf("Error no se encontro el disco\n");
                }
            }
        }
    }else{
        printf("Error no se encontro el mismo id montada\n");
    }
}

void crearFILE(string ruta, string id){
    bool comprobar =false;
    nodoMount *aux = ListaM->primero;
    if (aux->id == id){
        comprobar = true;
    }else{
        while (aux != nullptr){
            if (aux->id == id){
                comprobar = true;
                break;
            }
            aux = aux->sig;
        }
    }
    if(comprobar){
        FILE *archivo;
        if(archivo =fopen((aux->ruta).c_str(),"rb+")){
            /*Disco master;
            int NParticion = -1;
            int NParticionE = -1;
            fseek(archivo, 0, SEEK_SET);
            fread(&master, sizeof(Disco), 1, archivo);
            for (int i = 0; i < 4; i++) {
                if (strcmp(master.particiones[i].p_nombre, (aux->nombre).c_str())==0){
                    NParticion = i;
                    break;
                }
                if (master.particiones[i].p_type == 'E'){
                    NParticionE = i;
                }
            }
            if(NParticion != -1){*/

        }else{
            printf("Error no se contro el disco\n");
        }
    }else{
        printf("Error no se encontro el mismo id montada\n");
    }
}

void crearTREE(string ruta, string id, string root){
    printf("ARBOL");
    SuperBloque superblock;

    
}

void rep::CrearRep(rep *rep){
    string au = (rep->ruta).substr(0, (rep->ruta).size()-1);
    char ca1 = au.back();
    char ca = (rep->ruta).back();
    if(ca1 == '\''){
        rep->ruta = (rep->ruta).substr(0, (rep->ruta).size()-1);
        rep->ruta = (rep->ruta).substr(0, (rep->ruta).size()-1);
    }else if(ca == '"'){
        string aux;
        for (int i = 0; i < (rep->ruta).size(); i++) {
            if((rep->ruta)[i]!='"'){
                aux += (rep->ruta)[i];
            }
        }
        rep->ruta = aux;

    }else if(ca == ' '){
        rep->ruta = (rep->ruta).substr(0, (rep->ruta).size()-1);
    }
    ca = (rep->nombre).back();
    if(ca == '"'){
        string aux;
        for (int i = 0; i < (rep->nombre).size(); i++) {
            if((rep->nombre)[i]!='"'){
                aux += (rep->nombre)[i];
            }
        }
        rep->nombre = aux;
    }
    ca = (rep->id).back();
    if(ca == '"'){
        string aux;
        for (int i = 0; i < (rep->id).size(); i++) {
            if((rep->id)[i]!='"'){
                aux += (rep->id)[i];
            }
        }
        rep->id = aux;
    }

    if (rep->ruta != ""){
        if(rep->id != ""){
            if (rep->nombre == "MBR"){
                crearMBR(rep->ruta, rep->id);
            }else if (rep->nombre == "DISK"){
                crearDISK(rep->ruta, rep->id);
            }else if (rep->nombre == "INODE"){
                crearINODE(rep->ruta, rep->id);
            }else if (rep->nombre == "JOURNALING"){

            }else if (rep->nombre == "BLOCK"){
                crearBLOCK(rep->ruta, rep->id);
            }else if (rep->nombre == "BM_INODE"){

            }else if (rep->nombre == "BM_BLOCK"){

            }else if (rep->nombre == "TREE"){
                //crearTREE(rep->ruta, rep->id, rep->root);
            }else if (rep->nombre == "SB"){
                crearSB(rep->ruta, rep->id);
            }else if (rep->nombre == "FILE"){
                crearFILE(rep->ruta, rep->id);
            }else if (rep->nombre == "LS"){

            }else{
                printf("Error no se ingreso el parametro name\n");
            }
        }else{
            printf("Error no se ingreso el parametro id\n");
        }
    }else{
        printf("Error no se ingreso el parametro ruta en el reporte\n");
    }

}
