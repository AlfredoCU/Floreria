#include "dlnode.h"

DLNode::DLNode() {
    prev = next = nullptr;
    dataPtr = nullptr;
    }

DLNode::DLNode(Empleado& s):DLNode() {
    dataPtr = new Empleado(s);
    if(dataPtr == nullptr) {
        throw NodeException("-Memoria no disponible al inicializar nodo.");
        }
    }

Empleado* DLNode::getDataPtr() {
    return dataPtr;
    }

Empleado& DLNode::getData() {
    return *dataPtr;
    }

DLNode* DLNode::getPrev() {
    return prev;
    }

DLNode* DLNode::getNext() {
    return next;
    }

void DLNode::setDataPtr(Empleado* p) {
    dataPtr = p;
    }

void DLNode::setData(Empleado& s) {
    if(dataPtr == nullptr) {
        dataPtr = new Empleado(s);
        }
    if(dataPtr == nullptr) {
        throw NodeException("-Memoria no disponible al inicializar nodo.");
        }
    else {
        *dataPtr = s;
        }
    }

void DLNode::setPrev(DLNode* p) {
    prev = p;
    }

void DLNode::setNext(DLNode* n) {
    next = n;
    }

void DLNode::writeToDisk(std::string&) {
    }

void DLNode::readFromDisk(std::string&) {
    }
