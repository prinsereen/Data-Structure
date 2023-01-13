#include "Tubes_Queue.h"

using namespace std;

int main()
{
    int isiQ1, isiQ2, isiQ3, mn;
    adr P;
    infotype x;

    float sumTat = 0;
    float sumWT = 0;
    int n = 0;

    Queue Q, Q2, Q3, Q4;
    createQueue(Q);
    createQueue(Q2);
    createQueue(Q3);
    createQueue(Q4);

    menu();
    cin >> mn;
    while (mn != 6){
        if (mn == 1){
            cout << "Berapa Kegiatan yang Ingin Anda Inputkan pada Q1 : ";
            cin >> isiQ1;
            for (int i = 0; i < isiQ1; i ++){
                cout << "Masukan ID Kegiatan : ";
                cin >> x.idKegiatan;
                cout << "Masukan Nama Kegiatan : ";
                cin >> x.namaKegiatan;
                cout << "Burst Time Kegiatan : ";
                cin >> x.burstTime;
                x.turnaroundTime = 0;
                x.waitingTime = 0;
                cout << endl;

                P = createKegiatan(x);
                enque(Q, P);
            }
            cout << endl;
            cout << "Berapa Kegiatan yang Ingin Anda Inputkan pada Q2 : ";
            cin >> isiQ2;
            for (int i = 0; i < isiQ2; i ++){
                cout << "Masukan ID Kegiatan : ";
                cin >> x.idKegiatan;
                cout << "Masukan Nama Kegiatan : ";
                cin >> x.namaKegiatan;
                cout << "Burst Time Kegiatan : ";
                cin >> x.burstTime;
                x.turnaroundTime = 0;
                x.waitingTime = 0;
                cout << endl;

                P = createKegiatan(x);
                enque(Q2, P);
            }
            cout << endl;
            cout << "Berapa Kegiatan yang Ingin Anda Inputkan pada Q3 : ";
            cin >> isiQ3;
            for (int i = 0; i < isiQ3; i ++){
                cout << "Masukan ID Kegiatan : ";
                cin >> x.idKegiatan;
                cout << "Masukan Nama Kegiatan : ";
                cin >> x.namaKegiatan;
                cout << "Burst Time Kegiatan : ";
                cin >> x.burstTime;
                x.turnaroundTime = 0;
                x.waitingTime = 0;
                cout << endl;

                P = createKegiatan(x);
                enque(Q3, P);
            }
        }else if (mn == 2){
            cout << endl;
            cout << "Queue 1" << endl;
            printQueue2(Q);
            cout << endl;
            cout << "Queue 2" << endl;
            printQueue2(Q2);
            cout << endl;
            cout << "Queue 3" << endl;
            printQueue2(Q3);
        }else if (mn == 3){
            progress(Q, Q2, Q3, Q4, 10, 30, sumTat, sumWT, n);
        }else if (mn == 4){
            cout << endl;
            ATAT(sumTat, n);
        }else if (mn == 5){
            cout << endl;
            AWT(sumWT, n);
        }else {
            cout << "Inputan Tidak Valid !" << endl;
        }
        cout << endl;
        cout << endl;
        menu();
        cin >> mn;
    }
    cout << "SELESAI !1!"<<endl;



     /*
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



    ATAT(sumTat, n);
    AWT(sumWT, n);
    */



    return 0;
}
