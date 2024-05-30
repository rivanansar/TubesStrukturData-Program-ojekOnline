#include "ojol.h"

//Method Ojol
void createList_Ojol(CDLLOjol &ListOjol)
{
    first(ListOjol) = NULL;
    last(ListOjol) = NULL;
}

adrOjol new_elmOjol(string idOjol, string nama)
{
    adrOjol p = new elmOjol;
    info(p).idOjol = idOjol;
    info(p).nama = nama;
    next(p) = NULL;
    prev(p) = NULL;
    pesanan(p) = NULL;
    return p;
}

void insertLast_Ojol(CDLLOjol &ListOjol, adrOjol p) //Insert data ojol dari belakang (5)
{
    if (first(ListOjol) == NULL && last(ListOjol) == NULL){
        next(p) = p;
        prev(p) = p;
        first(ListOjol) = p;
        last(ListOjol) = p;
    } else {
        next(p) = first(ListOjol);
        prev(p) = last(ListOjol);
        next(last(ListOjol)) = p;
        prev(first(ListOjol)) = p;
        last(ListOjol) = p;
    }
}

void deleteFirst_Ojol(CDLLOjol &ListOjol, adrOjol &p)
{
    if (next(first(ListOjol)) == first(ListOjol)){
        p = first(ListOjol);
        next(p) = NULL;
        prev(p) = NULL;
        first(ListOjol) = NULL;
        last(ListOjol) = NULL;
    } else {
        p = first(ListOjol);
        first(ListOjol) = next(p);
        next(last(ListOjol)) = first(ListOjol);
        prev(first(ListOjol)) = last(ListOjol);
        next(p) = NULL;
        prev(p) = NULL;
    }
}

void deleteLast_Ojol(CDLLOjol &ListOjol, adrOjol &p)
{
    if (next(first(ListOjol)) == first(ListOjol)){
        p = first(ListOjol);
        next(p) = NULL;
        prev(p) = NULL;
        first(ListOjol) = NULL;
        last(ListOjol) = NULL;
    } else {
        p = last(ListOjol);
        last(ListOjol) = prev(p);
        next(last(ListOjol)) = first(ListOjol);
        prev(first(ListOjol)) = last(ListOjol);
        next(p) = NULL;
        prev(p) = NULL;
    }
}

void deleteAfter_Ojol(CDLLOjol &ListOjol, adrOjol prec, adrOjol &p)
{
    p = next(prec);
    next(prec) = next(p);
    prev(next(p)) = prec;
    next(p) = NULL;
    prev(p) = NULL;
}

void delete_Ojol(CDLLOjol &ListOjol, string idOjol, adrOjol &p) //Menghapus data ojol beserta relasinya (15)
{
    adrOjol q = search_Ojol(ListOjol, idOjol);
    if(q != NULL)
    {
        if(q == first(ListOjol))
        {
            deleteFirst_Ojol(ListOjol, p);
        }
        else if (q == last(ListOjol))
        {
            deleteLast_Ojol(ListOjol, p);
        }
        else
        {
            adrOjol r = first(ListOjol);
            while(next(r) != first(ListOjol))
            {
                if(next(r) == q)
                {
                    deleteAfter_Ojol(ListOjol, r, p);
                }
                r = next(r);
            }
        }
    }
}

adrOjol search_Ojol(CDLLOjol ListOjol, string idOjol) //Mencari data ojol (5)
{
    adrOjol p = first(ListOjol);
    while(next(p) != first(ListOjol))
    {
        if(info(p).idOjol == idOjol)
        {
            return p;
        }
        p = next(p);
    }
    if(info(p).idOjol == idOjol)
    {
        return p;
    }
    return NULL;
}

void show_Ojol(CDLLOjol ListOjol) //Show all data ojol (5)
{
    adrOjol p = first(ListOjol);
    int i = 1;
    cout << " ======= LIST OJOL =======" << endl;
    while(next(p) != first(ListOjol))
    {
        cout << "[" << i << "]" << endl;
        cout << "ID Ojol     : "<< info(p).idOjol << endl;
        cout << "Nama Ojol   : "<< info(p).nama << endl;
        p = next(p);
        i++;
    }
    cout << "[" << i << "]" << endl;
    cout << "ID Ojol     : "<< info(p).idOjol << endl;
    cout << "Nama Ojol   : "<< info(p).nama << endl;
    cout << endl;
}
//Method Ojol


