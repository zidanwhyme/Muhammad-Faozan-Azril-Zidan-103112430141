#ifndef MULTILIST_H_INCLUDED
#define MULTILIST_H_INCLUDED

#define Nil NULL

typedef int infotype;

struct elemen_induk;
struct elemen_anak;

typedef elemen_induk* address_induk;
typedef elemen_anak*  address_anak;

struct list_anak {
    address_anak first;
    address_anak last;
};

struct elemen_anak {
    infotype info;
    address_anak prev;
    address_anak next;
};

struct elemen_induk {
    infotype info;
    list_anak anak;
    address_induk prev;
    address_induk next;
};

struct list_induk {
    address_induk first;
    address_induk last;
};

void createList(list_induk &L);

address_induk alokasi(infotype x);
void insertLastInduk(list_induk &L, address_induk P);
address_induk findInduk(list_induk L, infotype x);

address_anak alokasiAnak(infotype x);
void insertLastAnak(list_anak &LA, address_anak PA);

void printInfo(list_induk L);

#endif
