/*
* @file         Taktik.c
* @description  Kalıtım yapılacak ebevyn sınıf Taktik oluşturulması.
* @course       2.Öğretim 2-A
* @assignment   Programa Dillerinin Prensibi 2.Ödev
* @date         19 Mayıs 2023
* @author       Melih Onbaşı - melih.onbasi@ogr.sakarya.edu.tr
*/

#include "Taktik.h"

Taktik taktikOlustur()
{
    //Bellekten alan alma ve fonksiyonların göstericileri tanımlama.
    Taktik this;
    this = (Taktik)malloc(sizeof(struct TAKTIK));
    this->yoket = &taktikYoket;
    return this;
}

void taktikYoket(const Taktik this) //Taktik yokedicisi
{
	if(this == NULL) return;
	free(this);
}
