#include "mkfs.h"
#include "fdisk.cpp"
#include "nodomount.h"
#include "estructura.h"
#include <ctime>


mkfs::mkfs()
{

}

void Fext2(int inicio, int size, string ruta){
    double n = (size-int(sizeof(SuperBloque)))/(4+int(sizeof(TablaInodo))+3*64);
    int num_struct = int(floor(n));
    int num_block = 3*num_struct;

    SuperBloque super;
    super.s_filesystem_type = 2;
    super.s_inodos_cont = num_struct;
    super.s_bloque_cont = num_block;
    super.s_free_inodes_count = num_struct-2;
    super.s_free_blocks_count = num_block-2;
    super.s_mtime = time(nullptr);
    super.s_unmtime = time(nullptr);
    super.s_mnt_count = 0;
    super.s_magic = 0xEF53;
    super.s_inode_size = sizeof(TablaInodo);
    super.s_block_size = 64;
    super.s_first_inode = 2;
    super.s_first_block = 2;
    super.s_bm_inodo_init = inicio + int(sizeof(SuperBloque));
    super.s_bm_bloque_init = inicio + int(sizeof(SuperBloque)) + num_struct;
    super.s_inodo_init = inicio + int(sizeof(SuperBloque)) + num_struct + num_block;
    super.s_bloque_init = inicio + int(sizeof(SuperBloque)) + num_struct + num_block + (int(sizeof(TablaInodo))*num_struct);

    TablaInodo inodo;
    BloqueCarpeta block;

    char buffer0 = '0';
    char buffer1 = '1';
    char buffer2 = '2';

    FILE *archivo = fopen(ruta.c_str(),"rb+");

    fseek(archivo, inicio, SEEK_SET);
    fwrite(&super, sizeof(SuperBloque), 1, archivo);

    for (int i = 0; i < num_struct; i++) {
        fseek(archivo, super.s_bm_inodo_init+i, SEEK_SET);
        fwrite(&buffer0, sizeof(char), 1, archivo);
    }

    fseek(archivo, super.s_bm_inodo_init, SEEK_SET);
    fwrite(&buffer1, sizeof(char), 1, archivo);
    fwrite(&buffer1, sizeof(char), 1, archivo);

    for (int i = 0; i < num_block; i++) {
        fseek(archivo, super.s_bm_bloque_init+i, SEEK_SET);
        fwrite(&buffer0, sizeof(char), 1, archivo);
    }

    fseek(archivo, super.s_bm_bloque_init, SEEK_SET);
    fwrite(&buffer1, sizeof(char), 1, archivo);
    fwrite(&buffer2, sizeof(char), 1, archivo);

    //root
    inodo.i_uid = 1;
    inodo.i_gid = 1;
    inodo.i_size = 0;
    inodo.i_atime = time(nullptr);
    inodo.i_ctime = time(nullptr);
    inodo.i_mtime = time(nullptr);
    inodo.i_bloque[0] = 0;
    for (int i = 1; i < 15; i++) {
        inodo.i_bloque[i] = -1;
    }
    inodo.i_tipo= '0';
    inodo.i_perm = 664;
    fseek(archivo, super.s_inodo_init, SEEK_SET);
    fwrite(&inodo, sizeof(TablaInodo), 1, archivo);

    strcpy(block.b_folder[0].b_nombre, ".");
    block.b_folder[0].b_inodo = 0;
    strcpy(block.b_folder[1].b_nombre, "..");
    block.b_folder[1].b_inodo = 0;
    strcpy(block.b_folder[2].b_nombre, "users.txt");
    block.b_folder[2].b_inodo = 1;
    strcpy(block.b_folder[3].b_nombre, ".");
    block.b_folder[3].b_inodo = -1;

    fseek(archivo, super.s_bloque_init, SEEK_SET);
    fwrite(&block, 64, 1, archivo);

    //user.txt
    inodo.i_uid = 1;
    inodo.i_gid = 1;
    inodo.i_size = 28;
    inodo.i_atime = time(nullptr);
    inodo.i_ctime = time(nullptr);
    inodo.i_mtime = time(nullptr);
    inodo.i_bloque[0] = 1;
    for (int i = 1; i < 15; i++) {
        inodo.i_bloque[i] = -1;
    }
    inodo.i_tipo = '1';
    inodo.i_perm = 755;
    fseek(archivo, (super.s_inodo_init+int(sizeof(TablaInodo))), SEEK_SET);
    fwrite(&inodo, sizeof(TablaInodo), 1, archivo);

    BloqueArchivo B_archivo;
    memset(B_archivo.b_archivo, 0, sizeof(B_archivo.b_archivo));
    strcpy(B_archivo.b_archivo, "1,G,root\n1,U,root,root,123\n");
    fseek(archivo, (super.s_bloque_init+64), SEEK_SET);
    fwrite(&B_archivo, 64, 1, archivo);
    fclose(archivo);
    printf("Se formateo en EXT2 correctamente\n");
}

