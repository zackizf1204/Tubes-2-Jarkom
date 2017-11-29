# IF3130 Jaringan Komputer - Tugas Besar 2 Distance Vector Simulation

## Petunjuk Penggunaan Program

### Menjalankan Program
Program ini ditulis dalam bahasa C++. Untuk menjalankan program harus melakukan kompilasi terlebih dahulu. Kompilasi
cukup dilakukan dengan perintah
```
make
```
pada bash.

### Format Input
Baris pertama berisi dua  bilangan N dan M, jumlah node pada topologi dan jumlah edge pada topologi.
M baris berikutnya masing-masing berisi 2 bilangan. Baris ke-i berisi ui dan vi, yang menyatakan bahwa node ui terhubung dengan node vi.
Baris berikutnya berisi sebuah bilangan S, banyaknya skenario yang terjadi.
S baris berikutnya masing-masing terdiri dari 2 bilangan. Baris ke-i berisi xi dan yi, yang menyatakan bahwa node xi akan mencoba mengirim informasi ke node yi.

## Penjelasan Program
Pada program ini, topologi direpresentasikan dengan dua buah matriks, yaitu nextHop dan distance sedangkan sebuah node tunggal
direpresentasikan oleh sebuah baris pada matriks nextHop dan distance. Untuk indeks i dan j pada matriks berarti informasi routing dari node-i ke node-j.

Pengiriman pesan terjadi ketika program menerima input skenario. Untuk setiap node asal yang berkomunikasi pada node tujuan, lakukan pembaruan pada node tujuan apabila node asal terhubung dengan suatu node lain yang belum terhubung dengan node tujuan.

## Pembagian Tugas

* 13515012 : readme, soal 1
* 13515135 : generate test
* 13515147 : update table

## Jawaban Pertanyaan
__A. 	Apakah perbedaan dari routing protocol distance-vector dan link state? Manakah yang​ ​ lebih​ ​ baik​ ​ untuk​ ​ digunakan?__

1. 	Distance Vector
	Sesuai namanya, distance vector routing menggunakan jarak untuk menentukan rute terbaik pada jaringan. Biasanya jarak ditentukan oleh jumlah hops ke Network tujuan. Algoritma yang digunakan adalah Bellman-Ford, untuk menghitung rute terbaik 
	
	Distance vector protocol mengirim routing table yang lengkap ke setiap tetangga. Distance vector protocol juga menggunakan lebih banyak bandwith, karena mengirim semua routing table. Contoh dari distance vector routing adalah RIP dan EIGRP
	
2. Link State
	Berbeda dengan distance vector protocol, Link State tidak mengirim semua informasi routing table, tapi hanya mengirim informasi tentang topologi jaringannya. Jadi, pada saat semua router dijalankan, link state protocol mempunyai database topologi jaringan yang sama.
	
	Link state membutuhkan router CPU dan penggunaan memori yang lebih banyak dibandingkan distance vector. Algoritma yang digunakan untuk menghitung rute terbaik adalah Shortest Path Algorithm. Contoh dari Link State adalah OSPF dan IS-IS.
	
	Penggunaan kedua routing protocol ini tergantung pada ukuran jaringannya, jika ukuran jaringannya kecil, maka lebih disarankan untuk memakai Distance vector protocol karena Distance vector lebih mudah di konfigurasi dan membutuhkan maintenance yang lebih sedikit, karena CPU yang dipakai juga sedikit, tapi membutuhkan performa yang tinggi dan bandwith yang besar.
	Sedangkan untuk link state lebih tepat jika diterapkan pada jaringan skala besar, karena waktu konvergensinya lebih cepat, tetapi membutuhkan CPU yang banyak. Hal ini menyebabkan link state perlu maintenance yang lebih banyak dan sulit di konfigurasi.


__B.	 Pada implementasinya saat ini manakah yang lebih banyak digunakan, distance-vector​ ​ atau​ ​ ​ link​ ​ state?​ ​ Kenapa?__

## Authors

* Rio Dwi Putra Perkasa - 13515012
* Muhammad Akmal Pratama - 13515135
* Zacki Zulfikar Fauzi - 13515147

