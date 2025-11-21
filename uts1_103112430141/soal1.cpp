#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

Node* head = nullptr;

// Insert di akhir list
void insertAkhir(string nama) {
    Node* baru = new Node{nama, nullptr};

    if (head == nullptr) {
        head = baru;
    } else {
        Node* p = head;
        while (p->next != nullptr) {
            p = p->next;
        }
        p->next = baru;
    }
}

// Delete nama pertama ditemukan (case-sensitive)
void deleteNama(string nama) {
    if (head == nullptr) {
        cout << "List kosong!\n";
        return;
    }

    // Jika node pertama yang dihapus
    if (head->nama == nama) {
        Node* hapus = head;
        head = head->next;
        delete hapus;
        return;
    }

    // Cari node sebelum yang akan dihapus
    Node* p = head;
    while (p->next != nullptr && p->next->nama != nama) {
        p = p->next;
    }

    if (p->next == nullptr) {
        cout << "Nama tidak ditemukan.\n";
    } else {
        Node* hapus = p->next;
        p->next = hapus->next;
        delete hapus;
    }
}

// View seluruh list
void viewList() {
    Node* p = head;
    while (p != nullptr) {
        cout << p->nama << " ";
        p = p->next;
    }
    cout << endl;
}

// Hitung nama dengan jumlah huruf genap
void hitungGenap() {
    int count = 0;
    Node* p = head;

    while (p != nullptr) {
        if (p->nama.length() % 2 == 0)
            count++;
        p = p->next;
    }

    cout << "Jumlah nama dengan huruf genap: " << count << endl;
}

int main() {
    int menu;
    string input;

    do {
        cout << "Menu: 1 insert, 2 delete, 3 view, 4 hitung genap, 0 exit\n";
        cin >> menu;
        cin.ignore();  

        switch (menu) {
            case 1:
                cout << "Masukkan nama: ";
                getline(cin, input);
                insertAkhir(input);
                break;

            case 2:
                cout << "Masukkan nama untuk delete: ";
                getline(cin, input);
                deleteNama(input);
                break;

            case 3:
                viewList();
                break;

            case 4:
                hitungGenap();
                break;

            case 0:
                break;

            default:
                cout << "Menu tidak valid\n";
        }

    } while (menu != 0);

    return 0;
}
