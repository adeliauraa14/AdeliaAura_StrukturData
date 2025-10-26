#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10;

struct Member {
    int id;
    string nama;
    int poin;
    Member* next;
};

void initTable(Member* table[]) {
    for (int i = 0; i < SIZE; i++) {
        table[i] = nullptr;
    }
}

int hashFunction(int id) {
    return (id % SIZE + SIZE) % SIZE;
}

void insert(Member* table[], int id, string nama, int poin) {
    int index = hashFunction(id);
    Member* cur = table[index];
    while (cur != nullptr) {
        if (cur->id == id) {
            cur->nama = nama;
            cur->poin = poin;
            return;
        }
        cur = cur->next;
    }
    Member* baru = new Member;
    baru->id = id;
    baru->nama = nama;
    baru->poin = poin;
    baru->next = table[index];
    table[index] = baru;
}

Member* search(Member* table[], int id) {
    int index = hashFunction(id);
    Member* cur = table[index];
    while (cur != nullptr) {
        if (cur->id == id) {
            return cur;
        }
        cur = cur->next;
    }
    return nullptr;
}

void removeMember(Member* table[], int id) {
    int index = hashFunction(id);
    Member* cur = table[index];
    Member* prev = nullptr;
    while (cur != nullptr) {
        if (cur->id == id) {
            if (prev == nullptr) {
                table[index] = cur->next;
            } else {
                prev->next = cur->next;
            }
            delete cur;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}

void display(Member* table[]) {
    cout << "\nDaftar Member Supermarket:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i << ": ";
        Member* tmp = table[i];
        while (tmp != nullptr) {
            cout << "(" << tmp->id << ", " << tmp->nama << ", Poin: " << tmp->poin << ") -> ";
            tmp = tmp->next;
        }
        cout << "NULL\n";
    }
}

int main() {
    Member* table[SIZE];
    initTable(table);

    insert(table, 1001, "Aura", 120);
    insert(table, 1002, "Jadin", 80);
    insert(table, 1012, "Citra", 150);
    insert(table, 1023, "Delvina", 200);
    insert(table, 1033, "Aisha", 90);

    display(table);

    Member* hasil = search(table, 1002);
    if (hasil != nullptr) {
        cout << "\nMember dengan ID 1002 ditemukan:\n";
        cout << "Nama: " << hasil->nama << ", Poin: " << hasil->poin << endl;
    } else {
        cout << "\nMember dengan ID 1002 tidak ditemukan.\n";
    }

    removeMember(table, 1002);
    cout << "\nSetelah menghapus member dengan ID 1002:\n";
    display(table);

    return 0;
}
