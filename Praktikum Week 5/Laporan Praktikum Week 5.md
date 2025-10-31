

## 1. Nama, NIM, Kelas
- **Nama**: Muhammad Faozan Azril Zidan
- **NIM**: 103112430141
- **Kelas**: Struktur Data-05

## 2. Motivasi Belajar Struktur Data
Struktur Data bukan hanya pelajaran atau teori teknis semata, melainkan dasar penting dalam memahami logika dan cara berpikir efisien dalam pemrograman. Dengan mempelajari struktur data, kita belajar bagaimana mengatur, menyimpan, dan mengelola data agar program yang kita buat bisa berjalan lebih cepat, lebih ringan, dan lebih efektif.

## 3. Dasar Teori

Struktur data adalah metode untuk menyimpan dan mengatur data di dalam komputer agar dapat diakses dan digunakan secara efisien. Salah satu bentuk struktur data yang banyak digunakan adalah **Linked List**, yaitu struktur data dinamis yang terdiri dari kumpulan node (simpul) yang tersebar di memori. Berbeda dengan array yang menempatkan elemen-elemen secara berurutan di lokasi memori yang berdekatan, setiap node dalam linked list memiliki dua bagian utama, yaitu **data (info)** yang menyimpan nilai dari elemen seperti integer atau string, dan **pointer (next)** yang menunjuk ke node berikutnya. Node terakhir memiliki pointer yang bernilai **NULL**, menandakan akhir dari list.

**Double Linked List (DLL)** merupakan pengembangan dari Single Linked List. Perbedaannya adalah setiap node pada DLL memiliki dua pointer, yaitu **next** yang menunjuk ke node setelahnya dan **prev** yang menunjuk ke node sebelumnya. Untuk mengelola list dengan lebih efisien, digunakan struktur **header list** yang berisi dua pointer penting: **first**, yang menunjuk ke node pertama dalam list, dan **last**, yang menunjuk ke node terakhir. Header list ini tidak menyimpan data, melainkan berfungsi sebagai penghubung utama untuk memudahkan proses penyisipan dan penghapusan node.

Linked list bersifat **dinamis**, artinya ukurannya dapat bertambah atau berkurang selama program berjalan. Hal ini dimungkinkan melalui proses **alokasi dan dealokasi memori** di area heap. Proses alokasi dilakukan menggunakan fungsi **alokasi(x)** yang memesan memori baru untuk node dengan operator `new`, mengisi bagian info dengan data `x`, serta menginisialisasi pointer `next` dan `prev` dengan nilai `Nil`. Sebaliknya, **dealokasi(P)** menggunakan operator `delete` untuk mengembalikan memori yang tidak lagi digunakan agar tidak terjadi kebocoran memori atau **memory leak**.

Operasi dasar yang dapat dilakukan pada Double Linked List antara lain **penyisipan (insertion)** dan **penghapusan (deletion)**. Pada operasi penyisipan, terdapat beberapa variasi seperti **insertFirst(L, P)** untuk menambahkan node di awal list dengan memperbarui pointer `L.first`, **insertLast(L, P)** untuk menambahkan node di akhir list dengan memperbarui pointer `L.last`, serta **insertAfter(L, P, R)** dan **insertBefore(L, P, R)** untuk menyisipkan node di antara dua node tertentu dengan menyesuaikan pointer `next` dan `prev`. Sementara itu, operasi penghapusan meliputi **deleteFirst(L, P)** untuk menghapus node pertama dengan menggeser pointer `L.first`, **deleteLast(L, P)** untuk menghapus node terakhir dengan memperbarui pointer `L.last`, dan **deleteAfter(L, P, R)** untuk menghapus node yang berada tepat setelah node tertentu.

Selain operasi dasar, terdapat juga operasi lanjutan seperti **findElm(L, x)** yang digunakan untuk mencari node dengan nilai tertentu menggunakan pencarian linear (sequential search), serta **deleteByValue(L, x)** yang menggabungkan pencarian dan penghapusan node berdasarkan nilai. Untuk mengosongkan seluruh list, dapat digunakan fungsi **deleteAll(L)** yang menghapus semua node dengan cara memanggil `deleteFirst` secara berulang hingga list kosong.

