/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
*   Modul               : 3 - Structure and Dynamic Arrays
*   Hari dan Tanggal    : Senin, 27 April 2026
*   Nama (NIM)          : Jeva Steve Sinaga (13224002)
*   Nama File           : soal1.c
*   Deskripsi           :   Sebuah pusat pemantauan badai menerima data kecepatan angin secara terus-menerus, tetapi jumlah
                            data yang masuk tidak diketahui sejak awal. Sistem harus tetap mampu menampung semua
                            pembacaan sampai sinyal penghenti diterima. Setelah pengumpulan selesai, tim analis ingin melihat
                            data yang sudah diurutkan dan mengetahui median sebagai gambaran kondisi umum badai selama
                            periode pengamatan.
                            Simpan data ke array dinamis hingga sentinel -1, lalu urutkan dan cari median.
                            Kondisi/Aturan
                            1. Input berakhir saat membaca -1
                            2. Semua nilai sebelum -1 dianggap data valid
                            3. Jumlah data minimal 1
                            4. Setelah diurutkan naik:
                                • jika banyak data ganjil, median adalah elemen tengah
                                • jika genap, median adalah rata-rata dua elemen tengah, dicetak .50 atau .00 bila perlu
*/

#include <stdio.h>
#include <stdlib.h>

 int main (){
    int *data = NULL;
    int n = 0;
    int x;
    while(1){
        scanf("%d", &x);
        if(x == -1){
            break;
        }
        n++;
        data = (int*) realloc(data, n * sizeof(int));
        data[n-1] = x;
    }
    printf("COUNT %d ", n);
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(data[j] > data[j+1]){
                int temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
    printf("SORTED ");
    for(int i = 0; i < n; i++){
        printf("%d ", data[i]);
    }
    
    double median;
    if(n % 2 == 1){
        median = data[n/2];
    } else {
        median = (data[n/2 - 1] + data[n/2]) / 2.0;
    }
    printf("MEDIAN %.2f", median);
    free(data);
    return 0;
 }
