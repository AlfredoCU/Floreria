#ifndef DLNODE_H_INCLUDED
#define DLNODE_H_INCLUDED

#include "nodeexception.h"
#include "empleado.h"

class DLNode {
    private:
        Empleado* dataPtr;
        DLNode* prev;
        DLNode* next;
    public:
        DLNode();
        DLNode(Empleado&);

        Empleado* getDataPtr();
        Empleado& getData();
        DLNode* getNext();
        DLNode* getPrev();

        void setDataPtr(Empleado*);
        void setData(Empleado&);
        void setNext(DLNode*);
        void setPrev(DLNode*);

        void writeToDisk(std::string&);
        void readFromDisk(std::string&);
    };

#endif // DLNODE_H_INCLUDED
