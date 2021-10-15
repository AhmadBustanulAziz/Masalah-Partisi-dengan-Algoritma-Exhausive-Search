/*
Nama      : Ahmad Bustanul Aziz
NIM       : 24060118120022
Matkul    : Analisis dan Strategi Algoritma
Tanggal   : 14 Oktober 2021
Deskripsi : Masalah Partisi dengan Algoritma Exhausive Search
*/

#include <iostream>

using namespace std;

int partisi(int himpunan[], int n, int himpunan2[], int himpunan3[]) {
    //Kamus Lokal
    int i, j, k=0, l, N=n, p=0, Total = 0, jmlMasing = 0, jumlah1 = 0, jumlah2 = 0, indexSisa;

    //Algoritma
    for (i=0; i<N; i++) {
        Total += himpunan[i];
    }
    jmlMasing = Total/2;

    for (j=0; j<N; j++) {
        jumlah1 += himpunan[j];
        if (jumlah1 > jmlMasing) {
            jumlah1 -= himpunan[j];
            himpunan2[k] = j;
            k++;
        } else {
            himpunan3[p] = j;
            p++;
        }
    }

    for (l=0; l<N/2; l++) {
        indexSisa = himpunan2[l];
        jumlah2 += himpunan[indexSisa];
    }

    if (jumlah1 == jumlah2) {
        return jumlah1;
    } else {
        return 0;
    }
}
int main() {
    //Kamus
    int i, j, k, n, index, Himpunan[100], Himpunan2[100], Himpunan3[100], jumlahBagianPartisi ;
    //Algoritma
    cout << "Masukkan Nilai n = ";
    cin >> n;
    cout << "Masukkan Himpunan = ";
    for (i=0; i<n; i++) {
        cin >> Himpunan[i];
    }

    jumlahBagianPartisi = partisi(Himpunan, n, Himpunan2, Himpunan3);

    if (jumlahBagianPartisi > 0) {
        for (j=0; j<n/2; j++) {
            index = Himpunan2[j];
            cout << Himpunan[index];
            cout << " ";
        }
        cout << "\n";
        for (k=0; k<n/2; k++) {
            index = Himpunan3[k];
            cout << Himpunan[index];
            cout << " ";
        }
        cout << "\nMasing-masing partisi berjumlah = ";
        cout << jumlahBagianPartisi;
    } else {
        cout << "Solusi tidak ditemukan";
    }


}
