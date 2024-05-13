#ifndef BTAKTIK_H
#define BTAKTIK_H

#include "Taktik.h"
#include "stdio.h"
#include "stdlib.h"
#include "Koloni.h"
#include "time.h"

struct BTAKTIK
{
    Taktik super;
    void (*yoket)(struct BTAKTIK*);
};
typedef struct BTAKTIK* BTaktik;

BTaktik yeniTaktikB();
void yoketTaktikB(const BTaktik);
int savas(const struct KOLONI*);

#endif