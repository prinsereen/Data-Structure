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
        cout << setw(9) << "id kegiatan  " <<setw(11) << "namaKegiatan  " <<setw(13)<<setw(11) << "Burst Time  " <<setw(13) << "Waiting Time  " <<setw(13) << "turn around Time" << endl;
        while (P != NULL){
            cout << setw(9) << info(P).idKegiatan
            <<setw(11) << info(P).namaKegiatan
            <<setw(13) << info(P).burstTime
            <<setw(13) << info(P).waitingTime
            <<setw(13) << info(P).turnaroundTime <<endl;
            P = next(P);
        }
    }
}

void printQueue2(Queue Q){
    if (first(Q) == NULL) {
        cout << "Antrian Kosong !" << endl;
    }else {
        adr P = first(Q);
        while (P != last(Q)){
            cout << "ID Kegiatan : " << info(P).idKegiatan <<endl;
            cout << "Nama Kegiatan : " << info(P).namaKegiatan <<endl;
            cout << "Burst Time Kegiatan : " << info(P).burstTime <<endl;
            cout << "Waktu Tunggu Kegiatan : " << info(P).waitingTime <<endl;
            cout << "TAT Kegiatan : " << info(P).turnaroundTime << endl;

            P = next(P);
            cout << endl;
        }
        cout << "ID Kegiatan : " << info(P).idKegiatan <<endl;
        cout << "Nama Kegiatan : " << info(P).namaKegiatan <<endl;
        cout << "Burst Time Kegiatan : " << info(P).burstTime <<endl;
        cout << "Waktu Tunggu Kegiatan : " << info(P).waitingTime <<endl;
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

void progress(Queue &Qx, Queue &Qy, Queue &Qz, Queue &temp, int K, int x, float &sumTAT, float &sumWT, int &n){
    int T, i;


    while(first(Qx) != NULL){
        adr p;
        deque(Qx, p);

        if (info(p).burstTime <= K){

            T += info(p).burstTime;
            info(p).turnaroundTime += info(p).burstTime;
            i = info(p).burstTime;
            updateTATWT(Qx, Qy, Qz, i);
            info(p).burstTime = 0;
            enque(temp, p);

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
        cout<<"Q1"<<endl;
        printQueue(Qx);
        cout<<endl;
        cout<<"Q2"<<endl;
        printQueue(Qy);
        cout<<endl;
        cout<<"Q3"<<endl;
        printQueue(Qz);
    }
    printQueue2(temp);
}

void print(adr P){
    cout << "ID Kegiatan : " << info(P).idKegiatan << endl;
    cout << "Nama Kegiatan : " << info(P).namaKegiatan << endl;
    cout << "Waktu Tunggu Kegiatan : " << info(P).waitingTime << endl;
    cout << "TAT Kegiatan : " << info(P).turnaroundTime << endl;

}

void ATAT(float sumTAT, int n){
    float rerata = sumTAT/n;

    cout << "Average Turnaround Time adalah : " << rerata << endl;
}

void AWT(float sumWT, int n){
    float rerata = sumWT/n;

    cout << "Average Waiting Time adalah : " << rerata << endl;
}

void menu(){
    cout
    << "========================MENU QUEUE ROUND ROBIN========================\n"
    << "[1] Input Queue\n"
    << "[2] Tampilkan Seluruh Queue\n"
    << "[3] Proses\n"
    << "[4] Tampilkan Average TAT\n"
    << "[5] Tampilkan Average WT\n"
    << "[6] Keluar\n"
    << "Pilih Menu: ";
}
