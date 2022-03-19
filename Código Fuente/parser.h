/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    Tbf = 258,
    Tff = 259,
    Twf = 260,
    Tk = 261,
    Tm = 262,
    Tb = 263,
    Tp = 264,
    Te = 265,
    Tl = 266,
    Tfull = 267,
    Tfast = 268,
    T3fs = 269,
    T2fs = 270,
    Trep = 271,
    Tmbr = 272,
    Tdisk = 273,
    Tinode = 274,
    Tjournaling = 275,
    Tblock = 276,
    Tbminode = 277,
    Tbmblock = 278,
    Ttree = 279,
    Tsb = 280,
    Tfile = 281,
    Tls = 282,
    Texec = 283,
    Tsize = 284,
    Tmkdisk = 285,
    Tf = 286,
    Tu = 287,
    Tpath = 288,
    Trmdisk = 289,
    Tfdisk = 290,
    Ttype = 291,
    Tname = 292,
    Tdelete = 293,
    Tadd = 294,
    Tmount = 295,
    Tumount = 296,
    Tid = 297,
    Tmkfs = 298,
    Tfs = 299,
    Truta = 300,
    Troot = 301,
    Tpause = 302,
    Tlogin = 303,
    Tlogout = 304,
    Tmkgrp = 305,
    Trmgrp = 306,
    Tmkusr = 307,
    Trmusr = 308,
    Tchgrp = 309,
    Tuser = 310,
    Tpwd = 311,
    Tgrp = 312,
    Ttouch = 313,
    Tcont = 314,
    Tstdin = 315,
    Tr = 316,
    Tloss = 317,
    num = 318,
    cadena = 319,
    cadena2 = 320,
    cadena3 = 321,
    cadena4 = 322,
    cadena5 = 323,
    identificador = 324,
    ide2 = 325,
    ide3 = 326,
    caracter = 327,
    guion = 328,
    igual = 329
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 40 "parser.y"

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

#line 152 "parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
