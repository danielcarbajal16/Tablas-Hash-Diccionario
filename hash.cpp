#include "hash.h"

long TablaHash::transformaCadena(string c) {
    long d = 0;
    for (unsigned int j = 0; j < c.size(); j++) {
        d = d * 27 + (int)c[j];
    }
    if (d < 0) {
        d = -d;
    }
    return d;
}

TablaHash::TablaHash() {
    *tabla = new word [TAMMAX];
    //fin = TAMMAX;
     for (int i=0;i<TAMMAX;i++) {
        tabla[i] = nullptr;
     }
     numElem = 0;
     factorCarga = 0.0;
}

int TablaHash::hasheo(string clave) {
    int i = 0;
    long p, d;
    d = transformaCadena(clave);
    p = d % TAMMAX; // aplica aritmética modular para obtener dirección base
    while (tabla[p] != nullptr && tabla[p]->getPalab() != clave) { // bucle de exploración
        i++;
        p = p + i * i;
        p = p % TAMMAX; // considera el array como circular
    }
    return (int)p;
}

void TablaHash::insertar(word palab) {
    int pos;
    pos = hasheo(palab.getPalab());
    //palab.setAlta(true);
    if (factorCarga < 0.8) {
        tabla[pos] = new word (palab);
        numElem++;
        factorCarga = (double)numElem/(double)TAMMAX;
        ofstream escribirDic("Diccionario.txt",ios::app);
        if (!escribirDic) {
            cerr << "\nNo se pudo abrir el archivo.\n" << endl;
            exit(EXIT_FAILURE);
            }
        string palabra = palab.getPalab(), definicion = palab.getDef();
        escribirDic << palabra/*palab.getPalab()*/ << '|' << definicion/*palab.getDef()*/ << endl;
        escribirDic.close();
    }
    else {
        cout << "\nChale bro ya no conviene meter nada, asi que pues ya no se arma\n" << endl;
    }
}

word* TablaHash::buscar(string clave) {
    word *pr;
    int posicion;
    posicion = hasheo(clave);
    pr = tabla[posicion];
    if (pr != nullptr) {
        if (!pr->getAlta()) {
            pr = nullptr;
        }
    }
    return pr;
}

void TablaHash::eliminar(string clave) {
    int posicion;
    posicion = hasheo(clave);
    if (tabla[posicion] != nullptr) {
        tabla[posicion] ->setAlta(false);
        numElem--;
        cout << "\nPalabra eliminada correctamente...\n" << endl;
    }
    else {
        cout << "\nLa palabra no se encuentra registrada...\n" << endl;
    }
}

void TablaHash::mostrarTodo() {
    if (numElem > 0) {
    for (int i=0;i<TAMMAX;i++) {
        if (tabla[i] != nullptr && tabla[i]->getAlta()) {
            cout << "Palabra: " << tabla[i]->getPalab() << endl << "Definicion: " << tabla[i]->getDef() << endl << endl;
        }
    }
    }
    else {
        cout << "No hay nada que imprimir.\n" << endl;
    }
}

