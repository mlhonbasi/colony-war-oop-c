/*
* @file         Test.c
* @description  Programın başlatılması.
* @course       2.Öğretim 2-A
* @assignment   Programa Dillerinin Prensibi 2.Ödev
* @date         8 Mayıs 2023
* @author       Melih Onbaşı - melih.onbasi@ogr.sakarya.edu.tr
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Koloni.h"
#include "Taktik.h"
#include "ATaktik.h"
#include "AUretim.h"
#include "Oyun.h"
#include "Uretim.h"

int main()
{
    system("cls");
    srand(time(NULL));

    int boyut = 50;

    //Girilen ifadeleri char dizisine alma işlemi.
    char* sayilarChar = malloc(boyut*sizeof(char));
    int k = 0;
    char c;
    printf("Sayilari girin: ");
    while ((c = getchar()) != '\n')
    {
        sayilarChar[k] = c;
        k++;
        if (k == boyut) {
            boyut *= 2;
            sayilarChar = realloc(sayilarChar, boyut * sizeof(char));
        }
    }
    sayilarChar[k] = '\0';

    char* token = strtok(sayilarChar," "); //Girilen ifadeyi bosluklara gore ayırma.
    
    boyut = 50;
    int koloniSayisi = 0;

    int* sayilar = malloc(boyut*sizeof(int)); //Sayıların tutulacagı dizi

    while (token != NULL) //Chardan alınan ifadelerin ayrıstırılıp int dizisine aktarılması.
    {
        int sayi = atoi(token);
        if(koloniSayisi == boyut)
        {
            boyut*= 2;
            sayilar = realloc(sayilar, boyut * sizeof(int));
        }       
        sayilar[koloniSayisi] = sayi;
        koloniSayisi++;
        token = strtok(NULL, " ");
    } 

    int kullanilanSembol[254] = {0}; //Sembol dizisi
    for(int z = 0; z < 254 ; z++) //Bosluk olan sembollerin isaretlenmesi.
    {
        if(isspace(z))
            kullanilanSembol[z] = 1;
    }
    kullanilanSembol[0] = 1; kullanilanSembol[8] = 1;
        
    Koloni* koloniler = (Koloni*)malloc(koloniSayisi * sizeof(struct KOLONI)); //Koloni dizisi için yer alınması.

    for(int i = 0; i < koloniSayisi; i++) //Kolonileri olusturan dongu
    {
        koloniler[i] = new_Koloni(sayilar[i], rand()%2); //Koloni kurucusu
        int tekilSembol;
        do
        {
            tekilSembol = rand() % 256 + 32;
            char k = (char)tekilSembol;
            koloniler[i]->sembol = tekilSembol; //Koloniye sembolunun verilmesi.                             
        } while (kullanilanSembol[tekilSembol]);
        kullanilanSembol[tekilSembol] = 1;   
    }

    Oyun oyun = oyunOlustur(); //Oyun olusturulması.

    oyun->raunt(koloniler, koloniSayisi, oyun); //Oyun tur fonksiyonu cagrimi.
    
    //Bellekten alınan alanların geri verilmesi.
    for(int d = 0; d < koloniSayisi; d++)
    {
        koloniler[d]->yoket(koloniler[d]);
    }
    oyun->yoket(oyun);
    free(sayilarChar);
    free(sayilar);
    return 0;
}
