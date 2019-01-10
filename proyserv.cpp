#include"proyserv.h"

ProyServ::ProyServ() {
    }

ProyServ::ProyServ(ProyServ& s) {
    ProyServNumber = s.ProyServNumber;
    nombre = s.nombre;
    descripcion = s.descripcion;
    costo = s.costo;
    }

int ProyServ::getProyServNumber() {
    return ProyServNumber;
    }

std::string ProyServ::getNombre() {
    return nombre;
    }

std::string ProyServ::getDescripcion() {
    return descripcion;
    }

float ProyServ::getCosto() {
    return costo;
    }

void ProyServ::setProyServNumber(int& n) {
    ProyServNumber = n;
    }

void ProyServ::setNombre(std::string& no) {
    nombre = no;
    }

void ProyServ::setDescripcion(std::string& d) {
    descripcion = d;
    }

void ProyServ::setCosto(float& c) {
    costo = c;
    }

void ProyServ::toString() {
    std::cout << "-Número de Producto y Servicio: "         <<ProyServNumber  << std::endl;
    std::cout << "-Nombre de Producto y Servicio: "         <<nombre          << std::endl;
    std::cout << "-Descripción de Producto y Servicio: "    <<descripcion     << std::endl;
    std::cout << "-Costo de Producto y Servicio: "          <<costo           << std::endl;
    }

bool ProyServ::operator > (ProyServ& s) {
    return nombre > s.nombre;
    }

bool ProyServ::operator == (const ProyServ& s) {
    return ProyServNumber == s.ProyServNumber;
    }

bool ProyServ::operator != (const ProyServ& s) {
    return ProyServNumber != s.ProyServNumber;
    }

bool ProyServ::operator < (ProyServ& s) {
    return nombre < s.nombre;
    }

bool ProyServ::operator>=(ProyServ& s) {
    return nombre >= s.nombre;
    }

bool ProyServ::operator <= (ProyServ& s) {
    return nombre <= s.nombre;
    }

std::ostream& operator << (std::ostream& os, ProyServ& c) {
    os << c.ProyServNumber <<std::endl;
    os << c.nombre       <<std::endl;
    os << c.descripcion  <<std::endl;
    os << c.costo;
    return os;
    }

std::istream& operator >> (std::istream& is, ProyServ& c) {

    std::string strC;
    getline(is, strC);
    c.ProyServNumber = atoi(strC.c_str());
    getline(is, c.nombre);
    getline(is, c.descripcion);
    is >> c.costo;
    return is;
    }
