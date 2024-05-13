/*
* @file         Koloni.c
* @description  Koloni sınıfının oluşturulması.
* @course       2.Öğretim 2-A
* @assignment   Programa Dillerinin Prensibi 2.Ödev
* @date         8 Mayıs 2023
* @author       Melih Onbaşı - melih.onbasi@ogr.sakarya.edu.tr
*/

#include "Koloni.h"
#include "ATaktik.h"
#include "BTaktik.h"
#include "AUretim.h"
#include "BUretim.h"

Koloni new_Koloni(int populasyon, int taktik) //Koloni struct tanımlama(Kurucu fonksiyon).
{
    //Bellekten alan alma ve fonksiyonların göstericileri tanımlama.
    Koloni this;
    this = (Koloni)malloc(sizeof(struct KOLONI));
    this->populasyon = populasyon;
    this->yemekStogu = populasyon*populasyon;
    this->zafer = 0;
    this->yenilgi = 0;
    this->yoket = &yoketKoloni;
    this->canlilik = true;
    
    if(taktik == 0)
    {
        this->taktikA = yeniTaktikA();
        this->uretimA = yeniUretimA();
        this->taktikSecim = 0;
    }
    else
    {
        this->uretimB = yeniUretimB();
        this->taktikB = yeniTaktikB();
        this->taktikSecim = 1;
    }   
}

void yoketKoloni(const Koloni this) //Koloni yokedicisi
{
    if(this == NULL) return;
    if(this->taktikSecim == 0) //Once icindeki diger structları yok eder. 
    {
        this->taktikA->yoket(this->taktikA);
        this->uretimA->yoket(this->uretimA);
    }
    else
    {
        this->taktikB->yoket(this->taktikB); 
        this->uretimB->yoket(this->uretimB);
    }
   
    free(this);
}