void Fext3(int inicio, int size, string ruta){
    double n = (size-int(sizeof(SuperBloque))-100*int(sizeof(BloqueArchivo)))/(4+int(sizeof(TablaInodo))+3*64);
    int num_struct = floor(n);
    int num_block = 3*num_struct;

    SuperBloque super;
    super.s_filesystem_type = 3;
    super.s_inodos_cont = num_struct;
    super.s_bloque_cont = num_block;
    super.s_free_inodes_count = num_struct-2;
    super.s_free_blocks_count = num_block-2;
    super.s_mtime = time(nullptr);
    super.s_unmtime = time(nullptr);
    super.s_mnt_count = 0;
    super.s_magic = 0xEF53;
    super.s_inode_size = sizeof(TablaInodo);
    super.s_block_size = 64;
    super.s_first_inode = 2;
    super.s_first_block = 2;
    super.s_bm_inodo_init = inicio + int(sizeof(SuperBloque))+ int(sizeof(Journaling));
    super.s_bm_bloque_init = inicio + int(sizeof(SuperBloque))+ int(sizeof(Journaling)) + num_struct;
    super.s_inodo_init = inicio + int(sizeof(SuperBloque))+ int(sizeof(Journaling)) + num_struct + num_block;
    super.s_bloque_init = inicio + int(sizeof(SuperBloque))+ int(sizeof(Journaling)) + num_struct + num_block + (int(sizeof(TablaInodo))*num_struct);

    TablaInodo inodo;
    BloqueCarpeta block;

    char buffer0 = '0';
    char buffer1 = '1';
    char buffer2 = '2';

    FILE *archivo = fopen(ruta.c_str(),"rb+");

    fseek(archivo, inicio, SEEK_SET);
    fwrite(&super, sizeof(SuperBloque), 1, archivo);

    for (int i = 0; i < num_struct; i++) {
        fseek(archivo, super.s_bm_inodo_init+i, SEEK_SET);
        fwrite(&buffer0, sizeof(char), 1, archivo);
    }

    fseek(archivo, super.s_bm_inodo_init, SEEK_SET);
    fwrite(&buffer1, sizeof(char), 1, archivo);
    fwrite(&buffer1, sizeof(char), 1, archivo);

    for (int i = 0; i < num_block; i++) {
        fseek(archivo, super.s_bm_bloque_init+i, SEEK_SET);
        fwrite(&buffer0, sizeof(char), 1, archivo);
    }

    fseek(archivo, super.s_bm_bloque_init, SEEK_SET);
    fwrite(&buffer1, sizeof(char), 1, archivo);
    fwrite(&buffer2, sizeof(char), 1, archivo);

    //root
    inodo.i_uid = 1;
    inodo.i_gid = 1;
    inodo.i_size = 0;
    inodo.i_atime = time(nullptr);
    inodo.i_ctime = time(nullptr);
    inodo.i_mtime = time(nullptr);
    inodo.i_bloque[0] = 0;
    for (int i = 1; i < 15; i++) {
        inodo.i_bloque[i] = -1;
    }
    inodo.i_tipo = '0';
    inodo.i_perm = 664;
    fseek(archivo, super.s_inodo_init, SEEK_SET);
    fwrite(&inodo, sizeof(TablaInodo), 1, archivo);

    strcpy(block.b_folder[0].b_nombre, ".");
    block.b_folder[0].b_inodo = 0;
    strcpy(block.b_folder[1].b_nombre, "..");
    block.b_folder[1].b_inodo = 0;
    strcpy(block.b_folder[2].b_nombre, "users.txt");
    block.b_folder[2].b_inodo = 1;
    strcpy(block.b_folder[3].b_nombre, ".");
    block.b_folder[3].b_inodo = -1;

    fseek(archivo, super.s_bloque_init, SEEK_SET);
    fwrite(&block, 64, 1, archivo);

    //user.txt
    inodo.i_uid = 1;
    inodo.i_gid = 1;
    inodo.i_size = 28;
    inodo.i_atime = time(nullptr);
    inodo.i_ctime = time(nullptr);
    inodo.i_mtime = time(nullptr);
    inodo.i_bloque[0] = 1;
    for (int i = 1; i < 15; i++) {
        inodo.i_bloque[i] = -1;
    }
    inodo.i_tipo = '1';
    inodo.i_perm = 755;
    fseek(archivo, (super.s_inodo_init+int(sizeof(TablaInodo))), SEEK_SET);
    fwrite(&inodo, sizeof(TablaInodo), 1, archivo);

    BloqueArchivo B_archivo;
    memset(B_archivo.b_archivo, 0, sizeof(B_archivo.b_archivo));
    strcpy(B_archivo.b_archivo, "1,G,root\n1,U,root,123\n");
    fseek(archivo, (super.s_bloque_init+64), SEEK_SET);
    fwrite(&B_archivo, 64, 1, archivo);
    fclose(archivo);
    printf("Se formateo en EXT3 correctamente\n");

}

