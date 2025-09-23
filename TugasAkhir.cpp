#include <iostream>
#include <string>
using namespace std;

int main() {
    string playlist[3][4] = {
        {"Terlintas", "Masa Sepi", "Sinyal-Sinyal", "Apa Mungkin"},  
        {"Sialnya, Hidup Harus Tetap Berjalan",
         "Kata Mereka Ini Berlebihan",
         "Lama-Lama",
         "Kita Kubur Sampai Mati"},  
        {"Percik Kecil", "Kini Mereka Tahu", "Apa Mungkin (Demo Version)", "Asumsi"}  
    };

    int pilihAlbum, pilihLagu;

    cout << "=== Playlist Album ===" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Album " << i+1 << ":" << endl;
        for (int j = 0; j < 4; j++) {
            cout << "   " << (j+1) << ". " << playlist[i][j] << endl;
        }
        cout << endl;
    }

    cout << "Pilih album (1-3): ";
    cin >> pilihAlbum;

    cout << "Pilih lagu dari Album " << pilihAlbum << " (1-4): ";
    cin >> pilihLagu;

    if (pilihAlbum >= 1 && pilihAlbum <= 3 &&
        pilihLagu >= 1 && pilihLagu <= 4) {
        cout << "Memutar: " << playlist[pilihAlbum-1][pilihLagu-1] << endl;
    } else {
        cout << "Pilihan tidak valid!" << endl;
    }

    return 0;
}