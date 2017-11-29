# Tubes-2-Jarkom

### Petunjuk Penggunaan Program

__Menjalankan Program__

__Format Input__
Baris Pertama berisi sebuah bilangan N, jumlah node pada topologi
N baris berikutnya masing-masing berisi nol atau lebih angka yang dipisahkan dengan tanda koma
Angka-angka pada baris ke-i menyatakan node-node yang terhubung dengan node ke-i.
Jika tidak ada node yang terhubung, maka baris tersebut hanya berupa newline('\n') saja.
Baris berikutnya berisi sebuah bilangan S atau banyaknya skenario yang terjadi.
S baris berikutnya masing-masing terdiri dari 2 bilangan.
Baris ke-i berisi u dan v, yang menyatakan bahwa node u mengirim informasi ke node v

### Penjelasan Program

### Pembagian Tugas

### Jawaban Pertanyaan
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
