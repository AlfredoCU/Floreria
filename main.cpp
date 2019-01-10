#include <locale>

#include "emplemenu.h"
#include "dllist.h"

using namespace std;

int main() {
    setlocale(LC_ALL,"spanish");
    system("color 2");
    cout<<"*******BIENVENIDO FLORERÍA Y JARDINES*******"<<endl<<endl;
    cout<<"Espere un momento por favor..."<<endl;

    for(int i=0; i<=79; i++) {
        cout<<"|";
        Sleep(20);
        }
    new EmpleadoMenu(new DLList);
    return 0;
    }
