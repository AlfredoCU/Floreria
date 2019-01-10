#include"slnode.h"

SLNode::SLNode() {
    next = nullptr;
    }

SLNode::SLNode(ProyServ& s): SLNode() {
    data = s;
    }

ProyServ& SLNode::getData() {
    return data;
    }

SLNode* SLNode::getNext() {
    return next;
    }

void SLNode::setData(ProyServ& s) {
    data = s;
    }

void SLNode::setNext(SLNode* p) {
    next = p;
    }
