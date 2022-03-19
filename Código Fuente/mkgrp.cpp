#include "mkgrp.h"

#include "login.cpp"
#include "login.h"
#include "estructura.h"
#include "nodomount.h"
#include <vector>

mkgrp::mkgrp()
{

}

bool existeGrupo(string nombreGrp, string ruta){
    listaGrupo.clear();
    FILE *archivo = fopen(ruta.c_str(), "rb+");
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
    for (int i = 0; i < listaGrupo.size(); i++) {
        if (listaGrupo[i] == nombreGrp){
            return true;
        }
    }
    return false;
}

bool existeUsuario(string nombreUsr, string path){
    listaUsaurio.clear();
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
                tok2 = strtok_r(nullptr, ",", &final2);
                tok2 = strtok_r(nullptr, ",", &final2);
                listaUsaurio.push_back(tok2);
            }
        }
        tok = strtok_r(nullptr, "\n", &final1);
    }
    for (int i = 0; i < listaUsaurio.size(); i++) {
        if (listaUsaurio[i] == nombreUsr){
            return true;
        }
    }
    return false;
}

void agregarTXT(string txt){
    SuperBloque super;
    TablaInodo inodo;
    BloqueArchivo blockfile;
    FILE *archivo = fopen((inicio.ruta).c_str(),"rb+");
    fseek(archivo, inicio.start_super, SEEK_SET);
    fread(&super, sizeof(SuperBloque), 1, archivo);
    fseek(archivo, super.s_inodo_init+int(sizeof(TablaInodo)), SEEK_SET);
    fread(&inodo, sizeof(TablaInodo), 1, archivo);
    int index = 0;
    for (int i = 0; i < 12; i++) {
        if(inodo.i_bloque[i] != -1){
            index = inodo.i_bloque[i];
        }
    }
    fseek(archivo, super.s_bloque_init+(64*index), SEEK_SET);
    fread(&blockfile, 64, 1, archivo);
    int sizelibre = 63 - int(strlen(blockfile.b_archivo));
    if(txt.length()<= sizelibre){
        strcat(blockfile.b_archivo, txt.c_str());
        fseek(archivo, super.s_bloque_init+(64*index), SEEK_SET);
        fwrite(&blockfile, 64,1,archivo);

        fseek(archivo, super.s_inodo_init+int(sizeof(TablaInodo)), SEEK_SET);
        fread(&inodo, sizeof(TablaInodo), 1, archivo);
        inodo.i_size = inodo.i_size + txt.length();
        inodo.i_mtime = time(nullptr);
        fseek(archivo, super.s_inodo_init+int(sizeof(TablaInodo)),SEEK_SET);
        fwrite(&inodo, sizeof(TablaInodo), 1, archivo);
    }else{
        string libreTxt;
        string otroTxt;
        int contador=0;
        for (int i = 0; i < sizelibre; i++) {
            libreTxt += txt.at(contador);
            contador++;
        }
        for (; contador < txt.length(); contador++) {
            otroTxt += txt.at(contador);
        }

        strcat(blockfile.b_archivo, libreTxt.c_str());
        fseek(archivo, super.s_bloque_init+(64*index), SEEK_SET);
        fwrite(&blockfile, 64,1,archivo);
        BloqueArchivo blockfile2;
        strcpy(blockfile2.b_archivo, otroTxt.c_str());
        fseek(archivo,inicio.start_super, SEEK_SET);
        fread(&super, sizeof(SuperBloque), 1, archivo);
        char temp = '0';
        int searchBit = -1;
        for (int i = 0; i < super.s_bloque_cont; ++i) {
            fseek(archivo, super.s_bm_bloque_init+i, SEEK_SET);
            temp = char(fgetc(archivo));
            if(temp=='0'){
                searchBit = i;
                break;
            }
        }

        fseek(archivo, super.s_bm_bloque_init+searchBit,SEEK_SET);
        fputc('2',archivo);
        fseek(archivo, super.s_bloque_init + 64*searchBit, SEEK_SET);
        fwrite(&blockfile2, 64, 1, archivo);

        fseek(archivo, super.s_inodo_init+int(sizeof(TablaInodo)), SEEK_SET);
        fread(&inodo, sizeof(TablaInodo), 1, archivo);
        inodo.i_size = inodo.i_size + txt.length();
        inodo.i_bloque[index]=searchBit;
        //cout<<index<<endl;
        inodo.i_mtime = time(nullptr);
        fseek(archivo, super.s_inodo_init+int(sizeof(TablaInodo)),SEEK_SET);
        fwrite(&inodo, sizeof(TablaInodo), 1, archivo);

        super.s_first_block = super.s_first_block + 1;
        super.s_free_blocks_count = super.s_free_blocks_count -1;
        fseek(archivo, inicio.start_super, SEEK_SET);
        fwrite(&super, sizeof(SuperBloque), 1, archivo);
    }
    fclose(archivo);
}

