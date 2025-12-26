#include "multilist.h"
#include <iostream>

using namespace std;

address_anak alokasiAnak(infotype nilai) {
    address_anak nodeBaru = new elemen_anak;
    nodeBaru->info = nilai;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void insertLastAnak(list_anak &LA, address_anak node) {
    if (LA.first != Nil) {
        node->prev = LA.last;
        LA.last->next = node;
        LA.last = node;
    } else {
        LA.first = node;
        LA.last  = node;
    }
}

void printInfo(list_induk L) {
    for (address_induk pInduk = L.first; pInduk != Nil; pInduk = pInduk->next) {
        cout << "Induk: " << pInduk->info << endl;

        address_anak pAnak = pInduk->anak.first;
        while (pAnak != Nil) {
            cout << "  Anak: " << pAnak->info << endl;
            pAnak = pAnak->next;
        }
    }
}
