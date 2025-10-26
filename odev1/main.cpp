#include <iostream>
#include <clocale> // Türkçe karakterler için
#include <cstdlib> // Clean fonksiyonunda komut çalıştırmak için
#include <thread>

const double PI = 3.14;

struct Konum{
      float x;
      float y;
};



using namespace std;

// TÜM FONKSİYONLAR BU ALANDA
// 01 Bir üçgenin 2 tane iç açısını verince diğer açıyı hesaplayıp geri döndüren fonskiyon
int eksikAci(int a1, int a2){return 180-(a1+a2);}

// 02 Eşkenar üçgenin Çevresini hesapla
int eskenarCevresi(int c) {return c*3;}

// 03 Üçgenin alanını hesapla
int ucgenAlani(int taban, int yukseklik){return (taban*yukseklik)/2;}

// 04 Karenin çevresini hesapla
int kareninCevresi(int kenar){ return kenar*4;}

// 05 Karenin alanını hesapla
int kareninAlani(int kenar){return kenar*kenar;}

// 06 Yuvarlağın çevresini hesapla
double daireninCevrei(int yaricap) {return yaricap*2*PI;}

// 07 Yuvarlağın alanını hesapla
double daireninAlani(int yaricap) {return yaricap*2*PI;}

// 08 Faktöriyal al
int faktoriyel(int faktor){
      int sayi = 1;
      int bnokta = 1;
      while (bnokta <= faktor) {
            sayi = sayi*bnokta;
            bnokta++;
      }
      return sayi;
}

// 09 Parabol atış hesapla
Konum parabolHesapla(Konum baslangicKonumu, float yatayhizi, float dikeyhizi){
      float x = baslangicKonumu.x;
      float y = baslangicKonumu.y;
      float yhiz = yatayhizi;
      float dhiz = dikeyhizi;
      if (y <= 0) {y = 1;}
      
      int zaman = 0;
      while (y > 0) {
            cout << "Kaçıncı saniye: " << zaman << endl;
            cout << "Şuanki konumu x: " << x << ",  y: " << y << endl;
            cout << "Şuanki hız yatay: " << yhiz << ", dikey hız: " << dhiz << endl;
            cout << endl;

            std::this_thread::sleep_for(1s);
            
            zaman++;
            x += yhiz;
            y = y+dhiz; // y += dhiz;  şeklindede kullanılabilir ama benim keyfim böyle istedi

            dhiz = dhiz-9.81;
      }

      return Konum {x,y};
}

// 10 Bileşik faiz
double mevduatFaiz(double anapara, float gunlukRepoFaizi, int kacgun) {
      double para = anapara;
      for (int x= 0; x <= kacgun; x++){
            cout << "Bugünkü paramız: " << para << " ₺" << endl << endl;
            std::this_thread::sleep_for(1s);
            para = para*(1+(gunlukRepoFaizi/100));
      }
      return para;
}




// Program burdan itibaren başlıyor

bool program = true;
int islem; // kullanıcı hangi işlemi yapmak istiyor

// Konsolu temizleyen method
void clean(){
	#ifdef _WIN32 // Windows işletim sistemleri için tanımlanmış makro
            system("cls");
      #else // Diğer sistemler (Linux, macOS, Unix)
            system("clear");
      #endif
}

void waitforEnter() {
      std::cout << "Devam etmek için ENTER tuşuna basın...";
      std::cin.ignore(10000, '\n'); // Akıştaki önceki karakterleri temizle
    
      // Şimdi Enter'a basılmasını bekler
      std::cin.get(); 
}


