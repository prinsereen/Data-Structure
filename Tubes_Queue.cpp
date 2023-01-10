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

void enque(Queue &Q, adr &P){
    if (first(Q) == NULL) {
        first(Q) = P;
        last(Q) = P;
    }else {
        adr Z = last(Q);
        last(Q) = P;
        next(Z) = P;
    }
}

void deque(Queue &Q, adr &P){
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


void prioUp(Queue &Qx, Queue &Qy, Queue &Qz){
    adr P;
    deque(Qy, P);
    enque(Qx, P);
    adr Q;
    deque(Qz, Q);
    enque(Qy, Q);
}


void progress(Queue &Qx, Queue &Qy, Queue &Qz, int K, int x){
    int T, i;

    adr e = first(Qx);
    adr p;
    //cout << 1 << endl;
    while(e != NULL){
        //cout << 2 << endl;

        deque(Qx, p);
        //cout << 3 << endl;
        if (info(p).burstTime <= K){
            //cout << 4 << endl;
            T += info(p).burstTime;
            //cout << info(p).idKegiatan << endl;
            info(p).turnaroundTime += info(p).burstTime;
            //cout << 6 << endl;
            i = info(p).burstTime;
            //cout << 7 << endl;
            updateTATWT(Qx, Qy, Qz, i);
            info(p).burstTime = 0;
            //cout << 8 << endl;
            print(p);
            //cout << 9 << endl;
            cout << "TIME : "<< T << endl;

            //cout << 10 << endl;
        }else if(info(p).burstTime > K){
            //cout << 11 << endl;
            info(p).burstTime -= K;
            T += K ;
            //cout << 12 << endl;
            info(p).turnaroundTime += info(p).burstTime;
            //cout << info(p).idKegiatan << endl;
            //cout << info(p).burstTime << endl;
            //cout << 13 << endl;
            i = K;
            //cout << 14 << endl;
            updateTATWT(Qx, Qy, Qz, i);
            //cout << 15 << endl;
            enque(Qx, p);
            //cout << 16 << endl;
        }
        if (T % x == 0){
            prioUp(Qx, Qy, Qz);
        }
        i = 0;
    }
}

void updateSubTATWT(Queue &Q, int i){
    adr A = first(Q);

    while(A != last(Q)){
        info(A).waitingTime += i;
        info(A).turnaroundTime += i;
        A = next(A);
    }
}

void updateTATWT(Queue &Qx, Queue &Qy, Queue &Qz, int i){
    updateSubTATWT(Qx, i);
    updateSubTATWT(Qy, i);
    updateSubTATWT(Qz, i);
}

void print(adr P){
    cout << "ID Kegiatan : " << info(P).idKegiatan << endl;
    cout << "Nama Kegiatan : " << info(P).namaKegiatan << endl;
    cout << "Burst Time Kegiatan : " << info(P).burstTime << endl;
    cout << "Waktu Tunggu Kegiatan : " << info(P).waitingTime << endl;
    cout << "TAT Kegiatan : " << info(P).turnaroundTime << endl;
}
