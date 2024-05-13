/*
* @file         Oyun.c
* @description  Oyun sınıfının oluşturulması.
* @course       2.Öğretim 2-A
* @assignment   Programa Dillerinin Prensibi 2.Ödev
* @date         8 Mayıs 2023
* @author       Melih Onbaşı - melih.onbasi@ogr.sakarya.edu.tr
*/

#include "Oyun.h"

Oyun oyunOlustur() //Oyun struct tanımlama(Kurucu fonksiyonu)
{
    //Bellekten alan alma ve fonksiyonların göstericileri tanımlama.
    Oyun this;
    this = (Oyun)malloc(sizeof(struct OYUN));
    this->koloniSavaslari = &koloniSavaslari;
    this->koloniSavas = &koloniSavas;
    this->koloniKontrol = &koloniKontrol;
    this->koloniGuncelle = &koloniGuncelle;
    this->raunt = &Tur;
    this->yoket = &yoketOyun;
    this->tekKoloniKontrol = &tekKoloniKontrol;
}

void Tur(Koloni* koloniDizisi, int koloniSayisi, const Oyun this) //Oyunun tur yapısını kontrol eden fonksiyon.
{
    int tur = 0;
    int sonKoloni = 0;

    while(sonKoloni == 0) //Son koloni kalıncaya dek döngü devam eder.
    {       
        printf("\nTur Sayisi: %d \n", tur); //Kolonilerin durumlarının yazdırılması
        printf("%-10s %-15s %-20s %-15s %-15s\n", "Koloni", "Populasyon", "Yemek Stogu", "Kazanma", "Kaybetme");
        for (int a = 0; a < koloniSayisi; a++)
        {       
            if(koloniDizisi[a]->canlilik == true)
                printf("%3c %13d %18d %16d %15d\n",koloniDizisi[a]->sembol, koloniDizisi[a]->populasyon, koloniDizisi[a]->yemekStogu, koloniDizisi[a]->zafer, koloniDizisi[a]->yenilgi);
            else
                printf("%3c %13s %18s %16s %15s\n",koloniDizisi[a]->sembol, "  ---", "  ---", "  ---", "  ---");
        }
        printf("\n------------------------------------------------------------------------\n");
        
        this->koloniSavaslari(koloniDizisi, koloniSayisi, this); //Kolonilerin savaşı.
        this->koloniGuncelle(koloniDizisi, koloniSayisi);   //Kolonilerin turdan sonra güncellenmesi
        sonKoloni = this->tekKoloniKontrol(koloniDizisi, koloniSayisi); //Tek koloni kalıp kalmadığının kontrolu.
        if(sonKoloni == 1)
        {
            printf("\nTur Sayisi: %d \n", tur+1);
            printf("%-10s %-15s %-20s %-15s %-15s\n", "Koloni", "Populasyon", "Yemek Stogu", "Kazanma", "Kaybetme");
            for (int a = 0; a < koloniSayisi; a++)
            {       
                if(koloniDizisi[a]->canlilik == true)
                    printf("%3c %13d %18d %16d %15d\n", koloniDizisi[a]->sembol, koloniDizisi[a]->populasyon, koloniDizisi[a]->yemekStogu, koloniDizisi[a]->zafer, koloniDizisi[a]->yenilgi);
                else
                    printf("%3c %13s %18s %16s %15s\n", koloniDizisi[a]->sembol, "  ---", "  ---", "  ---", "  ---");
            }
        printf("\n-------------------------------------------------------------------------\n");
        }
        tur++;
    }
      
}

void koloniSavaslari(Koloni* koloniler, int koloniSayisi, const Oyun this) //Bütün kolonileri teker teker savaştırma fonksiyonu.
{
    for(int i = 0; i < koloniSayisi - 1; i++)
    {
        for(int j = i + 1; j < koloniSayisi; j++)
        {
            if(koloniler[i]->canlilik == true && koloniler[j]->canlilik == true)
            {               
                this->koloniSavas(koloniler[i],koloniler[j], this); //Secilen ikili savasma fonksiyonuna gonderilir.
            }
        }
    }
}

