/**
* @file Proje1.c
* @description Bu projenin amacı, yapılar(struct), işaretçiler(pointers) ve
dinamik bellek ve dosyalama işlemlerini kullanarak bir şirketin birim ve çalışan bilgilerini
 yönetmek için bir veri yapısı oluşturmak ve bu verileri işlemek amacıyla çeşitli fonksiyonlar geliştirmektir.
* @assignment Lab dersi 1.ödev
* @date 24/12/2024
* @author Taha Selim Çağman - tahaselim.cagman@stu.fsm.edu.tr
*/



#include "Proje1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Birim oluşturma fonksiyonu
Birim birimOlustur(const char *birimAdi, unsigned short int birimKodu) {
    Birim yeniBirim;

    // Dinamik bellek ayırma
    yeniBirim.birimAdi = (char *)malloc(30 * sizeof(char));
    if (!yeniBirim.birimAdi) {
        fprintf(stderr, "Hata: Bellek tahsisi basarisiz. (birimAdi).\n");
        exit(1);
    }
    strncpy(yeniBirim.birimAdi, birimAdi, 30);

    yeniBirim.birimKodu = birimKodu;

    yeniBirim.birimCalisanlar = (Calisan *)malloc(20 * sizeof(Calisan));
    if (!yeniBirim.birimCalisanlar) {
        fprintf(stderr, "Hata: Bellek tahsisi basarisiz. (birimCalisanlar).\n");
        free(yeniBirim.birimAdi);
        exit(1);
    }

    
    for (int i = 0; i < 20; i++) {
        yeniBirim.birimCalisanlar[i].calisanAdi = NULL;
        yeniBirim.birimCalisanlar[i].calisanSoyadi = NULL;
    }

    return yeniBirim;
}

// Çalışan oluşturma fonksiyonu
Calisan calisanOlustur(const char *calisanAdi, const char *calisanSoyadi, unsigned short int birimKodu, float maas, int girisYili) {
    Calisan yeniCalisan;

    // Dinamik bellek ayırma
    yeniCalisan.calisanAdi = (char *)malloc(30 * sizeof(char));
    if (!yeniCalisan.calisanAdi) {
        fprintf(stderr, "Hata: Bellek tahsisi başarısız (calisanAdi).\n");
        exit(1);
    }
    strncpy(yeniCalisan.calisanAdi, calisanAdi, 30);
    
    yeniCalisan.calisanSoyadi = (char *)malloc(30 * sizeof(char));
    if (!yeniCalisan.calisanSoyadi) {
        fprintf(stderr, "Hata: Bellek tahsisi başarısız (calisanSoyadi).\n");
        free(yeniCalisan.calisanAdi);
        exit(1);
    }
    strncpy(yeniCalisan.calisanSoyadi, calisanSoyadi, 30);

    yeniCalisan.birimKodu = birimKodu;
    yeniCalisan.maas = maas;
    yeniCalisan.girisYili = girisYili;

    return yeniCalisan;
}

// Birime çalışan ekleme fonksiyonu
int birimeCalisanEkle(Birim *birim, const Calisan *calisan, int mevcutCalisanSayisi) {
    if (mevcutCalisanSayisi >= 20) {
        fprintf(stderr, "Hata: Birime daha fazla çalışan eklenemez. Maksimum kapasiteye ulaşıldı.\n");
        return -1; // Hata durumu
    }

    // Yeni çalışanı birimCalisanlar dizisine ekle
    birim->birimCalisanlar[mevcutCalisanSayisi] = *calisan;
    return mevcutCalisanSayisi + 1; // Yeni çalışan sayısını döndür
}

// Birim dizisine yeni birim ekleme fonksiyonu
int birimDizisineEkle(Birim *birimDizisi, const Birim *yeniBirim, int mevcutBirimSayisi, int maxBirimSayisi) {
    if (mevcutBirimSayisi >= maxBirimSayisi) {
        fprintf(stderr, "Hata:Maksimum kapasiteye ulasildi.\n");
        return -1; // Hata durumu
    }

    // Yeni birimi diziye ekle
    birimDizisi[mevcutBirimSayisi] = *yeniBirim;
    return mevcutBirimSayisi + 1; // Yeni birim sayısını döndür
}
// Çalışan bilgilerini yazdırma fonksiyonu
void calisanYazdir(const Calisan *calisan) {
    printf("Calisan Adi: %s\n", calisan->calisanAdi);
    printf("Calisan Soyadi: %s\n", calisan->calisanSoyadi);
    printf("Birim Kodu: %hu\n", calisan->birimKodu);
    printf("Maas: %.2f\n", calisan->maas);
    printf("Giris Yili: %d\n", calisan->girisYili);
}

