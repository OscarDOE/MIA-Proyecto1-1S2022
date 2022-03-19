#include "login.h"

#include "estructura.h"
#include "mkfs.cpp"
#include "nodomount.h"
#include <vector>

login::login()
{

}

InicioSession inicio;
bool comprobarLogin = false;
vector <string> listaGrupo(30);
vector <string> listaUsaurio(60);



int NumeroIdUsuario(string path){
    FILE *archivo = fopen(path.c_str(), "rb+");
    SuperBloque super;
    TablaInodo inodo;
    char usuarios[400] = "\0";
    fseek(archivo, inicio.start_super, SEEK_SET);
    fread(&super, sizeof(SuperBloque), 1, archivo);
    fseek(archivo, super.s_inodo_init+int(sizeof(TablaInodo)), SEEK_SET);
    fread(&inodo, sizeof(TablaInodo), 1, archivo);

    for (int i = 0; i < 15; i++) {
        if(inodo.i_bloque[i]!=-1){
            BloqueArchivo blockfile;
            fseek(archivo, super.s_bloque_init, SEEK_SET);
            for (int x = 0; x <= inodo.i_bloque[i]; x++) {
                fread(&blockfile, 64, 1, archivo);

            }
            strcat(usuarios, blockfile.b_archivo);
        }
    }
    fclose(archivo);

    char *final1;
    char *tok = strtok_r(usuarios,"\n", &final1);
    int aux = 0;
    while(tok != nullptr){
        char id[2];
        char tipo[2];
        char *final2;
        char *tok2 = strtok_r(tok, ",", &final2);
        strcpy(id, tok2);
        if (strcmp(id,"0")!=0){
            tok2 = strtok_r(nullptr, ",", &final2);
            strcpy(tipo, tok2);
            if(strcmp(tipo,"U")==0){
                aux++;
            }

        }
        tok = strtok_r(nullptr, "\n", &final1);
    }
    return ++aux;
}

int Logeando(string user, string pwd, string ruta){
    FILE *archivo = fopen(ruta.c_str(), "rb+");
    SuperBloque super;
    TablaInodo inodo;
    char usuarios[400] = "\0";
    fseek(archivo, inicio.start_super, SEEK_SET);
    fread(&super, sizeof(SuperBloque), 1, archivo);
    fseek(archivo, super.s_inodo_init+int(sizeof(TablaInodo)), SEEK_SET);
    fread(&inodo, sizeof(TablaInodo), 1, archivo);
    BloqueArchivo blockfile;
    fseek(archivo, (super.s_bloque_init+64), SEEK_SET);
    fread(&blockfile, sizeof(BloqueArchivo), 1, archivo);
    strcat(usuarios, blockfile.b_archivo);
    fclose(archivo);
    char *final1;
    char *tok = strtok_r(usuarios,"\n", &final1);
    while(tok != nullptr){
        char id[2];
        char tipo[2];
        char grupo[16];
        char usuarios[16];
        char pass[12];
        char *final2;
        char *tok2 = strtok_r(tok, ",", &final2);
        strcpy(id, tok2);
        if (strcmp(id,"0")!=0){
            tok2 = strtok_r(nullptr, ",", &final2);
            strcpy(tipo, tok2);
            if(strcmp(tipo,"U")==0){
                tok2 = strtok_r(nullptr, ",", &final2);
                strcpy(grupo,tok2);
                tok2 = strtok_r(nullptr, ",", &final2);
                strcpy(usuarios, tok2);
                if(strcmp(usuarios, user.c_str())==0){
                    tok2 = strtok_r(nullptr, ",", &final2);
                    strcpy(pass, tok2);
                    if(strcmp(pass,pwd.c_str())==0){
                        inicio.id_user = atoi(id);
                        inicio.ruta = ruta;
                        inicio.grupo = grupo;
                        return 1;
                    }else{
                        return 2;
                    }
                }
            }
        }
        tok = strtok_r(nullptr, "\n", &final1);
    }
    return -1;
}

void login::Logout(){
    if (comprobarLogin){
        inicio.id_user = 0;
        inicio.ruta = "";
        inicio.start_super = 0;
        comprobarLogin = false;
        printf("Cerrando seccion de usuario\n");
    }else{
        printf("Error no hay usuario logeado\n");
    }
}

