#include "Tubes_Queue.h"

adr createPasien(string id_pasien, string nama, int umur, string tipe, int burst, int waiting){
    adr P = new element;

    info(P).id_pasien = id_pasien;
    info(P).nama = nama;
    info(P).umur = umur;
    info(P).tipe = tipe;
    info(P).burst = burst;
    info(P).waiting = waiting;
    next(P) = NULL;

    return P;
}

void createQueue(Queue &Q){
    first(Q) = NULL;
    last(Q) = NULL;
}
