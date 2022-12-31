#include "Tubes_Queue.h"

int main()
{
    Queue Q;
    createQueue(Q);
    infotype x;

    x.id_pasien = "MH370";
    x.nama = "EREN";
    x.umur = 75;
    x.tipe = "PARAH";
    x.burst = 23;
    x.waiting = 0;
    adr P = createPasien(x);
    enque(Q, P);
    printQueue(Q);




    x.id_pasien = "M0";
    x.nama = "N";
    x.umur = 75;
    x.tipe = "PAAH";
    x.burst = 23;
    x.waiting = 0;
    P = createPasien(x);
    enque(Q, P);
    printQueue(Q);


    //cout << info(first(Q)).id_pasien << endl;



    return 0;
}
