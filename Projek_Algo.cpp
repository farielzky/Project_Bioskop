#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

struct Film {
    string judul_Film;
    string sinopsis;
    string direktur;
    string genre;
    int durasi;
};

struct makanan {
    string namaMakanan;
    int hargaMakanan;
};

struct minuman {
    string namaMinuman;
    int hargaMinuman;
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
    bool kursi[5][10]; 
};

vector<Film> Movie;
vector<makanan> food;
vector<minuman> drink;
vector<vector<jadwal_film>> Jadwal;
string passwordAdmin = "shafiq123";
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
    cout << " |     5. Kembali ke Menu Utama                                         | " << endl;
    cout << " |                                                                      | " << endl;
    cout << ">>>>>>>>>>>>>>>>>>>>>>>  Contact : 0812-3456-7890  <<<<<<<<<<<<<<<<<<<<<<<" << endl << endl;
}

void bacaDataFilmDariFile() {
    ifstream file("film.txt");
    if (!file.is_open()) {
        cout << "File data film tidak ditemukan. Membuat file baru.\n";
        return;
    }

    Movie.clear();
    string line;
    
    while (getline(file, line)) {
        Film film;
        // Format file harus konsisten
        film.judul_Film = line.substr(line.find(":") + 2);
        
        getline(file, line);
        film.sinopsis = line.substr(line.find(":") + 2);
        
        getline(file, line);
        film.direktur = line.substr(line.find(":") + 2);
        
        getline(file, line);
        film.genre = line.substr(line.find(":") + 2);
        
        getline(file, line);
        film.durasi = stoi(line.substr(line.find(":") + 2));

        // Buat vector jadwal untuk film ini
        Jadwal.push_back(vector<jadwal_film>());
        
        // Skip pembatas
        getline(file, line);
        
        Movie.push_back(film);
    }
    file.close();
}

void tampilanmenu_film(string name) {
    system("cls");
    bacaDataFilmDariFile();
    const int LEBAR_LAYAR = 100;
    const int LEBAR_KONTEN = LEBAR_LAYAR - 4; // 2 untuk border kiri dan kanan
    
    // Header
    cout << "||  Selamat datang, " << name << endl;
    cout << ">>>>>>>>>>>>>>>>>>>>>  BABARSARI PLAZA - CINEMA XX  <<<<<<<<<<<<<<<<<<<<<<" << endl;
    
    // Garis pembatas atas
    cout << setfill('=') << setw(LEBAR_LAYAR) << "" << setfill(' ') << endl;
    
    // Judul menu
    cout << "| " << left << setw(LEBAR_KONTEN) << "DAFTAR FILM" << " |" << endl;
    
    if (Movie.empty()) {
        cout << "| " << setw(LEBAR_KONTEN) << "Tidak ada film yang tersedia." << " |" << endl;
    }
    
    for (int i = 0; i < Movie.size(); i++) {
        // Garis pemisah antar film
        cout << "|" << setfill('-') << setw(LEBAR_LAYAR - 2) << "" << setfill(' ') << "|" << endl;
        
        // Judul film
        cout << "| " << left << setw(LEBAR_KONTEN) << (to_string(i+1) + ". " + Movie[i].judul_Film) << " |" << endl;
        
        // Informasi dasar film
        cout << "| " << left << setw(LEBAR_KONTEN) 
             << "   Genre: " + Movie[i].genre << " |" << endl;
        cout << "| " << left << setw(LEBAR_KONTEN) 
             << "   Durasi: " + to_string(Movie[i].durasi) + " Menit" << " |" << endl;
        cout << "| " << left << setw(LEBAR_KONTEN) 
             << "   Sutradara: " + Movie[i].direktur << " |" << endl;
        cout << "| " << left << setw(LEBAR_KONTEN)
             << "   Sinopsis: " + Movie[i].sinopsis << " |" << endl;
        }
    
    
    // Garis pembatas bawah
    cout << setfill('=') << setw(LEBAR_LAYAR) << "" << setfill(' ') << endl;
    
    cout << "Tekan Enter untuk kembali ke menu utama."; 
    cin.ignore();
    cin.get();
    system("cls");
}


void pesantiket(string name){
    int film;
    system("cls");
    if(Movie.empty()){
        cout << "Tidak ada film yang tersedia.\n";
        cout << "Tekan Enter untuk kembali ke menu utama.";
        cin.ignore();
        cin.get();
        system("cls");
        return;
    }
    cout << "||  Selamat datang, " << name << endl;
    cout << ">>>>>>>>>>>>>>>>>>>>>  BABARSARI PLAZA - CINEMA XX  <<<<<<<<<<<<<<<<<<<<<<" << endl;
    cout << ">=======================      DAFTAR FILM      ==========================<\n\n";
    for(int i = 0; i < Movie.size(); i++){
        cout << i + 1 << ". " << Movie[i].judul_Film << " (" << Movie[i].genre << ")" << endl << endl;
    }
    cout << ">========================================================================<\n";
    cout << "Pilih Film (1-" << Movie.size() << ") "; cin >> film;
    


    int film_pilih = film - 1; // Agar sesuai dengan indeks array Movie
    cout << Movie[film_pilih].judul_Film << endl;

}


