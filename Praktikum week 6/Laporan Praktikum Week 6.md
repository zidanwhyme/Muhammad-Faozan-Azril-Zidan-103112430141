

## 1. Nama, NIM, Kelas
- **Nama**: Muhammad Faozan Azril Zidan
- **NIM**: 103112430141
- **Kelas**: Struktur Data-05

## 2. Motivasi Belajar Struktur Data
Belajar struktur data itu ibarat belajar cara menata barang di gudang. Kalo barang ditumpuk sembarangan, pasti susah dicari, makan tempat, dan bikin ribet. Tapi kalo ditata rapi dengan sistem (pakai rak, label, urutan), semua jadi lebih mudah, cepat, dan efisien.

## 3. Dasar Teori

Struktur data adalah cara untuk menyimpan dan mengatur data dalam komputer agar proses pengolahan dapat berjalan dengan efisien. Pada materi ini, fokusnya adalah Stack atau tumpukan, yaitu salah satu bentuk Abstract Data Type (ADT) linear yang bekerja menggunakan prinsip LIFO (Last-In, First-Out). Prinsip ini dapat dianalogikan dengan tumpukan piring: piring yang terakhir ditambahkan adalah yang pertama kali diambil. Dalam stack, penambahan dan penghapusan elemen selalu dilakukan pada satu titik yang sama yang disebut TOP.

Implementasi stack yang digunakan adalah array statis, di mana ukuran array sudah ditentukan sebelumnya melalui konstanta MaxEl pada file stack.h. Seluruh elemen disimpan dalam array secara berurutan, dan variabel TOP digunakan untuk menunjukkan posisi elemen yang berada paling atas. Jika stack masih kosong, nilai TOP diberi Nil (biasanya -1). Stack dianggap penuh apabila TOP sudah mencapai indeks maksimum, yaitu MaxEl - 1.