void login::Login(login *usuario){
    nodoMount *aux = ListaM->primero;
    bool comprobar =false;
    if (aux->id == usuario->id){
        comprobar = true;
    }else{
        while (aux != nullptr){
            if (aux->id == usuario->id){
                comprobar = true;
                break;
            }
            aux = aux->sig;
        }
    }

    if (!comprobarLogin){
        if(comprobar){
            FILE *archivo;
            if (archivo=fopen((aux->ruta).c_str(), "rb+")){
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
                    SuperBloque super;
                    TablaInodo inodo;
                    fseek(archivo, master.particiones[NParticion].p_comienzo, SEEK_SET);
                    fread(&super, sizeof(SuperBloque), 1, archivo);
                    fseek(archivo, (super.s_inodo_init+int(sizeof(TablaInodo))), SEEK_SET);
                    fread(&inodo, sizeof(TablaInodo), 1, archivo);
                    fseek(archivo, (super.s_inodo_init+int(sizeof(TablaInodo))), SEEK_SET);
                    inodo.i_atime = time(nullptr);
                    fwrite(&inodo, sizeof(TablaInodo), 1, archivo);
                    fclose(archivo);
                    inicio.start_super = master.particiones[NParticion].p_comienzo;
                    int resultado = Logeando(usuario->user,usuario->pwd,aux->ruta);
                    listaGrupo.clear();
                    FILE *archivo = fopen(aux->ruta.c_str(), "rb+");
                    SuperBloque superaux;
                    TablaInodo inodoaux;
                    char usuarios[400] = "\0";
                    fseek(archivo, inicio.start_super, SEEK_SET);
                    fread(&superaux, sizeof(SuperBloque), 1, archivo);
                    fseek(archivo, superaux.s_inodo_init+int(sizeof(TablaInodo)), SEEK_SET);
                    fread(&inodoaux, sizeof(TablaInodo), 1, archivo);
                    for (int i = 0; i < 15; i++) {
                        if(inodoaux.i_bloque[i]!=-1){
                            BloqueArchivo blockfile;
                            fseek(archivo, superaux.s_bloque_init, SEEK_SET);
                            for (int x = 0; x <= inodoaux.i_bloque[i]; x++) {
                                fread(&blockfile, 64, 1, archivo);

                            }
                            strcat(usuarios, blockfile.b_archivo);
                        }
                    }
                    fclose(archivo);
                    char *final1;
                    char *tok = strtok_r(usuarios,"\n", &final1);

                    while(tok != nullptr){
                        char id[2];
                        char tipo[2];
                        char *final2;
                        char *tok2 = strtok_r(tok, ",", &final2);
                        strcpy(id, tok2);
                        if (strcmp(id,"0")!=0){
                            tok2 = strtok_r(nullptr, ",", &final2);
                            strcpy(tipo, tok2);
                            if(strcmp(tipo,"G")==0){
                                tok2 = strtok_r(nullptr, ",", &final2);
                                listaGrupo.push_back(tok2);
                            }
                        }
                        tok = strtok_r(nullptr, "\n", &final1);
                    }
                    if(resultado == 1){
                        comprobarLogin = true;
                        printf("Usuario logeado correctamente\n");
                    }else if (resultado ==2){
                        printf("Error pwd incorrecto\n");
                    }else if (resultado == -1){
                        printf("Error no se encontro el usuario\n");
                    }
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
                            SuperBloque super;
                            TablaInodo inodo;
                            fseek(archivo, Extendida.e_comienzo, SEEK_SET);
                            fread(&super, sizeof(SuperBloque), 1, archivo);
                            fseek(archivo, (super.s_inodo_init+int(sizeof(TablaInodo))), SEEK_SET);
                            fread(&inodo, sizeof(TablaInodo), 1, archivo);
                            fseek(archivo, (super.s_inodo_init+int(sizeof(TablaInodo))), SEEK_SET);
                            inodo.i_atime = time(nullptr);
                            fwrite(&inodo, sizeof(TablaInodo), 1, archivo);
                            fclose(archivo);
                            inicio.start_super = Extendida.e_comienzo;
                            int resultado = Logeando(usuario->user,usuario->pwd,aux->ruta);
                            listaGrupo.clear();
                            FILE *archivo = fopen(aux->ruta.c_str(), "rb+");
                            SuperBloque superaux;
                            TablaInodo inodoaux;
                            char usuarios[400] = "\0";
                            fseek(archivo, inicio.start_super, SEEK_SET);
                            fread(&superaux, sizeof(SuperBloque), 1, archivo);
                            fseek(archivo, superaux.s_inodo_init+int(sizeof(TablaInodo)), SEEK_SET);
                            fread(&inodoaux, sizeof(TablaInodo), 1, archivo);
                            for (int i = 0; i < 15; i++) {
                                if(inodoaux.i_bloque[i]!=-1){
                                    BloqueArchivo blockfile;
                                    fseek(archivo, superaux.s_bloque_init, SEEK_SET);
                                    for (int x = 0; x <= inodoaux.i_bloque[i]; x++) {
                                        fread(&blockfile, 64, 1, archivo);

                                    }
                                    strcat(usuarios, blockfile.b_archivo);
                                }
                            }
                            fclose(archivo);
                            char *final1;
                            char *tok = strtok_r(usuarios,"\n", &final1);

                            while(tok != nullptr){
                                char id[2];
                                char tipo[2];
                                char *final2;
                                char *tok2 = strtok_r(tok, ",", &final2);
                                strcpy(id, tok2);
                                if (strcmp(id,"0")!=0){
                                    tok2 = strtok_r(nullptr, ",", &final2);
                                    strcpy(tipo, tok2);
                                    if(strcmp(tipo,"G")==0){
                                        tok2 = strtok_r(nullptr, ",", &final2);
                                        listaGrupo.push_back(tok2);
                                    }
                                }
                                tok = strtok_r(nullptr, "\n", &final1);
                            }
                            if(resultado == 1){
                                printf("Usuario logeado correctamente\n");
                            }else if (resultado ==2){
                                printf("Error pwd incorrecto\n");
                            }else if (resultado == -1){
                                printf("Error no se encontro el usuario\n");
                            }
                        }else{
                            printf("Error no se encontro el disco\n");
                        }
                    }else{
                        printf("Error no se encontro el disco\n");
                    }
                }
            }else{
                printf("Error no se encontro el disco\n");
            }
        }else{
            printf("Error no se encontro el mismo id montada\n");
        }
    }else{
        printf("Error ya hay un usuario logeado\n");
    }

}
