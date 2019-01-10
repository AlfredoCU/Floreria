#include "sllist.h"

void SLList::modifyProyServ(SLNode* p) {
    if(!isValidPos(p)) {
        throw ListException("-Posición invalida a elminar!");
        }
    if(p==anchor) {
        anchor= anchor-> getNext();
        }
    else {
        getPrevPos(p) -> setNext(p->getNext());
        }
    delete p;
    }

SLNode* SLList::getPrevPos(SLNode*& p) {
    SLNode* aux = anchor;
    while(aux != nullptr and aux->getNext() != p) {
        aux=aux->getNext();
        }
    return aux;
    }

void SLList::deleteData(SLNode* p) {
    if(!isValidPos(p)) {
        throw ListException("-Posición invalida al eliminar!");
        }
    if (p == anchor) {
        anchor = anchor->getNext();
        }
    else {
        getPrevPos(p)->setNext(p->next);
        }
    delete p;
    }

SLNode* SLList::findData(ProyServ& e) {
    SLNode* aux = anchor;
    while(aux != nullptr and aux->getData() != e) {
        aux = aux->getNext();
        }
    return aux;
    }

void SLList::deleteAll() {
    SLNode* aux;
    while(anchor != nullptr) {
        aux= anchor;
        anchor = anchor->getNext();
        delete aux;
        }
    }

SLList::~SLList() {
    deleteAll();
    }

SLList::SLList() {
    anchor =nullptr;
    }

bool SLList::isEmpty() {
    return anchor == nullptr;
    }

void SLList::print() {
    SLNode* aux = anchor;
    while(aux != nullptr) {
        aux->getData().toString() ;
        aux = aux->getNext();
        std::cout << std::endl;
        }
    }

void SLList::insertData(SLNode* p, ProyServ& e) { //Insertar despuès.
    if(p != nullptr and !isValidPos(p)) {
        throw ListException("-La posición de inserción es invalida!");
        }
    SLNode* aux = new SLNode(e);

    if(aux == nullptr) {
        throw ListException("-Memoria no disponible al insertar!");
        }
    if(p==nullptr) { //Inserción al principio.
        aux->setNext(anchor);
        anchor = aux;
        }
    else { //Inserción en medio o al final de la lista.
        aux->setNext(p -> getNext());
        p->setNext(aux);
        }
    }

bool SLList::isValidPos(SLNode*& p) {
    SLNode* aux = anchor;
    while(aux != nullptr) {
        if (aux == p) {
            return true;
            }
        aux = aux->getNext();
        }
    return false;
    }

void SLList::insertOrdered(ProyServ s) {
    SLNode* aux = anchor;
    SLNode* prev = nullptr;

    while(aux != nullptr and s > aux->getData()) {
        prev=aux;
        aux = aux->getNext();
        }
    insertData(prev, s);
    }

SLList::SLList( SLList*& l) : SLList() {
    SLNode* aux = l->anchor;
    while(aux != nullptr) {
        insertData(getLastPos(), aux->getData());
        aux = aux->getNext();
        }
    }

SLNode* SLList::getFirsPos() {
    return anchor;
    }

SLNode* SLList::getLastPos() {
    if(isEmpty()) {
        return nullptr;
        }
    SLNode* aux = anchor;
    while(aux->getNext() != nullptr) {
        aux= aux->getNext();
        }
    return aux;
    }

SLNode* SLList::getNextPos( SLNode*& p) {
    if(!isValidPos(p)) {
        return nullptr;
        }
    return p->getNext();
    }

ProyServ& SLList::retrieve( SLNode* p) {
    if(!isValidPos(p)) {
        throw ListException("-Elemento inexistente al hacer retrieve!");
        }
    return p->getData();
    }

void SLList::writeToDisk (const std::string& fileName) {
    std::ofstream myFile;
    myFile.open(fileName, myFile.trunc);
    if(!myFile.is_open()) {
        throw ListException("-No se pudo Abrir el Archivo "+ fileName + " Para escritura!");
        }
    SLNode* aux = anchor;
    while(aux!=nullptr) {
        myFile << aux->getData()<<std::endl;
        aux = aux->getNext();
        }
    myFile.close();
    }

void SLList::readFromDisk(const std::string& fileName) {
    std::ifstream myFile;
    ProyServ myProyServ;
    myFile.open(fileName);
    if(!myFile.is_open()) {
        throw ListException("-No se pudo Abrir el Archivo"+ fileName + "Para lectura!");
        }
    deleteAll();
    while(myFile>>myProyServ) {
        insertOrdered(myProyServ);
        }
    myFile.close();
    }
