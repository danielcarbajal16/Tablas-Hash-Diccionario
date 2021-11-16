#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
#include "palabra.h"
#define TAMMAX 37
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class TablaHash {
    private:
        //int fin;
        int numElem;
        double factorCarga;
        word **tabla;
        long transformaCadena(string c);
    public:
        TablaHash();

        int hasheo(string clave);
        void insertar(word palab);
        void mostrarTodo();
        word* buscar(string clave);
        void eliminar(string clave);
};

#endif // HASH_H_INCLUDED
