#include <iostream>

using namespace std;

int main() {
    double total_pembelian, diskon;
    cout << "Total uang yang telah kamu belanjakan: Rp.";
    cin >> total_pembelian;
    if(total_pembelian >= 40000) {
        diskon = 0.1 * total_pembelian;
        cout << "Yeay kamu mendapatkan diskon sebesar" << diskon << "";
    } else {
        cout << "Maaf kamu belum bisa mendapatan diskon, karena total belanja kamu belum memenuhi minimal diskon";
    }
}