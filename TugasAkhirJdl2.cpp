#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cout << "=== Program Pengurutan Durasi Film (Insertion Sort) ===" << endl;
    cout << "Masukkan jumlah film: ";
    cin >> n;

    string judul[n];
    int durasi[n];

    for (int i = 0; i < n; i++) {
        cout << "\nJudul film ke-" << i + 1 << ": ";
        cin.ignore(); 
        getline(cin, judul[i]);
        cout << "Durasi film (menit): ";
        cin >> durasi[i];
    }

    for (int i = 1; i < n; i++) {
        int keyDurasi = durasi[i];
        string keyJudul = judul[i];
        int j = i - 1;

        while (j >= 0 && durasi[j] > keyDurasi) {
            durasi[j + 1] = durasi[j];
            judul[j + 1] = judul[j];
            j--;
        }
        durasi[j + 1] = keyDurasi;
        judul[j + 1] = keyJudul;
    }

    cout << "\n Daftar film berdasarkan durasi (terpendek ke terpanjang):" << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << judul[i] << " - " << durasi[i] << " menit" << endl;
    }

    return 0;
}
