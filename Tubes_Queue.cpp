#include "Tubes_Queue.h"

adr createKegiatan(infotype x){
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
        last(Q) = P;
    }else {
        adr Z = last(Q);
        last(Q) = P;
        next(Z) = P;
    }
}

void deque(Queue &Q, adr P){
    if (first(Q) == last(Q)){
        first(Q) = NULL;
        last(Q) = NULL;
    }else {
        P = first(Q);
        first(Q) = next(P);
        next(P) == NULL;
    }
}

void printQueue(Queue Q){
    if (first(Q) == NULL) {
        cout << "Antrian Kosong !" << endl;
    }else {
        adr P = first(Q);
        while (P != last(Q)){
            cout << "ID Kegiatan : " << info(P).idKegiatan << endl;
            cout << "Nama Kegiatan : " << info(P).namaKegiatan << endl;
            cout << "Burst Time Kegiatan : " << info(P).burstTime << endl;
            cout << "Waktu Tunggu Kegiatan : " << info(P).waitingTime << endl;
            cout << "TAT Kegiatan : " << info(P).turnaroundTime << endl;

            P = next(P);
            cout << endl;
        }
        cout << "ID Kegiatan : " << info(P).idKegiatan << endl;
        cout << "Nama Kegiatan : " << info(P).namaKegiatan << endl;
        cout << "Burst Time Kegiatan : " << info(P).burstTime << endl;
        cout << "Waktu Tunggu Kegiatan : " << info(P).waitingTime << endl;
        cout << "TAT Kegiatan : " << info(P).turnaroundTime << endl;
    }
}


void prioUp(Queue &Qx, Queue &Qy, adr P){
    //deque
    if (first(Qx) == last(Qx)){
        P = first(Qx);
        first(Qx) = NULL;
        last(Qx) = NULL;
    }else {
        P = first(Qx);
        first(Qx) = next(P);
        next(P) == NULL;
    }
    //Enque
    if (first(Qy) == NULL) {
        first(Qy) = P;
        last(Qy) = P;
    }else {
        adr Z = last(Qy);
        last(Qy) = P;
        next(Z) = P;
    }
}


void updateBurstTAT(Queue &Q, int T, int &QT){
    adr P = first(Q);
    while (P != NULL){
        info(P).turnaroundTime = T;
        P = next(P);
    }
    P = first(Q);
    while (T > 0 && P != NULL){
        if (info(P).burstTime - QT > 0){
            info(P).burstTime = info(P).burstTime - QT;
            T = T-QT;
        }else{
            T = T- info(P).burstTime;
            info(P).burstTime = 0;
            deque(Q, P);
        }
        P = next(P);
    }
}
