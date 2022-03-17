#include <QCoreApplication>
#include <iostream>
#include <QString>
#include <string>

#include <parser.h>
#include <scanner.h>
#include <QTextStream>


using namespace std;


int main(int argc, char* argv[])
{

    string paracorrer;
    for (int i = 1; i < argc; i++) {
        string aux;
        string aux2 = argv[i];
        for (int i = 0; i < 5; ++i) {
            aux += tolower(aux2[i]);
        }
        if (aux == "-path"){
           paracorrer += argv[i];
           paracorrer += "\' ";
        }else{
            paracorrer += argv[i];
            paracorrer +=  +" ";
        }
       //comandoLine += argv[i];
       //comandoLine += " ";
    }
    const char * c = paracorrer.c_str();
    //cout << c;
    YY_BUFFER_STATE buffer = yy_scan_string(c);
    if(yyparse()==0)
    {

    }else {

        printf("\nHay errores\n");
    }


   /* string p="------------------------------Ingrese un comando------------------------------\n";

    QTextStream qtin(stdin);
    QString line;

    while(line!="salir"){
        cout << p;
        line = qtin.readLine();
        cout << line.toUtf8().constData();
        if(line!="salir"){
            if(line.isEmpty()==false){
                YY_BUFFER_STATE buffer = yy_scan_string(line.toUtf8().constData());

                if(yyparse()==0)
                {
                    printf("\n\nComando ejecutado correctamente\n\n");

                }else {

                    printf("\n\nhay errores\n\n");
                }

            }
        }

    }*/


}
