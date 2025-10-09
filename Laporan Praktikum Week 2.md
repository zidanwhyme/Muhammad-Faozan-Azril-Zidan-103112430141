

## 1. Nama, NIM, Kelas
- **Nama**: Muhammad Faozan Azril Zidan
- **NIM**: 103112430141
- **Kelas**: Struktur Data-05

## 2. Motivasi Belajar Struktur Data
Belajar struktur data itu ibarat belajar cara menata barang di gudang. Kalo barang ditumpuk sembarangan, pasti susah dicari, makan tempat, dan bikin ribet. Tapi kalo ditata rapi dengan sistem (pakai rak, label, urutan), semua jadi lebih mudah, cepat, dan efisien.

## 3. Dasar Teori

Struktur data merupakan metode untuk menyimpan serta mengatur data di dalam komputer agar dapat diakses dan dikelola dengan lebih efisien. Berikut ini penjelasan dasar mengenai **Array**, **Pointer**, dan **Fungsi** dalam bahasa C++:

- **Konsep Array dan Pengolahan Data**
    Array adalah struktur data yang digunakan untuk menampung sejumlah elemen dengan tipe data yang sama di dalam satu variabel. Dalam C++, elemen-elemen array tersimpan secara berurutan di memori dan dapat diakses menggunakan indeks, misalnya `arr[i]`. Penggunaan array sangat membantu ketika perlu mengelola banyak data sekaligus, seperti menyimpan data nilai siswa atau stok barang. Menurut **Kusuma & Rahmadani (2023)**, struktur array memiliki peran penting dalam efisiensi penyimpanan dan pengolahan informasi karena memberikan cara yang terorganisir dalam manajemen data.
    
- ### **Pointer dan Pengelolaan Memori**
    Pointer merupakan variabel khusus yang berisi alamat memori dari variabel lain. Melalui pointer, program dapat membaca maupun mengubah nilai suatu variabel secara langsung melalui alamat memorinya, bukan melalui salinan datanya. Hal ini membuat pemrosesan data menjadi lebih cepat dan fleksibel. Dalam contoh program penghitungan diskon atau manajemen stok buku, pointer digunakan untuk mengubah nilai asli tanpa perlu menyalinnya terlebih dahulu. Seperti yang dijelaskan oleh **Santoso & Wirawan (2022)**, pemahaman terhadap konsep pointer merupakan dasar penting untuk memahami cara kerja memori komputer serta peningkatan efisiensi dalam manipulasi data di bahasa C dan C++.
    
- ### **Fungsi dan Penggunaan Parameter Referensi**

    Fungsi digunakan untuk membagi program menjadi bagian-bagian yang lebih kecil dan mudah dikelola. Salah satu konsep penting dalam penggunaannya adalah **parameter referensi (pass by reference)**, di mana variabel yang dikirim ke fungsi bukanlah salinannya, melainkan referensi langsung ke variabel aslinya. Dengan pendekatan ini, perubahan yang dilakukan di dalam fungsi akan langsung memengaruhi nilai sebenarnya dari variabel tersebut. Menurut **Putri & Nugroho (2021)**, penerapan parameter referensi dalam fungsi membantu meningkatkan efisiensi pemrosesan data dan memperkuat prinsip modularitas dalam pengembangan program.
## 4. Guided
### 4.1 Guided 1
```cpp
#include <iostream>

using namespace std;

int main() {

    int bukuPerHari[7] = {3,2,4,5,1,3,1};
    int totalBuku = 0;
    cout<<"Laporan Baca Buku Mingguan"<<endl;
    
    for (int i = 0; i < 7; i++) {
        cout<<"Hari ke-"<<i+1<<":"<<bukuPerHari[i]
        <<"buku"<<endl;
        totalBuku += bukuPerHari[i];
    }

}
```
Penjelasan : Program diatas berfungsi untuk menampilkan jumlah buku yang dibaca selama satu minggu. Data jumlah buku setiap harinya disimpan dalam array **bukuPerHari**, kemudian program menampilkan jumlah tersebut dari hari pertama hingga hari ketujuh. Selain itu, program juga menghitung total buku yang dibaca selama seminggu, namun nilai total tersebut belum muncul di output karena belum ada perintah **cout** untuk menampilkannya.

