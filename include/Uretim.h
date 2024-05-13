#ifndef URETIM_H
#define URETIM_H

#include "stdio.h"
#include "stdlib.h"

struct URETIM
{
    int (*Uret)();
    void (*yoket)(struct URETIM*);
};
typedef struct URETIM* Uretim;

Uretim uretimOlustur();
void uretimYoket(const Uretim);

 #endif