#ifndef ProyServMenu_H_INCLUDED
#define ProyServMenu_H_INCLUDED

#include <windows.h>
#include <string>

#include "proyserv.h"
#include "sllist.h"
#include "slnode.h"
#include "time.h"

class ProyServMenu {
    private:
        void mainMenu();
        void insertProyServ();
        void deleteProyServ();
        void modifyProyServ();
        void showProyServList();
        void deleteAll();
        void enterToContinue();
        void writeDisk();
        void readDisk();
        void bar2();
        SLList* ProyServList;
    public:
        ProyServMenu(SLList*); //Todas las interfaces van aquí.
    };

#endif // ProyServMenu_H_INCLUDED