int main(){
	// Tüm her şeyi yerele göre ayarla dioruz, karakterleri falan
	setlocale(LC_ALL, "Turkish");


	while (program) {
		clean();

		// Ekranda seçenekleri göster
		cout << "Merhaba canım ilk c++ ödevime hoşgelin\nÖDEV NO 1 İstediğin işlemi yap\n" << endl;
		cout << "0: Programdan çık" << endl;
		cout << "1: Üçgenin eksik açısını hesapla" << endl;
		cout << "2: Eşkenar üçgenin çevresini hesapla" << endl;
		cout << "3: Üçgenin alananı hesapla" << endl;
		cout << "4: Karenin çevresini hesapla" << endl;
		cout << "5: Karenin alanını hesapla" << endl;
		cout << "6: Yuvarlağın çevresini hesapla" << endl;
		cout << "7: Yuvarlağın alanını hesapla" << endl;
		cout << "8: Faktöriyel al" << endl;
		cout << "9: Bir nesneyi belirli bir açıda belirli bir hızda atınca o" << endl <<
		"Nesnenin kaç saniye sonra nereye ne hızla düşeceğini" << endl <<
		" hesapla, (Hava sürtünmesi olmadan, Klasik newton fiziği ile)" << endl;
		cout << "10: Bileşik faiz hesapla" << endl << endl;
		cout << "Hangi işlemi yapmap istesiniz: ";
		

		cin >> islem;
		switch (islem) {
                  default:
                        cout << "Öyle bir komut yok bikree ,sen naptın öyle ya" << endl;
                        break;
			case 0:
                        waitforEnter();
                        program = false;
				break;
                  case 1:
                        // Bir üçgenin iki açısını alıp diğer açısını hesaplayan kısım
                        int aci1, aci2;
                        cout << "1. açıyı gir: ";
                        cin >> aci1;
                        cout << "2. açıyı gir: ";
                        cin >> aci2;

                        cout << "Sonuç: " << eksikAci(aci1, aci2) << "° derece" << endl;
                        waitforEnter();
                        break;		
                  
                  case 2:
                        // Eşkenar üçgenin çevresini hesaplıyor
                        int kenar;
                        cout << "Eşkenar üçgenin bir kenarı: ";
                        cin >> kenar;

                        cout << "Sonuç: " << eskenarCevresi(kenar) << endl;
                        waitforEnter();
                        break;
                  case 3:
                        // Üçgenin alanını hesapla
                        int taban, yukseklik;
                        cout << "Üçgenin taban uzunluğunu gir: ";
                        cin >> taban;
                        cout << "Üçgenin yükseliğini gir: ";
                        cin >> yukseklik;

                        cout << "Sonuç: " << ucgenAlani(taban, yukseklik) << endl;
                        waitforEnter();
                        break;
                  case 4:
                        // Karenin çevresini hesapla
                        cout << "Karenin kenar uzunluğunu gir: ";
                        cin >> kenar;

                        cout << "Sonuç: " << kareninCevresi(kenar) << endl;
                        waitforEnter();
                        break;
                  case 5:
                        // Karenin alanını hesapla
                        cout << "Karenin kenar uzunluğunu gir: ";
                        cin >> kenar;

                        cout << "Sonuç: " << kareninAlani(kenar) << endl;
                        waitforEnter();
                        break;
                  case 6:
                        // Yuvarlağın çevresini hesapla
                        int yaricap;
                        cout << "Dairenin yarıçapını gir: ";
                        cin >> yaricap;

                        cout << "Sonuç: " << daireninCevrei(yaricap) << endl;
                        waitforEnter();
                        break;
                  case 7:
                        // Yuvarlağın alanını hesapla
                        cout << "Dairenin yarıçapını gir: ";
                        cin >> yaricap;

                        cout << "Sonuç: " << daireninAlani(yaricap) << endl;
                        waitforEnter();
                        break;
                  case 8:
                        // Faktöriyel hesapla
                        int sayi;
                        cout << "Faktöriyeli hesaplanacak sayıyı girin: ";
                        cin >> sayi;

                        cout << "Sonuç: " << faktoriyel(sayi) << endl;
                        waitforEnter();
                        break;
                  case 9:{
                        // Bir parabol olarak atılan bir nesneyi hesapla
                        float x,y, yatayhizi, dikeyhizi;

                        cout << "x konumunu gir: ";
                        cin >> x;
                        cout << "y konumunu gir: ";
                        cin >> y;
                        cout << "yatay hızını gir: ";
                        cin >> yatayhizi;
                        cout << "dikey hızını gir: ";
                        cin >> dikeyhizi;

                        Konum k = parabolHesapla(Konum {x,y}, yatayhizi, dikeyhizi);
                        cout << endl << "Bitiriş konumu x: " << k.x << ", y: " << k.y << endl;
                        waitforEnter();
                        break;
                        }
                  case 10:{
                        double anapara;
                        float gunlukRepoFaizi;
                        int kacgun;

                        cout << "Anaparamız kaç tl: ";
                        cin >> anapara;
                        cout << "Günlük repo faizi % kaç: ";
                        cin >> gunlukRepoFaizi;
                        cout << "Kaç gün mevduatta tutalım? ";
                        cin >> kacgun;

                        cout << "Paramız :" << mevduatFaiz(anapara, gunlukRepoFaizi, kacgun) << endl;
                        waitforEnter();
                        break;
                  }
                  
		}
	}
	return 0;
}