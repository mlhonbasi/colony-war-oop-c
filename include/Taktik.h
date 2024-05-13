#ifndef TAKTIK_H
#define TAKTIK_H

#include "stdio.h"
#include "stdlib.h"


struct TAKTIK
{
    int (*savas)();
    void (*yoket)(struct TAKTIK*);
}; 
typedef struct TAKTIK* Taktik;

Taktik taktikOlustur();
void taktikYoket(const Taktik);

 #endif