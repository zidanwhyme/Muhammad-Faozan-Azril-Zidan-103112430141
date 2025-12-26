#include <iostream>
#include "circular.h"

using namespace std;

int main() {
    List data;
    createList(data);

    cout << "Uji operasi insert pada circular list" << endl;

    // Data awal
    infotype a = {"01", "Ali", '1', 3.3};
    infotype b = {"04", "Danu", '1', 4.0};
    infotype c = {"06", "Fahmi", '1', 3.45};

    insertFirst(data, alokasi(a));
    insertFirst(data, alokasi(b));
    insertLast(data, alokasi(c));

    // Insert setelah Ali
    address posAli = findElm(data, "01");
    if (posAli != Nil) {
        infotype d = {"02", "Bobi", '1', 3.71};
        insertAfter(data, posAli, alokasi(d));
    }

    // Insert setelah Bobi
    address posBobi = findElm(data, "02");
    if (posBobi != Nil) {
        infotype e = {"03", "Cindi", 'p', 3.5};
        insertAfter(data, posBobi, alokasi(e));
    }

    // Insert setelah Danu
    address posDanu = findElm(data, "04");
    if (posDanu != Nil) {
        infotype f = {"05", "Eli", 'p', 3.4};
        insertAfter(data, posDanu, alokasi(f));
    }

    // Tambah data di akhir
    insertLast(data, alokasi({"07", "Gita", 'p', 3.75}));

    // Insert setelah Gita
    address posGita = findElm(data, "07");
    if (posGita != Nil) {
        infotype g = {"08", "Hilmi", '1', 3.3};
        insertAfter(data, posGita, alokasi(g));
    }

    // Tampilkan seluruh isi list
    printInfo(data);

    return 0;
}
