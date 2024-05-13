#ifndef AURETIM_H
#define AURETIM_H

#include "stdio.h"
#include "stdlib.h"
#include "Uretim.h"
#include "time.h"
#include "Koloni.h"

struct AURETIM
{
    Uretim super;    
    void (*yoket)(struct AURETIM*);
}; 
typedef struct AURETIM* AUretim;

AUretim yeniUretimA();
void yoketUretimA(const AUretim);
int UretA(const struct KOLONI*);

#endif