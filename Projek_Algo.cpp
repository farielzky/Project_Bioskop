#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

string passwordAdmin = "shafiq123";

struct Film {
    string judul_Film;
    string sinopsis;
    string direktur;
    string genre;
    int durasi;
};

Film Movie[5] = {
    {"Avengers: Endgame", 
     "Para Avengers yang tersisa melakukan perjalanan waktu untuk \n"
     "              mengumpulkan Infinity Stones dan mengalahkan Thanos demi \n"
     "              menyelamatkan alam semesta.",
     "The Russo Brothers", "Action", 181},

    {"The Walking Dead: The Movie", 
     "Rick Grimes yang diculik oleh CRM harus bertahan hidup dan\n"
     "              menemukan kebenaran di balik organisasi misterius ini.",
     "", "Action & Horror", 140},

    {"Boboiboy: The Movie", 
     "Boboiboy dan teman-temannya melawan The Tengkotak yang ingin\n"
     "              mencuri kekuatan Ochobot demi menguasai dunia.",
     "Anas Abdul Aziz", "Animation", 100},

     {"Pengepungan Di Bukit Duri", 
      "Kisah Seorang Guru yang mencari keponakannya yang hilang.  \n"
      "              Namun dia harus menghapi kerusuhan yang terjadi.", 
      "Joko Anwar", "Mystery & Thriller", 110},

    {"John Wick: Chapter 4", 
     "John Wick berjuang melawan musuh baru dan pasukan High Table \n"
     "              demi kebebasannya.",
     "Chad Stahelski", "Action", 169}
};

struct makanan {
    string namaMakanan;
    int hargaMakanan;
};

makanan food[5] {
    {"Small Popcorn", 20000},
    {"Medium Popcorn", 35000},
    {"Large Popcorn", 40000},
    {"French Fries", 25000},
    {"Sausage Box", 30000}
};

struct minuman {
    string namaMinuman;
    int hargaMinuman;
};

minuman drink[5] {
    {"Soda", 20000},
    {"Milo Dinosaurs", 35000},
    {"Lemon Tea", 20000},
    {"Mineral Water", 15000},
    {"Milkshake", 30000}
};

struct Tiket {
    string nama_pembeli;
    int jadwal_film_index;
    int jadwal_index;
    int baris_kursi;
    int nomor_kursi;
    vector<int> makanan_pesen;
    vector<int> minuman_pesen;
    int total_harga;
};

struct jadwal_film {
    int film_index;
    string tanggal_tayang;
    string studio;
    string jam_tayang;
    int harga_tiket;
    bool kursi[5][10]; // 5 baris, 10 kolom kursi
};

jadwal_film jadwal[5][3];

vector<Tiket> tiket_dipesan;

void tampilkanmenucustomer(string name) {
    cout << endl;
    cout << "||  Selamat datang, " << name << endl << endl;
    cout << ">>>>>>>>>>>>>>>>>>>>>  BABARSARI PLAZA - CINEMA XX  <<<<<<<<<<<<<<<<<<<<<<" << endl;
    cout << " |                  #        Pemesanan Tiket        #                   | " << endl;
    cout << " |                                                                      | " << endl;
    cout << " |                           ~~ Menu Utama ~~                           | " << endl;
    cout << " |     1. Pesan Tiket                                                   | " << endl;
    cout << " |     2. Film On-going                                                 | " << endl;
    cout << " |     3. Makanan dan Minuman                                           | " << endl;
    cout << " |     4. Cari Film                                                     | " << endl;
    cout << " |     5. Exit                                                          | " << endl;
    cout << " |                                                                      | " << endl;
    cout << ">>>>>>>>>>>>>>>>>>>>>>>  Contact : 0812-3456-7890  <<<<<<<<<<<<<<<<<<<<<<<" << endl << endl;
}

