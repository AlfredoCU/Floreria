#ifndef ProyServ_H_INCLUDED
#define ProyServ_H_INCLUDED

#include <iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
#include "time.h"

class ProyServ {
    private:
        int ProyServNumber;
        std::string nombre;
        std::string descripcion;
        float costo;
    public:
        ProyServ();
        ProyServ(ProyServ&);

        int  getProyServNumber();
        std::string getNombre();
        std::string getDescripcion();
        float getCosto();

        void setProyServNumber(int&);
        void setNombre(std::string&);
        void setDescripcion(std::string&);
        void setCosto(float&);
        void toString();

        bool operator != (const ProyServ&);
        bool operator >  (ProyServ&);
        bool operator == (const ProyServ&);
        bool operator <  (ProyServ&);
        bool operator <= (ProyServ&);
        bool operator >= (ProyServ&);

        friend std::ostream& operator << (std::ostream&, ProyServ&);
        friend std::istream& operator >> (std::istream&, ProyServ&);
    };
#endif // ProyServ_H_INCLUDED
