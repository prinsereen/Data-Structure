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
    x.burstTime = 5;
    x.turnaroundTime = 0;
    x.waitingTime = 0;
    adr P = createKegiatan(x);
    enque(Q, P);

    x.idKegiatan = "B";
    x.namaKegiatan = "";
    x.burstTime = 15;
    x.turnaroundTime = 0;
    x.waitingTime = 0;
    P = createKegiatan(x);
    enque(Q, P);

    x.idKegiatan = "C";
    x.namaKegiatan = "";
    x.burstTime = 25;
    x.turnaroundTime = 0;
    x.waitingTime = 0;
    P = createKegiatan(x);
    enque(Q, P);

    x.idKegiatan = "D";
    x.namaKegiatan = "";
    x.burstTime = 5;
    x.turnaroundTime = 0;
    x.waitingTime = 0;
    P = createKegiatan(x);
    enque(Q2, P);



    x.idKegiatan = "E";
    x.namaKegiatan = "";
    x.burstTime = 15;
    x.turnaroundTime = 0;
    x.waitingTime = 0;
    P = createKegiatan(x);
    enque(Q2, P);

    x.idKegiatan = "F";
    x.namaKegiatan = "";
    x.burstTime = 5;
    x.turnaroundTime = 0;
    x.waitingTime = 0;
    P = createKegiatan(x);
    enque(Q3, P);


    progress(Q, Q2, Q3, 10, 30);


    return 0;
}
