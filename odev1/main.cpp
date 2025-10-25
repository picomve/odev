#include <iostream>
#include <clocale> // Türkçe karakterler için
#include <cstdlib> // Clean fonksiyonunda komut çalıştırmak için

using namespace std;

// TÜM FONKSİYONLAR BU ALANDA
// 01 Bir üçgenin 2 tane iç açısını verince diğer açıyı hesaplayıp geri döndüren fonskiyon
int eksikAci(uint a1, uint a2){
      return 180-(a1+a2);
}

// 02 Eşkenar üçgenin Çevresini hesapla
int eskenarCevresi(int c) {return c*3;}

// 03 Üçgenin alanını hesapla
int ucgenAlani(int taban, int yukseklik){
      return (taban*yukseklik)/2;
}


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
		}
	}
	return 0;
}