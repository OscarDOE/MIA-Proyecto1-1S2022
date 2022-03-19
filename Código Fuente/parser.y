%{
#include "scanner.h"
#include <QString>
#include <string>
#include "qdebug.h"
#include <iostream>

#include "mkdisk.h"
#include "rmdisk.h"
#include "fdisk.h"
#include "mount.h"
#include "umount.h"
#include "mkfs.h"
#include "exec.h"
#include "rep.h"
#include "login.h"
#include "mkgrp.h"
#include "mkusr.h"
#include "chgrp.h"
#include "loss.h"


using namespace std;
extern int yylineno;
extern int columna;
extern char *yytext;

int yyerror(const char* mens)
{
std::cout << mens <<" "<<yytext<< std::endl;
return 0;
}
%}

%defines "parser.h"
%output "parser.cpp"
//%error-verbose
%locations

%union{
char TEXT[256];

class exec *objexec;

class mkdisk *objmkdisk;
class rmdisk *objrmdisk;
class fdisk *objfdisk;
class mount *objmount;
class umount *objumount;
class mkfs *objmkfs;
class rep *objrep;
class login *objlogin;
class mkgrp *objmkgrp;
class mkusr *objmkusr;
class chgrp *objchgrp;
class touch *objtouch;
class loss *objloss;
}


//TERMINALES
%token<TEXT> Tbf;
%token<TEXT> Tff;
%token<TEXT> Twf;

%token<TEXT> Tk;
%token<TEXT> Tm;
%token<TEXT> Tb;

%token<TEXT> Tp;
%token<TEXT> Te;
%token<TEXT> Tl;

%token<TEXT> Tfull;
%token<TEXT> Tfast;

%token<TEXT> T3fs;
%token<TEXT> T2fs;

%token<TEXT> Trep;
%token<TEXT> Tmbr;
%token<TEXT> Tdisk;
%token<TEXT> Tinode;
%token<TEXT> Tjournaling;
%token<TEXT> Tblock;
%token<TEXT> Tbminode;
%token<TEXT> Tbmblock;
%token<TEXT> Ttree;
%token<TEXT> Tsb;
%token<TEXT> Tfile;
%token<TEXT> Tls;

%token<TEXT> Texec;

%token<TEXT> Tsize;
%token<TEXT> Tmkdisk;
%token<TEXT> Tf;
%token<TEXT> Tu;
%token<TEXT> Tpath;
%token<TEXT> Trmdisk;
%token<TEXT> Tfdisk;
%token<TEXT> Ttype;
%token<TEXT> Tname;
%token<TEXT> Tdelete;
%token<TEXT> Tadd;
%token<TEXT> Tmount;
%token<TEXT> Tumount;
%token<TEXT> Tid;
%token<TEXT> Tmkfs;
%token<TEXT> Tfs;

%token<TEXT> Truta;
%token<TEXT> Troot;

%token<TEXT> Tpause;

%token<TEXT> Tlogin;
%token<TEXT> Tlogout;
%token<TEXT> Tmkgrp;
%token<TEXT> Trmgrp;
%token<TEXT> Tmkusr;
%token<TEXT> Trmusr;
%token<TEXT> Tchgrp;
%token<TEXT> Tuser;
%token<TEXT> Tpwd;
%token<TEXT> Tgrp;

%token<TEXT> Ttouch;
%token<TEXT> Tcont;
%token<TEXT> Tstdin;
%token<TEXT> Tr;

%token<TEXT> Tloss;

%token<TEXT> num;
%token<TEXT> cadena;
%token<TEXT> cadena2;
%token<TEXT> cadena3;
%token<TEXT> cadena4;
%token<TEXT> cadena5;

%token<TEXT> identificador;
%token<TEXT> ide2;
%token<TEXT> ide3;
%token<TEXT> caracter;

%token<TEXT> guion;
%token<TEXT> igual;


//NO TERMINALES
%type<objexec> _EXEC;

%type<objmkdisk> _MKDISK;
%type<objrmdisk> _RMDISK;
%type<objfdisk> _FDISK;
%type<objmount> _MOUNT;
%type<objumount> _UMOUNT;
%type<objmkfs> _MKFS;

%type<objrep> _REP;
%type<objlogin> _LOGIN;
%type<objmkgrp> _MKGRP;
%type<objmkusr> _MKUSR;
%type<objchgrp> _CHGRP;


%type<objtouch> _TOUCH;

%type<objloss> _LOSS;

%type<TEXT> PATH;
%type<TEXT> TIPO_AJUSTE;
%type<TEXT> TIPO_UNIDAD;
%type<TEXT> NAME;
%type<TEXT> TYPES
%type<TEXT> TIPO_DELETEoTYPES;
%type<TEXT> TIPO_REP;
%type<TEXT> TIPO_SISTEMA;

%type<TEXT> INS;
%type<TEXT> PWD;

%start INICIO
%%

INICIO : INSTRUCCIONES { }
;