void tampilanmenu_film(string name){
    system("cls");
    cout << "||  Selamat datang, " << name << endl;
    cout << ">>>>>>>>>>>>>>>>>>>>>  BABARSARI PLAZA - CINEMA XX  <<<<<<<<<<<<<<<<<<<<<<" << endl;
    cout << ">=======================      DAFTAR FILM      ==========================<\n";
    for(int i = 0; i < 5; i++){
        cout << endl;
        cout << i+1 << ". " << Movie[i].judul_Film << endl << endl;
        cout << "   Genre     : " << Movie[i].genre << endl;
        cout << "   Durasi    : " << Movie[i].durasi << " Menit" << endl;
        cout << "   Sutradara : " << Movie[i].direktur << endl;
        cout << "   Sinopsi   : " << Movie[i].sinopsis << endl << endl;
        cout << ">========================================================================<\n";
    }
    cout << "Tekan Enter untuk kembali ke menu utama."; 
    cin.ignore();
    cin.get();
    system("cls");
}

void pilihjadwal(){

}


void tambahtiket(string name){
    bool valid;
    int film;
    system("cls");
    while(!valid){
    cout << "||  Selamat datang, " << name << endl;
    cout << ">>>>>>>>>>>>>>>>>>>>>  BABARSARI PLAZA - CINEMA XX  <<<<<<<<<<<<<<<<<<<<<<" << endl;
    cout << ">=======================      DAFTAR FILM      ==========================<\n\n";
    for(int i = 0; i < 5; i++){
        cout << i + 1 << ". " << Movie[i].judul_Film << " (" << Movie[i].genre << ")" << endl << endl;
    }
    cout << ">========================================================================<\n";
    cout << "Pilih Film (1-5): "; cin >> film;
    if(film < 1 || film > 5){
        cout << "Pilihan tidak valid!";
        cin.ignore();
        cin.get();
        cout << "Tekan Enter untuk mencoba lagi.";
        system("cls");
    } else {
        valid = true;
    }
    }


    int film_pilih = film - 1;
    cout << Movie[film_pilih].judul_Film << endl;

}

void tampilanmenu_tiket(string name){
    int choice;
    cout << endl;
    system("cls");
    cout << ">>>>>>>>>>>>>>>>>>>>>  BABARSARI PLAZA - CINEMA XX  <<<<<<<<<<<<<<<<<<<<<<" << endl;
    cout << " |                  #        Pemesanan Tiket        #                   | " << endl;
    cout << " |                                                                      | " << endl;
    cout << " |                           ~~ Data Tiket ~~                           | " << endl;
    cout << " |     1. Tambah Tiket                                                  | " << endl;
    cout << " |     2. Hapus Tiket                                                   | " << endl;
    cout << " |     3. Lihat Daftar Tiket                                            | " << endl;
    cout << " |     4. Exit                                                          | " << endl;
    cout << " |                                                                      | " << endl;
    cout << ">>>>>>>>>>>>>>>>>>>>>>>  Contact : 0812-3456-7890  <<<<<<<<<<<<<<<<<<<<<<<" << endl << endl;
    cout << "Pilih Menu : "; cin >> choice;
    switch (choice) {
        case 1 :
            tambahtiket(name);
        case 4 :
            return;

    }
}

void carifilm(string name){
    string cari;
    bool ditemukan = false;

    cout << "\nMasukkan judul film yang ingin dicari : ";
    cin.ignore();
    getline(cin, cari);

    cout << "\nHasil Pencarian : \n";

    for(int i = 0; i < 5; i++){
        if(Movie[i].judul_Film == cari){
            cout << "\nFilm Ditemukan !" << endl;
            cout << "   Judul     : " << Movie[i].judul_Film << endl;
            cout << "   Genre     : " << Movie[i].genre << endl;
            cout << "   Durasi    : " << Movie[i].durasi << " Menit" << endl;
            cout << "   Sutradara : " << Movie[i].direktur << endl;
            cout << "   Sinopsis  : " << Movie[i].sinopsis << endl;
            ditemukan = true;
            break;
        }
    }

    if(!ditemukan){
        cout << "\nFilm tidak ditemukan !" << endl;
    }

    cout << "\nTekan Enter untuk kembali ke menu utama.";
    cin.ignore();
    cin.get();
    system("cls");
}