void koloniSavas(Koloni koloni1, Koloni koloni2, const Oyun this) //Secilen ikilinin belirtilen kosullara gore savasma fonksiyonu.
{

    int koloni1guc = 0; 
    int koloni2guc = 0;
    int gucFarki = 0;
    int gucOran = 0;

    if(koloni1->taktikSecim == 0 && koloni2->taktikSecim == 0)
    {
        koloni1guc = koloni1->taktikA->super->savas();
        koloni2guc = koloni2->taktikA->super->savas();      
    }
    else if(koloni1->taktikSecim == 0 && koloni2->taktikSecim == 1)
    {
        koloni1guc = koloni1->taktikA->super->savas();
        koloni2guc = koloni2->taktikB->super->savas();
    }
    else if(koloni1->taktikSecim == 1 && koloni2->taktikSecim == 0)
    {
        koloni1guc = koloni1->taktikB->super->savas();
        koloni2guc = koloni2->taktikA->super->savas();
    }
    else
    {
        koloni1guc = koloni1->taktikB->super->savas();
        koloni2guc = koloni2->taktikB->super->savas();
    }

    gucFarki = abs(koloni1guc - koloni2guc);
    gucOran = (gucFarki / 1000) * 100;

    if(koloni1guc > koloni2guc) //Birinci koloni kazanması halinde
    {
        koloni2->populasyon -= ((koloni2->populasyon * gucOran) / 100);
        koloni1->yemekStogu += ((koloni2->yemekStogu * gucOran) / 100);
        koloni2->yemekStogu -= ((koloni2->yemekStogu * gucOran) / 100);
        koloni1->zafer += 1;
        koloni2->yenilgi += 1;
    }
    else if(koloni2guc > koloni1guc) //Ikinci koloni kazanması halinde
    {
        koloni1->populasyon -= ((koloni1->populasyon * gucOran) / 100);
        koloni2->yemekStogu += ((koloni1->yemekStogu * gucOran) / 100);
        koloni1->yemekStogu -= ((koloni1->yemekStogu * gucOran) / 100);
        koloni2->zafer += 1;
        koloni1->yenilgi += 1;
    }
    else
    {
        if(koloni1->populasyon > koloni2->populasyon)
        {
            koloni2->populasyon -= ((koloni2->populasyon * gucOran) / 100);
            koloni1->yemekStogu += ((koloni2->yemekStogu * gucOran) / 100);
            koloni2->yemekStogu -= ((koloni2->yemekStogu * gucOran) / 100);
            koloni1->zafer += 1;
            koloni2->yenilgi += 1;
        }
        else if(koloni2->populasyon > koloni1->populasyon)
        {
            koloni1->populasyon -= ((koloni1->populasyon * gucOran) / 100);
            koloni2->yemekStogu += ((koloni1->yemekStogu * gucOran) / 100);
            koloni1->yemekStogu -= ((koloni1->yemekStogu * gucOran) / 100);
            koloni2->zafer += 1;
            koloni1->yenilgi += 1;
        }
        else
        {
            int kazanan = rand () % 2 ;

            if(kazanan == 1)
            {
                koloni2->populasyon -= ((koloni2->populasyon * gucOran) / 100);
                koloni1->yemekStogu += ((koloni2->yemekStogu * gucOran) / 100);
                koloni2->yemekStogu -= ((koloni2->yemekStogu * gucOran) / 100);
                koloni1->zafer += 1;
                koloni2->yenilgi += 1;
            }
            else
            {
                koloni1->populasyon -= ((koloni1->populasyon * gucOran) / 100);
                koloni2->yemekStogu += ((koloni1->yemekStogu * gucOran) / 100);
                koloni1->yemekStogu -= ((koloni1->yemekStogu * gucOran) / 100);
                koloni2->zafer += 1;
                koloni1->yenilgi += 1;
            }
        }
        
    }
    this->koloniKontrol(koloni1,koloni2); 
}

void koloniKontrol(Koloni k1, Koloni k2) //Savas bittikten sonra kolonilerın canlılık kontrolu.
{
    int ikisi = 0;
    if(k1->populasyon <= 0 || k1->yemekStogu <= 0)
    {
        k1->canlilik = false;
        ikisi+=1;
    }
       
    if(k2->populasyon <= 0 || k2->yemekStogu <= 0)
    {
        k2->canlilik = false;
        ikisi+=1;
    }
    if(ikisi == 2)
    {
        if(k1->populasyon > k2->populasyon)
        {
            k1->canlilik = true;
            k2->canlilik = false;
        }
        else if(k2->populasyon > k1->populasyon)
        {
            k2->canlilik = true;
            k1->canlilik = false;
        }
        else
        {
            if(k1->yemekStogu > k2->yemekStogu)
            {
                k1->canlilik = true;
                k2->canlilik = false;
            }
            else if(k2->yemekStogu > k1->yemekStogu)
            {
                k2->canlilik = true;
                k1->canlilik = false;
            }
            else
            {
                k1->canlilik = false;
                k2->canlilik = false;
            }
        }
    }      
}

void koloniGuncelle(Koloni* kolonis, int sayi) //Belirtilenlere gore kolonilerin turdan tura guncellenmeleri.
{
    int i = 0;

    for(i = 0; i < sayi; i++)
    {
        if(kolonis[i]->canlilik == true)
        {
            int rnd = rand() % 2;
            if(kolonis[i]->taktikSecim == 0)
            {
                kolonis[i]->yemekStogu += kolonis[i]->uretimA->super->Uret();
            }
            else
            {
                kolonis[i]->yemekStogu += kolonis[i]->uretimB->super->Uret(); 
            }  
            kolonis[i]->populasyon += (kolonis[i]->populasyon * 20) / 100;
            kolonis[i]->yemekStogu -= (kolonis[i]->populasyon * 2);      
        }
    }
}

int tekKoloniKontrol(Koloni* k, int koloniAdet) //Tek koloni olup olmadıgının kontrolu
{
    int sayi = 0;

    for(int i = 0; i < koloniAdet; i++)
    {
        if(k[i]->canlilik == false)
            sayi++;
    }

    if(sayi == koloniAdet - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

void yoketOyun(const Oyun this) //Oyun yokedicisi
{
    if(this == NULL) return;
	free(this);
}