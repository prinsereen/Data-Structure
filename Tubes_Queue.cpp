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

void printQueue(Queue Q){
    if (first(Q) == NULL) {
        cout << "Antrian Kosong !" << endl;
    }else {
        adr P = first(Q);
        while (P != last(Q)){
            cout << "ID Pasien : " << info(P).id_pasien << endl;
            cout << "Nama Pasien : " << info(P).nama << endl;
            cout << "Umur Pasien : " << info(P).umur << endl;
            cout << "Tipe Pasien : " << info(P).tipe << endl;
            cout << "Burst Pasien : " << info(P).burst << endl;
            cout << "Waktu Tunggu Pasien : " << info(P).waiting << endl;

            P = next(P);
            cout << endl;
        }
    }
}
