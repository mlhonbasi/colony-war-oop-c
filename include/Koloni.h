#ifndef KOLONI_H
#define KOLONI_H

#include "stdio.h"
#include "stdlib.h"
#include "Taktik.h"

typedef enum {false, true} bool;

struct ATAKTIK;
struct BTAKTIK;
struct AURETIM;
struct BURETIM;

struct KOLONI
{
    int yemekStogu;
    int populasyon;
    int zafer;
    int yenilgi;
    int taktikSecim;
    int sembol;    
    struct ATAKTIK* taktikA;
    struct BTAKTIK* taktikB;
    struct AURETIM* uretimA;
    struct BURETIM* uretimB;
    void (*yoket)(struct KOLONI*);
    bool canlilik;
}; 
typedef struct KOLONI* Koloni;

Koloni new_Koloni(int, int);
void yoketKoloni(const Koloni);

#endif