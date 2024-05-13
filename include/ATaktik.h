#ifndef ATAKTIK_H
#define ATAKTIK_H

#include "Taktik.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "Koloni.h"

struct TAKTIK;

struct ATAKTIK
{
    struct TAKTIK* super;
    void (*yoket)(struct ATAKTIK*);
}; 
typedef struct ATAKTIK* ATaktik;

ATaktik yeniTaktikA();
void yoketTaktikA(const ATaktik);
int Savas(const struct KOLONI*);

#endif