Dalam penerapan yang lebih kompleks, linked list dapat dikombinasikan dengan logika kondisi melalui operasi seperti **smartInsert** dan **conditionalDelete**, di mana penyisipan atau penghapusan elemen dilakukan berdasarkan kriteria tertentu, misalnya berdasarkan nilai ganjil-genap atau posisi dalam list. Saat melakukan penghapusan dalam sebuah loop, penting untuk menyimpan pointer ke node berikutnya (`nextNode = P->next`) sebelum node yang sedang dihapus didealokasi, agar iterasi tetap berlanjut tanpa terputus. Dengan memahami prinsip-prinsip dasar ini, kita dapat memanfaatkan linked list secara efektif dalam berbagai aplikasi pemrograman yang memerlukan pengelolaan data secara dinamis dan efisien.
## 4. Guided
### 4.1 Guided 1
```cpp
#include <iostream>

using namespace std;

#define Nil NULL

  

typedef int infotype;

typedef struct elmlist *address;

  

struct elmlist {

    infotype info;

    address next;

    address prev;

};

  

struct List {

    address first;

    address last;

};

  

address alokasi(infotype x) {

    address P = new elmlist;

    P->info = x ; P->next = Nil; P->prev = Nil; return P;

}

void dealokasi(address &P) {delete P; P = Nil;}

void insertFirst(List &L, address P) {

    P->next = L.first; P->prev = Nil;

    if (L.first != Nil) L.first->prev = P; else L.last = P;

    L.first = P;

}

  

void printInfo(List L) {

    address P = L.first; while (P != Nil) {cout << P->info << " "; P = P-> next;} cout;

}

void deleteFirst(List &L, address &P) {

    P = L.first; L.first = L.first->next;

    if (L.first != Nil) L.first->prev = Nil; else L.last = Nil;

    P->next = Nil; P->prev = Nil;

}

  

void deleteLast (List &L, address &P) {

    P = L.last; L.last = L.last->prev;

    if (L.last != Nil) L.last->next = Nil; else L.first = Nil;

    P->prev = Nil; P->next = Nil;

}

  

void deleteAfter (List &L, address &P, address R) {

    P = R->next; R->next = P->next;

    if (P->next != Nil) P->next->prev = R; else L.last = R;

    P->prev = Nil; P->next = Nil;

}

  

int main() {

    List L; L.first = Nil; L.last = Nil;

    insertFirst(L, alokasi (2)); insertFirst(L, alokasi(3)); insertFirst (L, alokasi(4));

    printInfo(L);

    address P; deleteFirst(L, P); dealokasi (P);

    deleteAfter (L, P, L.first); dealokasi (P);

    printInfo(L);

    return 0;

}
```
Penjelasan :Struktur elmlist berfungsi untuk menyimpan data serta dua pointer yaitu next dan prev, sedangkan struktur List berperan sebagai pengontrol utama dengan menyimpan pointer first dan last. Fungsi alokasi() digunakan untuk membuat node baru di memori, sementara dealokasi() bertugas untuk menghapus node yang sudah tidak digunakan. Operasi insertFirst() menambahkan elemen di bagian awal list, dan printInfo() digunakan untuk menampilkan seluruh isi list.

Selain itu, terdapat fungsi deleteFirst(), deleteLast(), dan deleteAfter() yang masing-masing berfungsi untuk menghapus elemen sesuai posisinya di dalam list. Pada bagian main(), program menambahkan node dengan nilai 2, 3, dan 4 di bagian depan, sehingga urutan akhir list menjadi 4 → 3 → 2. Setelah dilakukan beberapa operasi penghapusan, elemen yang tersisa akan ditampilkan kembali. Secara keseluruhan, program ini menggambarkan cara kerja dasar dari double linked list, mencakup proses penambahan, penghapusan, serta penelusuran elemen baik dari arah depan maupun belakang.

Output : ![[1.png]]