void mkfs::FormatoMkfs(mkfs *disco){
    //cout<<disco->fs<<endl;
    char ca = (disco->id).back();
    if(ca == '"'){
        string aux;
        for (int i = 0; i < (disco->id).size(); i++) {
            if((disco->id)[i]!='"'){
                aux += (disco->id)[i];
            }
        }
        disco->id = aux;
    }
    bool error = false;
    string fit = "";
    string tipo = "";
    if (disco->fs == "2FS"){
        fit = "2FS";
    }else if (disco->fs=="3FS"){
        fit = "3FS";
    }else if(disco->fs == ""){
        fit = "2FS";
    }else{
        error = true;
        printf("Error parametro -fs no es permitido\n");
    }
    if (disco->tipo=="FAST"){
        tipo = "FAST";
    }else if (disco->tipo == "FULL"){
        tipo = "FULL";
    }else if (disco->tipo == ""){
        tipo = "FULL";
    }else{
        error = true;
        printf("Error parametro -type no es permitido\n");
    }

    if (!error){
        if(disco->id != ""){
            bool comprobar = false;
            nodoMount *aux = ListaM->primero;
            while (aux!= nullptr){
                if (aux->id == disco->id){
                    comprobar = true;
                    break;
                }
                aux = aux->sig;
            }
            if (comprobar){
                FILE *archivo;
                if(archivo=fopen((aux->ruta).c_str(), "rb+")){
                    Disco master;
                    int NParticion = -1;
                    fseek(archivo, 0 , SEEK_SET);
                    fread(&master, sizeof(Disco), 1, archivo);
                    for (int i = 0; i < 4; ++i) {
                        if (strcmp(master.particiones[i].p_nombre, (aux->nombre).c_str())==0){
                            NParticion = i;
                            break;
                        }
                    }
                    if(NParticion != -1){
                        int inicio = master.particiones[NParticion].p_comienzo;
                        int size = master.particiones[NParticion].p_tam;
                        if (fit == "2FS"){
                            Fext2(inicio, size, aux->ruta);
                        }else{
                            Fext3(inicio, size, aux->ruta);
                        }
                    }else{
                        printf("Error no se encontro la particion con el mismo nombre\n");
                    }
                    fclose(archivo);
                }else{
                    printf("Error no se encontro el disco\n");
                }
            }else{
                printf("Error no se encontro el mismo id montada\n");
            }
        }else{
            printf("Error no se ingreso el parametro -id\n");
        }
    }
}
