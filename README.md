# HASTRACK - Simple Habits Tracker & To Do List

**Hastrack** adalah aplikasi task management _system_ berbasis _**command-line**_ yang dibuat dengan bahasa pemrograman C. Aplikasi ini dirancang untuk membantu pengguna dalam mengelola aktivitas sehari-hari dengan fitur-fitur seperti pencatatan tugas, pelacakan progres, dan penyimpanan data otomatis.

## Fitur 
* **To Do List :** Menambahkan daftar tugas/aktivitas.
* **View Activity :** Lihat dan kelola tugas/aktivitas.
* **View Recent :** Lihat data tugas/aktivitas terbaru.
* **Exit :** Keluar dan simpan data.

## Teknologi yang Digunakan
* **Bahasa Pemrograman :** C
* **Library :** (Standar) stdio.h, stdlib.h, time.h, string.h.
* **Konsep Pemrograman :** Variabel, Tipe Data, Function, I/O, Condition, Looping, Array, Pointer, Struct, File Processing, Enum, dan Bit Manipulation.

## Cara Menjalankan
1. Install compiler C (GCC/MinGW).
2. Clone Repository ini :
   ```bash
   git clone [sieeroo] (https://github.com/sieeroo/hastrack-cli.git)
3. Compile Program
   ```bash
   gcc -o hastrack.h main.c menu.c feature.c handlefile.c user.c
4. Jalankan Program
   ```bash
   ./hastrack
