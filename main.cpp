#include "Tubes_Queue.h"

using namespace std;

int main()
{
    Queue Q, Q2, Q3;
    createQueue(Q);
    createQueue(Q2);
    createQueue(Q3);
    infotype x;

    x.idKegiatan = "A";
    x.namaKegiatan = "";
    x.arrivalTime = 0;
    x.burstTime = 5;
    x.turnaroundTime = 0;
    x.waitingTime = 0;
    adr P = createKegiatan(x);
    enque(Q, P);

    x.idKegiatan = "B";
    x.namaKegiatan = "";
    x.arrivalTime = 1;
    x.burstTime = 15;
    x.turnaroundTime = 0;
    x.waitingTime = 0;
    P = createKegiatan(x);
    enque(Q, P);

    x.idKegiatan = "C";
    x.namaKegiatan = "";
    x.arrivalTime = 2;
    x.burstTime = 25;
    x.turnaroundTime = 0;
    x.waitingTime = 0;
    P = createKegiatan(x);
    enque(Q, P);

    x.idKegiatan = "D";
    x.namaKegiatan = "";
    x.arrivalTime = 3;
    x.burstTime = 5;
    x.turnaroundTime = 0;
    x.waitingTime = 0;
    P = createKegiatan(x);
    enque(Q2, P);



    x.idKegiatan = "E";
    x.namaKegiatan = "";
    x.arrivalTime = 4;
    x.burstTime = 5;
    x.turnaroundTime = 0;
    x.waitingTime = 0;
    P = createKegiatan(x);
    enque(Q3, P);

    x.idKegiatan = "F";
    x.namaKegiatan = "";
    x.arrivalTime = 5;
    x.burstTime = 5;
    x.turnaroundTime = 0;
    x.waitingTime = 0;
    P = createKegiatan(x);
    enque(Q3, P);

/*
    cout << "QUEUE 1" << endl;
    printQueue(Q);
    cout << endl;


    cout << "QUEUE 2" << endl;
    printQueue(Q2);
    cout << endl;


    cout << "QUEUE 3" << endl;
    printQueue(Q3);
    cout << endl;

    deque(Q, P);
    prioUp(Q3, Q2, P);
    prioUp(Q2, Q, P);

    cout << "QUEUE 1" << endl;
    printQueue(Q);
    cout << endl;


    cout << "QUEUE 2" << endl;
    printQueue(Q2);
    cout << endl;

    cout << "QUEUE 3" << endl;
    printQueue(Q3);
    cout << endl;
*/


    int QT = 10;
    updateBurstTAT(Q, 5, QT);
    printQueue(Q);




 /*
    cout << info(P).id_pasien << endl;
    printQueue(Q);
    deque(Q, P);
    printQueue(Q);
    adr Z = P;
    cout << info(Z).id_pasien << endl;
    */


    return 0;
}
