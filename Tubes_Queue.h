#ifndef TUBES_QUEUE_H_INCLUDED
#define TUBES_QUEUE_H_INCLUDED
#include <iostream>
#define info(p) p->info
#define next(p) p->next
#define first(Q) ((Q).first)
#define last(Q) ((Q).last)

using namespace std;

struct pasien{
    string id_pasien;
    string nama;
    int umur;
    string tipe;
    int burst;
    int waiting;
};

typedef pasien infotype;
typedef struct element *adr;

struct element{
    infotype info;
    adr next;
};

struct Queue{
    adr first;
    adr last;
};

adr createPasien(infotype x);
void createQueue(Queue &Q);
void enque(Queue &Q, adr P);
void printQueue(Queue Q);




#endif // TUBES_QUEUE_H_INCLUDED
