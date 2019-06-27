#include <iostream>
#include <string.h>
using namespace std;

#define MAX 100

struct order{
	string idOrder;
	string barang;
	int jumlah;
	string alamat[3];
	string jasaKirim;
};


int awal=-1, akhir=-1;

order queueOrder[MAX];

void addData(string Pesanan,int Kuantitas, string kec, string kab, string prov, string Jasa){
	++akhir; //menambah nilai Akhir dengan 1
	queueOrder[akhir].idOrder	= to_string(1000+akhir);
	queueOrder[akhir].barang	= Pesanan ;
	queueOrder[akhir].jumlah	= Kuantitas;
	queueOrder[akhir].alamat[0]	= kec;
	queueOrder[akhir].alamat[1]	= kab;
	queueOrder[akhir].alamat[2]	= prov;
	queueOrder[akhir].jasaKirim	= Jasa;	
}

void init(){
    ++awal;
	addData("TAS BIRU",		1, "KASIHAN", 	"BANTUL", "YOGYAKARTA",	"JNE");
	addData("BUKU BIRU",	8, "DEPOK", 	"SLEMAN", "YOGYAKARTA",	"TIKI");
	addData("PAYUNG BIRU",	3, "KRETEK", 	"BANTUL", "YOGYAKARTA",	"POS");
	addData("SEPATU MERAH",	2, "SALEM", 	"BREBES", "JAWA TENGAH","J&T");
	addData("LAPTOP APIK",	1, "GUCI", 		"TEGAL",  "JAWA TENGAH","NINJA EXPRESS");
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
		cout<<"Id Order\tNama Barang\tJumlah\tProvinsi\tKabupaten\tKecamatan\tJasa Kirim\n";
		for(int i=awal; i<=akhir; i++){
			cout<<queueOrder[i].idOrder<<"\t\t"
				<<queueOrder[i].barang<<"\t"
				<<queueOrder[i].jumlah<<"\t"
				<<queueOrder[i].alamat[2]<<"\t"
				<<queueOrder[i].alamat[1]<<"\t\t"
				<<queueOrder[i].alamat[0]<<"\t\t"
				<<queueOrder[i].jasaKirim<<"\n";
		}
	}else{
		cout<<"DATA KOSONG\n";
	}
	
}

//MAHESA
void tambah(){
	//inQueue : Menambah item di akhir index
	if (full()){
		system("CLS");
		cout<<"Maaf Pemesanan Kami Penuh, Silahkan Order dilain Waktu";
	}else{
		int Kuantitas;
		string prov, kab, kec;
		string Pesanan;
		string Jasa;
		
		cout<<" - Silahkan masukan nama barang pesanan : ";
		cin.ignore();getline(cin, Pesanan);
		cout<<" - Jumlah barang yang akan dipesan : ";
		cin>>Kuantitas;
		cout<<" - Input Provinsi : "; 		cin.ignore();getline(cin, prov);
		cout<<" - Input Kabupaten : "; 	getline(cin, kab);
		cout<<" - Input Kecamatan : ";	getline(cin, kec);
		cout<<" - Penggunaan Jasa Kirim : ";
		cin>>Jasa;
		
		addData(Pesanan,Kuantitas,kec,kab,prov,Jasa);
		
		cout<<"Data Berhasil Masuk\n";
	}	
}

void urutNama(){
    int par1;
    for (int i=awal; i<=akhir; i++) {
        for (int j = i+1; j<=akhir; j++) {
        	char barang1[50];
        	char barang2[50];
        	
        	strcpy(barang1, queueOrder[i].barang.c_str());
        	strcpy(barang2, queueOrder[j].barang.c_str());
        	
            par1 = strcmp(barang1, barang2);
            if (par1>0) {
                order temp;
                temp = queueOrder[i];
                queueOrder[i] = queueOrder[j];
                queueOrder[j] = temp;
            }
        }
    }
    
    tampil();
}

void urutKirim(){
	int par2;
    for (int i=awal; i<=akhir; i++) {
        for (int j = i+1; j<=akhir; j++) {
        	char jasa1[50];
        	char jasa2[50];
        	
        	strcpy(jasa1, queueOrder[i].jasaKirim.c_str());
        	strcpy(jasa2, queueOrder[j].jasaKirim.c_str());
        	
            par2 = strcmp(jasa1, jasa2);
            if (par2>=0) {
                order temp;
                temp = queueOrder[i];
                queueOrder[i] = queueOrder[j];
                queueOrder[j] = temp;
            }
        }
    }
    tampil();
}

