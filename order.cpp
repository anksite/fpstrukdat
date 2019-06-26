#include <iostream>
#include <string>
using namespace std;

#define MAX 100

struct order{
	string idOrder;
	string barang;
	int jumlah;
	string alamat;
	string jasaKirim;
};

int awal=-1, akhir=-1;

order queueOrder[MAX];

void init(){
    ++awal;
    ++akhir;
	queueOrder[akhir].idOrder	    = to_string(1000+akhir);
	queueOrder[akhir].barang		= "TAS BIRU";
	queueOrder[akhir].jumlah		= 1;
	queueOrder[akhir].alamat		= "BANTUL";
	queueOrder[akhir].jasaKirim	    = "JNE"; //JNE, J&T, TIKI, POS
	
	++akhir;
	queueOrder[akhir].idOrder		= to_string(1000+akhir);
	queueOrder[akhir].barang		= "BUKU BIRU";
	queueOrder[akhir].jumlah		= 8;
	queueOrder[akhir].alamat		= "SLEMAN";
	queueOrder[akhir].jasaKirim	    = "TIKI";
	
	++akhir;
	queueOrder[akhir].idOrder		= to_string(1000+akhir);
	queueOrder[akhir].barang		= "PAYUNG BIRU";
	queueOrder[akhir].jumlah		= 3;
	queueOrder[akhir].alamat		= "BALI";
	queueOrder[akhir].jasaKirim	    = "POS";
}

void tampil(){
	system("CLS");
	cout<<"Id Order\tNamaBarang\tJumlah\tAlamat\tJasa Kirim\n";
	for(int i=awal; i<=akhir; i++){
		cout<<queueOrder[i].idOrder<<"\t\t"<<queueOrder[i].barang<<"\t"<<queueOrder[i].jumlah<<"\t"<<queueOrder[i].alamat<<"\t"<<queueOrder[i].jasaKirim<<"\n";
	}
}


//MAHESA
void tambah(){//inQueue : Menambah item di akhir index

}

//HADI
void urut(){
	
}

//MITHA & ISQIA
void cari(){
	
}

void proses(){//deQueeu : Mengambilitem di awal index
	
}


bool full(){
	if(akhir==MAX-1){
		return true;
	}else{
		return false;
	}
}

bool empty(){
	if(akhir==-1){
		return true;
	}else{
		return false;
	}
}

void menu(){
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
		case 1: tampil(); 	break;
		case 2: tambah(); 	break;
		case 3: urut(); 	break;
		case 4: cari(); 	break;
		case 5: proses(); 	break;
	}
	
	if(pilih!=6){
		menu();
	}
}

main(){
	init();
	menu();
}