INSTRUCCIONES:        Tmkdisk _MKDISK {$2->CrearMkdisk($2);}
            |Trmdisk _RMDISK {$2->EliminarDisco($2);}
            |Tfdisk _FDISK {$2->AdmiDisco($2);}
            |Tmount _MOUNT{$2->MontarParticion($2);}
            |Tumount _UMOUNT{$2->DesmontarParticion($2);}
            |Tmkfs _MKFS{$2->FormatoMkfs($2);}
            |Texec _EXEC{$2->ejecutar($2);}
            |Trep _REP{$2->CrearRep($2);}
            |Tlogin _LOGIN{$2->Login($2);}
            |Tlogout {login obj; obj.Logout();}
            |Tmkgrp _MKGRP{$2->crearGrupo($2);}
            |Trmgrp _MKGRP{$2->eliminarGrupo($2);}
            |Tmkusr _MKUSR{$2->crearUsuario($2);}
            |Trmusr _MKUSR{$2->eliminarUsuario($2);}
            |Tchgrp _CHGRP{$2->cambiarGrupo($2);}
            |Ttouch _TOUCH{}
            |Tloss _LOSS{$2->lossPart($2);}
            |Tpause{}
;

_EXEC:
            guion Tpath igual PATH{exec *file= new exec(); file->contenido=$4; $$=file;}
;

_MKDISK:
            _MKDISK guion Tsize igual num {int tam=atoi($5); $1->size=tam; $$=$1;}
            |guion Tsize igual num {int tam=atoi($4); mkdisk *disco=new mkdisk(); disco->size=tam; $$=disco;}
            |_MKDISK guion Tpath igual PATH {$1->ruta=$5; $$=$1;}
            |guion Tpath igual PATH {mkdisk *disco=new mkdisk(); disco->ruta=$4; $$=disco;}
            |_MKDISK guion Tf igual TIPO_AJUSTE {$1->ajuste=$5; $$=$1;}
            |guion Tf igual TIPO_AJUSTE {mkdisk *disco=new mkdisk(); disco->ajuste=$4; $$=disco;}
            |_MKDISK guion Tu igual TIPO_UNIDAD {$1->unidad=$5; $$=$1;}
            |guion Tu igual TIPO_UNIDAD {mkdisk *disco=new mkdisk(); disco->unidad=$4; $$=disco;}
;

_RMDISK:
            guion Tpath igual PATH {rmdisk *disco=new rmdisk(); disco->path=$4; $$=disco;}
;

_FDISK:
            _FDISK guion Tsize igual num {int tam=atoi($5); $1->size=tam; $$=$1;}
            |guion Tsize igual num {int tam=atoi($4); fdisk *disco= new fdisk(); disco->size=tam; $$=disco;}
            |_FDISK guion Tu igual TIPO_UNIDAD {$1->unidad=$5; $$=$1;}
            |guion Tu igual TIPO_UNIDAD {fdisk *disco=new fdisk(); disco->unidad=$4; $$=disco;}
            |_FDISK guion Tpath igual PATH {$1->ruta=$5; $$=$1;}
            |guion Tpath igual PATH {fdisk *disco=new fdisk(); disco->ruta=$4; $$=disco;}
            |_FDISK guion Ttype igual TYPES{$1->tipo=$5; $$=$1;}
            |guion Ttype igual TYPES {fdisk * disco=new fdisk(); disco->tipo=$4; $$=disco;}
            |_FDISK guion Tf igual TIPO_AJUSTE {$1->ajuste=$5; $$=$1;}
            |guion Tf igual TIPO_AJUSTE {fdisk *disco=new fdisk(); disco->ajuste=$4; $$=disco;}
            |_FDISK guion Tdelete igual TIPO_DELETEoTYPES {$1->eliminar=$5; $$=$1;}
            |guion Tdelete igual TIPO_DELETEoTYPES {fdisk * disco=new fdisk(); disco->eliminar=$4; $$=disco;}

            |_FDISK guion Tdelete {$1->eliminar="FAST"; $$=$1;}
            |guion Tdelete {fdisk * disco=new fdisk(); disco->eliminar="FAST"; $$=disco;}

            |_FDISK guion Tname igual NAME {$1->nombre=$5; $$=$1;}
            |guion Tname igual NAME {fdisk * disco=new fdisk(); disco->nombre=$4; $$=disco;}
            |_FDISK guion Tadd igual num {int tam=atoi($5);$1->agregar=tam; $$=$1;}
            |guion Tadd igual num {int tam=atoi($4); fdisk * disco=new fdisk(); disco->agregar=tam; $$=disco;}
;

_MOUNT:
            _MOUNT guion Tpath igual PATH{$1->ruta=$5; $$=$1;}
            |guion Tpath igual PATH {mount * montar=new mount(); montar->ruta=$4; $$=montar;}
            |_MOUNT guion Tname igual NAME {$1->nombre=$5; $$=$1;}
            |guion Tname igual NAME {mount * montar=new mount(); montar->nombre=$4; $$=montar;}
;

_UMOUNT:
            guion Tid igual INS {umount *unmontar = new umount(); unmontar->id=$4; $$=unmontar;}
;