### 4.2 Guided 2
```cpp
#include <iostream>

#define Nil NULL

using namespace std;

  

typedef int infotype;

typedef struct elmlist *address;

  

struct elmlist{

    infotype info;

    address next;

    address prev;

};

  

struct List {

    address first;

    address last;

};

  

void insertFirst(List &L, address P) {

    P->next = L.first;

    P->prev = Nil;

    if (L.first != Nil) L.first->prev = P;

    else L.last = P ;

    L.first = P;

}

  

void insertLast(List &L, address P) {

    P->prev = L.last;

    P->next = Nil;

    if (L.last != Nil) L.last -> next = P;

    else L.first = P;

    L.last = P;

}

  

void insertAfter (List &L, address P, address R) {

    P->next = R->next;

    P->prev = R;

    if (R->next != Nil) R->next->prev = P;

    else L.last = P;

    R->next = P;

}

  
  

address alokasi(infotype x) {

    address P = new elmlist;

    P->info = x;

    P->next = Nil;

    P->prev = Nil;

    return P;

}

  

void printInfo(List L) {

    address P = L.first;

    while (P != Nil) {

        cout << P->info << " ";

        P = P-> next ;

    }

    cout << endl;

}

  

int main(){

    List L;

    L.first = Nil;

    L.last = Nil;

    address P1 = alokasi(2);

    insertFirst(L, P1);

    address P2 = alokasi(3);

    insertLast(L, P2);

    address P3 = alokasi(4);

    insertAfter(L, P3, P1);

    printInfo(L);

    return 0;

}
```


Penjelasan : Struktur elmlist berfungsi sebagai node yang menyimpan data serta dua pointer, yaitu next dan prev, sedangkan struktur List digunakan untuk menyimpan penunjuk ke elemen pertama (first) dan terakhir (last) dalam list. Fungsi alokasi() digunakan untuk membuat node baru sebelum dimasukkan ke dalam list. Operasi insertFirst() menambahkan node di bagian awal, insertLast() menambahkan di bagian akhir, dan insertAfter() menyisipkan node setelah elemen tertentu.
Pada fungsi main(), program dimulai dengan list yang masih kosong. Selanjutnya, tiga node dengan nilai 2, 3, dan 4 ditambahkan menggunakan fungsi penyisipan yang berbeda. Setelah semua proses selesai, urutan data di dalam list menjadi 2, 4, 3 dan hasilnya kemudian ditampilkan melalui fungsi printInfo(). Program ini menunjukkan penerapan dasar dari operasi penyisipan pada struktur double linked list.

Output : 
![[2.png]]

### 4.3 Guided 3

```cpp
#include <iostream>

  

#define Nil NULL

  

using namespace std;

  

typedef int infotype;

typedef struct elmlist *address;

  

struct elmlist {

    infotype info;

    address next;

    address prev;

};

  

struct List {

    address first;

    address last;

};

  

void insertFirst(List &L, address P) {

    P->next = L.first;

    P->prev = Nil;

    if (L.first != Nil) L.first->prev = P;

    else L.last = P;

    L.first = P;

}

  

void insertLast(List &L, address P) {

    P->prev = L.last;

    P->next = Nil;

    if (L.last != Nil) L.last->next = P;

    else L.first = P;

    L.last = P;

}

  

void insertAfter(List &L, address P, address R) {

    P->next = R->next;

    P->prev = R;

    if (R->next != Nil) R->next->prev = P;

    else L.last = P;

    R->next = P;

}

  

address alokasi(infotype x) {

    address P = new elmlist;

    P->info = x;

    P->next = Nil;

    P->prev = Nil;

    return P;

}

  

void printInfo(List L) {

    address P = L.first;

    while (P != Nil) {

        cout << P->info << " ";

        P = P->next;

    }

    cout << endl;

}

  

void insertBefore(List &L, address P, address R) {

    P->next = R;

    P->prev = R->prev;

    if (R->prev != Nil)

        R->prev->next = P;

    else

        L.first = P;

    R->prev = P;

}

  

void printReverse(List L) {

    address P = L.last;

    while (P != Nil) {

        cout << P->info << " ";

        P = P->prev;

    }

    cout << endl;

}

  

int main() {

    List L;

    L.first = Nil;

    L.last = Nil;

  

    cout << "TASK 1: INSERT OPERATIONS" << endl;

  

    // Membuat list awal: 2 3 4

    address P1 = alokasi(2);

    insertFirst(L, P1);

    address P2 = alokasi(3);

    insertLast(L, P2);

    address P3 = alokasi(4);

    insertAfter(L, P3, P1);

  

    cout << "List awal:" << endl;

    cout << "Forward: ";

    printInfo(L);

    cout << "Backward: ";

    printReverse(L);

  

    // InsertBefore: 5 sebelum 2

    address P4 = alokasi(5);

    insertBefore(L, P4, P2);

    cout << "Berhasil insert 5 sebelum 2" << endl;

  

    // InsertBefore: 6 sebelum 1

    address P5 = alokasi(6);

    insertBefore(L, P5, P1);

    cout << "Berhasil insert 6 sebelum 1" << endl;

  

    cout << "List setelah insertBefore:" << endl;

    cout << "Forward: ";

    printInfo(L);

    cout << "Backward: ";

    printReverse(L);

  

    return 0;

}
```


