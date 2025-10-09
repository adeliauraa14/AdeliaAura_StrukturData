#include <iostream>
#include <string>
using namespace std;

int main() {
    const int n = 10;
    string daftarBuah[n] = {"Durian", "Belimbing", "Alpukat", 
                            "Kedondong", "Salak", "Belimbing", "Nangka", 
                            "Jambu Biji", "Sirsak", "Kedondong"};
    string target;
    int i = 0;
    int counter = 0;

    cout << "Masukkan nama buah yang ingin dicari: ";
    cin >> target;

    while (i < n) {
        if (daftarBuah[i] == target) {
            counter++;
        }
        i++;
    }

    if (counter > 0) {
        cout << "Buah " << target << " ditemukan sebanyak " << counter << " kali di daftar buah." << endl;
    } else {
        cout << "Buah " << target << " tidak ditemukan di daftar buah." << endl;
    }

    return 0;
}