Output :
![[1.png]]





### 4.2 Guided 2
```cpp
#include <iostream>

using namespace std;

int main(){
    float hargaProduk = 70000.0f;
    float* ptrHarga;
    ptrHarga = &hargaProduk;

    cout << "Harga awal produk: Rp." << hargaProduk << endl;
    cout << "Alamat memori harga: "<< ptrHarga<< endl;
    cout << "\n --- Memberikan diskon 10% melalui pointer ---" << endl;
    
    *ptrHarga = *ptrHarga * 0.9;
    
    cout << "Harga setelah diskon: Rp." << hargaProduk << endl;
return 0;
}
```


Penjelasan : Program diatas digunakan untuk menampilkan harga suatu produk sekaligus menghitung potongan harga sebesar 10% menggunakan konsep pointer. Awalnya, variabel **hargaProduk** diisi dengan nilai 70.000. Selanjutnya, dibuat pointer **ptrHarga** yang menyimpan alamat memori dari variabel tersebut menggunakan operator **&**. Program kemudian menampilkan harga awal beserta alamat memorinya. Setelah itu, pointer dimanfaatkan untuk mengubah nilai **hargaProduk** secara langsung dengan perhitungan `*ptrHarga = *ptrHarga * 0.9`, yang berarti harga dikalikan 0,9 sebagai bentuk diskon 10%. Karena pointer terhubung langsung dengan variabel aslinya, perubahan nilai juga terjadi pada **hargaProduk**. Di akhir program, harga setelah diskon ditampilkan ke layar.

Output : 
![[2.png]]

### 4.3 Guided 3

```cpp
#include<iostream>

using namespace std;
float hitungRataRata(int nilaiTugas, int nilaiUts){
    return (nilaiTugas + nilaiUts) / 2.0f;
}

void cetakProfil(string nama, float nilai){
    cout<<"Nama : "<<nama<<endl;
    cout<<"Nilai : "<<nilai<<endl;
}

void beriNilaiBonus(float&nilai){
    nilai += 5.0f;
}

int main(){
    string namaSiswa = "kentung";
    int tugas = 100, uts = 80;

    float nilaiAkhir = hitungRataRata(tugas, uts);

    cout <<"Nilai Awal Siswa"<<endl;
    cetakProfil(namaSiswa, nilaiAkhir);

    cout <<"\nMemberikan Nilai Bonus.."<<endl;
    beriNilaiBonus(nilaiAkhir);

    cout <<"\nNilai Setelah Bonus"<<endl;
    cetakProfil(namaSiswa, nilaiAkhir);
return 0;

}
```


Penjelasan : Program diatas berfungsi untuk menghitung serta menampilkan nilai seorang siswa sebelum dan sesudah memperoleh tambahan nilai (bonus). Fungsi **hitungRataRata()** digunakan untuk menghitung rata-rata dari nilai tugas dan nilai UTS dengan rumus `(nilaiTugas + nilaiUts) / 2.0f`. Selanjutnya, fungsi **cetakProfil()** bertugas menampilkan nama siswa beserta nilai yang dimilikinya. Ada juga fungsi **beriNilaiBonus()**, yang menambahkan nilai sebesar 5 melalui parameter referensi (**float& nilai**) agar perubahan nilainya langsung memengaruhi variabel aslinya. Dalam fungsi **main()**, nama siswa diatur menjadi "Kentung" dengan nilai tugas 100 dan nilai UTS 80. Program kemudian menghitung rata-rata, menampilkan data awal siswa, memberikan tambahan nilai 5 poin, lalu menampilkan kembali profil setelah bonus diterapkan.
Output : 
![[3.png]]



