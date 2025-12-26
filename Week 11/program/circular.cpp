#include "circular.h"

void createList(List &L) {
    L.first = Nil;
}

address alokasi(infotype data) {
    address node = new elemen;
    node->info = data;
    node->next = Nil;
    return node;
}

void insertFirst(List &L, address node) {
    if (L.first == Nil) {
        L.first = node;
        node->next = node;
    } else {
        address tail = L.first;
        while (tail->next != L.first) {
            tail = tail->next;
        }
        node->next = L.first;
        tail->next = node;
        L.first = node;
    }
}

void insertLast(List &L, address node) {
    if (L.first == Nil) {
        insertFirst(L, node);
    } else {
        address tail = L.first;
        while (tail->next != L.first) {
            tail = tail->next;
        }
        tail->next = node;
        node->next = L.first;
    }
}

void insertAfter(List &L, address prev, address node) {
    if (prev != Nil) {
        node->next = prev->next;
        prev->next = node;
    }
}

void deleteFirst(List &L, address &node) {
    if (L.first == Nil) {
        node = Nil;
        return;
    }

    node = L.first;

    if (node->next == node) {
        L.first = Nil;
    } else {
        address tail = node;
        while (tail->next != L.first) {
            tail = tail->next;
        }
        L.first = node->next;
        tail->next = L.first;
    }
    node->next = Nil;
}

void deleteLast(List &L, address &node) {
    if (L.first == Nil) {
        node = Nil;
        return;
    }

    address curr = L.first;
    address prev = Nil;

    while (curr->next != L.first) {
        prev = curr;
        curr = curr->next;
    }

    node = curr;

    if (prev == Nil) {
        L.first = Nil;
    } else {
        prev->next = L.first;
    }
    node->next = Nil;
}

address findElm(List L, string nim) {
    if (L.first == Nil) return Nil;

    address p = L.first;
    do {
        if (p->info.nim == nim) {
            return p;
        }
        p = p->next;
    } while (p != L.first);

    return Nil;
}

void printInfo(List L) {
    if (L.first == Nil) {
        cout << "List Kosong" << endl;
        return;
    }

    address p = L.first;
    do {
        cout << "Nama : " << p->info.nama << endl;
        cout << "NIM  : " << p->info.nim << endl;
        cout << "L/P  : " << p->info.jenis_kelamin << endl;
        cout << "IPK  : " << p->info.ipk << endl;
        cout << endl;

        p = p->next;
    } while (p != L.first);
}
