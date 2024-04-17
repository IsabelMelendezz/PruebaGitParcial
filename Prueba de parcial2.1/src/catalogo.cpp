#include "catalogo.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;

catalogo::catalogo(string id, string nombre, string precio, string cantidad)
{
    this->id = id;
    this->nombre = nombre;
    this->precio = precio;
    this->cantidad = cantidad;
}

string catalogo::setId( string id)
{
    this-> id=id;
}
string catalogo::getId()
{
    return this -> id;
}

string catalogo::setNombre(string nombre)
{
    this->nombre=nombre;
}

string catalogo::getNombre()
{
    return this->nombre;
}

string catalogo::setPrecio(string precio)
{
    this->precio=precio;
}

string catalogo::getPrecio()
{
    return this->precio;
}

string catalogo::setCantidad(string cantidad)
{
    this->cantidad=cantidad;
}

string catalogo::getCantidad()
{
    return this->cantidad;
}
void catalogo::submenu()
{
int opcion;
    char x;
    bool repetir=true;
    system("cls");
   do
   {

    cout<<"\t\t\t--------------------------------------------"<<endl;
    cout<<"\t\t\t|        CRUD DE HOTELERIA OCEANA           |"<<endl;
    cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingresar Detalles de reservacion"<<endl;
	cout<<"\t\t\t 2. Modificar detalles elegidos"<<endl;
	cout<<"\t\t\t 3. Consultar el registro de reservaciones "<<endl;
	cout<<"\t\t\t 4. Borrar cambios realizados"<<endl;
	cout<<"\t\t\t 5. Salir del menu "<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t| Opcion a escoger:[1/2/3/4/5] |"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";

    cin>>opcion;

    switch(opcion)

   //--------------------------------------------------------------------------------------------------
    {

    case 1:
        do
            {  insertar(); //metodo para ingresar usuarios
                cout<<"\n\t\t\t ¿Desea agregar una nueva reservacion? (S/N)"<<endl;
                cin>>x;//Recibe algo del usuario
            } while(x=='s'|| x=='S');// si el char que recibe el usuario es S o s repetir el ciclo
            system("cls");
            break;
        break;
 //--------------------------------------------------------------------------------------------------

    case 2:
        modificar();
        system("pause");
        system ("cls");
        break;
 //--------------------------------------------------------------------------------------------------
    case 3:
        desplegar();
        system("pause");
        system ("cls");
        break;
    case 4:
         borrar();
         system("pause");
         system ("cls");
        break;
 //--------------------------------------------------------------------------------------------------
    case 5:
        break;
 //-------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
    break;}
        }while(opcion!= 5);

}

void catalogo::desplegar()
{
   system("cls");
int total=0;

//imprimir encabezado
cout<<"\n-------------------------Interfaz de reservacion de OCEANA------------------------"<<endl;
fstream fileDesplegar;
fileDesplegar.open("catalogos.txt",ios::in);
//condicion si el archivo no se puede abrir
if(!fileDesplegar)
    {
    cout<<"\n\t\t\tNo hay información..."; // muestra un mensaje de error
		fileDesplegar.close(); // cierra el archivo
    }
else
    {
        fileDesplegar >> id>> nombre>>precio>>cantidad;//lee el primer registro del archivo
        //condicion de seguir leyendo registrso hasta llegar al final del registro
        while(!fileDesplegar.eof())
        {
         total++;//contado de usuarios
         cout<<"\t\t\t ID DE PAGO: "<<id<<endl; // muestra el nombre del usuario
         cout<<"\t\t\t NOMBRE DE LA HABITACION RESERVADA: "<<nombre<<endl;
         cout<<"\t\t\t PRECIO: "<<precio<<endl;
        cout<<"\t\t\t CANTIDAD DE NOCHES A HOSPEDARSE: "<<cantidad<<endl<<endl<<endl;
        fileDesplegar >> id>> nombre>>precio>>cantidad;//leera el siguiente registro del archivo
        }

        if(total==0)//si no llegara a encontrar ningun registro en el archivo
        {
            cout<<"\n\t\t\tNo hay informacion..."; // muestra un mensaje de error
        }
    }
    fileDesplegar.close();
}

void catalogo::insertar()
{
    system("cls");
    string id,nombre,precio,cantidad;
    cout<<"\n-------------------------------------------------Agregar reservacion-------------------------------------------"<<endl;
    cout << "Ingrese el ID de su transaccion de pago: "<<endl;
    cin >> id;
      cout << "Ingrese el nombre de la habitacion a reservar :"<<endl;
    cin >> nombre;
      cout << "Ingrese el precio de la habitacion elegida:"<<endl;
    cin >> precio;
      cout << "Ingrese la cantidad de noches de estadia: "<<endl;
    cin >> cantidad;

    // Abre el archivo "" en modo de apendizaje y escritura
    fstream fileIngresar;
    fileIngresar.open("catalogos.txt",ios::app| ios:: out);

    // Escribe en el archivo los datos del usuario ingresados por el usuario
    fileIngresar<<std::left<<std::setw(15)<< id <<std::left <<std::setw(15)<< nombre<<std::left <<std::setw(15)<< precio<<std::left <<std::setw(15)<< cantidad<<"\n";

    //cierre del archivo
    fileIngresar.close();
    //mensaje de exito

    cout << "\t\t\t\Reservacion realizada exitosamente."<<endl;


}