Penjelasan : Program diatas memperlihatkan penerapan struktur data double linked list, di mana setiap elemen atau node (elmlist) berisi data serta dua pointer yang saling menghubungkan antar node. Struktur List berfungsi sebagai pengelola utama dengan menyimpan pointer ke elemen pertama (first) dan terakhir (last). Beberapa operasi utama yang digunakan meliputi insertFirst untuk menambah elemen di awal, insertLast untuk menambah di akhir, insertAfter untuk menyisipkan setelah node tertentu, dan insertBefore untuk menempatkan elemen sebelum node tertentu. Pada bagian main(), program membentuk list dengan urutan awal 2, 3, dan 4. Selanjutnya, elemen 5 disisipkan sebelum 2 dan elemen 6 ditempatkan sebelum 1, menghasilkan urutan akhir 6, 2, 4, 5, 3. Setelah semua operasi selesai, isi list ditampilkan dari arah depan maupun belakang untuk memastikan bahwa setiap node telah terhubung secara benar melalui pointer next dan prev.
Output : 
![[3.png]]



## 5. Unguided
### 5.1 Unguided 1
```cpp
#include <iostream>

  

using namespace std;

  

#define Nil NULL

  

  

typedef int infotype;

  

typedef struct elmlist *address;

  

  

struct elmlist {

  

    infotype info;

  

    address next;

  

    address prev;

  

};

  

  

struct List {

  

    address first;

  

    address last;

  

};

  

  

address alokasi(infotype x) {

  

    address P = new elmlist;

  

    P->info = x;

  

    P->next = Nil;

  

    P->prev = Nil;

  

    return P;

  

}

  

  

void dealokasi(address &P) {

  

    delete P;

  

    P = Nil;

  

}

  

  

void insertFirst(List &L, address P) {

  

    P->next = L.first;

  

    P->prev = Nil;

  

    if (L.first != Nil)

  

        L.first->prev = P;

  

    else

  

        L.last = P;

  

    L.first = P;

  

}

  

  

void printInfo(List L) {

  

    address P = L.first;

  

    while (P != Nil) {

  

        cout << P->info << " ";

  

        P = P->next;

  

    }

  

    cout << endl;

  

}

  

  

void deleteFirst(List &L, address &P) {

  

    P = L.first; L.first = L.first->next;

  

    if (L.first != Nil) L.first->prev = Nil; else L.last = Nil;

  

    P->next = Nil; P->prev = Nil;

  

}

  

  

void deleteLast (List &L, address &P) {

  

    P = L.last; L.last = L.last->prev;

  

    if (L.last != Nil) L.last->next = Nil; else L.first = Nil;

  

    P->prev = Nil; P->next = Nil;

  

}

  

  

void deleteAfter (List &L, address &P, address R) {

  

    P = R->next; R->next = P->next;

  

    if (P->next != Nil) P->next->prev = R; else L.last = R;

  

    P->prev = Nil; P->next = Nil;

  

}

  

  

bool deleteByValue(List &L, infotype x) {

  

    address P = L.first;

  

  

    while (P != Nil && P->info != x) {

  

        P = P->next;

  

    }

  

  

    if (P == Nil) {

  

        cout << "Nilai " << x << " tidak ditemukan" << endl;

  

        return false;

  

    }

  

  

    if (P == L.first) {

  

        L.first = P->next;

  

        if (L.first != Nil)

  

            L.first->prev = Nil;

  

        else

  

            L.last = Nil;

  

    } else if (P == L.last) {

  

        L.last = P->prev;

  

        if (L.last != Nil)

  

            L.last->next = Nil;

  

        else

  

            L.first = Nil;

  

    } else {

  

        P->prev->next = P->next;

  

        P->next->prev = P->prev;

  

    }

  

  

    cout << "Nilai " << x << " berhasil dihapus" << endl;

  

    dealokasi(P);

  

    return true;

  

}

  

  

void deleteAll(List &L) {

  

    address P = L.first;

  

    int count = 0;

  

    while (P != Nil) {

  

        address temp = P;

  

        P = P->next;

  

        dealokasi(temp);

  

        count++;

  

    }

  

    L.first = Nil;

  

    L.last = Nil;

  

    cout << "Semua elemen (" << count << ") berhasil dihapus" << endl;

  

}

  

  

int main() {

  

    List L;

  

    L.first = Nil;

  

    L.last = Nil;

  

  

    cout << "TASK 1: DELETE OPERATIONS" << endl;

  

  

    // List awal: 2 3 4 5

  

    insertFirst(L, alokasi(2));

  

    insertFirst(L, alokasi(3));

  

    insertFirst(L, alokasi(4));

  

    insertFirst(L, alokasi(5));

  

  

    cout << "List awal: ";

  

    printInfo(L);

  

  

    // Delete by value 2

  

    deleteByValue(L, 2);

  

    cout << "Setelah deleteByValue(2): ";

  

    printInfo(L);

  

  

    // Delete value yang tidak ada

  

    deleteByValue(L, 6);

  

    cout << "List tetap: ";

  

    printInfo(L);

  

  

    // Tambah data baru

  

    insertFirst(L, alokasi(6));

  

    cout << "List setelah tambah data: ";

  

    printInfo(L);

  

  

    // Delete semua elemen

  

    deleteAll(L);

  

  

    return 0;

  

}
```

