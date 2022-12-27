#include "Tubes_Queue.h"

adr createPasien(infotype x){
    adr P = new element;

    info(P) = x;
    next(P) = NULL;

    return P;
}

void createQueue(Queue &Q){
    first(Q) = NULL;
    last(Q) = NULL;
}

void enque(Queue &Q, adr P){
    if (first(Q) == NULL) {
        first(Q) = P;
    }else {
        next(P) = first(Q);
        first(Q) = P;
    }
}