_MKFS:
            _MKFS guion Tid igual INS{$1->id= $5; $$=$1;}
            |guion Tid igual INS {mkfs *Disco = new mkfs(); Disco->id = $4; $$=Disco;}
            |_MKFS guion Ttype igual TIPO_DELETEoTYPES{$1->tipo= $5; $$=$1;}
            |guion Ttype igual TIPO_DELETEoTYPES {mkfs *Disco = new mkfs(); Disco->tipo = $4; $$=Disco;}
            |_MKFS guion Tfs igual TIPO_SISTEMA{$1->fs= $5; $$=$1;}
            |guion Tfs igual TIPO_SISTEMA {mkfs *Disco = new mkfs(); Disco->fs = $4; $$=Disco;}

;

_REP:
            _REP guion Tname igual TIPO_REP {$1->nombre= $5; $$=$1;}
            |guion Tname igual TIPO_REP {rep *reporte = new rep(); reporte->nombre = $4; $$=reporte;}
            |_REP guion Tpath igual PATH {$1->ruta= $5; $$=$1;}
            |guion Tpath igual PATH {rep *reporte = new rep(); reporte->ruta = $4; $$=reporte;}
            |_REP guion Tid igual INS {$1->id= $5; $$=$1;}
            |guion Tid igual INS {rep *reporte = new rep(); reporte->id = $4; $$=reporte;}
            |_REP guion Truta igual PATH {$1->ruta= $5; $$=$1;}
            |guion Truta igual PATH {rep *reporte = new rep(); reporte->ruta = $4; $$=reporte;}
            |_REP guion Troot igual num {int tam=atoi($5);$1->root=tam; $$=$1;}
            |guion Troot igual num {int tam=atoi($4);rep *reporte = new rep(); reporte->root = tam; $$=reporte;}
;


_LOGIN:
            _LOGIN guion Tid igual INS {$1->id= $5; $$=$1;}
            |guion Tid igual INS {login *usuario = new login(); usuario->id = $4; $$=usuario;}
            |_LOGIN guion Tpwd igual PWD {$1->pwd= $5; $$=$1;}
            |guion Tpwd igual PWD {login *usuario = new login(); usuario->pwd = $4; $$=usuario;}
            |_LOGIN guion Tuser igual PWD {$1->user= $5; $$=$1;}
            |guion Tuser igual PWD {login *usuario = new login(); usuario->user = $4; $$=usuario;}
;

_MKGRP:
            guion Tname igual NAME {mkgrp *grupo = new mkgrp; grupo->nombre =$4; $$=grupo;}
;

_MKUSR:
            _MKUSR guion Tuser igual PWD {$1->usr=$5; $$=$1;}
            |guion Tuser igual PWD {mkusr *usuario = new mkusr; usuario->usr =$4; $$=usuario;}
            |_MKUSR guion Tpwd igual PWD {$1->pwd=$5; $$=$1;}
            |guion Tpwd igual PWD {mkusr *usuario = new mkusr; usuario->pwd =$4; $$=usuario;}
            |_MKUSR guion Tgrp igual NAME {$1->grp=$5; $$=$1;}
            |guion Tgrp igual NAME {mkusr *usuario = new mkusr; usuario->grp =$4; $$=usuario;}

;

_CHGRP:
            _CHGRP guion Tuser igual PWD {$1->usr=$5; $$=$1;}
            |guion Tuser igual PWD {chgrp *grupo = new chgrp; grupo->usr =$4; $$=grupo;}
            |_CHGRP guion Tgrp igual NAME {$1->grp=$5; $$=$1;}
            |guion Tgrp igual NAME {chgrp *grupo = new chgrp; grupo->grp =$4; $$=grupo;}
;

_TOUCH:
            _TOUCH guion Tpath igual PATH{}
            |guion Tpath igual PATH {}
            |_TOUCH guion Tr {}
            |guion Tr {}
            |_TOUCH guion Tsize igual num {}
            |guion guion Tsize igual num {}
            |_TOUCH guion Tcont igual num{}
            |guion Tcont igual num{}
            |_TOUCH guion Tstdin{}
            |guion Tstdin{}
;

_LOSS:
            guion Tid igual INS{loss *part = new loss; part->id=$4; $$=part;}
;

PATH:
            cadena{}
            |cadena2{}
            |cadena3{}
            |cadena4{}
            |cadena5{}
;

NAME:
            cadena{}
            |cadena2{}
            |identificador{}
            |Troot{}
;

INS:
            cadena{}
            |ide2{}
;

PWD:
            cadena{}
            |identificador{}
            |Troot{}
            |num {}
;

TYPES:
            Tp{}
            |Te{}
            |Tl{}
;

TIPO_AJUSTE:
            Tbf{}
            |Tff{}
            |Twf{}
;


TIPO_UNIDAD:
            Tk{}
            |Tm{}
            |Tb{}
;

TIPO_DELETEoTYPES:
            Tfull{}
            |Tfast{}
;

TIPO_REP:
            Tmbr{}
            |Tdisk{}
            |Tinode{}
            |Tjournaling{}
            |Tblock{}
            |Tbminode{}
            |Tbmblock{}
            |Ttree{}
            |Tsb{}
            |Tfile{}
            |Tls{}
;


TIPO_SISTEMA:
            T2fs{}
            |T3fs{}
;