Penjelasan ::Program diatas memanfaatkan sejumlah fungsi untuk melakukan pengelolaan data pada struktur linked list. Fungsi alokasi() digunakan untuk membuat node baru di memori, sedangkan dealokasi() berfungsi untuk menghapus node yang sudah tidak diperlukan. Operasi insertFirst() menambahkan data di bagian depan list, sementara printInfo() menampilkan seluruh elemen yang tersimpan. Untuk proses penghapusan, terdapat beberapa fungsi seperti deleteFirst() untuk menghapus node pertama, deleteLast() untuk menghapus node terakhir, deleteAfter() untuk menghapus node yang berada setelah node tertentu, deleteByValue() untuk menghapus elemen berdasarkan nilai yang dicari, serta deleteAll() untuk menghapus seluruh isi list. Pada bagian main(), program diawali dengan pembuatan list yang berisi elemen 2, 3, 4, dan 5. Setelah itu, nilai 2 dihapus dari list, program juga mencoba menghapus nilai 5 yang tidak ditemukan, kemudian menambahkan beberapa data baru, dan di akhir proses, seluruh elemen yang masih ada dihapus hingga list menjadi kosong.

Output : 
![[4.png]]

## **Unguided 2**

```cpp
`#include <iostream>

using namespace std;

#define Nil NULL

  

typedef int infotype;

typedef struct elmlist *address;

  

struct elmlist {

    infotype info;

    address next;

    address prev;

};

  

struct List {

    address first;

    address last;

};

  

address alokasi(infotype x) {

    address P = new elmlist;

    P->info = x;

    P->next = Nil;

    P->prev = Nil;

    return P;

}

  

void dealokasi(address &P) {

    delete P;

    P = Nil;

}

  

void insertFirst(List &L, address P) {

    P->next = L.first;

    P->prev = Nil;

    if (L.first != Nil)

        L.first->prev = P;

    else

        L.last = P;

    L.first = P;

}

  

