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

        adr z = first(Q);
        while(next(z) != NULL){
            z = next(z);
        }
        last(Q) = P;
        next(z) = last(Q);
    }
}

void deque(Queue &Q, adr &P){
    P = first(Q);
    if (first(Q) == last(Q)){
        first(Q) = NULL;
        last(Q) = NULL;
    }else {
        first(Q) = next(P);
        next(P) = NULL;
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
    while(first(Qy) != NULL){
        deque(Qy, P);
        enque(Qx, P);
    }

    adr Q;
    while(first(Qz) != NULL){
        deque(Qz, Q);
        enque(Qy, Q);
    }
}

void updateSubTATWT(Queue &Q, int i){
    adr A = first(Q);

    while(A != NULL){
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

void progress(Queue &Qx, Queue &Qy, Queue &Qz, int K, int x){
    int T, i, n;
    float sumTAT, sumWT;

    sumTAT = 0;
    sumWT = 0;
    n = 0;

    while(first(Qx) != NULL){
        adr p;
        deque(Qx, p);

        if (info(p).burstTime <= K){

            T += info(p).burstTime;
            info(p).turnaroundTime += info(p).burstTime;
            i = info(p).burstTime;
            updateTATWT(Qx, Qy, Qz, i);
            info(p).burstTime = 0;
            print(p);

            sumTAT += info(p).turnaroundTime;
            sumWT += info(p).waitingTime;
            n++;

            cout << "TIME : "<< T << endl;
            cout<<endl;

        }else if(info(p).burstTime > K){
            info(p).burstTime -= K;
            T += K ;
            info(p).turnaroundTime += K;
            i = K;
            updateTATWT(Qx, Qy, Qz, i);
            enque(Qx, p);
        }
        if (T % x == 0){
            prioUp(Qx, Qy, Qz);
        }
    }

    cout << "Rata - Rata Turnaround Time : " << rerata(sumTAT, n) << endl;
    cout << "Rata - Rata Waiting Time : " << rerata(sumWT, n) << endl;

}

void print(adr P){
    cout << "ID Kegiatan : " << info(P).idKegiatan << endl;
    cout << "Nama Kegiatan : " << info(P).namaKegiatan << endl;
    cout << "Waktu Tunggu Kegiatan : " << info(P).waitingTime << endl;
    cout << "TAT Kegiatan : " << info(P).turnaroundTime << endl;

}

float rerata(float sum, int n){
    return sum/n;
}
