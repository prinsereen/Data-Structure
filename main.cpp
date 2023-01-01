#include "Tubes_Queue.h"

using namespace std;

int main()
{
    Queue Q, Q2, Q3;
    createQueue(Q);
    createQueue(Q2);
    createQueue(Q3);
    infotype x;

    x.id_pasien = "MH370";
    x.nama = "EREN";
    x.umur = 1;
    x.tipe = "PARAH";
    x.burst = 23;
    x.waiting = 0;
    adr P = createPasien(x);
    enque(Q, P);

    x.id_pasien = "M0";
    x.nama = "N";
    x.umur = 2;
    x.tipe = "PAAH";
    x.burst = 23;
    x.waiting = 0;
    P = createPasien(x);
    enque(Q, P);

    x.id_pasien = "MH370";
    x.nama = "EREN";
    x.umur = 3;
    x.tipe = "PARAH";
    x.burst = 23;
    x.waiting = 0;
    P = createPasien(x);
    enque(Q2, P);

    x.id_pasien = "M0";
    x.nama = "N";
    x.umur = 4;
    x.tipe = "PAAH";
    x.burst = 23;
    x.waiting = 0;
    P = createPasien(x);
    enque(Q2, P);



    x.id_pasien = "MH370";
    x.nama = "EREN";
    x.umur = 5;
    x.tipe = "PARAH";
    x.burst = 23;
    x.waiting = 0;
    P = createPasien(x);
    enque(Q3, P);

    x.id_pasien = "M0";
    x.nama = "N";
    x.umur = 6;
    x.tipe = "PAAH";
    x.burst = 23;
    x.waiting = 0;
    P = createPasien(x);
    enque(Q3, P);


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
    dequeEnque(Q3, Q2, P);
    dequeEnque(Q2, Q, P);

    cout << "QUEUE 1" << endl;
    printQueue(Q);
    cout << endl;


    cout << "QUEUE 2" << endl;
    printQueue(Q2);
    cout << endl;

    cout << "QUEUE 3" << endl;
    printQueue(Q3);
    cout << endl;




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