void insertLast(List &L, address P) {

    P->prev = L.last;

    P->next = Nil;

    if (L.last != Nil)

        L.last->next = P;

    else

        L.first = P;

    L.last = P;

}

  

void insertAfter(List &L, address P, address R) {

    P->next = R->next;

    P->prev = R;

    if (R->next != Nil)

        R->next->prev = P;

    else

        L.last = P;

    R->next = P;

}

  

void printForward(List L) {

    address P = L.first;

    while (P != Nil) {

        cout << P->info << " ";

        P = P->next;

    }

    cout << endl;

}

  

void printBackward(List L) {

    address P = L.last;

    while (P != Nil) {

        cout << P->info << " ";

        P = P->prev;

    }

    cout << endl;

}

  

// SMART INSERT

void smartInsert(List &L, infotype x) {

    address P = alokasi(x);

    cout << "Smart Insert: ";

  

    // 1) List kosong

    if (L.first == Nil) {

        insertFirst(L, P);

        cout << "List kosong, insert " << x << " di first" << endl;

        return;

    }

  

    // 2) Nilai lebih kecil dari elemen pertama

    if (x < L.first->info) {

        insertFirst(L, P);

        cout << x << " < first, insert di first" << endl;

        return;

    }

  

    // 3) Nilai genap

    if (x % 2 == 0) {

        insertLast(L, P);

        cout << x << " genap, insert di last" << endl;

        return;

    }

  

    // 4) Nilai ganjil (di antara dua nilai)

    address Q = L.first;

    bool inserted = false;

    while (Q->next != Nil) {

        if (Q->info < x && x < Q->next->info) {

            insertAfter(L, P, Q);

            cout << x << " di antara " << Q->info << " dan " << Q->next->info << endl;

            inserted = true;

            break;

        }

        Q = Q->next;

    }

  

    // Jika tidak menemukan posisi di tengah

    if (!inserted) {

        insertLast(L, P);

        cout << x << " insert di last (tidak menemukan posisi tengah)" << endl;

    }

}

  

// CONDITIONAL DELETE (hapus semua bilangan ganjil)

void conditionalDelete(List &L) {

    cout << "Sebelum Conditional Delete: ";

    printForward(L);

  

    address P = L.first;

    int count = 0;

  

    while (P != Nil) {

        address next = P->next;

        if (P->info % 2 != 0) { // hapus ganjil

            if (P == L.first) {

                L.first = P->next;

                if (L.first != Nil) L.first->prev = Nil;

                else L.last = Nil;

            } else if (P == L.last) {

                L.last = P->prev;

                if (L.last != Nil) L.last->next = Nil;

                else L.first = Nil;

            } else {

                P->prev->next = P->next;

                P->next->prev = P->prev;

            }

            dealokasi(P);

            count++;

        }

        P = next;

    }

  

    cout << "Conditional Delete: " << count << " elemen ganjil dihapus" << endl;

    cout << "Setelah Conditional Delete: ";

    printForward(L);

}

  

// MAIN PROGRAM

