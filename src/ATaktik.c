/*
* @file         ATaktik.c
* @description  Taktikten kalıtım alan ATaktik sınıfı.
* @course       2.Öğretim 2-A
* @assignment   Programa Dillerinin Prensibi 2.Ödev
* @date         8 Mayıs 2023
* @author       Melih Onbaşı - melih.onbasi@ogr.sakarya.edu.tr
*/

#include "ATaktik.h"

ATaktik yeniTaktikA() //ATaktik struct tanımlama (Kurucu fonksiyon).
{
    //Bellekten alan alma ve fonksiyonların göstericileri tanımlama.
    ATaktik this;
    this = (ATaktik)malloc(sizeof(struct ATAKTIK)); 
    this->super = taktikOlustur();
    this->super->savas = &Savas;
    this->yoket = &yoketTaktikA;
    return this;
}

int Savas(const struct KOLONI* koloni) //0-1000 deger ureten Savas fonksiyonu.
{
    srand(time(NULL));

    int rastgeleDeger = rand() % 1000;
    int sonuc = (koloni->populasyon * rastgeleDeger)%1000;   
    return sonuc;
}

void yoketTaktikA(const ATaktik this) //ATaktik yokedici.
{ 
	if(this == NULL) return;
	this->super->yoket(this->super);
	free(this);
}