Kode yang dipelajari juga memperlihatkan beberapa algoritma yang memanfaatkan stack. Salah satunya adalah fungsi balikStack, yang membalik urutan elemen dengan cara memindahkan semua elemen dari stack utama ke stack sementara. Setelah dipindahkan, urutannya otomatis menjadi terbalik. Ada juga fungsi pushAscending, yang menunjukkan proses memasukkan elemen sambil menjaga agar isi stack tetap berada dalam urutan tertentu, dengan bantuan stack sementara sebagai penyimpanan sementara.
## 4. Guided
### 4.1 Guided 1
```cpp
#ifndef STACK_H
#define STACK_H

#define MaxEl 20
#define Nil -1

typedef int infotype;

struct Stack {
    infotype info[MaxEl];
    int TOP;
};

void CreateStack(Stack &A);
bool IsEmpty(Stack A);
bool IsFull(Stack A);
void Push(Stack &A, infotype B);
infotype Pop(Stack &A);
void printInfo(Stack A);

void balikStack(Stack &A);          
void pushAscending(Stack &A, infotype B);
void getInputStream(Stack &A);

#endif
```
Penjelasan : File stack.h berperan sebagai header yang berisi definisi dasar untuk struktur data Stack serta daftar fungsi yang dapat digunakan oleh file lain dalam program. Dengan kata lain, file ini menyediakan antarmuka yang menjadi acuan bagi stack.cpp dan main.cpp agar keduanya mengetahui struktur dan operasi apa saja yang boleh diakses. Untuk mencegah file ini dimuat berulang-ulang ketika proses kompilasi berlangsung, digunakan mekanisme pengaman berupa header guard (#ifndef, #define, #endif). Di dalamnya terdapat beberapa konstanta yang dideklarasikan menggunakan #define, misalnya MaxEl yang bernilai 20 sebagai batas kapasitas array stack, sehingga implementasi menggunakan alokasi statis. Ada pula Nil yang bernilai -1, yang dipakai menandai kondisi ketika stack belum memiliki elemen apa pun. File ini juga membuat alias tipe data melalui typedef int infotype sehingga tipe data elemen stack menjadi fleksibel dan mudah diubah jika diperlukan. Bagian utama dari header ini adalah struktur Stack. Struktur tersebut memiliki dua anggota: sebuah array info dengan ukuran MaxEl yang menjadi tempat penyimpanan elemen, serta sebuah variabel TOP yang menyimpan posisi indeks elemen paling atas dalam stack. Struktur inilah yang menjadi dasar representasi stack pada program. Sebagai pelengkap, stack.h mencantumkan deklarasi semua fungsi yang akan diimplementasikan di file sumber. Daftar tersebut mencakup operasi-operasi dasar seperti membuat stack, memeriksa apakah kosong atau penuh, menambahkan dan mengambil elemen, hingga mencetak isi stack. Di samping itu, terdapat juga fungsi tambahan seperti membalik isi stack, memasukkan elemen dalam urutan tertentu, dan membaca input beberapa nilai sekaligus. Dengan adanya deklarasi ini, file lain dapat menggunakan fungsi-fungsi tersebut tanpa harus mengetahui detail implementasinya.



### 4.2 Guided 2
```cpp
#include "stack.h"
#include <iostream>
using namespace std;

void CreateStack(Stack &S) {
    S.TOP = Nil; // Nil = -1
}

bool IsEmpty(Stack S) {
    return S.TOP == Nil;
}

bool IsFull(Stack S) {
    return S.TOP == MaxEl - 1;
}

void Push(Stack &S, infotype X) {
    if (!IsFull(S)) {
        if (IsEmpty(S)) {
            S.TOP = 0;
        } else {
            S.TOP++;
        }
        S.info[S.TOP] = X;
    } else {
        cout << "Stack penuh" << endl;
    }
}

infotype Pop(Stack &S) {
    infotype X = -999;
    if (!IsEmpty(S)) {
        X = S.info[S.TOP];
        S.TOP--;
        if (S.TOP < 0) {
            S.TOP = Nil;
        }
    } else {
        cout << "Stack kosong" << endl;
    }
    return X;
}

void printInfo(Stack S) {
    if (IsEmpty(S)) {
        cout << "Stack kosong" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.TOP; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    if (!IsEmpty(S)) {
        Stack temp;
        CreateStack(temp);
        while (!IsEmpty(S)) {
            Push(temp, Pop(S));
        }
        S = temp;
    }
}

  

void pushAscending(Stack &S, infotype X) {
    if (IsFull(S)) {
        cout << "Stack penuh" << endl;
        return;
    }

    Stack temp;
    CreateStack(temp);
    while (!IsEmpty(S) && S.info[S.TOP] < X) {
        Push(temp, Pop(S));
    }

    Push(S, X);
    while (!IsEmpty(temp)) {
        Push(S, Pop(temp));
    }
}

void getInputStream(Stack &S) {
    cout << "Masukkan angka: ";
    string input;
    cin >> input;

    for (char c : input) {
        if (isdigit(c)) {
            int value = c - '0';
            Push(S, value);
        }
    }
}
```


Penjelasan :Program `stack.cpp` merupakan implementasi struktur data Stack berbasis array yang menggunakan konsep LIFO (Last In First Out). File ini meng-include `stack.h` untuk mengenali struktur dan konstanta yang digunakan, serta `<iostream>` untuk proses input-output. Stack diinisialisasi melalui fungsi `CreateStack` dengan menetapkan `TOP = Nil`, lalu kondisi stack dicek menggunakan `IsEmpty` dan `IsFull`. Fungsi `Push` menambah elemen baru pada posisi TOP jika stack belum penuh, sedangkan `Pop` menghapus dan mengembalikan elemen teratas jika stack tidak kosong. Isi stack dapat ditampilkan menggunakan `printInfo` yang mencetak data dari posisi TOP ke bawah. Terdapat juga fungsi `balikStack` yang membalik urutan elemen dengan stack sementara, serta `pushAscending` yang menyisipkan elemen secara terurut menaik dengan memindahkan sementara elemen yang lebih kecil. Selain itu, fungsi `getInputStream` memungkinkan pengguna memasukkan deretan angka sebagai string, mengonversinya menjadi integer, lalu menambahkannya ke stack. Seluruh fungsi tersebut bekerja sama membentuk operasi stack yang lengkap, mulai dari penyimpanan data, pengambilan data, pengaturan urutan, hingga visualisasi isi stack.

### 4.3 Guided 3

```cpp
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    Stack S;
    CreateStack(S);

    Push(S, 4);
    Push(S, 5);
    Push(S, 9);
    Pop(S);
    Push(S, 3);
    Push(S, 4);
    Pop(S);
    Push(S, 10);

    cout << "Stack sebelum dibalik:" << endl;
    printInfo(S);

    balikStack(S);

    cout << "Stack sesudah dibalik:" << endl;
    printInfo(S);

    return 0;

}
```


Penjelasan : main.cpp berperan sebagai program utama yang bertugas menjalankan serta menguji fitur-fitur stack yang telah diimplementasikan pada stack.h dan stack.cpp. File ini meng-include stack.h agar dapat menggunakan tipe data Stack dan seluruh fungsinya, serta meng-include untuk keperluan menampilkan output ke layar. Di dalam fungsi main(), sebuah variabel stack bernama S dibuat, lalu diinisialisasi menggunakan CreateStack(S) sehingga stack berada dalam kondisi kosong pada awal program. Setelah itu, dilakukan serangkaian percobaan operasi stack, yaitu beberapa kali Push dan Pop yang disusun dalam urutan tertentu: Push(3), Push(4), Push(8), Pop(), Push(2), Push(3), Pop(), dan Push(9). Rangkaian instruksi ini menghasilkan sebuah kondisi akhir stack yang kemudian ditampilkan dengan mencetak tulisan "Stack sebelum dibalik:" dan memanggil printInfo(S) untuk memperlihatkan isinya. Setelah tampilan pertama ini, program memanggil balikStack(S) untuk membalik susunan elemen dalam stack. Untuk menunjukkan perubahan yang terjadi, program kembali mencetak pesan "Stack sesudah dibalik:" dan memanggil printInfo(S) lagi, sehingga pengguna dapat melihat perbedaan keadaan stack sebelum dan setelah proses pembalikan dilakukan.
Output : 
![[2.png]]



## 5. Unguided
### 5.1 Unguided 1
```cpp
#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World!" << endl;
    Stack S;
    CreateStack(S);

    Push(S, 4);
    Push(S, 5);
    Push(S, 9);
    Pop(S);
    Push(S, 3);
    Push(S, 4);
    Pop(S);
    Push(S, 10);

    cout << "Stack sebelum dibalik:" << endl;
    printInfo(S);
    
    balikStack(S);

    cout << "Stack sesudah dibalik:" << endl;
    printInfo(S);

    return 0;
}
```

Penjelasan ::Unguided1.cpp pada dasarnya memiliki peran yang sama seperti main.cpp, yaitu berfungsi sebagai program utama yang digunakan untuk mencoba dan memastikan bahwa operasi-operasi Stack berjalan sebagaimana mestinya. File ini tetap meng-include stack.h agar dapat memanfaatkan struktur dan fungsi stack, serta meng-include untuk menampilkan keluaran ke layar. Perbedaan paling mencolok dibandingkan main.cpp adalah munculnya output "Hello World!" di awal eksekusi program, namun setelah itu alurnya kembali mengikuti pola yang sama. Program membuat sebuah variabel Stack bernama S, menginisialisasikannya dengan CreateStack(S), lalu menjalankan serangkaian instruksi stack yang identik dengan main.cpp, yaitu Push(3), Push(4), Push(8), Pop(), Push(2), Push(3), Pop(), dan Push(9). Setelah operasi tersebut dilakukan, program menampilkan kondisi stack sebelum dibalik, kemudian memanggil fungsi balikStack(S) untuk membalik urutan elemen, dan akhirnya menampilkan isi stack kembali setelah proses pembalikan selesai, sehingga perubahan susunan elemen dapat terlihat dengan jelas.

Output : 
![[1.png]]


### 5.1 Unguided 2
```cpp
#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World!" << endl;
    Stack S;
    CreateStack(S);
    pushAscending(S, 4);
    pushAscending(S, 5);
    pushAscending(S, 9);
    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 10);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```

Penjelasan ::Unguided2.cpp berfungsi sebagai program utama yang difokuskan untuk menguji kinerja fungsi pushAscending pada struktur stack yang telah dibuat. Setelah meng-include stack.h dan iostream, program mendeklarasikan sebuah Stack S kemudian menginisialisasinya dengan CreateStack(S). Berbeda dengan driver sebelumnya yang menggunakan operasi Push biasa, file ini secara khusus memanggil pushAscending dengan urutan nilai 4, 5, 9, 3, 4, dan 10. Urutan angka tersebut dipilih sebagai skenario pengujian untuk memastikan bahwa setiap penyisipan dapat menjaga agar elemen-elemen dalam stack tetap tersusun sesuai aturan ascending yang telah didefinisikan pada stack.cpp. Setelah seluruh nilai dimasukkan menggunakan pushAscending, program memanggil printInfo(S) untuk menampilkan kondisi akhir stack yang telah tertata. Sebagai tambahan pengujian, stack yang sudah terurut tersebut kemudian dibalik menggunakan fungsi balikStack(S), dan hasil akhirnya kembali ditampilkan agar terlihat jelas perubahan susunan elemen setelah proses pembalikan dilakukan.

Output : 
![[3.png]]


### 5.1 Unguided 3
```cpp
#include "stack.h
#include <iostream>
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    Stack S;
    CreateStack(S);
    getInputStream(S);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```

Penjelasan :Unguided3.cpp berperan sebagai program utama yang tujuan utamanya adalah menguji cara kerja fungsi getInputStream(S). Seperti file driver lainnya, program ini menyertakan stack.h dan iostream, lalu di dalam fungsi main, sebuah Stack S dibuat dan diinisialisasi menggunakan CreateStack(S). Berbeda dari driver sebelumnya yang menggunakan data bawaan, program ini menyerahkan pengisian stack sepenuhnya kepada pengguna. Begitu getInputStream(S) dipanggil, program menunggu input berupa deretan angka yang akan dibaca dan dimasukkan satu per satu ke dalam stack sesuai mekanisme yang telah diimplementasikan. Setelah proses input selesai, printInfo(S) dipanggil untuk memperlihatkan isi stack hasil masukan pengguna. Untuk memastikan operasi lain juga berjalan dengan benar, program kemudian memanggil balikStack(S) guna membalik susunan elemen yang sudah terisi, dan menampilkan kembali hasilnya melalui printInfo(S), sehingga perbedaan kondisi stack sebelum dan sesudah pembalikan dapat dilihat dengan jelas.

Output : 
![[4.png]]

## 6. Kesimpulan
Secara ringkas, keenam program tersebut membentuk satu kesatuan sistem yang memperlihatkan bagaimana sebuah struktur data Stack statis berbasis array dirancang, direalisasikan, dan diuji. Pembagian perannya sangat terstruktur: stack.h berfungsi sebagai bagian deklaratif yang mendeskripsikan susunan Stack, yaitu array info[MaxEl] serta variabel TOP, sekaligus mencantumkan daftar fungsi yang akan digunakan. Implementasi nyata dari fungsi-fungsi tersebut berada di stack.cpp, yang menangani seluruh proses kerja stack mulai dari operasi fundamental seperti Push, Pop, IsEmpty, dan IsFull, hingga fitur tambahan seperti membalik isi stack (balikStack), menyisipkan elemen secara terurut (pushAscending), dan menerima input angka dari pengguna (getInputStream). Sementara itu, empat file lain berperan sebagai penguji yang menjalankan berbagai skenario berbeda: main.cpp dan Unguided1.cpp mengetes alur umum operasi Push/Pop dan proses pembalikan stack, Unguided2.cpp memfokuskan pengujian pada mekanisme pushAscending agar tetap mempertahankan urutan stack, dan Unguided3.cpp menitikberatkan pada pengujian proses input pengguna melalui getInputStream. Dengan pembagian seperti ini, seluruh aspek dari pembuatan hingga pengujian stack dapat diamati dengan jelas.

## 7. Referensi
1. 1. Fathurrozi, M., & WN, H. (2024). Application of Stack Data Structure in Application Development. _JASIC (Journal of Applied Science, Informatics, and Computing)_, _2_(1), 1-8.
2. Mak, T., & Mitrović, S. (2024). Execution Efficiency of the use of Array and Linked-List Implementations of a Stack Abstract Data Types... in Methods of an Android Application. _TEM Journal_, _13_(2), 1618–1632.
3. Novikov, E., Glushkov, A., & Ignatev, D. (2021). Technology Stack Selection Model for Software Design of Digital Platforms. _Mathematics_, _9_(4), 308.
4. Setiyawan, D., & Simarmata, E. P. (2024). Penggunaan Struktur Data Stack dalam Pemrograman C++ dengan Pendekatan Array dan Linked List. _JUTECH : Journal Education and Technology_, _3_(2), 116-123.