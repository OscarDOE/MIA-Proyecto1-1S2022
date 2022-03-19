%option case-insensitive
%option yylineno

%{
#include <iostream>
#include <QString>
#include "parser.h"
#include <stdio.h>
#include <string>
#include <QList>

    int yylex();
    void yyerror(const char *s);

%}
%option noyywrap
%option nounput




DIGIT   [0-9]

NUM     ("-")?{DIGIT}+("."{DIGIT}+)?
letra   [a-zA-Z]+



identificador   {letra}({letra}|{NUM}|"_")*
ide2            {NUM}[a-zA-Z]

cadena          [\"][^\"\n]*[\"]
cadena2         "/"[^\"\n]*"\'"
cadena4         "/"[^\" | ^" "]*" "
cadena3         "/"[^\" | ^" "]*{letra}
cadena5         ({letra})"."{letra}?

caracter        "\'"("\\")?({letra}|{NUM})"\'"

comentario      "#"[^\n]*

%x COM


%%

"BF"        {strcpy(yylval.TEXT, "BF");return Tbf;}
"FF"        {strcpy(yylval.TEXT, "FF");return Tff;}
"WF"        {strcpy(yylval.TEXT, "WF");return Twf;}

"K"        {strcpy(yylval.TEXT, "K");return Tk;}
"M"        {strcpy(yylval.TEXT, "M");return Tm;}
"B"        {strcpy(yylval.TEXT, "B");return Tb;}

"P"        {strcpy(yylval.TEXT, "P");return Tp;}
"E"        {strcpy(yylval.TEXT, "E");return Te;}
"L"        {strcpy(yylval.TEXT, "L");return Tl;}

"FULL"        {strcpy(yylval.TEXT, "FULL");return Tfull;}
"FAST"        {strcpy(yylval.TEXT, "FAST");return Tfast;}

"2FS"        {strcpy(yylval.TEXT, "2FS");return T2fs;}
"3FS"        {strcpy(yylval.TEXT, "3FS");return T3fs;}

"REP"        {strcpy(yylval.TEXT, yytext);return Trep;}
"MBR"        {strcpy(yylval.TEXT, "MBR");return Tmbr;}
"DISK"       {strcpy(yylval.TEXT, "DISK");return Tdisk;}
"INODE"      {strcpy(yylval.TEXT, "INODE");return Tinode;}
"JOURNALING" {strcpy(yylval.TEXT, "JOURNALING");return Tjournaling;}
"BLOCK"      {strcpy(yylval.TEXT, "BLOCK");return Tblock;}
"BM_INODE"   {strcpy(yylval.TEXT, "BM_INODE");return Tbminode;}
"BM_BLOCK"   {strcpy(yylval.TEXT, "BM_BLOCK");return Tbmblock;}
"TREE"       {strcpy(yylval.TEXT, "TREE");return Ttree;}
"SB"         {strcpy(yylval.TEXT, "SB");return Tsb;}
"FILE"       {strcpy(yylval.TEXT, "FILE");return Tfile;}
"LS"         {strcpy(yylval.TEXT, "LS");return Tls;}


"EXEC"       {strcpy(yylval.TEXT, yytext);return Texec;}


"SIZE"      {strcpy(yylval.TEXT, yytext);return Tsize;}
"MKDISK"    {strcpy(yylval.TEXT, yytext);return Tmkdisk;}
"FIT"         {strcpy(yylval.TEXT, yytext);return Tf;}
"UNIT"         {strcpy(yylval.TEXT, yytext);return Tu;}
"PATH"      {strcpy(yylval.TEXT, yytext);return Tpath;}
"RMDISK"    {strcpy(yylval.TEXT, yytext);return Trmdisk;}
"FDISK"     {strcpy(yylval.TEXT, yytext);return Tfdisk;}
"TYPE"      {strcpy(yylval.TEXT, yytext);return Ttype;}
"NAME"      {strcpy(yylval.TEXT, yytext);return Tname;}
"DELETE"    {strcpy(yylval.TEXT, yytext);return Tdelete;}
"ADD"       {strcpy(yylval.TEXT, yytext);return Tadd;}
"MOUNT"     {strcpy(yylval.TEXT, yytext);return Tmount;}
"UMOUNT"    {strcpy(yylval.TEXT, yytext);return Tumount;}
"ID"        {strcpy(yylval.TEXT, yytext);return Tid;}
"MKFS"      {strcpy(yylval.TEXT, yytext);return Tmkfs;}
"FS"        {strcpy(yylval.TEXT, yytext);return Tfs;}
"RUTA"      {strcpy(yylval.TEXT, yytext);return Truta;}
"ROOT"      {strcpy(yylval.TEXT, yytext);return Troot;}

"PAUSE"     {strcpy(yylval.TEXT, yytext);return Tpause;}


"LOGIN" {strcpy(yylval.TEXT, yytext);return Tlogin;}
"LOGOUT" {strcpy(yylval.TEXT, yytext);return Tlogout;}
"MKGRP" {strcpy(yylval.TEXT, yytext);return Tmkgrp;}
"RMGRP" {strcpy(yylval.TEXT, yytext);return Trmgrp;}
"MKUSR" {strcpy(yylval.TEXT, yytext);return Tmkusr;}
"RMUSR" {strcpy(yylval.TEXT, yytext);return Trmusr;}
"CHGRP" {strcpy(yylval.TEXT, yytext);return Tchgrp;}

"USUARIO"  {strcpy(yylval.TEXT, yytext);return Tuser;}
"PASSWORD"   {strcpy(yylval.TEXT, yytext);return Tpwd;}
"PWD"   {strcpy(yylval.TEXT, yytext);return Tpwd;}
"GRP"   {strcpy(yylval.TEXT, yytext);return Tgrp;}

"TOUCH" {strcpy(yylval.TEXT, yytext);return Ttouch;}
"CONT" {strcpy(yylval.TEXT, yytext);return Tcont;}
"STADIN" {strcpy(yylval.TEXT, yytext);return Tstdin;}
"R" {strcpy(yylval.TEXT, yytext);return Tr;}

"LOSS" {strcpy(yylval.TEXT, yytext);return Tloss;}

"-" {strcpy(yylval.TEXT, yytext);return guion;}
"=" {strcpy(yylval.TEXT, yytext);return igual;}


{NUM}           { strcpy(yylval.TEXT, yytext);return num;}
{identificador} { strcpy(yylval.TEXT, yytext);return identificador;}
{ide2}          { strcpy(yylval.TEXT, yytext);return ide2;}
{caracter}      { strcpy(yylval.TEXT, yytext);return caracter;}
{cadena}       { strcpy(yylval.TEXT, yytext);return cadena;}
{cadena2}       { strcpy(yylval.TEXT, yytext);return cadena2;}
{cadena3}       { strcpy(yylval.TEXT, yytext);return cadena3;}
{cadena4}       { strcpy(yylval.TEXT, yytext);return cadena4;}
{cadena5}       { strcpy(yylval.TEXT, yytext);return cadena5;}

{comentario}    {}



"\n" {}


[[:blank:]] ;

. {

std::cout<<"Error Lexico \n";
}
