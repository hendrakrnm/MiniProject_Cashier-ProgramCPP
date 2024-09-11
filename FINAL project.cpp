#include <iostream>
#include <string>
#include <iomanip> //berfungsi untuk bisa membaca setw (library untuk setw)
#include <ctime>
#include <windows.h> //untuk library waktu
using namespace std;



struct daftar {  //struct untuk mendata produk , kode dan harganya
    string kodeNomor;
    string namaProduk;
    double long harga;
};
    

void swap(daftar &a, daftar &b) { //berfungsi untuk mengsorting; sc chatgpt
    daftar temp = a;
    a = b;
    b = temp;
}

void bubbleSort(daftar data[], int size) { //program sorting dg bubble sort harga agar bisa dimulai dari yang rendah chat gpt
    for (int i=0; i<size-1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (data[j].harga > data[j + 1].harga) {
                swap(data[j], data[j + 1]);
            }
        }
    }
}

void bubble(daftar minum[], int minumsize) { //program sorting harga agar bisa dimulai dari yang rendah
    for (int i = 0; i < minumsize - 1; i++) {
        for (int j = 0; j < minumsize - i - 1; j++) {
            if (minum[j].harga > minum[j + 1].harga) {
                swap(minum[j], minum[j + 1]);
            }
        }
    }
}
    
void tabel(const daftar data[], int jbrg[], int total, int jmlh, int sum[], string brgterpilih[], string nama){ /*sub fungsi untuk
 menampilkan tabel total akhir; sc chatgpt*/
    int diskon; 
    string dskn;
    if (total>=50000 && total<100000) { // untuk memberi diskon jika total barang yang dibeli lebih dari 50 ribu dan kurang dari 100 ribu
        dskn="3%";
        diskon=total*0.03;
    }
    else if (total>=100000 && total<1000000){ // untuk memberi diskon jika total barang yang dibeli lebih dari 100 ribu dan kurang dari 1 juta
        dskn="6%";
         diskon=total*0.06;
    }
    else if (total>=1000000){ // untuk memberi diskon jika total barang yang dibeli lebih dari 1 juta
        dskn="10%";
         diskon=total*0.1;
    }
	else diskon=0; // mengembalikan ke nilai asli total jika tidak sesuai persyaratan diskon
    

    //PROGRAM UNTUK BISA MENAMPILKAN WAKTU SAAT PEMBELIAN; sc: youtube"Ngoding yuk" https://youtu.be/ZlCIQP9QGSc?si=w9s-gqYm62efv6WE
    using std::cin;
	bool loop=false;
	do {
		time_t now=time(0);
		tm *local=localtime(&now);
		local ->tm_hour -= 12;
		system("cls");
		cout<<ctime(&now);
		Sleep(1000);
	} while(loop);
	cin.get();

	
	//MENAMPILKAN TABEL STRUK PEMBELIAN BERUPA BARANG YANG DIPILIH DAN TOTAL PEMBAYARAN
	cout<<"\n                      SCIENCE MART                     \n";
    cout<<"                       FMIPA UGM                       \n\n";
    cout<<"Pembeli: "<<nama<<endl;
    //untuk menampilkan tabel kode, daftar barang dan harga
    cout << "========================================================\n"; 
    cout << "| No |" << setw(27) << " produk" << setw(14) << "| Jmlh Pcs |" << setw(1) << "Harga   |\n";
    cout << "========================================================\n";

    for (int i = 0; i < jmlh + 3; i++) {
        if (i<jmlh){
            cout << "| " << setw(2) << i + 1 << " | " << setw(26) << brgterpilih[i] <<setw(2) <<"| " <<setw(2)<< jbrg[i]<<setw(7);
			cout<<" pcs"<< "|" << setw(4) << "Rp. "<<setw(6)<<sum[i] << "|\n";
        } else {
            cout << "|    |" <<setw(27)<<"   "<<"|"<< setw(10) << " " << "|" << setw(10) << " " << "|\n";
        }
    }
    
    cout << "--------------------------------------------------------\n";
    cout << "|    |" <<setw(21)<<"   "<<" "<< setw(16) << "Total" << "|" << setw(4) << "Rp. "<<setw(6)<<total << "|\n";
    cout << "|    |" <<setw(21)<<"   "<<" "<< setw(16) << "Diskon" << "|" << setw(10) << dskn << "|\n";
    cout << "|    |" <<setw(21)<<"   "<<" "<< setw(10) << "Total Pembayaran" << "|" << setw(4) <<"Rp. "<<setw(6)<<total-diskon << "|\n";
    cout << "--------------------------------------------------------\n";
    
}
    
 
    
