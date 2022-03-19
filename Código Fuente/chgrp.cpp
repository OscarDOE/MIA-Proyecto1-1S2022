#include "chgrp.h"

#include "mkusr.cpp"
#include "estructura.h"

chgrp::chgrp()
{

}


void chgrp::cambiarGrupo(chgrp *grupo){
    if(comprobarLogin){
        if (inicio.grupo=="root"&& inicio.id_user == 1){
            if(existeGrupo(grupo->grp, inicio.ruta) && existeUsuario(grupo->usr, inicio.ruta)){
                FILE *archivo = fopen((inicio.ruta).c_str(), "rb+");
                SuperBloque super;
                TablaInodo inodo;
                fseek(archivo, inicio.start_super, SEEK_SET);
                fread(&super, sizeof(SuperBloque), 1, archivo);
                fseek(archivo, super.s_inodo_init+int(sizeof(TablaInodo)), SEEK_SET);
                fread(&inodo, sizeof(TablaInodo), 1, archivo);
                BloqueArchivo blockfile;
                char car;
                int contador=1;
                int pos=0;
                int posf = 0;
                int blocknumber = 0;
                string cadena;
                string user;
                bool comprobar = false;
                bool sig1 = false;
                bool sig2 = false;
                bool sig3 = false;
                for (int i = 0; i < 12; i++) {
                    if(inodo.i_bloque[i]!=-1){
                        fseek(archivo, super.s_bloque_init+64*inodo.i_bloque[i], SEEK_SET);
                        fread(&blockfile, 64, 1, archivo);
                        for (int x = 0; x < 63; x++) {
                            car = blockfile.b_archivo[x];
                            if (car == '\n'){
                                if(user == grupo->usr){
                                    comprobar = true;

                                    fseek(archivo, super.s_bloque_init+64*blocknumber,SEEK_SET);
                                    fread(&blockfile, 64, 1, archivo);
                                    int n = 0;
                                    for (int m = pos; m <= posf; m++) {
                                        if(n<(grupo->grp).length()){
                                            blockfile.b_archivo[m] = (grupo->grp)[n];
                                            n++;
                                        }else{
                                            blockfile.b_archivo[m] = ' ';
                                        }
                                    }
                                    fseek(archivo, super.s_bloque_init+64*blocknumber,SEEK_SET);
                                    fwrite(&blockfile, 64, 1, archivo);
                                    printf("Se cambio correctamente el usuario\n");
                                    break;
                                }
                                contador =1;
                                cadena = "";
                            }else if (car != ','){
                                cadena += car;
                                contador++;
                            }else if (car == ','){
                                if (contador == 2){
                                    blocknumber = inodo.i_bloque[i];
                                }else if (contador == 4){
                                    pos = x-1;
                                    sig1 = true;
                                }else if (sig1){
                                    posf = x-1;
                                    sig1 = false;
                                    sig2 = true;
                                }else if (sig2){
                                    user = cadena;
                                    sig2 =false;
                                    sig3 =true;
                                }
                                contador++;
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
                printf("Error el grupo o usuario no existe\n");
            }
        }else{
            printf("Error no eres usaurio root");
        }
    }else{
        printf("Error no hay usuario logeado\n");
    }
}
