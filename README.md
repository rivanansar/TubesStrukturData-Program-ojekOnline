# TubesStrukturData-Program-ojekOnline

Program ini menggunakan bahasa C++ yang merupakan sebuah aplikasi manajemen pemesanan ojek online sederhana yang melibatkan beberapa entitas, yaitu ojol (ojek online), penumpang, dan pesanan. Berikut adalah deskripsi cara kerja dari program ini:

-> Program memiliki 9 menu yang terdiri dari Insert Ojol(ID ojol dan nama ojol), Insert Penumpang(ID Penumpang dan Nama penumpang), Insert pesanan(ID pesanan), Delete suatu ojol berdasarkan ID, Delete suatu pesanan(berdasarkan ID), dapat menunjukan/show list dari semua ojol yang di-input, dapat show list ojol beserta pesanannya, dapat show pesanan salah satu ojol yang dicari(dengan memasukkan ID ojol) dan menu terakhir dapat Show Pesanan Suatu Penumpang Dalam Satu Hari yang sama.

-> Struktur Data yang Digunakan :
CDLLOjol (Circular Doubly Linked List Ojol): Digunakan untuk menyimpan daftar ojol.
DLLPenumpang (Doubly Linked List Penumpang): Digunakan untuk menyimpan daftar penumpang.
Pesanan (Linked List dalam setiap node Ojol): Digunakan untuk menyimpan daftar pesanan yang terkait dengan ojol dan penumpang.