// MEMASUKAN INPUT USER UNTUK DICARI KE DAFTAR DATA YANG TELAH DIBUAT DNEGAN MENGGUNAKAN STRUCT
int pembelian(int jmlh, const daftar data[], const daftar minum[], int size, int minumsize, string nama) {
    int total = 0,  sum[17], jbrg[30]; /* deklarasi array untuk total (berfungsi menyimpan hasil total),
	sum (menyimpan hasil kali harga barang dengan jumlah beli)*/
	string input[30], brgterpilih[30]; /*jbrg(menyimpan jumlah barang yang akan dibel),
	brgterpilih(menyimpan barang yang telah dipilih user untuk nantinya dimasukan*/
    
	for (int i = 0; i < jmlh; i++) { // kedalam tabel akhir), input(untuk memilih kode nomor makanan atau minuman)
        string input[30];
        cout << "Pilih barang ke-" << i + 1 << "\t: "; //berfungsi untuk memilih barang melalui kode
        cin >> input[i];
        cout<<"Jumlah barang ke-"<<i+1<<"\t: "; //berfungsi untuk jumlah barang yang akan dibeli
        cin>>jbrg[i];
        bool found = false;
        for (int j = 0; j < size; j++) { //searching untuk mencari makanan yang dipilih di daftar struct
            if (data[j].kodeNomor == input[i]) {
                found = true;
                cout <<setw(15) <<data[j].namaProduk <<" Rp. " << data[j].harga<<" x "<<jbrg[i]<<" = "<<data[j].harga*jbrg[i]<<endl;
                sum[i]=data[j].harga*jbrg[i]; //sum[i] berfungsi u/ menyimpan hasil kali harga dan jumlah yang akan dibeli
                brgterpilih[i]=data[j].namaProduk; //proses untuk menyimpan nama produk yang telah dipilih
                total+=data[j].harga*jbrg[i]; 
                break;
            } 
        } 
        for (int j = 0; j < minumsize; j++) { //searching untuk mencari minum yang dipilih di daftar struct
            if (minum[j].kodeNomor == input[i]) {
                found = true;
                cout <<setw(15) <<minum[j].namaProduk <<" Rp. " << minum[j].harga<<" x "<<jbrg[i]<<" = "<<minum[j].harga*jbrg[i]<<endl;
                sum[i]=minum[j].harga*jbrg[i]; //sum[i] berfungsi u/ menyimpan hasil kali harga dan jumlah yang akan dibeli
                brgterpilih[i]=minum[j].namaProduk; //brgterpilih[i] berfungsi u/ menyimpan nama produk yang telah dipilih
                total+=minum[j].harga*jbrg[i]; //total u/ menyimpan seluruh total sum[i]
                break;
            } 
        } 
        cout<<endl;
        if (!found) {
            cout << "Kode yang anda masukkan tidak terdaftar" << endl;
            
        }
    }
    tabel(data, jbrg, total, jmlh, sum, brgterpilih, nama); //pemanggilan tabel
    return total;
}