## 5. Unguided
### 5.1 Unguided 1
```cpp
#include <iostream>

using namespace std;

  

void cetakStok(int arr[], int size) {

    cout <<"[";

    for (int i = 0; i < size; i++) {

        cout << arr[i] << (i < size - 1 ? " " : ",");

}

    cout << "]" << endl;

}

  

int hitungTotalStok(int arr[], int size) {

    int total = 0;

    for (int i = 0; i < size; i++) {

        total += arr[i];

    }

    return total;

}

  

int* cariStokPalingSedikit(int arr[], int size) {

    int* ptrPalingSedikit = &arr[0];

    for (int i = 1; i < size; i++) {

        if (arr[i] < *ptrPalingSedikit) {

            ptrPalingSedikit = &arr[i];

        }

    }

    return ptrPalingSedikit;

}

  

void tambahStokBonus(int* ptrStok){

    *ptrStok += 10;

}

int main() {

    int stokBuku[] = {15,20,35,10,5};

    int jumlahJenisBuku = 5;

    cout <<"Stok Buku Awal: " <<endl;

    cetakStok(stokBuku, jumlahJenisBuku);

  

    int total = hitungTotalStok(stokBuku, jumlahJenisBuku);

    cout <<"Total semua Stok Buku: " << total << endl;

  

    int* ptrStokRendah = cariStokPalingSedikit(stokBuku, jumlahJenisBuku);

    tambahStokBonus(ptrStokRendah);

  

    cout << "\nStok Buku Setelah Penambahan Bonus:" << endl;

    cetakStok(stokBuku, jumlahJenisBuku);

  

    return 0;

}
```

Penjelasan ::Program diatas dibuat untuk mengatur dan menampilkan data stok buku dengan memanfaatkan **array** serta **pointer**. Fungsi **cetakStok()** digunakan untuk menampilkan seluruh isi array stok buku dalam format yang mudah dibaca. Selanjutnya, fungsi **hitungTotalStok()** berfungsi menghitung total keseluruhan stok dengan menjumlahkan setiap elemen dalam array. Fungsi **cariStokPalingSedikit()** bertugas menemukan nilai stok terkecil dengan membandingkan tiap elemen dan mengembalikan alamat memorinya melalui pointer. Setelah itu, fungsi **tambahStokBonus()** menambah stok sebanyak 10 pada buku dengan stok paling sedikit menggunakan pointer yang dikembalikan sebelumnya. Pada bagian **main()**, data awal stok disimpan di array **stokBuku**, lalu program menampilkan stok awal, menghitung jumlah total, mencari buku dengan stok terendah, menambahkan bonus stok, dan menampilkan kembali hasil akhir setelah pembaruan dilakukan.

Output : 
![[4.png]]

## 6. Kesimpulan
Dari berbagai contoh program C++ yang telah dibahas, dapat ditarik kesimpulan bahwa penguasaan konsep dasar seperti array, pointer, fungsi, referensi, dan operasi aritmetika merupakan landasan penting untuk melangkah ke tingkat pemrograman yang lebih lanjut. Array berperan dalam menyimpan serta mengelola kumpulan data dengan cara yang efisien, sedangkan **pointer** memungkinkan akses langsung ke data melalui alamat memori, sehingga memberikan fleksibilitas dan efisiensi yang lebih tinggi dalam pengolahan data. Penggunaan parameter referensi dalam fungsi memperkuat konsep modular programming karena memungkinkan perubahan nilai variabel tanpa harus membuat salinan data baru. Sementara itu, penerapan operasi aritmetika pada tipe data numerik seperti float membantu dalam memperoleh hasil perhitungan yang lebih tepat dan akurat. Dengan memahami keterkaitan antar konsep tersebut, seorang programmer dapat merancang program yang lebih efisien, terstruktur, serta mampu menyelesaikan berbagai permasalahan komputasi dengan cara yang optimal.

## 7. Referensi
1.  1. Kusuma, A. P., & Rahmadani, D. (2023). _Implementasi Struktur Data Array dalam Efisiensi Pengolahan Data pada Bahasa Pemrograman C++_. Jurnal Teknologi dan Informatika, 9(2), 115–124.
2. Santoso, R., & Wirawan, T. (2022). _Analisis Pemanfaatan Pointer untuk Efisiensi Memori dalam Bahasa Pemrograman C++_. Jurnal Ilmiah Informatika dan Komputer, 7(1), 45–53.