void urutAlamat(){
	int par3, par4, par5;
    for (int i=awal; i<=akhir; i++) {
    	for (int j = i+1; j<=akhir; j++) {
    		char kec1[50];
        	char kec2[50];
			char kab1[50];
        	char kab2[50];
        	char prov1[50];
        	char prov2[50];
        	
        	strcpy(kec1, queueOrder[i].alamat[0].c_str());
        	strcpy(kec2, queueOrder[j].alamat[0].c_str());
			strcpy(kab1, queueOrder[i].alamat[1].c_str());
        	strcpy(kab2, queueOrder[j].alamat[1].c_str());
        	strcpy(prov1, queueOrder[i].alamat[2].c_str());
        	strcpy(prov2, queueOrder[j].alamat[2].c_str());
    		
            par3 = strcmp(prov1, prov2);
            par4 = strcmp(kab1, kab2);
            par5 = strcmp(kec1, kec2);

            if (par3>0) {
                order temp;
                temp = queueOrder[i];
                queueOrder[i] = queueOrder[j];
                queueOrder[j] = temp;  
            }else if(par3==0){
                if(par4>0){
                    order temp1;
                    temp1 = queueOrder[i];
                    queueOrder[i] = queueOrder[j];
                    queueOrder[j] = temp1; 
                }else if(par4==0){
                    if(par5>0){
                        order temp2;
                		temp2 = queueOrder[i];
                		queueOrder[i] = queueOrder[j];
                		queueOrder[j] = temp2; 
                    }
                }
            }
        }
    }
}

//HADI
void urut(){
	int pilih;
	cout<<"\nURUTKAN BERDASARKAN\n";
	cout<<"1. Nama Barang\n";
	cout<<"2. Jasa Kirim\n";
	cout<<"3. Alamat\n";
	cout<<"Input Pilihan: "; cin>>pilih;
	
	switch(pilih){
		case 1: urutNama(); break;
		case 2: urutKirim(); break;
		case 3: urutAlamat(); break;			
	}
}

//MITHA & ISQIA
void cari(){
	string idOrder;
	bool ketemu;
	cout<<"Masukan idOrder yang akan dicari:"; cin>>idOrder;
	int hasil;	
		
	for(int i=0;i<=akhir;i++){
		if (queueOrder[i].idOrder==idOrder){
			ketemu= true;
			hasil = i;
		}
	}
			
	if(ketemu){
		system("CLS");
		cout<<"IdOrder "<<idOrder<<" yang dicari ada di dalam data"<<endl;		
		cout<<"Id Order\tNamaBarang\tJumlah\tProvinsi\tKabupaten\tKecamatan\tJasa Kirim\n";
		cout<<queueOrder[hasil].idOrder<<"\t\t"
			<<queueOrder[hasil].barang<<"\t"
			<<queueOrder[hasil].jumlah<<"\t"
			<<queueOrder[hasil].alamat[2]<<"\t"
			<<queueOrder[hasil].alamat[1]<<"\t\t"
			<<queueOrder[hasil].alamat[0]<<"\t\t"
			<<queueOrder[hasil].jasaKirim<<"\n";
	}else{
		system("CLS");
		cout<<"IdOrder tidak ditemukan"<<endl;
	}
			
	cout<<endl;	
}

//FAQIH
void proses(){//deQueeu : Mengambilitem di awal index
	system("CLS");

	if(!empty()){
		cout<<"Silahkan Proses Data Berikut...."<<endl;
		cout<<"Id Order\tNamaBarang\tJumlah\tProvinsi\tKabupaten\tKecamatan\tJasa Kirim\n";
		cout<<queueOrder[0].idOrder<<"\t\t"
				<<queueOrder[0].barang<<"\t"
				<<queueOrder[0].jumlah<<"\t"
				<<queueOrder[0].alamat[2]<<"\t"
				<<queueOrder[0].alamat[1]<<"\t\t"
				<<queueOrder[0].alamat[0]<<"\t\t"
				<<queueOrder[0].jasaKirim<<"\n";
		cout<<endl;
		
		for(int i=awal;i<akhir;i++){
			queueOrder[i] = queueOrder[i+1];
		}
		akhir--;
	}else{
		cout<<"Antrean kosong\n";
	}	
}

void menu(){
	int pilih;
	cout<<"\nPROSES ORDER ONLINE SHOP\n";
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
