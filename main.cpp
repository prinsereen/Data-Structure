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



    return 0;
}
