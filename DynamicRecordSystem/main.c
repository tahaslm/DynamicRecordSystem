/**
* @file main.c
* @description Bu projenin amacı, yapılar(struct), işaretçiler(pointers) ve
dinamik bellek ve dosyalama işlemlerini kullanarak bir şirketin birim ve çalışan bilgilerini
 yönetmek için bir veri yapısı oluşturmak ve bu verileri işlemek amacıyla çeşitli fonksiyonlar geliştirmektir.
* @assignment Lab dersi 1.ödev
* @date 24/12/2024
* @author Taha Selim Çağman - tahaselim.cagman@stu.fsm.edu.tr
*/







#include "Proje1.h"

int main() {

    // Birim dizisinin oluşturulması;
    Birim birimDizisi[2];  
    int mevcutBirimSayisi = 0;

    // Birimlerin oluşturulma kısmı
    Birim hukuk = birimOlustur("Hukuk", 101);
    Birim pazarlama = birimOlustur("Pazarlama", 102);

    // Birimleri Birim dizisine ekleme
    mevcutBirimSayisi = birimDizisineEkle(birimDizisi, &hukuk, mevcutBirimSayisi, 5);
    mevcutBirimSayisi = birimDizisineEkle(birimDizisi, &pazarlama, mevcutBirimSayisi, 5);

    // Çalışanların oluşturulması
    Calisan arda = calisanOlustur("Arda", "Ozturk", 101, 6800.0f, 2020);
    Calisan hale = calisanOlustur("Hale", "Karaman", 101, 4500.0f, 2009);
    Calisan mehmet = calisanOlustur("Mehmet", "Zorlu", 102, 3500.0f, 2023);
    Calisan emre = calisanOlustur("Emre", "Tan", 102, 5700.0f, 2016);
    // Çalışanların birimlere eklenmesi
    int mevcutCalisanSayisi = 0;
    mevcutCalisanSayisi = birimeCalisanEkle(&hukuk, &arda, mevcutCalisanSayisi);
    mevcutCalisanSayisi = birimeCalisanEkle(&hukuk, &hale, mevcutCalisanSayisi);
    mevcutCalisanSayisi = birimeCalisanEkle(&pazarlama, &mehmet, mevcutCalisanSayisi);
    mevcutCalisanSayisi = birimeCalisanEkle(&pazarlama, &emre, mevcutCalisanSayisi);

    // Çalışan bilgilerini yazdırma
    printf("Calisan Bilgileri:\n");
    calisanYazdir(&arda);
    calisanYazdir(&hale);
    calisanYazdir(&mehmet);
    calisanYazdir(&emre);

    // Birim bilgilerini yazdırma
    printf("\nBirim Bilgileri:\n");
    birimYazdir(&hukuk);
    birimYazdir(&pazarlama);

    // Birim dizisini yazdırma
    printf("\nBirim Dizisi Bilgileri:\n");
    birimDiziYazdir(birimDizisi, mevcutBirimSayisi);


    // Birimlerin ortalama maaşlarının hesaplanması  
      float muhasebeMaasOrtalamasi = ortalamaMaasHesapla(&hukuk);
printf("Hukuk biriminin maas ortalamasi: %.2f\n", muhasebeMaasOrtalamasi);

     float pazarlamaMaas = ortalamaMaasHesapla(&pazarlama);
  printf("Pazarlama biriminin maas ortalamasi: %.2f\n", pazarlamaMaas);   


  //Her bir birimde ortalama maaşın üzerinde kazanan çalışanların yazdırılması
ortalamaUstuCalısan(&hukuk);
ortalamaUstuCalısan(&pazarlama);


    // Her bir birimdeki en yüksek maaşlı çalışanı yazdırma
    enYuksekMaasli(&hukuk);
    enYuksekMaasli(&pazarlama);

    // Birimlerde şartlara uyan çalışanların maaşının güncellenmesi
    printf("\nMaas guncelleniyor..\n");
    maasGuncelle(&hukuk, 5500.0f);
    maasGuncelle(&pazarlama, 6500.0f);

    //Birimlerin bilgilerinin dosyaya yazdırılması
Birim x[] = {hukuk, pazarlama};
birimiDosyayaYazdir(x, 2, "birimler.txt");
printf("Birimler dosyaya aktarildi.\n");


    //Çalışan bilgilerinin dosyaya yazdırılması
calisaniDosyayaYazdir(&hukuk, 2, "calisanlar.txt");
calisaniDosyayaYazdir(&pazarlama, 2, "calisanlar.txt");
printf("Calisanlar dosyaya aktarildi.\n");

// Dosyadaki birim ve çalışan bilgilerinin diziye aktarılması

Birim b[5];  
int mbs = 0;
int mcs = 0;

    if (diziyeAktar(b, &mbs, &mcs, "birimler.txt", "calisanlar.txt") != 0) {
        fprintf(stderr, "Dosyalar okunamadi.\n");
        return 1;
    }

    
    printf("Birimler ve Calisanlar Diziye Aktarildi:\n");
    birimDiziYazdir(birimDizisi, mevcutBirimSayisi);


// Bellek temizleme
 bellekTemizle(birimDizisi, mevcutBirimSayisi);


    return 0;
}