void mkgrp::crearGrupo(mkgrp *grupo){
    char ca = (grupo->nombre).back();
    if(ca == '"'){
        string aux;
        for (int i = 0; i < (grupo->nombre).size(); i++) {
            if((grupo->nombre)[i]!='"'){
                aux += (grupo->nombre)[i];
            }
        }
        grupo->nombre = aux;
    }
    if(comprobarLogin){
        if (inicio.grupo=="root"&& inicio.id_user == 1){
            if(!(existeGrupo(grupo->nombre, inicio.ruta))){

                FILE *archivo = fopen(inicio.ruta.c_str(), "rb+");
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
                }\
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
                        if(strcmp(tipo,"G")==0){
                            aux = atoi(id);
                        }
                    }
                    tok = strtok_r(nullptr, "\n", &final1);
                }
                int NumGrupo = ++aux;
                string txtGrupo = to_string(NumGrupo)+",G,"+grupo->nombre+"\n";
                agregarTXT(txtGrupo);
                printf("Se creo correctamente el grupo\n");

            }else{
                printf("Error el grupo ya existe\n");
            }
        }else{
            printf("Error no eres usuario root\n");
        }
    }else{
        printf("Error no hay usuario logeado\n");
    }
}


void mkgrp::eliminarGrupo(mkgrp *grupo){
    char ca = (grupo->nombre).back();
    if(ca == '"'){
        string aux;
        for (int i = 0; i < (grupo->nombre).size(); i++) {
            if((grupo->nombre)[i]!='"'){
                aux += (grupo->nombre)[i];
            }
        }
        grupo->nombre= aux;
    }
    if(comprobarLogin){
        if (inicio.grupo=="root"&& inicio.id_user == 1){
            InicioSession user = inicio;
            if((existeGrupo(grupo->nombre, user.ruta))){
                FILE *archivo = fopen((user.ruta).c_str(), "rb+");
                SuperBloque super;
                TablaInodo inodo;
                fseek(archivo, inicio.start_super, SEEK_SET);
                fread(&super, sizeof(SuperBloque), 1, archivo);
                fseek(archivo, super.s_inodo_init+int(sizeof(TablaInodo)), SEEK_SET);
                fread(&inodo, sizeof(TablaInodo), 1, archivo);
                BloqueArchivo blockfile;
                char now;
                int cont=1;
                int pos=0;
                int blocknumber = 0;
                char tipo;
                string cadena;
                bool comprobar = false;
                for (int i = 0; i < 12; i++) {
                    if(inodo.i_bloque[i]!=-1){
                        fseek(archivo, super.s_bloque_init+64*inodo.i_bloque[i], SEEK_SET);
                        fread(&blockfile, 64, 1, archivo);
                        for (int x = 0; x < 63; x++) {
                            now = blockfile.b_archivo[x];
                            if (now == '\n'){
                                if(tipo == 'G'){
                                    if(strcmp(cadena.c_str(), (grupo->nombre).c_str())==0){
                                        comprobar = true;
                                        fseek(archivo, super.s_bloque_init+64*blocknumber,SEEK_SET);
                                        fread(&blockfile, 64, 1, archivo);
                                        blockfile.b_archivo[pos] = '0';
                                        fseek(archivo, super.s_bloque_init+64*blocknumber,SEEK_SET);
                                        fwrite(&blockfile, 64, 1, archivo);
                                        printf("Se elimino correctamente el grupo\n");
                                        break;
                                    }
                                }
                                cont =1;
                                cadena = "";
                            }else if (now != ','){
                                cadena += now;
                                cont++;
                            }else if (now == ','){
                                if (cont == 2){
                                    pos = x-1;
                                    blocknumber = inodo.i_bloque[i];
                                }else if (cont == 4){
                                    tipo = cadena[0];
                                }
                                cont++;
                                cadena="";
                            }
                        }
                        if (comprobar){
                            break;
                        }
                    }
                }
                fclose(archivo);
            }else{
                printf("Error el grupo no existe\n");
            }
        }else{
            printf("Error no eres usuario root\n");
        }
    }else{
        printf("Error no hay usuario logeado\n");
    }
}
