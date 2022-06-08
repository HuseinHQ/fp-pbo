#include <iostream>
#include <conio.h>
//#include <windows.h>

using namespace std;

class Makanan{
    //Attribute
    public:
    int number;
    string nama;
    int harga;
    int jumlah;
    int totalHarga;
    int no = 4;
    Makanan* next;
    Makanan* head;
    Makanan* cursor;
    Makanan* tail;

    void deklarasi(){
        head = new Makanan();
        cursor = new Makanan();
        tail = new Makanan();
        
        head->number = 1;
        head->nama = "Nasi Putih     ";
        head->harga = 5000;
        head->jumlah = 0;
        head->next = cursor;
        
        cursor->number = 2;
        cursor->nama = "Daging Rendang ";
        cursor->harga = 10000;
        cursor->jumlah = 0;
        cursor->next = tail;
        
        tail->number = 3;
        tail->nama = "Cah Kangkung   ";
        tail->harga = 7000;
        tail->jumlah = 0;
        tail->next = NULL;
    }

    void append(Makanan** head_ref, string nama, int harga){
        Makanan* new_makanan = new Makanan();
        Makanan *last = *head_ref;
        new_makanan->number = no;
        no += 1;
        new_makanan->nama = nama;
        new_makanan->harga = harga;
        new_makanan->jumlah = 0;
        new_makanan->next = NULL;
        while (last->next != NULL){
            last = last->next; 
        }
        last->next = new_makanan;
    }
};

class Pesan: public Makanan{
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
        cout << "+-----------------------------------------------------------+" << endl;
        cout << "| Masukkan nomor meja: ";
        cin >> noMeja;
        cout << "+-----------------------------------------------------------+" << endl;
        system("cls");
    }
    int getMeja(){
        return noMeja;
    }
 
};

class AddMenu: public Pesan{
    int nomer;

    void setNama(Makanan* n, string nama){
        while(n != NULL){
            if(n->next == NULL){
                n->nama = nama;
            }
            n = n->next;
        }
    }
    void setHarga(Makanan* n, int harga){
        while(n != NULL){
            if(n->next == NULL){
                n->harga = harga;
            }
            n = n->next;
        }
    }
    void setJumlah(Makanan* n){
        while(n != NULL){
            if(n == NULL){
                n->harga = harga;
            }
            n = n->next;
        }
    }
};

class Transaksi: public AddMenu{
    //Attribute
    public:
    string idTransaksi = "090622001";
    string hari = "09", bulan = "06", tahun = "2022";
    int totalHarga = 0;

    string getTransaksi(){
        return idTransaksi;
    }

    void getTotal(Makanan*n){
        while(n != NULL){
            totalHarga += n->harga * n->jumlah;
            n = n->next;
        }
        cout << totalHarga;
    }

};



class Terminal: public Transaksi{
    //Attribute
    public:
    int jml;
    int pilih;

    //function overloading------------------------------------------------------------------------------
    void printList(Makanan* n){
        while(n != NULL){
            cout << "| [" << n->number << "] " << n->nama << " -> Rp." << n->harga;
            cout << "\t\t\t    |" << endl;
            n = n->next;
        }
    }
    void printList(Makanan* n, int tanda){
        while(n != NULL){
            cout << "| [" << n->number << "] " << n->nama << " -> Rp." << n->harga;
            cout << "\t\t\t    |" << endl;
            n = n->next;
        }
        if(tanda == 1){
            cout << "| [0] Kembali\t\t\t\t\t\t    |" << endl;
        }
    }
    //--------------------------------------------------------------------------------------------------

    void linkedList(Makanan* n, int p, int j){
        while(n != NULL){
            if(n->number == p){
                n->jumlah += j;
            }
            n = n->next;
        }
    }

    void lihatPesanan(Makanan* n){
        while(n != NULL){
            if(n->jumlah != 0){
                cout << "| " << n->jumlah << "x " << n->nama << "\t\t\t\t\t    |" << endl;
            }
            n = n->next;
        }
    }
    void lihatPesanan(Makanan* n, int x){
        while(n != NULL){
            if(n->jumlah != 0){
                cout << "|\t" << n->jumlah << "x " << n->nama << "\t\t= " << n->harga << "\t\t    |" << endl;
            }
            n = n->next;
        }
    }

    void getJml(){
        cout << cursor->jumlah;
    }

