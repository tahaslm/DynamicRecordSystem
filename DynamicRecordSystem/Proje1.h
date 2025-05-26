/**
* @file Proje1.h
* @description Bu projenin amacı, yapılar(struct), işaretçiler(pointers) ve
dinamik bellek ve dosyalama işlemlerini kullanarak bir şirketin birim ve çalışan bilgilerini
 yönetmek için bir veri yapısı oluşturmak ve bu verileri işlemek amacıyla çeşitli fonksiyonlar geliştirmektir.
* @assignment Lab dersi 1.ödev
* @date 24/12/2024
* @author Taha Selim Çağman - tahaselim.cagman@stu.fsm.edu.tr
*/



#ifndef PROJE1_H
#define PROJE1_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Çalışan yapısı
typedef struct {
    char *calisanAdi;
    char *calisanSoyadi;
    unsigned short int birimKodu;
    float maas;
    int girisYili;
} Calisan;

// Birim yapısı 
typedef struct {
    char *birimAdi;
    unsigned short int birimKodu;
    Calisan *birimCalisanlar;
} Birim;


Birim birimOlustur(const char *birimAdi, unsigned short int birimKodu);
Calisan calisanOlustur(const char *calisanAdi, const char *calisanSoyadi, unsigned short int birimKodu, float maas, int girisYili);
int birimeCalisanEkle(Birim *birim, const Calisan *calisan, int mevcutCalisanSayisi);
int birimDizisineEkle(Birim *birimDizisi, const Birim *yeniBirim, int mevcutBirimSayisi, int maxBirimSayisi);
void calisanYazdir(const Calisan *calisan);
void birimYazdir(const Birim *birim);
void birimDiziYazdir(Birim *birimDizisi, int diziBoyutu);
float ortalamaMaasHesapla(const Birim *birim);
void ortalamaUstuCalısan(const Birim *birim);
void enYuksekMaasli(const Birim *birim);
void maasGuncelle(const Birim *birim, float maas);
void bellekTemizle(Birim *birimDizisi, int mevcutBirimSayisi);
void birimiDosyayaYazdir(Birim *birimDizisi, int birimSayisi, const char *dosyaAdi);
void calisaniDosyayaYazdir(Birim *birim, int calisanSayisi, const char *dosyaAdi);
int diziyeAktar(Birim *birimDizisi, int *mevcutBirimSayisi, int *mevcutCalisanSayisi, const char *birimDosyasi, const char *calisanDosyasi);
int birimVarMi(Birim *birimDizisi, int mevcutBirimSayisi, int birimKodu);

#endif
