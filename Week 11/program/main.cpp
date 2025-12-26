#include <iostream>
#include "multilist.h"

using namespace std;

int main() {
    list_induk data;
    createList(data);

    address_induk firstInduk = alokasi(1);
    insertLastInduk(data, firstInduk);

    address_anak firstChild = alokasiAnak(10);
    insertLastAnak(firstInduk->anak, firstChild);

    address_induk secondInduk = alokasi(2);
    insertLastInduk(data, secondInduk);

    address_anak secondChild = alokasiAnak(20);
    insertLastAnak(secondInduk->anak, secondChild);

    printInfo(data);

    return 0;
}
