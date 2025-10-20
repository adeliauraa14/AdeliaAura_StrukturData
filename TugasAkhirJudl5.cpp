#include <iostream>
using namespace std;

struct Node {
    int nilai;
    Node* left;
    Node* right;
    Node(int n): nilai(n), left(nullptr), right(nullptr) {}
};

Node* insertNode(Node* root, int nilai) {
    if (!root) return new Node(nilai);
    if (nilai < root->nilai) root->left = insertNode(root->left, nilai);
    else if (nilai > root->nilai) root->right = insertNode(root->right, nilai);
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->nilai << " ";
    inorder(root->right);
}

int findMin(Node* root) {
    if (!root) return -1;
    while (root->left) root = root->left;
    return root->nilai;
}

int findMax(Node* root) {
    if (!root) return -1;
    while (root->right) root = root->right;
    return root->nilai;
}

int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

long long sumNodes(Node* root) {
    if (!root) return 0;
    return root->nilai + sumNodes(root->left) + sumNodes(root->right);
}

int main() {
    Node* root = nullptr;
    int pilih, nilai;

    do {
        cout << "\n=== SISTEM NILAI SISWA ===\n";
        cout << "1. Tambah nilai siswa\n";
        cout << "2. Tampilkan semua nilai (urut)\n";
        cout << "3. Tampilkan nilai tertinggi dan terendah\n";
        cout << "4. Statistik nilai (jumlah siswa & total nilai)\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilih;

        if (pilih == 1) {
            cout << "Masukkan nilai siswa: ";
            cin >> nilai;
            root = insertNode(root, nilai);
        } 
        else if (pilih == 2) {
            cout << "Daftar nilai siswa (terurut): ";
            inorder(root);
            cout << "\n";
        } 
        else if (pilih == 3) {
            cout << "Nilai tertinggi: " << findMax(root) << endl;
            cout << "Nilai terendah: " << findMin(root) << endl;
        } 
        else if (pilih == 4) {
            cout << "Jumlah siswa: " << countNodes(root) << endl;
            cout << "Total nilai: " << sumNodes(root) << endl;
        } 
        else if (pilih == 5) {
            cout << "Keluar dari program.\n";
        } 
        else {
            cout << "Pilihan tidak valid!\n";
        }

    } while (pilih != 5);

    return 0;
}
