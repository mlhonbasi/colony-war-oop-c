#ifndef BURETIM_H
#define BURETIM_H

#include "stdio.h"
#include "stdlib.h"
#include "Uretim.h"
#include "Koloni.h"
#include "time.h"

struct BURETIM
{
    Uretim super;
    void (*yoket)(struct BURETIM*);
}; 
typedef struct BURETIM* BUretim;

BUretim yeniUretimB();
void yoketUretimB(const BUretim);
int UretB(const struct KOLONI*);


#endif