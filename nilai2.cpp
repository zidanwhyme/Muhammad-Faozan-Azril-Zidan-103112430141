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