#ifndef ESTRUCTURA_H
#define  ESTRUCTURA_H * /
#include <time.h>


#include <QString>
#include "string"
#include <iostream>
using namespace std;

typedef struct{
    char p_estado;
    char p_type;
    int p_tam;
    int p_comienzo;
    char p_tipo;
    char p_nombre[16];
}particion;

typedef struct{
    int d_tam;
    time_t creacion;
    int asignacion;
    char p_tipo;
    particion particiones[4];
}Disco;

typedef struct{
    char e_estado;
    char e_tipo;
    int e_comienzo;
    int e_tam;
    int e_siguiente;
    char e_nombre[16];
}ext;

typedef struct{
    int s_filesystem_type;
    int s_free_blocks_count;
    int s_free_inodes_count;
    time_t s_mtime;
    time_t s_unmtime;
    int s_mnt_count;
    int s_magic;
    int s_inode_size;
    int s_block_size;
    int s_first_inode;
    int s_first_block;
    int s_bm_inodo_init;
    int s_bm_bloque_init;
    int s_inodos_cont;
    int s_inodo_init;
    int s_bloque_cont;
    int s_bloque_init;
}SuperBloque;

typedef struct{
    SuperBloque reserva[100];
}Journaling;

typedef struct{
    int i_gid;
    int i_uid;
    int i_size;
    time_t i_atime;
    time_t i_ctime;
    time_t i_mtime;
    int i_bloque[15];
    char i_tipo;
    int i_perm;
}TablaInodo;

typedef struct{
    char b_nombre[12];
    int b_inodo;
}content;

typedef struct{
    content b_folder[4];
}BloqueCarpeta;

typedef struct{
    char b_archivo[64];
}BloqueArchivo;

typedef struct{
    int b_apuntador[16];
}BloqueApuntador;

typedef struct{
    int id_user;
    int start_super;
    string grupo;
    string ruta;
}InicioSession;

#endif // PARTICION_H