//Method Penumpang
void createList_Penumpang(DLLPenumpang &ListPenumpang)
{
    first(ListPenumpang) = NULL;
    last(ListPenumpang) = NULL;
}
adrPenumpang new_elmPenumpang(string idPenumpang, string nama)
{
    adrPenumpang p = new elmPenumpang;
    info(p).idPenumpang = idPenumpang;
    info(p).nama = nama;
    next(p) = NULL;
    prev(p) = NULL;
    return p;
}
void insertLast_Penumpang(DLLPenumpang &ListPenumpang, adrPenumpang p) //Menambahkan data penumpang (5)
{
    if (first(ListPenumpang) == NULL && last(ListPenumpang) == NULL){
        first(ListPenumpang) = p;
        last(ListPenumpang) = p;
    } else {
        prev(p) = last(ListPenumpang);
        next(last(ListPenumpang)) = p;
        last(ListPenumpang) = p;
    }
}

adrPenumpang search_Penumpang(DLLPenumpang &ListPenumpang, string idPenumpang) //Mencari data penumpang (5)
{
    adrPenumpang p = first(ListPenumpang);
    while(next(p) != first(ListPenumpang))
    {
        if(info(p).idPenumpang == idPenumpang)
        {
            return p;
        }
        p = next(p);
    }
    return NULL;
}
//Method Penumpang


//Method Pesanan
adrPesanan new_elmPesanan(string idPesanan, string tanggal, string idOjol, string idPenumpang)
{
    adrPesanan p = new elmPesanan;
    info(p).idPesanan = idPesanan;
    info(p).tanggal = tanggal;
    info(p).idOjol = idOjol;
    info(p).idPenumpang = idPenumpang;
    next(p) = NULL;
    penumpang(p) = NULL;
    return p;
}

void insertPesanan(CDLLOjol &ListOjol, DLLPenumpang ListPenumpang, adrPesanan p) //Menghubungkan data ojol ke data penumpang (5)
{
    adrOjol ojol = search_Ojol(ListOjol, info(p).idOjol);
    adrPenumpang penumpang = search_Penumpang(ListPenumpang, info(p).idPenumpang);

    if(ojol != NULL && penumpang != NULL){
        penumpang(p) = penumpang;
        if(pesanan(ojol) == NULL)
        {
            pesanan(ojol) = p;
        }
        else
        {
            adrPesanan q = pesanan(ojol);
            while(next(q) != NULL)
            {
                q = next(q);
            }
            next(q) = p;
        }
    }
}

void showAllPesanan(CDLLOjol ListOjol) //Menampilkan seluruh data ojol beserta penumpangnya (15)
{
    adrOjol ojol = first(ListOjol);
    int i = 1;
    int u = 1;

    while(next(ojol) != first(ListOjol))
    {
        cout << "[" << i << "]" << endl;
        cout << "ID Ojol : "<< info(ojol).idOjol << "\t Nama Ojol : " << info(ojol).nama <<endl;
        adrPesanan pesanan = pesanan(ojol);
        if(pesanan != NULL)
        {
            cout << "===================================================================================" << endl;
            cout << "No.     ID Pesanan \t Tanggal Pesanan \t ID Ojol \t ID Penumpang \t Nama Penumpang" << endl;
            while(pesanan != NULL)
            {
                cout << u << "       " << info(pesanan).idPesanan << "\t\t " << info(pesanan).tanggal << "\t\t " << info(pesanan).idOjol << "\t\t "<< info(pesanan).idPenumpang<< "\t\t "<< info(penumpang(pesanan)).nama<< endl;
                pesanan = next(pesanan);
                u++;
            }
        }
        else
        {
            cout << "Ojol ini tidak memiliki pesanan !" << endl;
        }
        i++;
        ojol = next(ojol);
        cout << endl;
    }
    cout << "[" << i << "]" << endl;
        cout << "ID Ojol : "<< info(ojol).idOjol << "\t Nama Ojol : " << info(ojol).nama <<endl;
        adrPesanan pesanan = pesanan(ojol);
        if(pesanan != NULL)
        {
            cout << "===================================================================================" << endl;
            cout << "No.     ID Pesanan \t Tanggal Pesanan \t ID Ojol \t ID Penumpang \t Nama Penumpang" << endl;
            while(pesanan != NULL)
            {
                cout << u << "       " << info(pesanan).idPesanan << "\t\t " << info(pesanan).tanggal << "\t\t " << info(pesanan).idOjol << "\t\t "<< info(pesanan).idPenumpang<< "\t\t "<< info(penumpang(pesanan)).nama<< endl;
                pesanan = next(pesanan);
                u++;
            }
        }
        else
        {
            cout << "Ojol ini tidak memiliki pesanan !" << endl;
        }
}