void catalogo::modificar()
{

	system("cls");
    fstream fileOri, fileModif;  // Se crean dos objetos de archivo para leer y escribir en archivos de texto
    string productoModificar;  // Se define una cadena para almacenar el nombre del usuario a modificar

    int contador=0;  // Se define una variable para contar si se encuentra el usuario en el archivo
    cout<<"\n-------------------------Modificacion de  reservacion -------------------------"<<endl;  // Muestra un mensaje en pantalla
    fileOri.open("catalogos.txt",ios::in);  // Abre el archivo de texto en modo lectura

    if(!fileOri)  // Si el archivo no se pudo abrir
    {
        cout<<"\n\t\t\tNo hay informacion..,";  // Muestra un mensaje en pantalla
        fileOri.close();  // Cierra el archivo
    }
    else  // Si el archivo se pudo abrir
    {
        cout<<"\n Ingrese el nombre de la habitacion que desea modificar: ";  // Muestra un mensaje en pantalla para ingresar el usuario a modificar
        cin>>productoModificar;  // Lee el nombre del usuario a modificar
        fileModif.open("record2.txt",ios::app | ios::out);  // Abre otro archivo de texto en modo escritura y agrega el contenido al final del archivo
        fileOri >> id>> nombre>>precio>>cantidad;  // Lee el primer usuario y contraseña del archivo

        while(!fileOri.eof())  // Mientras no se llegue al final del archivo
        {
            if(productoModificar!=nombre)  // Si el usuario no es el que se quiere modificar
                {
                fileModif<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre<<std::left<<std::setw(15)<< precio<<std::left<<std::setw(15)<< cantidad<<"\n";  // Escribe en el archivo temporal el usuario y contraseña sin modificar


                }

            else  // Si se encuentra el usuario a modificar
                {
                cout << "\t\t\t\nIngrese el nuevo id de pago: ";
                cin >> id;
                cout << "\t\t\t\nIngrese el nuevo nombre de la habitacion: ";
                cin >> nombre;
                cout << "\t\t\t\nIngrese el nuevo precio: ";
                cin >> precio;
                cout << "\t\t\t\nIngrese la nueva cantidad de dias a hospedarse: ";
                cin >> cantidad;
                fileModif<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre<<std::left<<std::setw(15)<< precio<<std::left<<std::setw(15)<< cantidad<<"\n";  // Escribe en el archivo temporal el usuario y contraseña sin modificar
                contador++;  // Incrementa el contador de usuarios modificados
                cout << "\t\t\t\Reservacion Modificada exitosamente.";
                }

                    fileOri >> id>> nombre>>precio>>cantidad; // Lee el siguiente usuario y contraseña del archivo
        }

        fileModif.close();  // Cierra el archivo temporal
        fileOri.close();  // Cierra el archivo original

        remove("catalogos.txt");  // Elimina el archivo original
        rename("record2.txt","catalogos.txt");  // Renombra el archivo temporal con el nombre del archivo original
         cout << "\t\t\t\nReservacion no encontrada.";
          // Muestra un mensaje en pantalla
    }
}

void catalogo::borrar()
{
   	system("cls");

	// Declarar dos objetos de la clase fstream para manejar los archivos
	fstream file, file1;

	// Declarar una variable para almacenar el nombre del usuario a borrar
	string partcipante;

	// Declarar una variable para indicar si se encontró al usuario a borrar
	int encontrados= 0;

	// Mostrar un mensaje para indicar que se va a borrar un usuario
	cout << "\n-------------------------Reservacion a Borrar-------------------------" << endl;

	// Abrir el archivo "Usuarios1.txt" en modo lectura
	file.open("catalogos.txt", ios::in);

	// Verificar si el archivo se pudo abrir
	if (!file)
	{
		cout << "\t\t\tNo hay informacion...";

		// Cerrar el archivo
		file.close();
	}
	else
	{
		// Pedir al usuario que ingrese el nombre del usuario a borrar
		cout << "\n Ingrese el nombre de la habitacion reservada que desea eliminar : "<<endl;
		cin >> partcipante;

		// Abrir el archivo "Record.txt
		file1.open("record2.txt", ios::app | ios::out);

		// Leer el nombre de usuario y contraseña del archivo "Usuario y contraseñas.txt"
		file >> id>> nombre>>precio>>cantidad;

		// Mientras no se llegue al final del archivo "Usuarios1.txt"
		while (!file.eof())
		{
			// Verificar si el nombre de usuario leído es diferente al nombre del usuario a borrar
			if (partcipante != nombre)
			{
				// Escribir el nombre de usuario y contraseña en el archivo "Record.txt"
                file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre<<std::left<<std::setw(15)<< precio<<std::left<<std::setw(15)<< cantidad<<"\n";  // Escribe en el archivo temporal el usuario y contraseña sin modificar
			}
			else
			{
				// Incrementar el contador de usuarios encontrados
				encontrados++;

				// Mostrar un mensaje indicando que se borró al usuario exitosamente
				cout << "\n\t\t\tBorrado de reservacion exitoso"<<endl;
			}

			// Leer el siguiente nombre de usuario y contraseña del archivo "Usuarios1.txt"
                file >> id>> nombre>>precio>>cantidad;

		}

		// Verificar si no se encontró al usuario a borrar
		if (encontrados == 0)
		{
			cout << "\n\t\t\t Nombre de habitacion no encontrada...";
		}

		// Cerrar los archivos
		file1.close();
		file.close();

		// Borrar el archivo "Usuarios1.txt"
		remove("catalogos.txt");

		// Renombrar el archivo "Record.txt" como "Usuarios1.txt"
		rename("record2.txt", "catalogos.txt");
	}
}
