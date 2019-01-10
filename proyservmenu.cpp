#include <cstdlib>
#include <conio.h>

#include "proyservmenu.h"

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif // _WIN32

using namespace std;

ProyServMenu::ProyServMenu(SLList* l) {
    ProyServList= l;
    mainMenu();
    }

void ProyServMenu::mainMenu() {
    char opc;
    do {
        system(CLEAR);
        cout << "*****Programa de Administración de Productos y Servicios*****" << endl << endl;
        cout << "-Menú de Productos y servicios." << endl << endl;
        cout << "(I)Insertar." << endl;
        cout << "(E)Eliminar." << endl;
        cout << "(M)Modificar." << endl;
        cout << "(N)Mostrar Lista." << endl;
        cout << "(L)Leer del Disco."<<endl;
        cout << "(R)Escribir del Disco."<<endl;
        cout << "(B)Borrar Todo."<< endl;
        cout << "(S)Salir." << endl;
        cout << "-La opción es: ";
        cin >> opc;
        cin.ignore();
        opc=toupper(opc);

        switch(opc) {
            case 'I':
                insertProyServ();
                break;
            case 'E':
                deleteProyServ();
                break;
            case 'M':
                modifyProyServ();
                break;
            case 'N':
                showProyServList();
                break;
            case 'L':
                readDisk();
                break;
            case 'R':
                writeDisk();
                break;
            case 'B':
                deleteAll();
                break;
            case 'S':
                cout << "-Regresando al menú principal..." << endl;
                break;
            default:
                cout << "-La opción elegida no existe, intente de nuevo." << endl;
                enterToContinue();
                break;
            }
        }
    while(opc!='S');
    cout << "-Gracias, vuelva pronto" << endl;
    }

void ProyServMenu::insertProyServ() {
    system(CLEAR);
    int myProyServNumber;
    string myNombre;
    string myDescripcion;
    float myCosto;
    ProyServ myProyServ;

    cout << "-Insertar Producto o Servicio" << endl << endl;
    cout << "-Número de Producto o Servicio: ";
    cin >> myProyServNumber;

    cout << "-Nombre del Producto o Servicio: ";
    cin.ignore();
    getline(cin, myNombre);

    cout << "-Descripción del Producto o Servicio: ";
    cin.ignore();
    getline(cin, myDescripcion);

    cout << "-Costo del Producto o Servicio: ";
    cin >> myCosto;

    myProyServ.setProyServNumber(myProyServNumber);
    myProyServ.setNombre(myNombre);
    myProyServ.setDescripcion(myDescripcion);
    myProyServ.setCosto(myCosto);
    ProyServList -> insertOrdered(myProyServ);

    cout <<"-Se inserto correctamente!" << endl;
    cin.get();
    enterToContinue();
    }

void ProyServMenu::deleteProyServ() {
    system(CLEAR);
    int myProyServNumber;
    ProyServ myProyServ;
    SLNode* myPos;

    cout << "-Eliminar Producto o Servicio" << endl << endl;
    cout << "-Número de productos y servicios: ";
    cin >> myProyServNumber;

    myProyServ.setProyServNumber(myProyServNumber);
    myPos = ProyServList -> findData(myProyServ);

    if(myPos == nullptr) {
        cout << "-El producto o servicio no se encuentra en la lista." << endl<<endl;
        }
    else {
        ProyServList -> deleteData(myPos);
        cout << "-El producto o servicio fue eliminado!" << endl<<endl;
        }
    cin.get();
    enterToContinue();
    }

void ProyServMenu::modifyProyServ() {
    int myProyServNumber;
    string myNombre;
    string myDescripcion;
    float myCosto;
    ProyServ myProyServ;
    SLNode* myPos;

    system(CLEAR);
    cout << "-Modificar Producto o Servicio." << endl << endl;
    cout << "-Número de Producto o Servicio: ";
    cin >> myProyServNumber;

    myProyServ. setProyServNumber(myProyServNumber);
    myPos = ProyServList -> findData(myProyServ);

    if(myPos == nullptr) {
        cout << "-Producto o Servicio no se encuentra." << endl<<endl;
        cin.get();
        enterToContinue();
        }
    else {
        cout << "-Número de productos y servicios: " ;
        cin>> myProyServNumber;
        cout << "-Nombre de productos y servicios: " ;
        cin.ignore();
        getline(cin, myNombre);
        cout << "-Descripción de productos y servicios: " ;
        cin.ignore();
        getline(cin, myDescripcion);
        cout << "-Costo de productos y servicios: " ;
        cin>> myCosto;

        myProyServ.setProyServNumber(myProyServNumber);
        myProyServ.setNombre(myNombre);
        myProyServ.setDescripcion(myDescripcion);
        myProyServ.setCosto(myCosto);
        ProyServList -> modifyProyServ(myPos);
        ProyServList -> insertOrdered(myProyServ);

        cout << "-El Producto o Servicio se a modificado!" << endl<<endl;
        cin.get();
        enterToContinue();
        }
    }

void ProyServMenu::showProyServList() {
    system(CLEAR);
    cout << "-Lista de Productos y Servicios." << endl << endl;
    ProyServList -> print();
    cout << endl;
    enterToContinue();
    }
void ProyServMenu::writeDisk() {
    system("cls");
    cout<<"-Escribiendo en disco: "<<endl;
    bar2();
    try {
        ProyServList->writeToDisk("ProductosyServicios.txt");
        }
    catch(ListException ex) {
        }
    enterToContinue();
    }

void ProyServMenu::readDisk() {
    system("cls");
    bar2();
    cout<<endl;
    cout<<"-Se ha completado la lectura desde el disco: "<<endl;
    try {
        ProyServList->readFromDisk("ProductosyServicios.txt");
        }
    catch(ListException ex) {
        }
    enterToContinue();
    }

void ProyServMenu::bar2() {
    int segundos=5;
    system("cls");
    for(int i=0; i<=10; i++)
        cout << "\n";

    cout << "-Espera Por Favor..."<<endl;
    cout << "-CARGANDO..." <<endl;
    for(int i=0; i<=79; i++)
        cout << "_";
    for(int i=0; i<=79; i++) {
        cout<<"|";
        Sleep(segundos*100/80);
        }
    }

void ProyServMenu::deleteAll() {
    system(CLEAR);
    char answer;

    cout << "-Borrar todo los Datos." <<endl << endl;
    cout << "-Seguro que quieres eliminar todos los datos de ProyServe? (S/N): ";
    cin >> answer;

    if((answer == 's')||(answer=='S')) {
        ProyServList -> deleteAll();
        cout << "-Datos eliminados."<< endl;
        }
    else {
        cout << "-Regresando al menú principal." << endl;
        }
    cin.get();
    enterToContinue();
    }

void ProyServMenu::enterToContinue() {
    cout << "-Presione ENTER para continuar...";
    cin.get();
    }