void showPesanan(CDLLOjol ListOjol, string idOjol) //Mencari data penumpang pada ojol tertentu (10)
{
    adrOjol ojol = search_Ojol(ListOjol, idOjol);


    cout << "ID Ojol : "<< info(ojol).idOjol << "\t Nama Ojol : " << info(ojol).nama <<endl;
    adrPesanan pesanan = pesanan(ojol);
    if(pesanan != NULL)
    {
        int u = 1;
        cout << "===================================================================================" << endl;
        cout << "No.     ID Pesanan \t Tanggal Pesanan \t ID Ojol \t ID Penumpang \t Nama Penumpang" << endl;
        while(pesanan != NULL)
        {
            cout << u << "       " << info(pesanan).idPesanan << "\t\t " << info(pesanan).tanggal << "\t\t " << info(pesanan).idOjol << "\t\t "<< info(pesanan).idPenumpang<< "\t\t "<< info(penumpang(pesanan)).nama<<endl;
            pesanan = next(pesanan);
            u++;
        }
    }
    else
    {
        cout << "Ojol ini tidak memiliki pesanan !" << endl;
    }
}

void deleteFirst_Pesanan(CDLLOjol &ListOjol, adrOjol ojol, adrPesanan &p)
{
    if(next(pesanan(ojol)) == NULL)
    {
        p = pesanan(ojol);
        pesanan(ojol) = NULL;
    }
    else
    {
        p = pesanan(ojol);
        pesanan(ojol) = next(p);
        next(p) = NULL;
    }
}

void deleteLast_Pesanan(CDLLOjol &ListOjol, adrOjol ojol, adrPesanan &p)
{
    if(next(pesanan(ojol)) == NULL)
    {
        p = pesanan(ojol);
        pesanan(ojol) = NULL;
    }
    else
    {
        adrPesanan q = pesanan(ojol);
        while(next(next(q)) != NULL)
        {
            q = next(q);
        }
        p = next(q);
        next(q) = NULL;
    }
}

void deleteAfter_Pesanan(CDLLOjol &ListOjol, adrPesanan prec, adrPesanan &p)
{
    p = next(prec);
    next(prec) = next(p);
    next(p) = NULL;
}

void deletePesanan(CDLLOjol &ListOjol, string idPesanan, adrPesanan &p) //Menghapus data penumpang pada ojol tertentu beserta relasinya (15)
{
    adrOjol ojol = first(ListOjol);
    bool deleted = false;
    while(next(ojol) != first(ListOjol))
    {
        adrPesanan pesanan = pesanan(ojol);
        if (pesanan != NULL)
        {
            if (info(pesanan).idPesanan == idPesanan)
            {
                deleteFirst_Pesanan(ListOjol, ojol, p);
            }
            while(next(pesanan) != NULL)
            {
                if(info(next(pesanan)).idPesanan == idPesanan)
                {
                    deleteAfter_Pesanan(ListOjol, pesanan, p);
                    deleted = true;
                    break;
                }

                pesanan = next(pesanan);
            }
        }
        ojol = next(ojol);
    }
}

void showPesananOnDay(CDLLOjol ListOjol, string idPenumpang, string tanggal) //Menampilkan jumlah ojol yang dipesan seorang penumpang dalam satu hari (5)
{
    adrOjol ojol = first(ListOjol);
    cout << "Pesanan ID Penumpang "<< idPenumpang<< " pada tanggal " << tanggal <<endl;
    cout << "===================================================================================" << endl;
    cout << "No.     ID Pesanan \t Tanggal Pesanan \t ID Ojol \t ID Penumpang \t Nama Penumpang" << endl;
    while(next(ojol) != first(ListOjol))
    {
        int u = 1;

        adrPesanan pesanan = pesanan(ojol);
        if(pesanan != NULL)
        {

            while(pesanan != NULL)
            {
                if (info(pesanan).idPenumpang == idPenumpang && info(pesanan).tanggal == tanggal)
                {
                    cout << u << "       " << info(pesanan).idPesanan << "\t\t " << info(pesanan).tanggal << "\t\t " << info(pesanan).idOjol << "\t\t " << info(pesanan).idPenumpang<< "\t\t "<< info(penumpang(pesanan)).nama<< endl;
                }

                pesanan = next(pesanan);
                u++;
            }
        }
        ojol = next(ojol);
    }

}
//Method Pesanan
