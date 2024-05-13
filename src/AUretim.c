/*
* @file         AUretim.c
* @description  Uretimden kalıtım alan AUretim sınıfı.
* @course       2.Öğretim 2-A
* @assignment   Programa Dillerinin Prensibi 2.Ödev
* @date         8 Mayıs 2023
* @author       Melih Onbaşı - melih.onbasi@ogr.sakarya.edu.tr
*/

#include "AUretim.h"

AUretim yeniUretimA() //AUretim struct tanımlama (Kurucu fonksiyon).
{
    //Bellekten alan alma ve fonksiyonların göstericileri tanımlama.
    AUretim this;
    this = (AUretim)malloc(sizeof(struct AURETIM));
    this->super = uretimOlustur();
    this->super->Uret = &UretA;
    this->yoket = &yoketUretimA;
    return this;
}


int UretA(const struct KOLONI* koloni) // 0-10 deger donduren uretim fonksiyonu.
{
    srand(time(NULL));

    int rastgeleDeger = rand() % 10;
    int sonuc = (koloni->populasyon * koloni->yemekStogu * rastgeleDeger)%10;
    return sonuc;
}

void yoketUretimA(const AUretim this) //AUretim yokedicisi.
{
	if(this == NULL) return;
	this->super->yoket(this->super);
	free(this);
}