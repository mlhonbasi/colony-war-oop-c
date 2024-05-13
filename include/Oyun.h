#ifndef OYUN_H
#define OYUN_H

#include "stdio.h"
#include "stdlib.h"
#include "Koloni.h"
#include "time.h"
#include "ATaktik.h"
#include "BTaktik.h"
#include "AUretim.h"
#include "BUretim.h"
#include "math.h"


struct OYUN
{
    void (*raunt)(struct KOLONI**, int, struct OYUN*);
    void (*koloniSavaslari)(struct KOLONI**, int, struct OYUN*);
    void (*koloniSavas)(struct KOLONI*, struct KOLONI*, struct OYUN*);
    void (*koloniKontrol)(struct KOLONI*, struct KOLONI*);
    void (*koloniGuncelle)(struct KOLONI**, int);
    int (*tekKoloniKontrol)(struct KOLONI**, int);
    void (*yoket)(struct OYUN*);
}; typedef struct OYUN* Oyun;

Oyun oyunOlustur();
void Tur(Koloni*, int, const Oyun);
void koloniSavaslari(Koloni*, int, const Oyun);
void koloniSavas(Koloni, Koloni, const Oyun);
void koloniKontrol(Koloni,Koloni);
void koloniGuncelle(Koloni*, int);
int tekKoloniKontrol(Koloni*, int);
void yoketOyun(const Oyun);
#endif