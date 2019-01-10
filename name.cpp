#include "name.h"

Name::Name() {
    last = "";
    first = "";
    }

Name::Name(Name& n) {
    last = n.last;
    first = n.first;
    }

Name::Name(std::string l, std::string f) {
    last = l;
    first = f;
    }

std::string Name::getLast() {
    return last;
    }

std::string Name::getFirst() {
    return first;
    }

void Name::setLast(std::string l) {
    last = l;
    }

void Name::setFirst(std::string f) {
    first = f;
    }

bool Name::operator == (Name& n) {
    return toString() == n.toString();
    }

bool Name::operator != (Name& n) {
    return toString() != n.toString();
    }

bool Name::operator <= (Name& n) {
    return toString() <= n.toString();
    }

bool Name::operator >= (Name& n) {
    return toString() >= n.toString();
    }

bool Name::operator < (Name& n) {
    return toString() < n.toString();
    }

bool Name::operator > (Name& n) {
    return toString() > n.toString();
    }

std::string Name::toString() {
    return last + ", " + first;
    }

std::ostream& operator << (std::ostream&os, Name& n) {
    os << n.last;
    os << ",";
    os << n.first;
    return os;
    }

std::istream& operator >> (std::istream&is, Name& n) {
    getline(is, n.last,',');
    getline(is, n.first);
    return is;
    }
