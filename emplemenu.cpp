#include "emplemenu.h"
#include "proyservmenu.h"

using namespace std;

EmpleadoMenu::EmpleadoMenu(DLList* l) {
    EmpleadoList = l;
    mainMenu();
    }

void EmpleadoMenu::mainMenu() {
    char op;
    do {
        system("cls");
        cout << "*****Programa de Administración de Empleados*****" << endl << endl;
        cout << "-Menú de Empleados." << endl << endl;
        cout << "(I)Insertar." << endl;
        cout << "(E)Eliminar." << endl;
        cout << "(M)Modificar." << endl;
        cout << "(D)Desplegar." << endl;
        cout << "(B)Borrar Todo."<<endl;
        cout << "(L)Leer del Disco."<<endl;
        cout << "(R)Escribir del Disco."<<endl;
        cout << "(O)Ordenar."<<endl;
        cout << "(S)Salir." << endl;
        cout << "-Elija una opción: ";
        cin >> op;
        cin.ignore();
        op = toupper(op); //Minúsculas a mayúsculas

        switch(op) {
            case 'I':
                insertEmpleado();
                break;
            case 'E':
                deleteEmpleado();
                break;
            case 'M':
                modifyEmpleado();
                break;
            case 'D':
                showEmpleadoList();
                break;
            case 'B':
                deleteAll();
                break;
            case 'O':
                sortBy();
                break;
            case 'R':
                writeToDisk();
                break;
            case 'L':
                readFromDisk();
                break;
            case 'S': {
                cout << "-Saliendo del programa, vuelva pronto." << endl << endl;
                enterToContinue();
                }
            break;
            default:
                cout << "-La opción elegida no existe, intente de nuevo." << endl << endl;
                enterToContinue();
            }
        }
    while(op != 'S');
    }

void EmpleadoMenu::insertEmpleado() {
    system("cls");
    string myStr,myHour,myMinute;
    Time myTime;
    Name myName;
    Empleado myEmpleado;
    int myInt;
    DLNode* myPos;
    char op;

    cout << "-Insertando un nuevo Empleado." << endl << endl;
    cout << "-Código de Empleado: ";
    getline(cin, myStr);
    myEmpleado.setEmpleadoNum(myStr);
    cout<<endl;

    cout << "-Horario Empleado (HH:MM): ";
    getline(cin, myHour, ':');
    getline(cin, myMinute);
    myTime.setHour(atoi(myHour.c_str()));
    myTime.setMinute(atoi(myMinute.c_str()));
    myEmpleado.setSchedule(myTime);
    cout<<endl;

    cout << "-Apellido: ";
    getline(cin, myStr);
    myName.setLast(myStr);
    cout<<endl;

    cout << "-Nombre: ";
    getline(cin, myStr);
    myName.setFirst(myStr);
    cout<<endl;

    myEmpleado.setName(myName);

    cout <<"-Especialidad: " <<endl <<endl;
    cout <<"-Ingresa el nombre de la especialidad: "<<endl;
    cout <<"  +Administradores."<<endl;
    cout <<"  +Proveedores."<<endl;
    cout <<"  +Vendedores."<<endl;
    cout <<"  +Jardineros."<<endl;
    cout <<"  +Floricultores."<<endl;
    cout <<"  +Viveristas."<<endl<<endl;
    cout <<"-La especialidad es: ";
    getline(cin, myStr);
    myEmpleado.setDepart(myStr);

    cout<<endl;
    cout<< "-Horas Extras: ";
    getline(cin,myStr);
    myEmpleado.setHours(myStr);

    cout<<endl;
    cout << "-Número de extensión:";
    cin>>myInt;
    myEmpleado.setNumExt(myInt);

    try {
        myPos = EmpleadoList->insertData(EmpleadoList->getLastPos(), myEmpleado);
        }
    catch(ListException ex) {
        cout<<"-Error al insertar empleado."<<endl;
        cout<<"-El sistema informa que: "<<ex.what()<<endl;
        enterToContinue();
        return;
        }

    do {
        system("cls");
        cout << "-Quieres la lista de Productos y servicios? (S/N): ";
        cin >> op;
        op = toupper(op);
        }
    while(op != 'S' and op != 'N');

    if(op == 'S') {
        new ProyServMenu(&myPos->getData().getProyServList());
        }
    cin.ignore();
    bar();
    cout<<"-Empleado ingresado con exito!"<<endl;
    enterToContinue();
    }

