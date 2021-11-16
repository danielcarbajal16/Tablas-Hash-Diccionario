#include <iostream>
#include <windows.h>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include "palabra.h"
#include "hash.h"

using namespace std;

int main() {
    word palabra;
    word* palabraAux = nullptr;
    TablaHash dic;
    string aux="",registro="",def="",pal="";
    char opc;

    do {
        system("cls");
        cout << "Que desea hacer?\n\n"
             << "1) Agregar palabras al diccionario.\n"
             << "2) Buscar una palabra.\n"
             << "3) Eliminar una palabra del diccionario.\n"
             << "4) Mostrar todo.\n"
             << "5) Salir.\t\t";
        cin >> opc;
        cin.ignore();
        switch (opc) {
            case '1': {
                system("cls");
                cout << "Ingresa la palabra a definir: ";
                getline(cin,aux);
                palabra.setPalab(aux);
                cout << "\nAhora ingrese la definicion de dicha palabra: ";
                getline(cin,aux);
                palabra.setDef(aux);
                dic.insertar(palabra);
                /*ofstream escribirDic("Diccionario.txt",ios::app);
                if (!escribirDic) {
                    cerr << "\nNo se pudo abrir el archivo.\n" << endl;
                    exit(EXIT_FAILURE);
                    }
                escribirDic << palabra.getPalab() << '|' << palabra.getDef() << endl;
                escribirDic.close();*/
                cout << endl;
                system("pause");
                break;
                }
            case '2': {
                system("cls");
                cout << "Ingrese la palabra que busca: ";
                getline(cin,aux);
                palabraAux = dic.buscar(aux);
                if (palabraAux != nullptr) {
                    cout << endl << palabraAux->getDef() << endl << endl;
                    }
                else {
                    cout << "\nNo se encuentra dicha palabra...\n" << endl;
                    }
                system("pause");
                break;
                }
            case '3': {
                system("cls");
                cout << "Ingrese la palabra que desea eliminar: ";
                getline(cin,aux);
                dic.eliminar(aux);
                system("pause");
                break;
                }
            case '4':
                system("cls");
                dic.mostrarTodo();
                system("pause");
                break;
            case '5':
                break;
            default:
                break;
            }
        }
    while(opc != '5');
    return 0;
    }
