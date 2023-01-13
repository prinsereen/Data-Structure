#ifndef TUBES_QUEUE_H_INCLUDED
#define TUBES_QUEUE_H_INCLUDED
#include <iostream>
#include <iomanip>
#define info(p) p->info
#define next(p) p->next
#define first(Q) ((Q).first)
#define last(Q) ((Q).last)
using namespace std;

struct kegiatan{
    string idKegiatan;
    string namaKegiatan;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
};

typedef kegiatan infotype;
typedef struct element *adr;

struct element{
    infotype info;
    adr next;
};

struct Queue{
    adr first;
    adr last;
};

adr createKegiatan(infotype x);
void createQueue(Queue &Q);
void enque(Queue &Q, adr &P);
void deque(Queue &Q, adr &P);
void printQueue(Queue Q);
void prioUp(Queue &Qx, Queue &Qy, Queue &Qz);
void progress(Queue &Qx, Queue &Qy, Queue &Qz, Queue &temp, int K, int x, float &sumTAT, float &sumWT, int &n);
void updateTATWT(Queue &Qx, Queue &Qy, Queue &Qz, int i);
void print(adr P);
void ATAT(float sumTAT, int n);
void AWT(float sumWT, int n);
void printQueue2(Queue Q);
void menu();






#endif // TUBES_QUEUE_H_INCLUDED