// Birim bilgilerini yazdırma fonksiyonu
void birimYazdir(const Birim *birim) {
    printf("Birim Adi: %s\n", birim->birimAdi);
    printf("Birim Kodu: %hu\n", birim->birimKodu);

    // Birime kayıtlı çalışanları yazdırma
    printf("Calisanlar:\n");
    for (int i = 0; i < 20; i++) {
        // Çalışan adı ve soyadı yazdırılır.
        if (birim->birimCalisanlar[i].calisanAdi && birim->birimCalisanlar[i].calisanSoyadi) {
            printf("  %s %s\n", birim->birimCalisanlar[i].calisanAdi, birim->birimCalisanlar[i].calisanSoyadi);
        }
    }
}

void birimDiziYazdir(Birim *birimDizisi, int diziBoyutu) {
    for (int i = 0; i < diziBoyutu; i++) {
        printf("Birim %d:\n", i + 1);
        printf("Birim Adi: %s\n", birimDizisi[i].birimAdi);
        printf("Birim Kodu: %hu\n", birimDizisi[i].birimKodu);

        // Çalışanları yazdırma
        printf("Calisanlar:\n");
        for (int j = 0; j < 20; j++) {
            if (birimDizisi[i].birimCalisanlar[j].calisanAdi != NULL && birimDizisi[i].birimCalisanlar[j].calisanSoyadi != NULL) {
                printf("  %s %s\n", birimDizisi[i].birimCalisanlar[j].calisanAdi, birimDizisi[i].birimCalisanlar[j].calisanSoyadi);
            }
        }
        printf("\n");
    }
}

// Her bir birim için maaş ortalamasını hesaplayan fonksiyon
float ortalamaMaasHesapla(const Birim *birim) {
    float toplamMaas = 0.0f;
    int calisanSayisi = 0;

    // Birimin çalışanlarını kontrol et
    for (int i = 0; i < 20; i++) {
        // Çalışanların maaşını topla
        if (birim->birimCalisanlar[i].calisanAdi != NULL && birim->birimCalisanlar[i].calisanSoyadi != NULL) {
            toplamMaas += birim->birimCalisanlar[i].maas;
            calisanSayisi++;
        }
    }

    // Eğer hiç çalışan yoksa, ortalama maaşı 0 döndür
    if (calisanSayisi == 0) {
        return 0.0f;
    }

    // Maaş ortalamasını hesapla ve döndür
    return toplamMaas / calisanSayisi;
}

void ortalamaUstuCalısan(const Birim *birim) {
    // Üstteki fonksiyonda bulunan ortalama maaşı döndür
    float ortalamaMaas = ortalamaMaasHesapla(birim);
    printf("Ortalama maas: %.2f\n", ortalamaMaas);

    printf("Ortalama maas uzerinde maas alan calisanlar:\n");

    for (int i = 0; i < 20; i++) {
        if (birim->birimCalisanlar[i].calisanAdi != NULL && birim->birimCalisanlar[i].maas > ortalamaMaas) {
            printf("  %s %s - Maas: %.2f\n", birim->birimCalisanlar[i].calisanAdi, 
                                             birim->birimCalisanlar[i].calisanSoyadi, 
                                             birim->birimCalisanlar[i].maas);
        }
    }
}

void enYuksekMaasli(const Birim *birim) {
    float enYuksekMaas = -1.0f;
    Calisan enYuksekMaasAlaniCalisan;

    // Birimdeki her bir çalışanın maaşını kontrol et
    for (int i = 0; i < 20; i++) {
        if (birim->birimCalisanlar[i].calisanAdi != NULL && birim->birimCalisanlar[i].maas > enYuksekMaas) {
            enYuksekMaas = birim->birimCalisanlar[i].maas;
            enYuksekMaasAlaniCalisan = birim->birimCalisanlar[i];
        }
    }

    // En yüksek maaşa sahip çalışanı yazdır
    if (enYuksekMaas > -1.0f) {
        printf("Birim: %s\n", birim->birimAdi);
        printf("En yuksek maasli calisan: %s %s - Maas: %.2f\n", 
                enYuksekMaasAlaniCalisan.calisanAdi, 
                enYuksekMaasAlaniCalisan.calisanSoyadi, 
                enYuksekMaasAlaniCalisan.maas);
    } else {
        printf("Bu birimde calisan bulunamadi.\n");
    }
}

void maasGuncelle(const Birim *birim, float yeniMaas) {
    for (int i = 0; i < 20; i++) {
        // Çalışanın bilgilerini kontrol et
        if (birim->birimCalisanlar[i].calisanAdi != NULL && 
            birim->birimCalisanlar[i].calisanSoyadi != NULL) {

            // Eğer çalışan 10 yıldan fazla süre çalışıyorsa maaşı yeni maaştan düşükse
            if (birim->birimCalisanlar[i].girisYili <= 2014 && 
                birim->birimCalisanlar[i].maas < yeniMaas) {
                
                // Çalışanın eski maaşını yazdır
                printf("Calisan %s %s'nin maasi guncelleniyor: %.2f -> %.2f\n", 
                       birim->birimCalisanlar[i].calisanAdi, 
                       birim->birimCalisanlar[i].calisanSoyadi, 
                       birim->birimCalisanlar[i].maas, 
                       yeniMaas);
                
                // Maaşı güncelle
                birim->birimCalisanlar[i].maas = yeniMaas;
            }

            // Güncellenmiş maaşla çalışan bilgilerini yazdır
            printf("Calisan: %s %s, Maas: %.2f, Giris Yili: %d\n", 
                   birim->birimCalisanlar[i].calisanAdi,
                   birim->birimCalisanlar[i].calisanSoyadi,
                   birim->birimCalisanlar[i].maas,
                   birim->birimCalisanlar[i].girisYili);
        }
    }
}

