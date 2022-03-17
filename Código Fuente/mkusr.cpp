#include "mkusr.h"

#include "mkgrp.cpp"

mkusr::mkusr()
{

}


void mkusr::crearUsuario(mkusr *usuario){
    if(comprobarLogin){
        if((usuario->grp).length() <= 10){
            if((usuario->pwd).length() <= 10){
                if((usuario->usr).length() <= 10){
                    if (inicio.grupo=="root"&& inicio.id_user == 1){
                        if(existeGrupo(usuario->grp,inicio.ruta)){
                            int NumUsuario =  NumeroIdUsuario(inicio.ruta);
                            string txtUsuario = to_string(NumUsuario)+",U,"+usuario->grp+","+usuario->usr+","+usuario->pwd+"\n";
                            agregarTXT(txtUsuario);
                            printf("Se creo exitosamente el usuario\n");
                        }else{
                            printf("Error no hay un grupo con ese nombre\n");
                        }
                    }else{
                        printf("Error no eres usuario root\n");
                    }
                }else{
                    printf("Error el parametro usr tiene mas de 10 caracteres\n");
                }
            }else{
                printf("Error el parametro pwd tiene mas de 10 caracteres\n");
            }
        }else{
            printf("Error el parametro grp tiene mas de 10 caracteres\n");
        }

    }else{
        printf("Error no hay usuario logeado");
    }
}

void mkusr::eliminarUsuario(mkusr *usuario){
    if (comprobarLogin){
        if (inicio.grupo=="root"&& inicio.id_user == 1){
            if(existeUsuario(usuario->usr, inicio.ruta)){
                FILE *archivo = fopen((inicio.ruta).c_str(), "rb+");
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
                string user;
                bool comprobar = false;
                bool sig1 = false;
                bool sig2 = false;
                for (int i = 0; i < 12; i++) {
                    if(inodo.i_bloque[i]!=-1){
                        fseek(archivo, super.s_bloque_init+64*inodo.i_bloque[i], SEEK_SET);
                        fread(&blockfile, 64, 1, archivo);
                        for (int x = 0; x < 63; x++) {
                            now = blockfile.b_archivo[x];
                            if (now == '\n'){
                                if(tipo == 'U'){
                                    if(strcmp(user.c_str(), (usuario->usr).c_str())==0){
                                        comprobar = true;
                                        fseek(archivo, super.s_bloque_init+64*blocknumber,SEEK_SET);
                                        fread(&blockfile, 64, 1, archivo);
                                        blockfile.b_archivo[pos] = '0';
                                        fseek(archivo, super.s_bloque_init+64*blocknumber,SEEK_SET);
                                        fwrite(&blockfile, 64, 1, archivo);
                                        printf("Se elimino correctamente el usuario\n");
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
                                    sig1 = true;
                                }else if (sig1){
                                    sig2 = true;
                                    sig1 = false;
                                }else if (sig2){
                                    user = cadena;
                                    sig2 = false;
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
                printf("Error no hay un usuario con el mismo nombre en el grupo\n");
            }
        }else{
            printf("Error no eres usuario root\n");
        }
    }else{
        printf("Error no hay usuario logeado");
    }
}