void carifilm(string name){
    string cari;
    bool ditemukan = false;

    cout << "\nMasukkan judul film yang ingin dicari : ";
    cin.ignore();
    getline(cin, cari);

    cout << "\nHasil Pencarian : \n";

    for(int i = 0; i < Movie.size(); i++){
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

void hapusfilm(){
    string hapus;
    bool ditemukan = false;

    cout << "Masukkan judul film yang ingin dihapus : ";
    getline(cin, hapus);

    for(int i = 0; i < Movie.size(); i++){
        if(Movie[i].judul_Film == hapus){
            Movie.erase(Movie.begin() + i);
            cout << "Film berhasil dihapus!" << endl;
            ditemukan = true;
            break;
        }
    }

    if(!ditemukan){
        cout << "Film tidak ditemukan!" << endl;
    }

    cout << "\nTekan Enter untuk kembali ke menu admin.";
    cin.ignore();
    cin.get();
    system("cls");
}

void simpanFilm() {
    ofstream file("film.txt");
    if (!file.is_open()) {
        cout << "Gagal membuka file untuk penyimpanan.\n";
        return;
    }

    for (const auto& film : Movie) {
        file << "Judul Film: " << film.judul_Film << endl;
        file << "Sinopsis: " << film.sinopsis << endl;
        file << "Sutradara: " << film.direktur << endl;
        file << "Genre: " << film.genre << endl;
        file << "Durasi: " << film.durasi << endl;
        file << "==========================================\n";
    }
    file.close();
}
void tambahfilm(){
    system("cls");
    Film film_baru;
    cout << ">=======================      TAMBAH FILM      =======================<\n";
    cout << "Masukkan Judul Film : ";
    getline(cin, film_baru.judul_Film);
    cout << "Masukkan Sinopsis   : ";
    getline(cin, film_baru.sinopsis);
    cout << "Masukkan Sutradara  : ";
    getline(cin, film_baru.direktur);
    cout << "Masukkan Genre      : ";
    getline(cin, film_baru.genre);
    cout << "Masukkan Durasi     : ";
    cin >> film_baru.durasi;
    cin.ignore();
    
    Movie.push_back(film_baru);
    simpanFilm(); 
    Jadwal.push_back(vector<jadwal_film>()); // Tambahkan vector kosong untuk jadwal film ini

    cout << "\nFilm berhasil ditambahkan!" << endl;
    cout << "\nTekan Enter untuk kembali ke menu admin.";
    cin.get();
    system("cls");
}

void tambahJadwal(){
    system("cls");
    bool valid = true;

    if(Movie.empty()){
        cout << "Tidak ada film yang tersedia. Tambahkan film terlebih dahulu.\n";
        cout << "\nTekan Enter untuk kembali ke menu admin.";
        cin.ignore();
        cin.get();
        system("cls");
        return;
    }
    while(valid){
        cout << ">=======================      TAMBAH JADWAL FILM      =======================<\n";
        cout << "Daftar Film:\n";
        for(int i = 0; i < Movie.size(); i++){
            cout << i + 1 << ". " << Movie[i].judul_Film << endl;
        }
        cout << "Pilih Film (1-" << Movie.size() << ") : ";
        int film_pilih;
        cin >> film_pilih;
        cin.ignore();

        if(film_pilih < 1 || film_pilih > Movie.size()){
            cout << "Pilihan tidak valid!" << endl;
            cout << "\nTekan Enter untuk kembali ke menu admin.";
            cin.ignore();
            cin.get();
            system("cls");
            return;
        } else{
            int film_index = film_pilih - 1;
            jadwal_film jadwal_baru;
            jadwal_baru.film_index = film_index;

            cout << "Masukkan Tanggal Tayang (DD/MM/YYYY) : ";
            getline(cin, jadwal_baru.tanggal_tayang);
            cout << "Masukkan Jam Tayang (HH:MM) : ";
            getline(cin, jadwal_baru.jam_tayang);
            cout << "Masukkan Studio : ";
            getline(cin, jadwal_baru.studio);
            cout << "Masukkan Harga Tiket : ";
            cin >> jadwal_baru.harga_tiket;
            cin.ignore();

            for(int i = 0; i < 5; i++){
                for(int j = 0; j < 10; j++){
                    jadwal_baru.kursi[i][j] = false;
                }
            }

            Jadwal[film_index].push_back(jadwal_baru);
            valid = false;
            cout << "\nJadwal berhasil ditambahkan!" << endl;
            cin.get();
            system("cls");
        }
    }
}

void lihatJadwal(){
    system("cls");
    cout << ">=======================      DAFTAR JADWAL FILM      =======================<\n";
    if(Movie.empty()){
        cout << "Tidak ada film yang tersedia.\n";
        cout << "\nTekan Enter untuk kembali ke menu admin.";
        cin.ignore();
        cin.get();
        system("cls");
        return;
    }
    for(int i = 0; i < Movie.size(); i++){
        cout << "\nFilm: " << Movie[i].judul_Film << endl;
        if(Jadwal[i].empty()){
            cout << "  Tidak ada jadwal tersedia.\n";
        } else {
            for(int j = 0; j < Jadwal[i].size(); j++){
                cout << "  " << j + 1 << ". Tanggal: " << Jadwal[i][j].tanggal_tayang 
                     << ", " << Jadwal[i][j].jam_tayang 
                     << ", " << Jadwal[i][j].studio 
                     << ", Harga: Rp " << Jadwal[i][j].harga_tiket << endl;
            }
        }
    }

    cout << "\nTekan Enter untuk kembali ke menu admin.";
    cin.ignore();
    cin.get();
    system("cls");
}

void tampilanmenu_makanan_minuman(string name){
    system("cls");
    cout << "||  Selamat datang, " << name << endl;
    cout << ">>>>>>>>>>>>>>>>>>  BABARSARI PLAZA - CINEMA XX  <<<<<<<<<<<<<<<<<<<" << endl;
    cout << ">=================      DAFTAR MAKANAN      =================<\n";
    if(food.empty()){
        cout << "Tidak ada makanan yang tersedia.\n";
    }
    for(int i = 0; i < 5; i++){
        cout << i+1 << ". " << setw(20) << left << food[i].namaMakanan << "Rp " << food[i].hargaMakanan << endl;   
    }
    cout << "\n>=================      DAFTAR MINUMAN      =================<\n";
    if(drink.empty()){
        cout << "Tidak ada minuman yang tersedia.\n";
    }
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
            pesantiket(nama);
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

void tampilkanmenuAwal(){
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

void tampilkanmenuAdmin(){
    cout << "Selamat Datang di Menu Admin" << endl;
    cout << ">>>>>>>>>>>>>>>>>>>>>>  BABARSARI PLAZA - CINEMA XX  <<<<<<<<<<<<<<<<<<<<<" << endl;
    cout << " |                  #        Menu Admin        #                       | " << endl;
    cout << " |     1. Tambah Film                                                  | " << endl;
    cout << " |     2. Hapus Film                                                   | " << endl;
    cout << " |     3. Lihat Daftar Film                                            | " << endl;
    cout << " |     4. Tambah Jadwal Film                                           | " << endl;
    cout << " |     5. Lihat Jadwal Film                                            | " << endl;
    cout << " |     6. Tambah Makanan/Minuman                                       | " << endl;
    cout << " |     7. Lihat Riwayat Transaksi                                      | " << endl;
    cout << " |     8. Kembali ke Menu Utama                                        | " << endl;
    cout << " |                                                                     | " << endl;
    cout << ">>>>>>>>>>>>>>>>>>>>>>>  Contact : 0812-3456-7890  <<<<<<<<<<<<<<<<<<<<<<<" << endl << endl;
}

void menuAdmin(){
    int pil;

    while(pil != 8){
    system("cls");
    tampilkanmenuAdmin();
    cout << "Pilih Menu : ";
    cin >> pil;
    cin.ignore();
    switch(pil){
        case 1 :
            tambahfilm();
            break;
        case 2 :
            hapusfilm();
            break;
        case 3 :
            tampilanmenu_film("Admin");
            break;
        case 4 :
            tambahJadwal();
            break;
        case 5 :
            lihatJadwal();
            break;
        case 6 :
            //lihatdaftarjadwal();
            break;
        case 7 :
            //lihatdaftarpembeli();
            break;
        case 8 :
            cout << "Kembali ke menu utama" << endl;
            break;
        default : 
            cout << "Pilihan tidak valid!" << endl;
            cout << "Tekan Enter untuk mencoba lagi.";
            cin.ignore();
            cin.get();
            system("cls");
            menuAdmin();
            break;
        }
    }
}

void menuawalAdmin(){
    int percobaan = 0;
    string password;

    while(percobaan <= 3 ){
        cout << "Selamat Datang di Menu Admin" << endl;
        cout << "Masukkan password admin: ";
        cin >> password;

    if(percobaan >= 3){
        cout << "Anda telah mencoba 3 kali. Kembali ke menu utama." << endl;
        cout << "\nGoodbye";
        cin.get();
        system("cls");
        exit(0);
    }
    
    if(password != passwordAdmin){
        cout << "Password salah!.";
        cout << "\nTekan Enter untuk coba lagi.";
        cin.ignore();
        cin.get();
        system("cls");
        percobaan++;
    } else {
        cout << "Password benar!" << endl;
        system("cls");
        menuAdmin();
        break;
    }
    }
    
}


int main()
{
    bacaDataFilmDariFile(); 
    int pil;
    tampilkanmenuAwal();
    cout << "Pilih Menu : ";
    cin >> pil;
    cin.ignore();

    switch(pil){
        case 1 :
            system("cls");
            menuawalAdmin(); 
            break;
        case 2 :
            system("cls");
            cout << "Selamat Datang di Menu Customer" << endl;
            menucustomer();
            break;
        }
    return 0;
}
