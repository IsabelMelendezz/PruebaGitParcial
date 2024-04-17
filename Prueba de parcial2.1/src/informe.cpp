#include "informe.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <conio.h>
#include <iomanip>

using namespace std;

informe::informe(string id2, string nombre2, string precio2, string cantidad2) {
    // Constructor
}

void informe::desplegar() {

    int total = 0;
    system("cls");


    // Imprimir encabezado
    cout <<setw(15)<<"\n-------------------------Interfaz de reservaciones realizadas--------------------------------------"<< endl;
    fstream fileDesplegar;
    fileDesplegar.open("catalogos.txt", ios::in);

    // Condición si el archivo no se puede abrir
    if (!fileDesplegar) {
        cout << "\n\t\t\tNo hay información..." << endl;
        fileDesplegar.close();
    } else {
        // Leer registros del archivo y mostrarlos
        while (fileDesplegar >> id2 >> nombre2 >> precio2 >> cantidad2) {
            total++;
            cout <<"\t\tID DE PAGO: "<< setw(2)<<id2<< endl;
            cout <<"\t\tNOMBRE DE LA HABITACION :"<< setw(2)<< nombre2 << endl;
            cout <<"\t\tPRECIO :"<< setw(2)<< precio2 << endl;
            cout <<"\t\tCANTIDAD DE NOCHES A HOSPEDARSE :" << setw(2)<< cantidad2 << endl << endl << endl;
        }

        if (total == 0) {
            cout << "\t\t\tNo hay información..." << endl;
        }
    }

    fileDesplegar.close();
    system("pause");
}

