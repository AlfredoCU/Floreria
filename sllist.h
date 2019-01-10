#ifndef SLLIST_H_INCLUDED
#define SLLIST_H_INCLUDED

#include <iostream>
#include <fstream>

#include "listexception.h"
#include "proyserv.h"
#include "slnode.h"
#include "sllist.h"

class SLList {
    private:
        SLNode* anchor;
        bool isValidPos(SLNode*&);
    public:
        SLList();
        SLList(SLList*&);
        ~SLList();
        bool isEmpty();

        void insertData(SLNode*, ProyServ&);
        void insertOrdered(ProyServ);
        void deleteData( SLNode*);
        void modifyProyServ(SLNode*);

        SLNode* getFirsPos();
        SLNode* getLastPos();
        SLNode* getPrevPos(SLNode*&);
        SLNode* getNextPos(SLNode*&);
        SLNode* findData(ProyServ&);
        ProyServ& retrieve(SLNode*);

        void print();
        void deleteAll();
        void writeToDisk(const std::string&);
        void readFromDisk(const  std::string&);
    };

#endif // SLLIST_H_INCLUDED
