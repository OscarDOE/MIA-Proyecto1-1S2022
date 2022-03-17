#include "nodomount.h"

nodoMount::nodoMount(string id, string ruta, string nombre, int numero, char letra)
{
    this->id = id;
    this->ruta = ruta;
    this->nombre = nombre;
    this->numero = numero;
    this->letra =letra;
    this->sig = nullptr;
}