    int mainMenu(){
    cout << "+-----------------------------------------------------------+" << endl;
    cout << "|        SELAMAT DATANG DI RESTORAN PADANG BINTANG 5        |" << endl;
    cout << "+-----------------------------------------------------------+" << endl;
    cout << "| Pilih Menu:                                               |" << endl;
    cout << "| [1] Lihat Menu Makanan                                    |" << endl;
    cout << "| [2] Pesan Makanan                                         |" << endl;
    cout << "| [3] Lihat Pesanan                                         |" << endl;
    cout << "| [4] Tambah Menu Makanan                                   |" << endl;
    cout << "| [5] Bayar Pesanan                                         |" << endl;
    cout << "| [6] Keluar                                                |" << endl;
    cout << "+-----------------------------------------------------------+" << endl;
    cout << "| Masukkan pilihan: ";
    cin >> pilih;
    cout << "+-----------------------------------------------------------+\n" << endl;
    system("cls");
    return pilih;
    }

    void case1(){
        cout << "+-----------------------------------------------------------+" << endl;
        cout << "|                          MENU MAKANAN                     |" << endl;
        cout << "+-----------------------------------------------------------+" << endl;
        printList(head);
        cout << "+-----------------------------------------------------------+" << endl;
        cout << "\n                 tekan apapun untuk lanjut";
        getch();
        system("cls");
    }
    int case2(int tanda){
        cout << "+-----------------------------------------------------------+" << endl;
        cout << "|                       PILIH MAKANAN                       |" << endl;
        cout << "+-----------------------------------------------------------+" << endl;
        printList(head, tanda);
        cout << "+-----------------------------------------------------------+" << endl;
        cout << "| Masukkan Pilihan : ";
        cin >> pilih;
        if(pilih != 0){
            cout << "| Masukkan Jumlah  : ";
            cin >> jml;
            cout << "+-----------------------------------------------------------+" << endl;
            linkedList(head, pilih, jml);
            cout << "\n                   *pesanan dicatat" << endl;
            cout << "               tekan apapun untuk lanjut";
            getch();
            system("cls");
        }else{
            cout << "+-----------------------------------------------------------+" << endl;
            return pilih;
        }
        return 1;
    }

    void case3(){
        cout << "+-----------------------------------------------------------+" << endl;
        cout << "|                       PESANAN ANDA                        |" << endl;
        cout << "+-----------------------------------------------------------+" << endl;
        lihatPesanan(head);
        cout << "+-----------------------------------------------------------+" << endl;
        cout << "\n               tekan apapun untuk lanjut";
        getch();
        system("cls");
    }

    void case4(){
        string namaMakanan;
        int hargaMakanan;
        int x = 1;

        cout << "+-----------------------------------------------------------+" << endl;
        cout << "|                    TAMBAH MENU MAKANAN                    |" << endl;
        cout << "+-----------------------------------------------------------+" << endl;
        cout << "| Nama Makanan  : ";
        cin >> namaMakanan;
        cout << "| Harga Makanan :";
        cin >> hargaMakanan;
        append(&head, namaMakanan, hargaMakanan);
        cout << "+-----------------------------------------------------------+" << endl;
        cout << "\n                  *Menu ditambahkan" << endl;
        cout << "\n               tekan apapun untuk lanjut";
        getch();
        system("cls");
    }

    void case5(){
        cout << "+-----------------------------------------------------------+" << endl;
        cout << "|                       STRUK TAGIHAN                       |" << endl;
        cout << "+-----------------------------------------------------------+" << endl;
        cout << "| id Transaksi : " << getTransaksi() << "\t\t\t\t    |" << endl;
        cout << "| No Meja      : " << getMeja() << "\t\t\t\t\t    |" << endl;
        cout << "|----------------------Rincian Pesanan----------------------|" << endl;
        lihatPesanan(head, 0);
        cout << "|\tTotal Harga\t\t\t= Rp.";
        getTotal(head);
        cout << "\t    |" << endl;;
        cout << "+-----------------------------------------------------------+\n" << endl;
        cout << "        TERIMA KASIH TELAH BERKUNJUNG KE RESTORAN KAMI!" << endl;
        cout << "                KEPUASAN ANDA, KEPUASAN KAMI" << endl;
        getch();
        system("cls");
        exit(0);
    }

    int case6(){
        exit(0);
    }

    void notAvailable(){
        cout << "  Pilihan tidak tersedia" << endl;
        getch();
        system("cls");
    }
};



int flag = 0;

int main(){
    int noMeja;
    int choose;
    int loop;

    system("cls");

    Terminal pengunjung;

    if(flag == 0)
        pengunjung.deklarasi();
        flag++;

    while(true){
        choose = pengunjung.mainMenu();
        if(choose==1){
            pengunjung.case1();
        }else if (choose == 2){
            pengunjung.setMeja();
            while(true){
                choose = pengunjung.case2(1);
                if(choose == 0){
                    system("cls");
                    break;
                }
            }
        }else if(choose == 3){
            pengunjung.case3();
        }else if(choose == 4){
            pengunjung.case4();
        }else if(choose == 5){
            pengunjung.case5();
        }else if(choose == 6){
            pengunjung.case6();
        }else{
            pengunjung.notAvailable();
        }
    }
}