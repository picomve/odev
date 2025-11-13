#include <iostream>
#include <cmath> // Sinüs dalgası için

using namespace std;

// --- Yardımcı Fonksiyon: Tek bir şekil için başlık yazdırma ---
void print_header(const string& title) {
    cout << "\n========================================\n";
    cout << "### " << title << "\n";
    cout << "========================================\n";
}

// --- 1. Yukarıdan Aşağıya Ters Üçgen (Ters Piramit) ---
void draw_inverted_pyramid(int rows) {
    // print_header("1. Yukarıdan Aşağıya Ters Üçgen (Ters Piramit)");
    for (int i = 0; i < rows; ++i) { // Satırlar (0'dan 5'e)
        // Boşluklar
        for (int j = 0; j < i; ++j) {
            cout << " ";
        }
        // Yıldızlar
        for (int k = 0; k < 2 * (rows - i) - 1; ++k) {
            cout << "*";
        }
        cout << "\n";
    }
}

// --- 2. Aşağıdan Yukarıya Normal Üçgen (Piramit) ---
void draw_pyramid(int rows) {
    // print_header("2. Aşağıdan Yukarıya Normal Üçgen (Piramit)");
    for (int i = 0; i < rows; ++i) { // Satırlar (0'dan 5'e)
        // Boşluklar
        for (int j = 0; j < rows - i - 1; ++j) {
            cout << " ";
        }
        // Yıldızlar
        for (int k = 0; k < 2 * i + 1; ++k) {
            cout << "*";
        }
        cout << "\n";
    }
}

// --- 3. Sağa Bakan Üçgen (Sağa Dayalı Üçgen) ---
void draw_right_triangle(int rows) {
    // print_header("3. Sağa Bakan Üçgen (Sağa Dayalı Üçgen)");
    // Üst yarı (Orta satır dahil)
    for (int i = 1; i <= rows; ++i) {
        for (int j = 0; j < i; ++j) {
            cout << "*";
        }
        cout << "\n";
    }
    // Alt yarı
    for (int i = rows - 1; i >= 1; --i) {
        for (int j = 0; j < i; ++j) {
            cout << "*";
        }
        cout << "\n";
    }
}

// --- 4. Sola Bakan Üçgen (Sola Dayalı Üçgen) ---
void draw_left_triangle(int rows) {
    // print_header("4. Sola Bakan Üçgen (Sola Dayalı Üçgen)");
    // Üst yarı (Orta satır dahil)
    for (int i = 1; i <= rows; ++i) {
        // Boşluklar
        for (int j = 0; j < rows - i; ++j) {
            cout << " ";
        }
        // Yıldızlar
        for (int k = 0; k < i; ++k) {
            cout << "*";
        }
        cout << "\n";
    }
    // Alt yarı
    for (int i = rows - 1; i >= 1; --i) {
        // Boşluklar
        for (int j = 0; j < rows - i; ++j) {
            cout << " ";
        }
        // Yıldızlar
        for (int k = 0; k < i; ++k) {
            cout << "*";
        }
        cout << "\n";
    }
}

// --- 5. Dikey Baklava (Elmas Şekli) ---
void draw_diamond(int half_rows, bool horizantal) {
    // print_header("5. Dikey Baklava (Elmas Şekli)");
    int rows = half_rows;

    string a = "*";
    string emt=" ";
    // Üst yarı (Normal Üçgen)
    if (horizantal){
        a = " * ";
        emt = "   ";
    }


    for (int i = 0; i < rows; ++i) {
        // Boşluklar
        for (int j = 0; j < rows - i - 1; ++j) {
            cout << emt;
        }
        // Yıldızlar
        for (int k = 0; k < 2 * i + 1; ++k) {
            cout << a;
        }
        cout << "\n";
    }

    // Alt yarı (Ters Üçgen) - En geniş satırı tekrarlamamak için i=1'den başlat
    for (int i = rows - 2; i >= 0; --i) {
            // Boşluklar
        for (int j = 0; j < rows - i - 1; ++j) {
            cout << emt;
        }
        // Yıldızlar
        for (int k = 0; k < 2 * i + 1; ++k) {
            cout << a;
        }
        cout << "\n";
        }
    
    
}


// --- 7. Sinüs Dalgası (Temel Karakter Çizimi) ---
void draw_sine_wave(int amplitude, int length) {
    // print_header("7. Sinüs Dalgası (Karakter Çizimi)");
    const double PI = 3.14159265;
    double period_factor = PI / 10.0; // Dalga sıkılığını ayarlar (daha az dalgalanma için artırın)

    for (int i = 0; i < length; ++i) { // X ekseni boyunca ilerleme
        // Sinüs değeri hesaplanır (i * periyot faktörü)
        double sine_value = sin(i * period_factor);

        // Y pozisyonu hesaplanır ve tam sayıya yuvarlanır
        // Genlik (amplitude) ve dikey kayma (amplitude) eklenir
        int y_position = (int)round(amplitude * sine_value) + amplitude;

        // Ekrana boşluklar basılır
        for (int j = 0; j < y_position; ++j) {
            cout << " ";
        }

        // Dalga işareti basılır
        cout << "*" << "\n";
    }
}


// --- ANA FONKSİYON ---
int main() {
    // Tüm şekiller için kullanılacak satır/genişlik değerleri
    const int ROW_COUNT = 10;
    const int SINE_AMPLITUDE = 8;
    const int SINE_LENGTH = 70;

    // Şekilleri sırayla çizdirme
    draw_inverted_pyramid(ROW_COUNT);
    draw_pyramid(ROW_COUNT);
    draw_right_triangle(ROW_COUNT);
    draw_left_triangle(ROW_COUNT);
    draw_diamond(ROW_COUNT, false);
    draw_diamond(ROW_COUNT, true);
    // draw_horizontal_diamond(ROW_COUNT);

    // Sinüs dalgası çizimi
    draw_sine_wave(SINE_AMPLITUDE, SINE_LENGTH);

    return 0;
}