#include "ojol.h"

using namespace std;

int main() //MAIN PROGRAM (10)
{

    // Inisiasi list ojol
    CDLLOjol ListOjol;
    createList_Ojol(ListOjol);
    adrOjol ojol;
    adrPenumpang penumpang;
    adrPesanan pesanan;
    string nama, tanggal, idOjol, idPenumpang, idPesanan;

    //Insert data ojol dari belakang (5)
    insertLast_Ojol(ListOjol, new_elmOjol("0", "Ojol 0"));
    insertLast_Ojol(ListOjol, new_elmOjol("1", "Ojol 1"));
    insertLast_Ojol(ListOjol, new_elmOjol("2", "Ojol 2"));
    insertLast_Ojol(ListOjol, new_elmOjol("3", "Ojol 3"));
    insertLast_Ojol(ListOjol, new_elmOjol("4", "Ojol 4"));
    insertLast_Ojol(ListOjol, new_elmOjol("ASD", "Ojol ASD"));
    insertLast_Ojol(ListOjol, new_elmOjol("5", "Ojol 5"));
    insertLast_Ojol(ListOjol, new_elmOjol("6", "Ojol 6"));
    insertLast_Ojol(ListOjol, new_elmOjol("7", "Ojol 7"));

    cout<< "\n ================ MENAMPILKAN LIST OJOL ================ \n"<< endl;
    show_Ojol(ListOjol);

    // Menghapus data ojol beserta relasinya (15)
    delete_Ojol(ListOjol, "0", ojol);
    delete_Ojol(ListOjol, "ASD", ojol);
    delete_Ojol(ListOjol, "7", ojol);

    //Show all data ojol (5)
    cout<< "\n ================ MENAMPILKAN LIST OJOL SETELAH DIHAPUS ================ \n"<< endl;
    show_Ojol(ListOjol);

    //Mencari data ojol (5)
    //Mencari data ojol dengan id = 4
    ojol = search_Ojol(ListOjol, "4");
    cout<< "\n\n ================ MENAMPILKAN DATA SUATU OJOL ================ \n"<< endl;
    cout << "ID Ojol     : "<< info(ojol).idOjol << endl;
    cout << "Nama Ojol   : "<< info(ojol).nama << "\n\n";


    //Inisiasi list penumpang
    DLLPenumpang ListPenumpang;
    createList_Penumpang(ListPenumpang);

    //Menambahkan data penumpang (5)
    insertLast_Penumpang(ListPenumpang, new_elmPenumpang("1", "Penumpang 1"));
    insertLast_Penumpang(ListPenumpang, new_elmPenumpang("2", "Penumpang 2"));
    insertLast_Penumpang(ListPenumpang, new_elmPenumpang("3", "Penumpang 3"));
    insertLast_Penumpang(ListPenumpang, new_elmPenumpang("4", "Penumpang 4"));
    insertLast_Penumpang(ListPenumpang, new_elmPenumpang("5", "Penumpang 5"));
    insertLast_Penumpang(ListPenumpang, new_elmPenumpang("6", "Penumpang 6"));
    insertLast_Penumpang(ListPenumpang, new_elmPenumpang("7", "Penumpang 7"));

    //Mencari data penumpang (5)
    penumpang = search_Penumpang(ListPenumpang, "4");
    cout<< "\n\n ================ MENAMPILKAN DATA SUATU PENUMPANG ================ \n"<< endl;
    cout << "ID Penumpang     : "<< info(penumpang).idPenumpang << endl;
    cout << "Nama Penumpang   : "<< info(penumpang).nama << "\n\n";

    //Menghubungkan data ojol ke data penumpang (5)
    insertPesanan(ListOjol, ListPenumpang, new_elmPesanan("1","15-12-2022","1","3"));
    insertPesanan(ListOjol, ListPenumpang, new_elmPesanan("2","17-12-2022","1","5"));
    insertPesanan(ListOjol, ListPenumpang, new_elmPesanan("3","18-12-2022","1","6"));
    insertPesanan(ListOjol, ListPenumpang, new_elmPesanan("4","18-12-2022","1","1"));
    insertPesanan(ListOjol, ListPenumpang, new_elmPesanan("5","16-12-2022","2","1"));
    insertPesanan(ListOjol, ListPenumpang, new_elmPesanan("6","16-12-2022","2","2"));
    insertPesanan(ListOjol, ListPenumpang, new_elmPesanan("7","17-12-2022","2","4"));
    insertPesanan(ListOjol, ListPenumpang, new_elmPesanan("8","18-12-2022","2","7"));
    insertPesanan(ListOjol, ListPenumpang, new_elmPesanan("9","18-12-2022","3","1"));
    insertPesanan(ListOjol, ListPenumpang, new_elmPesanan("10","19-12-2022","3","6"));
    insertPesanan(ListOjol, ListPenumpang, new_elmPesanan("11","16-12-2022","4","1"));
    insertPesanan(ListOjol, ListPenumpang, new_elmPesanan("12","16-12-2022","4","2"));
    insertPesanan(ListOjol, ListPenumpang, new_elmPesanan("13","16-12-2022","4","3"));
    insertPesanan(ListOjol, ListPenumpang, new_elmPesanan("14","17-12-2022","4","5"));
    insertPesanan(ListOjol, ListPenumpang, new_elmPesanan("15","18-12-2022","4","6"));
    insertPesanan(ListOjol, ListPenumpang, new_elmPesanan("16","20-12-2022","6","2"));


    //Menampilkan seluruh data ojol beserta penumpangnya (15)
    cout<< "\n\n ================ MENAMPILKAN SEMUA OJOL BESERTA PESANANNYA ================ \n"<< endl;
    showAllPesanan(ListOjol);

    //Mencari data penumpang pada ojol tertentu (10)
    //Menampilkan data penumpang pada ojol dengan id = 4
    cout<< "\n\n ================ MENAMPILKAN SUATU OJOL BESERTA PESANANNYA ================ \n"<< endl;
    showPesanan(ListOjol, "4");

    //Menghapus data penumpang pada ojol tertentu beserta relasinya (15)
    //Mencoba untuk menghapus pesanan dengan id = 5, 8, dan 13

    deletePesanan(ListOjol, "5", pesanan);
    deletePesanan(ListOjol, "8", pesanan);
    deletePesanan(ListOjol, "13", pesanan);

    cout<< "\n\n ================ LIST SETELAH PESANAN DIHAPUS ================ \n"<< endl;
    showAllPesanan(ListOjol);

    //Menampilkan jumlah ojol yang dipesan seorang penumpang dalam satu hari (5)
    cout<< "\n\n ================ PESANAN SUATU PENUMPANG DI SATU HARI ================ \n"<< endl;
    showPesananOnDay(ListOjol, "6", "18-12-2022");

    cout << "\n\n\n";
    int n = 1;
    while (n != 0) {
        cout << "========== MENU ==========" << endl;
        cout << "1. Insert Ojol" << endl;
        cout << "2. Insert Penumpang" << endl;
        cout << "3. Insert Pesanan" << endl;
        cout << "4. Delete Suatu Ojol" << endl;
        cout << "5. Delete Suatu Pesanan" << endl;
        cout << "6. Show List Ojol" << endl;
        cout << "7. Show List Ojol Beserta Pesanannya" << endl;
        cout << "8. Show Pesanan Suatu Ojol" << endl;
        cout << "9. Show Pesanan Suatu Penumpang Dalam Satu Hari" << endl;
        cout << "0. Selesai" << endl;
        cout << "Pilihan menu : ";
        cin >> n ;
        switch(n) {
    case 1 :
        system("CLS");
        cout << "\nMasukkan ID ojol   : ";
        cin >> idOjol;
        cout << "Masukkan Nama ojol : ";
        cin >> nama;
        insertLast_Ojol(ListOjol, new_elmOjol(idOjol, nama));
        cout << endl;
        break;
    case 2:
        system("CLS");
        cout << "\nMasukkan ID penumpang   : ";
        cin >> idPesanan;
        cout << "Masukkan Nama penumpang : ";
        cin >> nama;
        insertLast_Penumpang(ListPenumpang, new_elmPenumpang(idPesanan, nama));
        cout << endl;
        break;
    case 3:
        system("CLS");
        cout << endl;
        cout << "Masukkan ID pesanan                     : ";
        cin >> idPesanan;
        cout << "Masukkan tanggal pesanan (DD-MM-YYYY)   : ";
        cin >> tanggal;
        cout << "Masukkan ID ojol                        : ";
        cin >> idOjol;
        cout << "Masukkan ID penumpang   : ";
        cin >> idPenumpang;
        insertPesanan(ListOjol, ListPenumpang, new_elmPesanan(idPesanan, tanggal, idOjol, idPenumpang));
        cout << endl;
        break;
    case 4:
        system("CLS");
        cout << "\nMasukkan ID ojol   : ";
        cin >> idOjol;
        delete_Ojol(ListOjol, idOjol, ojol);
        cout << endl;
        break;
    case 5:
        system("CLS");
        cout << "\nMasukkan ID pesanan   : ";
        cin >> idPesanan;
        deletePesanan(ListOjol, idPesanan, pesanan);
        cout << endl;
        break;
    case 6:
        system("CLS");
        cout << endl;
        show_Ojol(ListOjol);
        cout << endl;
        break;
    case 7 :
        system("CLS");
        cout << endl;
        showAllPesanan(ListOjol);
        cout << endl;
        break;
    case 8 :
        system("CLS");
        cout << "\nMasukkan ID ojol   : ";
        cin >> idOjol;
        showPesanan(ListOjol, idOjol);
        cout << endl;
        break;
    case 9 :
        system("CLS");
        cout << endl;
        cout << "Masukkan ID penumpang            : ";
        cin >> idPenumpang;
        cout << "Masukkan tanggal (DD-MM-YYYY)    : ";
        cin >> tanggal;
        showPesananOnDay(ListOjol, idPenumpang, tanggal);
        cout << endl;
        break;
        }
    }
    return 0;
}
