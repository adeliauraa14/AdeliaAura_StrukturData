#include <iostream>
#include <string>
using namespace std;

const int MAX = 20; 
string tumpukan[MAX];
int topIdx = -1;

bool isEmpty();
bool isFull();
void tambahBuku(string judul);
void ambilBuku();
void lihatBukuTeratas();
void tampilkanTumpukan();

int main() {
    int pilih;
    string judul;

    do {
        cout << "\n=== TUMPUKAN BUKU PERPUSTAKAAN ===\n";
        cout << "1. Tambah Buku (Push)\n";
        cout << "2. Ambil Buku (Pop)\n";
        cout << "3. Lihat Buku Teratas (Peek)\n";
        cout << "4. Tampilkan Semua Buku\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;
        cin.ignore(); 

        if (pilih == 1) {
            cout << "Masukkan judul buku: ";
            getline(cin, judul);
            tambahBuku(judul);
        } 
        else if (pilih == 2) ambilBuku();
        else if (pilih == 3) lihatBukuTeratas();
        else if (pilih == 4) tampilkanTumpukan();

    } while (pilih != 5);
    return 0;
}

bool isEmpty() {
    return topIdx == -1;
}

bool isFull() {
    return topIdx == MAX - 1;
}

void tambahBuku(string judul) {
    if (isFull()) {
        cout << "Tumpukan penuh! Tidak bisa menambah buku lagi.\n";
        return;
    }
    tumpukan[++topIdx] = judul;
    cout << "Buku \"" << judul << "\" berhasil ditambahkan ke tumpukan.\n";
}

void ambilBuku() {
    if (isEmpty()) {
        cout << "Tumpukan kosong! Tidak ada buku yang bisa diambil.\n";
        return;
    }
    cout << "Buku \"" << tumpukan[topIdx--] << "\" telah diambil dari tumpukan.\n";
}

void lihatBukuTeratas() {
    if (isEmpty()) {
        cout << "Tumpukan kosong.\n";
        return;
    }
    cout << "Buku teratas saat ini: \"" << tumpukan[topIdx] << "\"\n";
}

void tampilkanTumpukan() {
    if (isEmpty()) {
        cout << "Tumpukan kosong.\n";
        return;
    }
    cout << "Daftar buku dari atas ke bawah:\n";
    for (int i = topIdx; i >= 0; --i) {
        cout << i + 1 << ". " << tumpukan[i] << '\n';
    }
}
