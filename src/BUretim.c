/*
* @file         BUretim.c
* @description  Uretimden kalıtım alan BUretim sınıfı sınıfı.
* @course       2.Öğretim 2-A
* @assignment   Programa Dillerinin Prensibi 2.Ödev
* @date         8 Mayıs 2023
* @author       Melih Onbaşı - melih.onbasi@ogr.sakarya.edu.tr
*/

#include "Buretim.h"

BUretim yeniUretimB() //BUretim struct tanımlama(Kurucu fonksiyonu)
{
    //Bellekten alan alma ve fonksiyonların göstericileri tanımlama.
    BUretim this;
    this = (BUretim)malloc(sizeof(struct BURETIM));
    this->super = uretimOlustur();
    this->super->Uret = &UretB;
    this->yoket = &yoketUretimB;
    return this;
}


int UretB(const struct KOLONI* koloni) //0-10 arası deger donduren uretim fonksiyonu.
{
    
    srand(time(NULL));

    int rastgeleDeger = rand() % 10;
    int sonuc = ((koloni->populasyon+koloni->yemekStogu) * rastgeleDeger)%10;
    return sonuc;
}

void yoketUretimB(const BUretim this) //BUretim yokedicisi.
{
    if(this == NULL) return;
	this->super->yoket(this->super);
	free(this);
}
