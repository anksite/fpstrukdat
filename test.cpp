#include <iostream>
#include <string>
#include <string.h>

using namespace std;

struct order {
    char namaBarang[1][60];
    int idOrder;
    char jasaKirim[1][15];
    char alamat[3][50];
    int jumlah;

};

int awal =-1, akhir=-1;
order queryOrder[10];

int main() {awal++;

    akhir++;
    queryOrder[akhir].idOrder = 1001; //inisilaisai id order
    strcpy(queryOrder[akhir].namaBarang[0], "Tisue Basah"); //inisialisai nama barang
    strcpy(queryOrder[akhir].jasaKirim[0], "JNT"); // inisialisai jasa kirim
    strcpy(queryOrder[akhir].alamat[0], "Depok"); // inisialisasi alamat(kecamatan)
    strcpy(queryOrder[akhir].alamat[1], "Sleman"); // inisialisai alamat(kabupaten)
    strcpy(queryOrder[akhir].alamat[2], "Yogyakarta"); // inisialisasi alamat(provinsi/kota)
    queryOrder[akhir].jumlah = 1000; // inisialisai jumlah

    akhir++;
    queryOrder[akhir].idOrder = 1002; //inisilaisai id order
    strcpy(queryOrder[akhir].namaBarang[0], "Jas Hujan"); //inisialisai nama barang
    strcpy(queryOrder[akhir].jasaKirim[0], "TIKI"); // inisialisai jasa kirim
    strcpy(queryOrder[akhir].alamat[0], "Depok"); // inisialisasi alamat(kecamatan)
    strcpy(queryOrder[akhir].alamat[1], "Sleman"); // inisialisai alamat(kabupaten)
    strcpy(queryOrder[akhir].alamat[2], "Yogyakarta"); // inisialisasi alamat(provinsi/kota)
    queryOrder[akhir].jumlah = 500; // inisialisai jumlah

    akhir++;
    queryOrder[akhir].idOrder = 1003; //inisilaisai id order
    strcpy(queryOrder[akhir].namaBarang[0], "Jaket Kulit"); //inisialisai nama barang
    strcpy(queryOrder[akhir].jasaKirim[0], "J&T"); // inisialisai jasa kirim
    strcpy(queryOrder[akhir].alamat[0], "Cangkringan"); // inisialisasi alamat(kecamatan)
    strcpy(queryOrder[akhir].alamat[1], "Sleman"); // inisialisai alamat(kabupaten)
    strcpy(queryOrder[akhir].alamat[2], "Yogyakarta"); // inisialisasi alamat(provinsi/kota)
    queryOrder[akhir].jumlah = 15; // inisialisai jumlah
    
    akhir++;
    queryOrder[akhir].idOrder = 1004; //inisilaisai id order
    strcpy(queryOrder[akhir].namaBarang[0], "Sepatu Adidas"); //inisialisai nama barang
    strcpy(queryOrder[akhir].jasaKirim[0], "TIKI"); // inisialisai jasa kirim
    strcpy(queryOrder[akhir].alamat[0], "Banguntapan"); // inisialisasi alamat(kecamatan)
    strcpy(queryOrder[akhir].alamat[1], "Bantul"); // inisialisai alamat(kabupaten)
    strcpy(queryOrder[akhir].alamat[2], "Yogyakarta"); // inisialisasi alamat(provinsi/kota)
    queryOrder[akhir].jumlah = 2; // inisialisai jumlah
    
    akhir++;
    queryOrder[akhir].idOrder = 1005; //inisilaisai id order
    strcpy(queryOrder[akhir].namaBarang[0], "Lamborghini"); //inisialisai nama barang
    strcpy(queryOrder[akhir].jasaKirim[0], "JNE"); // inisialisai jasa kirim
    strcpy(queryOrder[akhir].alamat[0], "Larangan"); // inisialisasi alamat(kecamatan)
    strcpy(queryOrder[akhir].alamat[1], "Brebes"); // inisialisai alamat(kabupaten)
    strcpy(queryOrder[akhir].alamat[2], "Jawa Tengah"); // inisialisasi alamat(provinsi/kota)
    queryOrder[akhir].jumlah = 10; // inisialisai jumlah

    int par3, par4, par5;
    for (int i=awal; i<=akhir; i++) {
        for (int j = i+1; j<=akhir; j++) {
            par3 = strcmp(queryOrder[i].alamat[2],queryOrder[j].alamat[2]);
            par4 = strcmp(queryOrder[i].alamat[1],queryOrder[j].alamat[1]);
            par5 = strcmp(queryOrder[i].alamat[0],queryOrder[j].alamat[0]);

            if (par3>0) {
                order temp;
                temp = queryOrder[i];
                queryOrder[i] = queryOrder[j];
                queryOrder[j] = temp;  
            } else if (par3==0){
                if(par4>0){
                    order temp1;
                    temp1 = queryOrder[i];
                    queryOrder[i] = queryOrder[j];
                    queryOrder[j] = temp1; 
                } else if (par4==0)
                {
                    if (par5>0) {
                        order temp2;
                temp2 = queryOrder[i];
                queryOrder[i] = queryOrder[j];
                queryOrder[j] = temp2; 
                    }
                }
                
            }
        }
    }

    for (int i=awal; i<=akhir; i++) {
    cout<<queryOrder[i].idOrder<<"\t"<<queryOrder[i].namaBarang[0]<<"\t"<<queryOrder[i].jumlah<<"\t"<<queryOrder[i].jasaKirim[0]<<"\t"<<queryOrder[i].alamat[0]<<", "<<queryOrder[i].alamat[1]<<", "<<queryOrder[i].alamat[2]<<endl;
    };
    
    return 0;
}