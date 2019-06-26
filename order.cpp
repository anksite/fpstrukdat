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

void addData(string Pesanan,int Kuantitas,string Adress,string Jasa)
{
	++akhir; //menambah nilai Akhir dengan 1
	queueOrder[akhir].idOrder	= to_string(1000+akhir);
	queueOrder[akhir].barang	= Pesanan ;
	queueOrder[akhir].jumlah	= Kuantitas;
	queueOrder[akhir].alamat	= Adress;
	queueOrder[akhir].jasaKirim	= Jasa;	
}

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

void tampil(){
	system("CLS");
	if(!empty()){
		cout<<"Id Order\tNamaBarang\tJumlah\tAlamat\tJasa Kirim\n";
		for(int i=awal; i<=akhir; i++){
			cout<<queueOrder[i].idOrder<<"\t\t"<<queueOrder[i].barang<<"\t"<<queueOrder[i].jumlah<<"\t"<<queueOrder[i].alamat<<"\t"<<queueOrder[i].jasaKirim<<"\n";
		}
	}else{
		cout<<"DATA KOSONG\n";
	}
	
}

//MAHESA
void tambah(){
	//inQueue : Menambah item di akhir index
	if (full()){
		cout<<"Maaf Pemesanan Kami Penuh,,Silahkan Order dilain Waktu";
	}else{
		int Kuantitas;
		string Adress;
		char Pesanan[30];
		string Jasa;
		
		cout<<" - Silahkan masukan nama barang pesanan : ";
		//cin>>Pesanan;
		cin.getline(Pesanan,sizeof(Pesanan));
		cout<<" - Jumlah barang yang akan dipesan : ";
		cin>>Kuantitas;
		cout<<" - Alamat anda : ";
		cin>>Adress;
		cout<<" - Penggunaan Jasa Kirim : ";
		cin>>Jasa;
		
		addData(Pesanan,Kuantitas,Adress,Jasa);
		
		cout<<"Data Berhasil Masuk";
	}	
}

//HADI
void urut(){
	
}

//MITHA & ISQIA
void cari(){
	
}

//FAQIH
void proses(){//deQueeu : Mengambilitem di awal index
	system("CLS");

	if(!empty()){
		cout<<"Silahkan Proses Data Berikut...."<<endl;
		cout<<"Id Order\tNamaBarang\tJumlah\tAlamat\tJasa Kirim\n";
		cout<<queueOrder[0].idOrder<<"\t\t"<<queueOrder[0].barang<<"\t"<<queueOrder[0].jumlah<<"\t"<<queueOrder[0].alamat<<"\t"<<queueOrder[0].jasaKirim<<"\n";
		cout<<endl;
		
		for(int i=awal;i<akhir;i++){
			queueOrder[i].idOrder=queueOrder[i+1].idOrder;
			queueOrder[i].alamat=queueOrder[i+1].alamat;
			queueOrder[i].barang=queueOrder[i+1].barang;
			queueOrder[i].jasaKirim=queueOrder[i+1].jasaKirim;
			queueOrder[i].jumlah=queueOrder[i+1].jumlah;
		}
		akhir--;
	}else{
		cout<<"Antrean kosong\n";
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
