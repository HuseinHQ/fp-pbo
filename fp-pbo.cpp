#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

void gotoxy(int x, int y){
    HANDLE hConsoleOutput;
    COORD dwCursorPosition;
    cout.flush();
    dwCursorPosition.X = x;
    dwCursorPosition.Y = y;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
    }

class Makanan{
    //Attribute
    public:
    int number;
    string nama;
    int harga;
    int jumlah;
    Makanan* next;

    //Method
    // Makanan(string x, int y){  //Constructor
    //     this -> nama = x;
    //     this -> harga = y; 
    // }
};

void printList(Makanan* n){
    while(n != NULL){
        cout << "| [" << n->number << "] " << n->nama << " " << n->harga << endl;
        n = n->next;
    }
}

// class Console: public Makanan{
//     public:

    void mainMenu(){
    cout << "+-------------------------------------------------------------+" << endl;
    cout << "|         SELAMAT DATANG DI RESTORAN PADANG BINTANG 5         |" << endl;
    cout << "+-------------------------------------------------------------+" << endl;
    cout << "| Pilih Menu:                                                 |" << endl;
    cout << "| [1] Lihat Menu Makanan                                      |" << endl;
    cout << "| [2] Pesan Makanan                                           |" << endl;
    cout << "| [3] Tambah Pesanan                                          |" << endl;
    cout << "| [4] Bayar Pesanan                                           |" << endl;
    cout << "| [5] Keluar                                                  |" << endl;
    cout << "+-------------------------------------------------------------+" << endl;
    cout << "| Masukkan pilihan: ";
    
    //cout << "|" << endl;
    }
    void switchCase(Makanan* n);
    
    
    
//};

class Transaksi{
    //Attribute
    public:
    int idTransaksi = 906220;
    int hari, bulan, tahun;
    int totalHarga;


};

class Pesan{
    //Attribute
    public:
    int noPesanan = 0;
    int noMeja;
    int jumlah;

    //Method
    int getPesanan(){
        return noPesanan;
    }
    void setMeja(){
        noPesanan += 1;
        cout << "Masukkan nomor meja: ";
        cin >> noMeja;
    }
    int getMeja(){
        return noMeja;
    }
 
};

int main(){
    int noMeja;
   
    Pesan pengunjung;

    Makanan* head = NULL;
    Makanan* cursor = NULL;
    Makanan* tail = NULL;

    head = new Makanan();
    cursor = new Makanan();
    tail = new Makanan();
    
    head->number = 1;
    head->nama = "Nasi Putih";
    head->harga = 5000;
    head->jumlah = 0;
    head->next = cursor;
    
    cursor->number = 2;
    cursor->nama = "Daging Rendang";
    cursor->harga = 10000;
    cursor->next = tail;
    
    tail->number = 3;
    tail->nama = "Cah Kangkung";
    tail->harga = 7000;
    tail->next = NULL;

    mainMenu();
    switchCase(head);

    return 0;
}

void switchCase(Makanan* n){
    int pilih;
    int jml;
    char temp;

    cin >> pilih;
    gotoxy(62, 9);
    cout << "|\n";
    cout << "+ ------------------------------------------------------------+\n" << endl;
    switch (pilih){
        case 1:
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "|                         MENU MAKANAN                        |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        printList(n);
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "Press Enter to Continue\n";
        getch();
            
        main();

        case 2:
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "|                        PILIH MAKANAN                        |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        printList(n);
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "| Masukkan Pilihan: ";
        cin >> pilih;
        do{
            ;
        }while(0);

        cout << "+-------------------------------------------------------------+\n" << endl;
        cout << "| Masukkan Jumlah: ";
        cin >> jml;

        case 5:
        exit(0);

        default:
        cout << "Pilihan tidak tersedia" << endl;
        main();
        cout << "halo";
    }
}