int main() {
    bool found = false;
    int  sum[17], jbrg[17];
    
    daftar data[] = { //mendata daftar makanan
        {"122", "Risol Mayo", 3000},
        {"112", "Donat", 2000},
        {"111", "Gorengan", 1000},
        {"121", "Tahu Bakso", 3000},
        {"113", "Pukis", 2000},
        {"114", "Cireng", 2500},
        {"123", "Onigiri", 8000}, 
        {"134", "Martabak bangka", 50000},
        {"124", "Nasi Ayam Suwir", 10000},
        {"132", "Nasi goreng", 12000},
        {"131", "Kupat Tahu", 10000},
        {"133", "Ayam Blackpaper", 14000},
    };
    int size = sizeof(data) / sizeof(data[0]); //untuk mengetahui banyak data di daftar makanan
    
    daftar minum[]={ //mendata daftar minuman
        {"214", "Akua", 3250},
        {"223", "Susu Kedelai", 4000},
        {"224", "Teh Botol", 5000},
        {"212", "Kopiko", 3000},
        {"231", "Susu indofood", 5000},
        {"211", "Marimas", 2000},
        {"232", "coca cola", 5000},
        {"222", "jus mangga", 4000},
        {"221", "jus jambu", 4000},
        {"213", "mizone", 3000}
    };
    int minumsize=sizeof(minum)/sizeof(minum[0]); //untuk mengetahui banyak data di daftar minuman
    
    bubbleSort(data, size); //memanggil pengurutan makanan
    bubble(minum, minumsize); //memanggil pengurutan minuman
    
    
    
    //TAMPILAN AWAL PROGRAM BERUPA ALAMAT DAN DAFTAR MENU
    cout<<"SCIENCE MARET\n";
    cout<<"Fakultas MIPA UGM\n";
    cout<<"JL. Geografi, kec. Mlati, Kab Sleman, Yogyakarta\n\n";
    cout<<"========================================================\n";
    cout<<"--------------------------------------------------------\n";
    cout<<"                      SCIENCE MART                     \n";
    cout<<"                       FMIPA UGM                       \n";
    cout<<"--------------------------------------------------------\n";
    cout<<"========================================================\n\n\n";
    ulang: //berfungsi u/ bisa mengulang kembali
    cout<<"                        DAFTAR                     \n";
    cout<<"                    M A K A N A N                    \n";
    cout<<"--------------------------------------------------------\n";
    cout << setw(5) << "Kode     " << setw(38) << left << "Nama Produk" << setw(10) << "Harga" << endl;//menampilkan menu makanan dengan setw agar jarak rapi dan sama
    cout<<"--------------------------------------------------------\n";
    for (int i = 0; i < 12; i++) {
    cout << setw(9) << data[i].kodeNomor << setw(36)<<left << data[i].namaProduk << setw(3) <<"Rp. "<<setw(7)<<data[i].harga << endl;
    }
    cout<<"\n                        DAFTAR                     \n"; //menampilkan daftar minum
    cout<<"                      M I N U M                    \n";
    cout<<"--------------------------------------------------------\n";
    cout << setw(5) << "Kode     " << setw(38) << left << "Nama Produk" << setw(10) << "Harga" << endl;
    cout << "--------------------------------------------------------\n";

    for (int i = 0; i < minumsize; i++) {
    cout << setw(9) << minum[i].kodeNomor << setw(36)<<left << minum[i].namaProduk << setw(3) <<"Rp. "<<setw(7)<<minum[i].harga << endl;
    }
    
    
    int n;
    string nama;
    
     
    cin.ignore(); //berfungsi untuk  mengabaikan atau menghapus satu atau lebih karakter dari buffer input agar getline bisa jalan
    cout << "Masukan Nama Pembeli\t\t: ";
    getline(cin, nama); //getline berguna u/ input bisa berupa kaliamat
    cout << "Masukan Jumlah barang\t\t: ";
    cin >> n;
    cout<<endl;
    
    
    if (n > 0) {
        int total = pembelian(n, data, minum, size,minumsize, nama); 
    } else {
        cout << "Jumlah barang harus lebih dari 0." << endl;
    }
   
    string lanjut;
    cout<<"Apakah masih dilanjutkan[ya/tidak]: ";  
    cin>>lanjut;
    
    if (lanjut=="ya"|| lanjut=="Ya" || lanjut=="YA") {
        cout<<"\n\n";
        goto ulang; //berguna u/ bisa mengulangi lagi program dari setelah "ulang:" yang ada diatas tadi 
    }
    else cout<<"\nTerimakasih "<<nama<<" telah berkunjung 3<"; //prgram selesai ><

    return 0;
}




/*
    //int data[] = {5,3,7,2,0,9,4,1,8,6};
    //int dataSize=sizeof(data)/sizeof(data[0]),
    int min, temp;
    for(int i = 0; i<size; i++) {
        min = i;
        for(int j=1+i; j<dataSize; j++){
            if(data[j] < data[min]){
                min = j;
            }
        }
    temp = data[i];
    data[i] = data[min];
    data[min] = temp;
    }
    for(int i = 0;i<dataSize;i++){
    cout<<data[i]<<" ";
    }
return 0;
*/







