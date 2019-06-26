#include <iostream>
#include <string>
using namespace std;

#define MAX 10

struct order{
	string idOrder;
	string barang;
	int jumlah;
	string alamat;
	string jasaKirim;
};

int awal;
int akhir = 2;

order queueOrder[MAX];

void tampil(){
	//system("CLS");
	cout<<"Id Order\tNamaBarang\tJumlah\tAlamat\tJasa Kirim\n";
	for(int i=0; i<akhir; i++){
		cout<<queueOrder[i].idOrder<<"\t\t"<<queueOrder[i].barang<<"\t"<<queueOrder[i].jumlah<<"\t"<<queueOrder[i].alamat<<"\t"<<queueOrder[i].jasaKirim<<"\n";
	}
}

void tambahOrder(int i, string idOrder, string barang, string jumlah, string alamat, string jasaKirim){

}

main(){
	queueOrder[0].idOrder	= "1001";
	queueOrder[0].barang	= "TAS BIRU";
	queueOrder[0].jumlah	= 1;
	queueOrder[0].alamat	= "BANTUL";
	queueOrder[0].jasaKirim	= "JNE"; //JNE, J&T, TIKI, POS
	
	queueOrder[1].idOrder	= "1002";
	queueOrder[1].barang	= "BUKU BIRU";
	queueOrder[1].jumlah	= 8;
	queueOrder[1].alamat	= "SLEMAN";
	queueOrder[1].jasaKirim	= "TIKI";
	
	int pilih;
	cout<<"PROSES ORDER ONLINE SHOP\n";
	cout<<"1. Tampilkan Order\n";
	cout<<"2. Tambah Order\n";
	cout<<"3. Urutkan\n";
	cout<<"4. Cari Order\n";
	cout<<"5. Proses Order\n";
	cout<<"6. Keluar\n";
	cout<<"Input Pilihan: "; cin>>pilih;
	
	switch(pilih){
		case 1: tampil(); break;
	}
	
	if(pilih!=6){
		main();
	}
}