void tampilanmenu_makanan_minuman(string name){
    system("cls");
    cout << "||  Selamat datang, " << name << endl;
    cout << ">>>>>>>>>>>>>>>>>>  BABARSARI PLAZA - CINEMA XX  <<<<<<<<<<<<<<<<<<<" << endl;
    cout << ">=================      DAFTAR MAKANAN      =================<\n";
        for(int i = 0; i < 5; i++){
        cout << i+1 << ". " << setw(20) << left << food[i].namaMakanan << "Rp " << food[i].hargaMakanan << endl;
        }
    cout << "\n>=================      DAFTAR MINUMAN      =================<\n";
        for(int i = 0; i < 5; i++){
        cout << i+1 << ". " << setw(20) << left << drink[i].namaMinuman << "Rp " << drink[i].hargaMinuman << endl;
        }

    cout << "\nTekan Enter untuk kembali ke menu utama.";
    cin.ignore();
    cin.get();
    system("cls");
}

void menucustomer(){
    string nama;
    int choice;
    cout << "Masukkan nama : ";
    getline(cin, nama);
    system("cls");

    while(choice != 5){
    tampilkanmenucustomer(nama);
    cout << "Pilih Menu : "; cin >> choice;

    switch (choice){
        case 1 : 
            tampilanmenu_tiket(nama);
            break;
        case 2 :    
            tampilanmenu_film(nama);
            break;
        case 3: 
            tampilanmenu_makanan_minuman(nama);
            break;
        case 4 :
            carifilm(nama);
            break;
        case 5:
            cout << "Terima kasih telah menggunakan aplikasi ini!" << endl;
            break;
        default: cout << "Pilihan tidak valid!" << endl;
    }
    }
}

void menuawal(){
    system("cls");
    cout << endl;
    cout << ">>>>>>>>>>>>>>>>>>>>>  BABARSARI PLAZA - CINEMA XX  <<<<<<<<<<<<<<<<<<<<<<" << endl;
    cout << " |                         ~~ Menu Awal ~~                             | " << endl;
    cout << " |     1. Admin                                                        | " << endl;
    cout << " |     2. Customer                                                     | " << endl;
    cout << " |     3. Exit                                                         | " << endl;
    cout << " |                                                                     | " << endl;
    cout << ">>>>>>>>>>>>>>>>>>>>>>>  Contact : 0812-3456-7890  <<<<<<<<<<<<<<<<<<<<<<<" << endl << endl;
}

void menuadmin(){
    int percobaan = 0;
    string password;

    while(percobaan <= 3 ){
    cout << "Masukkan password admin: ";
    getline(cin, password);
    
    if(password != passwordAdmin){
        cout << "Password salah! ." << endl;
        cout << "\nTekan Enter untuk coba lagi.";
        cin.get();
        system("cls");
        percobaan++;
    } else {
        //menu mantap admin
    }
    }
    if(percobaan >= 3){
        cout << "Anda telah mencoba 3 kali. Kembali ke menu utama." << endl;
        cout << "\nGoodbye";
        cin.get();
        system("cls");
        exit(0);
    }
    
}

int main()
{
    int pil;
    menuawal();
    cout << "Pilih Menu : ";
    cin >> pil;
    cin.ignore();

    switch(pil){
        case 1 :
            system("cls");
            cout << "Selamat Datang di Menu Admin" << endl;
            menuadmin(); 
            break;
        case 2 :
            system("cls");
            cout << "Selamat Datang di Menu Customer" << endl;
            menucustomer();
            break;
        }
    return 0;
}
