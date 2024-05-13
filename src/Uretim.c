/*
* @file         Uretim.c
* @description  Kalıtım yapılacak ebeveyn sınıf Uretim olusturulması.
* @course       2.Öğretim 2-A
* @assignment   Programa Dillerinin Prensibi 2.Ödev
* @date         8 Mayıs 2023
* @author       Melih Onbaşı - melih.onbasi@ogr.sakarya.edu.tr
*/

#include "Uretim.h"

Uretim uretimOlustur()
{
    //Bellekten alan alma ve fonksiyonların göstericileri tanımlama.
    Uretim this;
    this = (Uretim)malloc(sizeof(struct URETIM));
    this->yoket = &uretimYoket;
    return this;
}

void uretimYoket(const Uretim this) //Uretim yokedicisi.
{
    if(this == NULL) return;
    free(this);
}
