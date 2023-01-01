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

void deque(Queue &Q, adr P){
    if (first(Q) == last(Q)){
        first(Q) = NULL;
        last(Q) = NULL;
    }else {
        P = last(Q);
        adr beforeLast = first(Q);
        while (next(beforeLast) != last(Q)){
            beforeLast = next(beforeLast);
        }
        last(Q) = beforeLast;
        next(beforeLast) = NULL;
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


bool isFullQ1(Queue Q1){
    int sum = 0;

    adr P = first(Q1);
    sum += 1;
    while (next(P) != last(Q1)){
        sum += 1;
        P = next(P);
    }
    return (sum == 2);
}

bool isFullQ2(Queue Q2){
    int sum = 0;

    adr P = first(Q2);
    sum += 1;
    while (next(P) != last(Q2)){
        sum += 1;
        P = next(P);
    }
    return (sum == 10);
}


void dequeEnque(Queue &Qx, Queue &Qy, adr P){
    //Deque
    cout << "tes 1" << endl;
    P = last(Qx);
    cout << "tes 2" << endl;
    adr beforeLast = first(Qx);
    cout << "tes 3" << endl;
    while (next(beforeLast) != last(Qx)){
        cout << "tes 4" << endl;
        beforeLast = next(beforeLast);
        cout << "tes 5" << endl;
    }
    last(Qx) = beforeLast;
    cout << "tes 6" << endl;
    next(beforeLast) = NULL;
    cout << "tes 7" << endl;
    //Enque
    if (first(Qy) == NULL) {
        cout << "tes 8" << endl;
        first(Qy) = P;
    }else {
        cout << "tes 9" << endl;
        next(last(Qx)) = first(Qy);
        cout << "tes 10" << endl;
        first(Qy) = last(Qx);
    }

}

