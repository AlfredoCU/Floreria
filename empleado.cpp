#include"empleado.h"

Empleado::Empleado() {
    }

Empleado::Empleado(const Empleado& a) {
    name=a.name;
    EmpleadoNum=a.EmpleadoNum;
    depart=a.depart;
    numExt=a.numExt;
    schedule=a.schedule;
    hours=a.hours;
    proyServList=a.proyServList;
    }

Name& Empleado::getName() {
    return name;
    }

std::string Empleado::getDepart() {
    return depart;
    }

int Empleado::getNumExt() {
    return numExt;
    }

Time Empleado::getSchedule() {
    return schedule;
    }

std::string Empleado::getHours() {
    return hours;
    }

SLList& Empleado::getProyServList() {
    return proyServList;
    }

std::string Empleado::getEmpleadoNum() {
    return EmpleadoNum;
    }

int Empleado::getProyServ() {
    return ProyServ;
    }

void Empleado::setProyServ(const int& c) {
    ProyServ=c;
    }

void Empleado::setName(const Name& n) {
    name=n;
    }

void Empleado::setEmpleadoNum(const std::string& an) {
    EmpleadoNum=an;
    }

void Empleado::setDepart(const std::string& d) {
    depart=d;
    }

void Empleado::setNumExt(const int& nex) {
    numExt=nex;
    }

void Empleado::setSchedule(const Time& h) {
    schedule=h;
    }

void Empleado::setHours(const std::string& he) {
    hours=he;
    }

void Empleado::setProyServList(const SLList& lc) {
    proyServList=lc;
    }

bool Empleado::operator==(Empleado& d) {
    return EmpleadoNum==d.EmpleadoNum;
    }

bool Empleado::operator!=(Empleado&d) {
    return EmpleadoNum!=d.EmpleadoNum;
    }

bool Empleado::operator<(Empleado&d) {
    return depart<d.depart;
    }

bool Empleado::operator<=(Empleado&d) {
    return depart<=d.depart;
    }

bool Empleado::operator>(Empleado&d) {
    return depart>d.depart;
    }

bool Empleado::operator>=(Empleado&d) {
    return depart>=d.depart;
    }

void Empleado::toString() {
    std::cout << "-Código: "       <<EmpleadoNum            << std::endl;
    std::cout << "-Nombre: "       <<name.toString()     << std::endl;
    std::cout << "-Especialidad: " <<depart              << std::endl;
    std::cout << "-Horario: "      <<schedule.toString() << std::endl;
    std::cout << "-Horas: "        <<hours               << std::endl;
    std::cout << "-Extensión: "    <<numExt              << std::endl;
    }

std::ostream& operator << (std::ostream&os, Empleado&s) {
    os << s.EmpleadoNum <<std::endl;
    os << s.name     <<std::endl;
    os << s.depart   <<std::endl;
    os << s.schedule <<std::endl;
    os << s.hours    <<std::endl;
    os << s.numExt;
    return os;
    }

std::istream& operator >> (std::istream&is, Empleado&s) {
    std::string strH;
    getline(is, s.EmpleadoNum);
    is >> s.name;
    getline(is, s.depart);
    is >> s.schedule;
    getline(is, s.hours);
    getline(is, strH);
    s.numExt = atoi(strH.c_str());
    return is;
    }
