#include "multilist.h"
#include <iostream>

using namespace std;

void createList(list_induk &L) {
    L.first = Nil;
    L.last  = Nil;
}

address_induk alokasi(infotype data) {
    address_induk node = new elemen_induk;

    node->info = data;
    node->next = Nil;
    node->prev = Nil;

    node->anak.first = Nil;
    node->anak.last  = Nil;

    return node;
}

void insertLastInduk(list_induk &L, address_induk node) {
    if (L.first != Nil) {
        node->prev = L.last;
        L.last->next = node;
        L.last = node;
    } else {
        L.first = node;
        L.last  = node;
    }
}

address_induk findInduk(list_induk L, infotype key) {
    for (address_induk p = L.first; p != Nil; p = p->next) {
        if (p->info == key) {
            return p;
        }
    }
    return Nil;
}
