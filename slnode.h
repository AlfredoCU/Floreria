#ifndef SLNODE_H_INCLUDED
#define SLNODE_H_INCLUDED

#include "ProyServ.h"

class SLNode {
    private:
        ProyServ data;
    public:
        SLNode();
        SLNode(ProyServ&);
        SLNode*next;

        ProyServ& getData();
        SLNode* getNext();

        void setData(ProyServ&);
        void setNext(SLNode*);
    };

#endif // SLNODE_H_INCLUDED
