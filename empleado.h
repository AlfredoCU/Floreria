#ifndef Empleado_H_INCLUDED
#define Empleado_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>

#include "proyserv.h"
#include "sllist.h"
#include "name.h"
#include "time.h"

class Empleado {
    private:
        std::string EmpleadoNum;
        Name name;
        std::string depart;
        int numExt;
        Time schedule;
        std::string hours;
        int ProyServ;
        SLList proyServList;
    public:
        Empleado();
        Empleado(const Empleado&);

        std::string getEmpleadoNum();
        Name& getName();
        std::string getDepart();
        int getNumExt();
        Time getSchedule();
        std::string getHours();
        int getProyServ();
        SLList& getProyServList();
        void toString();

        void setEmpleadoNum(const std::string&);
        void setName(const Name&);
        void setDepart(const std::string&);
        void setNumExt(const int&);
        void setSchedule (const Time&);
        void setHours (const std::string&);
        void setProyServ (const int&);
        void setProyServList(const SLList&);

        bool operator == (Empleado&);
        bool operator != (Empleado&);
        bool operator < (Empleado&);
        bool operator <= (Empleado&);
        bool operator > (Empleado&);
        bool operator >= (Empleado&);

        friend std::ostream& operator << (std::ostream&, Empleado&);
        friend std::istream& operator >> (std::istream&, Empleado&);
    };

#endif // Empleado_H_INCLUDED