void EmpleadoMenu::deleteEmpleado() {
    std::string myStr;
    Empleado myEmpleado;
    DLNode* myPos;
    char op;
    system("cls");

    cout << "-Eliminación de Empleado" << endl<< endl;
    cout << "-Código de Empleado: ";
    getline(cin, myStr);
    myEmpleado.setEmpleadoNum(myStr);
    myPos = EmpleadoList->findData(myEmpleado);

    if(myPos == nullptr) {
        cout << "-El Empleado no se encuentra en el sistema!" << endl;
        enterToContinue();
        }
    else {
        do {
            cout << "-Empleado encontrado, está seguro de eliminarlo (S/N): ";
            cin >> op;
            cin.ignore();
            op = toupper(op);
            }
        while(op != 'S' and op != 'N');
        if(op == 'S') {
            EmpleadoList->deleteData(myPos);
            bar();
            }
        }
    }

void EmpleadoMenu::modifyEmpleado() {
    string myStr,myHour,myMinute;
    Time myTime;
    Name myName;
    Empleado myEmpleado;
    int myInt,salida;
    DLNode* myPos;
    char opc2;

    system("cls");
    cout << "-Modificando Empleado: " << endl << endl;
    cout << "-Código de Empleado: ";
    getline(cin, myStr);
    myEmpleado.setEmpleadoNum(myStr);

    myPos = EmpleadoList->findData(myEmpleado);

    if(myPos == nullptr) {
        cout << "-El Empleado no se encuentra en el sistema!"<< endl;
        }
    else {
        system("cls");
        cout << "-Empleado encontrado!" << endl<<endl;
        myPos->getData().toString();

        do {
            cout << "\n-Qué dato quieres modificar?: " << endl;
            cout << "(C)Código." << endl;
            cout << "(N)Nombre." << endl;
            cout << "(E)Especialidad." << endl;
            cout << "(U)Numero de Extensión." << endl;
            cout << "(H)Horario." << endl;
            cout << "(O)Horas Extras." << endl;
            cout << "(L)Lista de Productos y servicios."<<endl;
            cout << "(S)Salir."<<endl;
            cout << "La opción es: ";
            cin>>opc2;
            cin.ignore();
            opc2=toupper(opc2);

            switch(opc2) {
                case 'C':
                    system("cls");
                    cout << "-Nuevo Código de Empleado: ";
                    getline(cin, myStr);
                    myPos->getData().setEmpleadoNum(myStr);
                    break;
                case 'H':
                    system("cls");
                    cout << "-Nuevo Horario Empleado(HH:MM): ";
                    getline(cin, myHour, ':');
                    getline(cin, myMinute);
                    myTime.setHour(atoi(myHour.c_str()));
                    myTime.setMinute(atoi(myMinute.c_str()));
                    myPos->getData().setSchedule(myTime);
                    break;
                case 'N':
                    system("cls");
                    cout << "-Apellido: ";
                    getline(cin, myStr);
                    myName.setLast(myStr);
                    system("cls");
                    cout << "-Nombre: ";
                    getline(cin, myStr);
                    myName.setFirst(myStr);
                    myPos->getData().setName(myName);
                    break;
                case 'E':
                    system("cls");
                    cout <<"-Especialidad: " << endl << endl;
                    cout <<"-Ingresa el nombre de la especialidad:"<<endl;
                    cout <<"  +Administradores."<<endl;
                    cout <<"  +Proveedores."<<endl;
                    cout <<"  +Vendedores."<<endl;
                    cout <<"  +Jardineros."<<endl;
                    cout <<"  +Floricultores."<<endl;
                    cout <<"  +Viveristas."<<endl<<endl;
                    cout <<"-La especialidad es: ";
                    getline(cin, myStr);
                    myPos->getData().setDepart(myStr);
                    break;
                case 'O':
                    cout<<"-Horas Extras: ";
                    getline(cin,myStr);
                    myPos->getData().setHours(myStr);
                    break;
                case 'U':
                    system("cls");
                    cout << "-Número de extensión: ";
                    cin>>myInt;
                    myPos->getData().setNumExt(myInt);
                    break;
                case 'L':
                    system("cls");
                    new ProyServMenu(&myPos->getData().getProyServList());
                    bar();
                    break;
                case 'S':
                    cout << "-La opción es invalida!" << endl;
                    break;
                default:
                    cout<<"-Opción invalida, elige una opción correcta."<<endl;
                }
            }
        while(opc2!='S');
        }
    }

