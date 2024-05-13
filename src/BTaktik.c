/*
* @file         BTaktik.c
* @description  Taktikten kalıtım alan BTaktik sınıfı.
* @course       2.Öğretim 2-A
* @assignment   Programa Dillerinin Prensibi 2.Ödev
* @date         8 Mayıs 2023
* @author       Melih Onbaşı - melih.onbasi@ogr.sakarya.edu.tr
*/

#include "BTaktik.h"

BTaktik yeniTaktikB() //BTaktik struct tanımlama (Kurucu fonksiyonu)
{
    //Bellekten alan alma ve fonksiyonların göstericileri tanımlama.
    BTaktik this;
    this = (BTaktik)malloc(sizeof(struct BTAKTIK));
    this->super = taktikOlustur();
    this->super->savas = &savas;
    this->yoket = &yoketTaktikB;
    return this;

}

void yoketTaktikB(const BTaktik this) //BTaktik yokedicisi
{
	if(this == NULL) return;
	this->super->yoket(this->super);
	free(this);
}

int savas(const struct KOLONI* koloni) //0-1000 deger donduren savas fonksiyonu.
{
    srand(time(NULL));

    int rastgeleDeger = rand() % 1000;
    int guc = ((koloni->yemekStogu + koloni->yemekStogu*koloni->populasyon)*rastgeleDeger)%1000;
    return guc;
}