void birimiDosyayaYazdir(Birim *birimDizisi, int birimSayisi, const char *dosyaAdi) {
    FILE *dosya = fopen(dosyaAdi, "a"); // Dosyayı ekleme modunda aç
    if (dosya == NULL) {
        perror("Dosya açılamadı");
        return;
    }

    for (int i = 0; i < birimSayisi; i++) {
        // Birim bilgilerini yaz
        fprintf(dosya, "Birim Adı: %s, Birim Kodu: %u\n", birimDizisi[i].birimAdi, birimDizisi[i].birimKodu);
    }

    fclose(dosya);
}

void calisaniDosyayaYazdir(Birim *birim, int calisanSayisi, const char *dosyaAdi) {
    FILE *dosya = fopen(dosyaAdi, "a"); // Dosyayı ekleme modunda aç
    if (dosya == NULL) {
        perror("Dosya açılamadı");
        return;
    }

   
    for (int i = 0; i < calisanSayisi+2; i++) {
        Calisan *calisan = &birim->birimCalisanlar[i];

        // Verilerin geçerliliğini kontrol et
        if (calisan->calisanAdi == NULL || calisan->calisanSoyadi == NULL) {
            fprintf(stderr, "\n");
            continue; // Hatalı çalışan bilgilerini atla
        }

        // Dosyaya yaz
        fprintf(dosya, "Çalışan Adı: %s %s, Birim Kodu: %u, Maaş: %.2f, Giriş Yılı: %d\n",
                calisan->calisanAdi,
                calisan->calisanSoyadi,
                calisan->birimKodu,
                calisan->maas,
                calisan->girisYili);
    }

    fclose(dosya);
}

void bellekTemizle(Birim *birimDizisi, int mevcutBirimSayisi) {
    // Birimler için bellek temizleme
    for (int i = 0; i < mevcutBirimSayisi; i++) {
        // Birim adı ve çalışanlar için bellek temizleme
        free(birimDizisi[i].birimAdi);
        free(birimDizisi[i].birimCalisanlar);
    }
}
// diziyeAktar fonksiyonunda birim kontrolü yapması için tanımladığım fonksiyon
int birimVarMi(Birim *birimDizisi, int mevcutBirimSayisi, int birimKodu) {
    for (int i = 0; i < mevcutBirimSayisi; i++) {
        if (birimDizisi[i].birimKodu == birimKodu) {
            return 1; // Birim zaten var
        }
    }
    return 0; // Birim yok
}

int diziyeAktar(Birim *birimDizisi, int *mevcutBirimSayisi, int *mevcutCalisanSayisi, const char *birimDosyasi, const char *calisanDosyasi) {
    FILE *birimFile = fopen(birimDosyasi, "r");
    FILE *calisanFile = fopen(calisanDosyasi, "r");

    if (birimFile == NULL || calisanFile == NULL) {
        return -1; // Dosya açılamadı
    }

    // Birimler dosyasından okuma
    char birimAdi[30];
    int birimKodu;
    while (fscanf(birimFile, "%s %d", birimAdi, &birimKodu) != EOF) {
        // Birim zaten eklendiyse ekleme
        if (!birimVarMi(birimDizisi, *mevcutBirimSayisi, birimKodu)) {
            Birim yeniBirim = birimOlustur(birimAdi, birimKodu);
            birimDizisineEkle(birimDizisi, &yeniBirim, *mevcutBirimSayisi, 5);
        }
    }

    // Çalışanlar dosyasından okuma
    char calisanAdi[30], calisanSoyadi[30];
    int calisanBirimKodu, calisanYili;
    float calisanMaas;
    while (fscanf(calisanFile, "%s %s %d %f %d", calisanAdi, calisanSoyadi, &calisanBirimKodu, &calisanMaas, &calisanYili) != EOF) {
        Calisan yeniCalisan = calisanOlustur(calisanAdi, calisanSoyadi, calisanBirimKodu, calisanMaas, calisanYili);
        // Çalışanı doğru birime ekleme
        for (int i = 0; i < *mevcutBirimSayisi; i++) {
            if (birimDizisi[i].birimKodu == calisanBirimKodu) {
                birimeCalisanEkle(&birimDizisi[i], &yeniCalisan, *mevcutCalisanSayisi);
                (*mevcutCalisanSayisi)++;
            }
        }
    }

    fclose(birimFile);
    fclose(calisanFile);

    return 0;
}