void EmpleadoMenu::showEmpleadoList() {
    system("cls");
    cout << "-Lista de Empleados:" << endl << endl;
    EmpleadoList ->print();
    cout << endl << endl;
    cin.ignore();
    }

void EmpleadoMenu::deleteAll() {
    system("cls");
    char op;
    int segundos=5;

    cout<<"-Está seguro que quiere Borrar todo? (S/N): "<<endl;
    cin>>op;
    if((op == 's')||(op=='S')) {
        EmpleadoList -> deleteAll();
        system("cls");
        for(int i=0; i<=21; i++)
            cout << "\n";

        cout <<"-Espera Por Favor."<<endl;
        cout <<"-Eliminando..."<<endl;
        for(int i=0; i<=79; i++)
            cout << "_";
        for(int i=0; i<=79; i++) {
            cout<<"|";
            Sleep(segundos*100/80);
            }
        cout << endl << "-Información Borrada." << endl;
        }
    else {
        cout << endl << "-Regresando al Menú Anterior.";
        }
    cin.get();
    enterToContinue();
    }

void EmpleadoMenu::sortBy() {
    char ops3;
    do {
        system("cls");
        cout <<"-Desea ordenar por: "<<endl;
        cout <<"(E)Especialidad."<<endl;
        cout <<"(N)Nombre."<<endl;
        cout <<"(S)Salir."<<endl;
        cout <<"-Elija una opción: ";
        cin>>ops3;
        ops3=toupper(ops3);

        switch(ops3) {
            case 'E':
                cin.ignore();
                cout<<"-Antes: "<<endl;
                EmpleadoList ->print();
                cout<<endl;
                EmpleadoList->sortByDepartment();
                cout<<"-Despues: "<<endl;
                EmpleadoList ->print();
                enterToContinue();
                break;
            case'N':
                cin.ignore();
                cout<<"-Antes: "<<endl;
                EmpleadoList ->print();
                cout<<endl;
                EmpleadoList->sortByName();
                cout<<"-Despues. "<<endl;
                EmpleadoList ->print();
                enterToContinue();
                break;
            case 'S':
                cout<<"-Regresando al menú Anterior..."<<endl;
                cin.ignore();
                enterToContinue();
                break;
            default:
                cout<<"-Opción no valida!"<<endl;
                enterToContinue();
            }
        }
    while(ops3!='S');
    }

void EmpleadoMenu::writeToDisk() {
    system("cls");
    cout<<"-Escribiendo en disco: "<<endl;
    bar();
    try {
        EmpleadoList->writeToDisk("FloresyJardines.txt");
        }
    catch(ListException ex) {
        }
    enterToContinue();
    }

void EmpleadoMenu::readFromDisk() {
    system("cls");
    bar();
    cout<<endl;
    cout<<"-Se ha completado la lectura desde el disco: "<<endl;
    try {
        EmpleadoList->readFromDisk("FloresyJardines.txt");
        }
    catch(ListException ex) {
        }
    enterToContinue();
    }

void EmpleadoMenu::bar() {
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

void EmpleadoMenu::enterToContinue() {
    cout << "-Presione ENTER para continuar..." << endl;
    getchar();
    }
