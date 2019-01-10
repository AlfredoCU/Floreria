#ifndef EmpleadoMenu_H_INCLUDED
#define EmpleadoMenu_H_INCLUDED

#include <windows.h>
#include <string>

#include "empleado.h"
#include "dllist.h"
#include "name.h"
#include "time.h"

class EmpleadoMenu {
    private:
        DLList* EmpleadoList;
    public:
        EmpleadoMenu(DLList*);//Todas las interfaces van aqui//
        void mainMenu();
        void insertEmpleado();
        void modifyEmpleado();
        void deleteEmpleado();
        void deleteAll();
        void showEmpleadoList();
        void sortBy();
        void writeToDisk();
        void readFromDisk();
        void bar();
        void enterToContinue();
    };

#endif // EmpleadoMenu_H_INCLUDED