int main() {

    List L;

    L.first = Nil;

    L.last = Nil;

  

    cout << "ADVANCED OPERATIONS" << endl;

    cout << "SMART INSERT DEMO" << endl;

  

    smartInsert(L, 6);

    smartInsert(L, 4);

    smartInsert(L, 9);

    smartInsert(L, 7);

    smartInsert(L, 5);

    smartInsert(L, 8);

  

    cout << "\nHasil Smart Insert:" << endl;

    cout << "Forward: ";

    printForward(L);

    cout << "Backward: ";

    printBackward(L);

    cout << endl;

  

    cout << "CONDITIONAL DELETE" << endl;

    conditionalDelete(L);

    cout << endl;

  

    cout << "DELETE BY VALUE DEMO" << endl;

    // hapus nilai 6

    int x = 6;

    address P = L.first;

    while (P != Nil && P->info != x) P = P->next;

    if (P != Nil) {

        if (P == L.first) {

            L.first = P->next;

            if (L.first != Nil) L.first->prev = Nil;

        } else if (P == L.last) {

            L.last = P->prev;

            if (L.last != Nil) L.last->next = Nil;

        } else {

            P->prev->next = P->next;

            P->next->prev = P->prev;

        }

        cout << "Nilai " << x << " berhasil dihapus" << endl;

        dealokasi(P);

    } else {

        cout << "Nilai " << x << " tidak ditemukan" << endl;

    }

  

    // hapus nilai 10

    x = 10;

    P = L.first;

    while (P != Nil && P->info != x) P = P->next;

    if (P != Nil) {

        if (P == L.first) {

            L.first = P->next;

            if (L.first != Nil) L.first->prev = Nil;

        } else if (P == L.last) {

            L.last = P->prev;

            if (L.last != Nil) L.last->next = Nil;

        } else {

            P->prev->next = P->next;

            P->next->prev = P->prev;

        }

        cout << "Nilai " << x << " berhasil dihapus" << endl;

        dealokasi(P);

    } else {

        cout << "Nilai " << x << " tidak ditemukan" << endl;

    }

  

    cout << "List akhir: ";

    printForward(L);

    cout << endl;

  

    cout << "DELETE ALL DEMO" << endl;

    int count = 0;

    while (L.first != Nil) {

        address temp = L.first;

        L.first = L.first->next;

        dealokasi(temp);

        count++;

    }

    L.last = Nil;

    cout << "Semua elemen (" << count << ") berhasil dihapus" << endl;

  

    return 0;

}
```
Penjelasan : Program diatas terdiri dari dua fungsi utama, yaitu Smart Insert dan Conditional Delete. Fungsi Smart Insert digunakan untuk menambahkan elemen ke dalam list sesuai dengan aturan atau kondisi tertentu yang telah ditentukan sebelumnya. Secara keseluruhan, program ini memperlihatkan bagaimana Double Linked List bekerja dengan menerapkan logika penyisipan dan penghapusan elemen secara dinamis berdasarkan kondisi yang berlaku.

Output : ![[5.png]]

## 6. Kesimpulan 
Praktikum ini berhasil menerapkan struktur data Doubly Linked List (DLL) secara menyeluruh. Proses implementasi dimulai dari operasi dasar seperti penyisipan data (insertFirst, insertLast, insertAfter, insertBefore) dan penghapusan data (deleteFirst, deleteLast, deleteAfter), kemudian dikembangkan menjadi fungsi-fungsi dengan tingkat kompleksitas yang lebih tinggi.

Tujuan dari praktikum ini tercapai melalui penerapan berbagai fitur tambahan seperti fungsi pencarian (findElm), penghapusan berdasarkan nilai tertentu (deleteByValue), serta pengosongan seluruh elemen list (deleteAll). Selain itu, praktikum juga mencakup pembuatan fungsi bersyarat seperti smartInsert yang berfungsi menambahkan elemen secara selektif, dan conditionalDelete yang digunakan untuk menghapus elemen dengan kriteria tertentu, misalnya nilai ganjil.

Secara keseluruhan, kegiatan ini menunjukkan pemahaman yang baik mengenai cara kerja dan manipulasi pointer next serta prev, pentingnya pengelolaan memori melalui proses alokasi dan dealokasi, serta penanganan berbagai kondisi khusus seperti list kosong atau operasi yang melibatkan elemen pertama dan terakhir.

## 7. Referensi
1. Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2022). _Introduction to Algorithms_ (4th ed.). MIT Press.
2. Weiss, M. A. (2014). _Data Structures and Algorithm Analysis in C++_ (4th ed.). Pearson.
3. Wijoyo, A., Prayudi, L. A., Fiqih, M., Santoso, R. D., Putra, R. T., Arifin, T., & Farhan, A. (2024). Penggunaan Algoritma Doubly Linked List Untuk Insertion Dan Deletion. _JRIIN : Jurnal Riset Informatika dan Inovasi_, 1(12), 1329–1331.
4. Sjafari, A. N., & Mulyani, A. (2018). IMPLEMENTASI DOUBLE LINKED LIST PADA APLIKASI ANTRIAN KLINIK. _Jurnal Ilmiah Informatika_, 3(01).