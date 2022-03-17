#include "exec.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

#include <parser.h>
#include <scanner.h>
exec::exec()
{

}

void exec::ejecutar(exec *archivo){
    //cout << file->namefile;

    vector<string> lines;
    string line;

    string au = (archivo->contenido).substr(0, (archivo->contenido).size()-1);
    char ca1 = au.back();
    char ca = (archivo->contenido).back();
    if(ca1 == '\''){
        archivo->contenido = (archivo->contenido).substr(0, (archivo->contenido).size()-1);
        archivo->contenido = (archivo->contenido).substr(0, (archivo->contenido).size()-1);
    }else if(ca == '"'){
        string aux;
        for (int i = 0; i < (archivo->contenido).size(); i++) {
            if((archivo->contenido)[i]!='"'){
                aux += (archivo->contenido)[i];
            }
        }
        archivo->contenido = aux;
    }

    //file->namefile = (file->namefile).substr(0, (file->namefile).size()-1);
    ifstream input_file(archivo->contenido);

    while (getline(input_file, line)){
        lines.push_back(line);
    }
    //int lin = 0;
    for (const auto &i : lines){
        string com = i;
        string com2 = "pause";
        transform(com.begin(), com.end(), com.begin(), :: tolower);
        transform(com2.begin(), com2.end(), com2.begin(), :: tolower);
        if (com.compare(com2)== 0){
            //system("read");
            cout<<"Presione enter para continuar\n"<<endl;
            cin.get();
            continue;
        }
        if(i!=""){
            cout <<"\n"<< i << endl ;
            const char * c = i.c_str();
            YY_BUFFER_STATE buffer = yy_scan_string(c);
            if(yyparse()==0){
                //printf("\nComando ejecutado correctamente\n\n");

            }else {
                printf("\nHay errores\n\n");
            }
        }
    }
    input_file.close();
}
