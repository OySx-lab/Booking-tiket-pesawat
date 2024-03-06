#include <iostream>
#include <string> // buat fungsi getline-stringnya
#include <cstdlib> // buat di fungsi rand()
#include <iomanip> // agar output hasil tiketnya engga 1.5e+06 , dan agar bisa jadi 1500000 (1.5jt)
using namespace std;

string generateRandomPaymentCode() // password acak
{
    const char charset[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"; // buat elemen password random 
    const int codeLength = 6; // panjang kodenya 

    string paymentCode = "";  // tanda "", itu buat masukin si random passwordnya yang di atas 
    int charsetSize = sizeof(charset) - 1; // ini di - 1 karena dari 62 variabel cahr nnti jadi kurang menjadi 61, jadi huruf atau angaka yang sudah digunakan tidak bisa digunakan lagi

    // Inisialisasi generator angka acak
    srand((time(NULL))); // nilai dari code acak/nilai awal yang berubah dengan waktu saat ini, sehingga setiap kali program dijalankan, generator angka acak akan diinisialisasi dengan nilai yang berbeda.

    // Generate kode pembayaran acak atau fungsi membuat kode acaknya
    for (int i = 0; i < codeLength; ++i) {
        paymentCode += charset[rand() % charsetSize];
    }

    return paymentCode;
}


int main()
{
    // jspr = jenis perjalanan
    int jspr_tanggal_b, jspr_tanggal_p, 
        jspr_bulan_b, jspr_bulan_p,
        jspr_tahun_b, jspr_tahun_p,
        jspr_tanggal_sa, jspr_bulan_sa,
        jspr_tahun_sa;

    string jspr, asal, tujuan,
           validasi_PulPer;

// <-----------------------------------------------------------------------------------pilih asal tujuan pulang pergi & satu arah (2 orang)--------------------------------------------------------------------------->

main_menu:

    cout << " _____________________________ \n";
    cout << "|      Maskapai Pesawat       |\n";
    cout << "|____--------1-2-3--------____|\n";

asal_tujuan_menu:                                                                                              // jspr menu
    cout << "\nPilih Asal dan Tujuan\n";
    do {
        cout << "Asal   : ";
        getline(cin, asal);
    } 
    while (asal.empty());

    do {
        cout << "Tujuan : ";
        getline(cin, tujuan);
    } 
    while (tujuan.empty());
    
    cout << "_______________________\n";


jsper_menu_2:
    cout << asal << " => " << tujuan << endl;
    cout << "  (1) Pulang - Pergi\n  (2) Satu Arah\n  (3) Kembali\n";
    cout << "      Memilih Jenis Perjalanan : ";
    getline(cin, jspr);

    // ini kalo pilih jenis perjalananya "pulang pergi"
    if (jspr == "1" || jspr == "PULANG - PERGI" || jspr == "Pulang - Pergi" || jspr == "pulang - pergi" || jspr == "PULANG PERGI" || jspr == "Pulang Pergi" || jspr == "pulang pergi" || jspr == "PP" || jspr == "pp" || jspr == "PULPER" || jspr == "PulPer" || jspr == "pulper")
    {

        cout << "____________________________________";
        system("cls");

        // ini validasi                                                                                 
        do  // ini looping klo pulang lebih kecil dari berangkat                                                                                      
        {
        pulang_pergi_menu:
            // cout << endl << endl;
            cout << "> Pulang-Pergi\n";
            cout << "  Silahkan Mengisi Data Berikut : \n";
            cout << "  (Data berupa = tanggal, bulan, tahun keberangkatan &\n";
            cout << "                 tanggal, bulan, tahun kembali)\n";

            cout << "   Tanggal(Berangkat) : ";
            cin >> jspr_tanggal_b;
            cout << "   Bulan(Berangkat)   : ";
            cin >> jspr_bulan_b;
            cout << "   Tahun(Berangkat)   : ";
            cin >> jspr_tahun_b;

            cout << endl;

            cout << "   Tanggal(Pulang)    : ";
            cin >> jspr_tanggal_p;
            cout << "   Bulan(Pulang)      : ";
            cin >> jspr_bulan_p;
            cout << "   Tahun(Pulang)      : ";
            cin >> jspr_tahun_p;

            if (jspr_tahun_b > jspr_tahun_p ||
            (jspr_tahun_b == jspr_tahun_p && jspr_bulan_b > jspr_bulan_p) ||
            (jspr_tahun_b == jspr_tahun_p && jspr_bulan_b == jspr_bulan_p && jspr_tanggal_b > jspr_tanggal_p)) 
            {
                cin.ignore();
                cout << "\n   !!! Validasi gagal, waktu pulang harus lebih besar dari pada waktu berangkat !!!, [enter] untuk mengubah \n";
                cin.get();

            } else 
            {
                // ini buat memastikan data pulang pergi benar atau mau di edit 
                do  // ini looping yakin mau tanggal segitu atau ubah
                {
                    // ini buat memastikan lagi klo tanggal yang dipilih benar atau mau ganti dan seabgainya
                    string validasi_PulPer;
                    cout << endl;
                    cout << "  Apakah Benar Anda Memesan Pada Tanggal \n";
                    cout << "   Berangkat          : " << jspr_tanggal_b << "/" << jspr_bulan_b << "/" << jspr_tahun_b << endl;
                    cout << "   Pulang             : " << jspr_tanggal_p << "/" << jspr_bulan_p << "/" << jspr_tahun_p << endl;
                    cout << "     (1) Benar/Lanjut\n";
                    cout << "     (2) Salah/Edit\n";
                    cout << "     (3) Kembali (Ke Jenis Perjalanan)\n";
                    cout << "         Memilih : ";
                    cin >> validasi_PulPer;

                    if (validasi_PulPer == "1" || validasi_PulPer == "BENAR" || validasi_PulPer == "Benar" || validasi_PulPer == "benar" || validasi_PulPer == "LANJUT" || validasi_PulPer == "Lanjut" || validasi_PulPer == "lanjut")
                    {
                        goto validasi_pulang_pergi_berhasil;

                    }
                    else if (validasi_PulPer == "2" || validasi_PulPer == "SALAH" || validasi_PulPer == "Salah" || validasi_PulPer == "salah" || validasi_PulPer == "EDIT" || validasi_PulPer == "Edit" || validasi_PulPer == "edit")
                    {
                        cout << endl;
                        goto pulang_pergi_menu;

                    }
                    else if (validasi_PulPer == "3" || validasi_PulPer == "KEMBALI" || validasi_PulPer == "Kembali" || validasi_PulPer == "kembali")
                    {
                        cin.ignore();
                        system("cls");
                        goto jsper_menu_2;

                    }
                    else
                    {
                        cin.ignore();
                        cout << "         Silahkan pilih (1) (2) / (3), [enter] untuk melanjutkan";
                        cin.get();
                    }

                } while (!(validasi_PulPer == "1" || validasi_PulPer == "BENAR" || validasi_PulPer == "Benar" || validasi_PulPer == "benar" || validasi_PulPer == "LANJUT" || validasi_PulPer == "Lanjut" || validasi_PulPer == "lanjut" || validasi_PulPer == "2" || validasi_PulPer == "SALAH" || validasi_PulPer == "Salah" || validasi_PulPer == "salah" || validasi_PulPer == "EDIT" || validasi_PulPer == "Edit" || validasi_PulPer == "edit"));

            }


        } while (jspr_tahun_b > jspr_tahun_p ||
            (jspr_tahun_b == jspr_tahun_p && jspr_bulan_b > jspr_bulan_p) ||
            (jspr_tahun_b == jspr_tahun_p && jspr_bulan_b == jspr_bulan_p && jspr_tanggal_b > jspr_tanggal_p));

    validasi_pulang_pergi_berhasil:
        // output vlalidasi pulang pergi berhasil
        cin.ignore();
        cout << "\n   Validasi berhasil . . . [enter]";
        cin.get();

        cout << endl;
        cout << "   Data : \n";

        cout << "            " << asal << " - " << tujuan << " | " << "Berangkat - Pulang" << endl
            << "            ----------------------------" << endl
            << "            Berangkat " << "(" << jspr_tanggal_b << "/" << jspr_bulan_b << "/" << jspr_tahun_b << ")" << endl
            << "            Pulang " << "   (" << jspr_tanggal_p << "/" << jspr_bulan_p << "/" << jspr_tahun_p << ")"
            << "\n                                         . . . [enter]";
        cout << "\n______________________________________________________";


//<------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------->


            // ini kalo pilih jenis perjalananya "satu arah"
    }
    else if (jspr == "2" || jspr == "SATU ARAH" || jspr == "Satu Arah" || jspr == "satu arah" || jspr == "SA" || jspr == "Sa" || jspr == "sa") // eror disini bisa dibenerin dgn jspr == "2", gt
    {

        cout << "____________________________________";
        system("cls");
    satu_arah_menu:
        // cout << endl << endl;
        cout << "> Satu Arah\n";
        cout << "  Silahkan Mengisi Data Berikut :\n";
        cout << "  (Data berupa = tanggal, bulan dan tahun keberangkatan)\n";
        cout << "    Tanggal             : ";
        cin >> jspr_tanggal_sa;
        cout << "    Bulan               : ";
        cin >> jspr_bulan_sa;
        // getline(cin, jspr_bulan_sa);
        cout << "    Tahun Keberangkatan : ";
        cin >> jspr_tahun_sa;

        // ini buat memastikan data pulang pergi benar atau mau di edit 
        do
        {
            string validasi_PulPer;
            cout << endl;
            cout << "   Apakah Benar Anda Memesan Pada Tanggal : " << jspr_tanggal_sa << "/" << jspr_bulan_sa << "/" << jspr_tahun_sa << endl;
            cout << "     (1) Benar/Lanjut\n";
            cout << "     (2) Salah/Edit\n";
            cout << "     (3) Kembali (Ke Jenis Perjalanan)\n";
            cout << "         Memilih : ";
            cin >> validasi_PulPer;

            if (validasi_PulPer == "1" || validasi_PulPer == "BENAR" || validasi_PulPer == "Benar" || validasi_PulPer == "benar" || validasi_PulPer == "LANJUT" || validasi_PulPer == "Lanjut" || validasi_PulPer == "lanjut")
            {
                goto validasi_satu_arah_berhasil;

            }
            else if (validasi_PulPer == "2" || validasi_PulPer == "SALAH" || validasi_PulPer == "Salah" || validasi_PulPer == "salah" || validasi_PulPer == "EDIT" || validasi_PulPer == "Edit" || validasi_PulPer == "edit")
            {
                cout << endl;
                goto satu_arah_menu;

            }
            else if (validasi_PulPer == "3" || validasi_PulPer == "KEMBALI" || validasi_PulPer == "Kembali" || validasi_PulPer == "kembali")
            {
                cin.ignore();
                system("cls");
                goto jsper_menu_2;

            }
            else
            {
                cin.ignore();
                cout << "         Silahkan pilih (1) (2) / (3), [enter] untuk melanjutkan";
                cin.get();
            }

        } while (!(validasi_PulPer == "1" || validasi_PulPer == "BENAR" || validasi_PulPer == "Benar" || validasi_PulPer == "benar" || validasi_PulPer == "LANJUT" || validasi_PulPer == "Lanjut" || validasi_PulPer == "lanjut" || validasi_PulPer == "2" || validasi_PulPer == "SALAH" || validasi_PulPer == "Salah" || validasi_PulPer == "salah" || validasi_PulPer == "EDIT" || validasi_PulPer == "Edit" || validasi_PulPer == "edit"));

    validasi_satu_arah_berhasil:
        cout << "\n    Data : \n";

        cout << "             " << asal << " - " << tujuan << " | " << "Satu Arah " << " | " << "(" << jspr_tanggal_sa << "/" << jspr_bulan_sa << "/" << jspr_tahun_sa << ")"
            << "\n                                           . . . [enter]";

        cout << "\n________________________________________________________";
        // cin.ignore();
        cin.get();

        goto jenkls_menu;

    }
    else if (jspr == "3" || jspr == "KEMBALI" || jspr == "Kembali" || jspr == "kembali")
    {
        cout << "__________________________________\n";
        system("cls");
        goto main_menu;

        return 0;
    }
    else
    {
        cout << "      Silahkan pilih (1) (2) / (3), [enter] untuk melanjutkan\n";
        // cout << "\n____________________________________________________________";
        cin.get();

        goto jsper_menu_2;
    }


// <-------------------------------------------------------------------------------------------------harga tiket (3 orang)------------------------------------------------------------------------------------------->


jenkls_menu: // jk = jenis kelas   
   // jk menu

    string info_HargaTiket, tambah_tiket, cek_nama, 
           nama_dewasa_ekonomi[100], 
           nama_dewasa_bisnis[100], 
           nama_dewasa_utama[100],
           nama_anak_ekonomi[100], 
           nama_anak_bisnis[100], 
           nama_anak_utama[100];;

    float jskls_anak,
          jskls_anak_ekonomi = 0,
          jskls_anak_bisnis = 0,
          jskls_anak_utama = 0,

          semua_jml_anak = 0,
          jml_harga = 0,
          jml_akumulasi = 0,
          jml_akumulasi_dewasa = 0,
          jml_akumulasi_anak = 0;

    int jskls_dewasa,
        jml_dewasa = 0,
        jml_anak = 0,

        jskls_dewasa_ekonomi = 0,
        jskls_dewasa_bisnis = 0,
        jskls_dewasa_utama = 0,

        jml_tiket = 0,
        semua_jml_dewasa = 0,

        jml_dewasa_ekonomi = 0,
        jml_dewasa_bisnis = 0,
        jml_dewasa_utama = 0,
        jml_anak_ekonomi = 0,
        jml_anak_bisnis = 0,
        jml_anak_utama = 0,


        i_dewasa_ekonomi = 1,
        i_dewasa_bisnis = 1,
        i_dewasa_utama = 1,
        sn_dewasa_ekonomi = 0,
        sn_dewasa_bisnis = 0,
        sn_dewasa_utama = 0,
        i_anak_ekonomi = 1,
        i_anak_bisnis = 1,
        i_anak_utama = 1,
        sn_anak_ekonomi = 0,
        sn_anak_bisnis = 0,
        sn_anak_utama = 0;

     // tipe data ini buat ganti jkls dewasa/anak jadi angka 1, biar netral jadi 1 lagi (kan kalo kita masuakin 3 ke var jskls_dewasa klo misal pilih 3 jadi nilainya kan 3:v)

    const int harga_tiket = 1000000; // 1 000.000
    
    cin.get();
    system("cls");
    cout << "> Pesan Tiket";

    // bawah ini memperlihatkan informasi dari memilih jenis perjalanan
    if (jspr == "1" || jspr == "PULANG - PERGI" || jspr == "Pulang - Pergi" || jspr == "pulang - pergi" || jspr == "PULANG PERGI" || jspr == "Pulang Pergi" || jspr == "pulang pergi" || jspr == "PP" || jspr == "pp" || jspr == "PULPER" || jspr == "PulPer" || jspr == "pulper")  // pulang pergi hasil jenis perjalanan
    {
        cout << "\n\n  " << asal << " - " << tujuan << " | " << "Berangkat - Pulang" << endl
            << "  ----------------------------" << endl
            << "  Berangkat " << "(" << jspr_tanggal_b << "/" << jspr_bulan_b << "/" << jspr_tahun_b << ")" << endl
            << "  Pulang " << "   (" << jspr_tanggal_p << "/" << jspr_bulan_p << "/" << jspr_tahun_p << ")";

    }
    else if (jspr == "2" || jspr == "SATU ARAH" || jspr == "Satu Arah" || jspr == "satu arah" || jspr == "SA" || jspr == "Sa" || jspr == "sa")   // satu arah hasil jenis perjalanan
    {
        cout << "\n\n  " << asal << " - " << tujuan << " | " << "Satu Arah " << " | " << "(" << jspr_tanggal_sa << "/" << jspr_bulan_sa << "/" << jspr_tahun_sa << ")";
    }


    // cin.ignore();
    cin.get();
    cout << endl;
    cout << "Pilih *0 Jika Tidak Ingin Memesan Tiket.\n";
    cout << "Harga Tiket = 1.000.000\n";
    cout << " Tiket Anak    = 1/2 Harga Tiket\n";
    cout << " Kelas Ekonomi = 1x Harga Tiket\n";
    cout << " Kelas Bisnis  = 2x Harga Tiket\n";
    cout << " Kelas Utama   = 3x Harga Tiket\n";
    cout << " > Tekan (1) untuk informasi lebih, \n";
    cout << "   tekan selain (1) untuk melewati : ";
    cin >> info_HargaTiket;

    if (info_HargaTiket == "1")
    {
        cout << endl;
        cout << "Pilih *0 di [Memilih Jenis Kelas] / [Jumlah Orang Dewasa/Anak-anak] Jika Tidak Ingin Memesan Tiket.\n";
        cout << "Harga Tiket = Rp.1.000.000\n";
        cout << " > Tiket Dewasa : \n";
        cout << "   Harga Tiket Ekonomi = Rp.1.000.000\n";
        cout << "   Harga Tiket Bisnis  = Rp.2.000.000\n";
        cout << "   Harga Tiket Utama   = Rp.3.000.000\n";
        cout << " > Tiket Anak-anak : \n";
        cout << "   Harga Tiket Ekonomi = Rp.500.000\n";
        cout << "   Harga TIket Bisnis  = Rp.1.000.000\n";
        cin.ignore();
        cout << "   Harga Tiket Utama   = Rp.1.500.000  . . . [enter]";
        cin.get();
    }

    cout << endl;


//<------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------->


    cout << "Berikutnya Anda akan Memilih Kelas dan Jumlah Penumpang (Dewasa & Anak)\n";

    // ini looping si tambah tiketnya 
    do {
    tambah_tiket:
    jenkls_dewasa:
        cout << "  Jenis Kelas - (Dewasa)\n";
        cout << "    (1) Ekonomi\n    (2) Bisnis\n    (3) Kelas Utama\n";
        cout << "        Memilih Jenis Kelas : ";
        cin >> jskls_dewasa;


        // ini agar mengubah nilai harga saat memilih jenis kelas   

        if (jskls_dewasa == 1)                  // dewasa - ekonomi           
        {
            jskls_dewasa = 1;

        }
        else if (jskls_dewasa == 2)           // dewasa - binis
        {
            jskls_dewasa = 2;

        }
        else if (jskls_dewasa == 3)           // dewasa - utama
        {
            jskls_dewasa = 3;

        }
        else if (jskls_dewasa == 0)
        {
            jskls_dewasa = 0;
            jskls_dewasa_ekonomi += 0;
            jskls_dewasa_bisnis += 0;
            jskls_dewasa_utama += 0;

            goto jenkls_anak;
        }
        else
        {
            cin.ignore();
            cout << "        Silahkan pilih kelas (1), (2) / (3), [enter] untuk melanjutkan";
            cin.get();
            cout << endl;
            goto jenkls_dewasa;
        }
        cout << "        Jumlah Orang Dewasa : ";
        cin >> jml_dewasa;

        if (jml_dewasa == 0) // biar keskip ke page berikutnya
        {
            goto jenkls_anak;
        }

        // ini codingan buat mengetahui jumlah tiket dewasa dan anak di setiap kelas yang dipilih
        if (jskls_dewasa == 1)                  // dewasa - ekonomi           
        {
            jskls_dewasa_ekonomi += jml_dewasa;
            jml_dewasa_ekonomi = jml_dewasa ; 
            sn_dewasa_ekonomi += jml_dewasa_ekonomi;

        }
        else if (jskls_dewasa == 2)           // dewasa - binis
        {
            jskls_dewasa_bisnis += jml_dewasa;
            jml_dewasa_bisnis = jml_dewasa;
            sn_dewasa_bisnis += jml_dewasa_bisnis;

        }
        else if (jskls_dewasa == 3)           // dewasa - utama
        {
            jskls_dewasa_utama += jml_dewasa;
            jml_dewasa_utama = jml_dewasa;
            sn_dewasa_utama += jml_dewasa_utama;


        }
        else if (jskls_dewasa == 0)
        {
            jskls_dewasa = 1;

            goto jenkls_anak;

        }

        // ini codingan buat nama tiket dewasa yang dipesan 
        cout << endl;
        cout << "        Mohon Masukan Nama Anda untuk Proses Pemesanan\n";
        cout << "        (Jumlah inputan nama sama sesuai jumlah tiket dewasa yg diinputkan)\n";

        // ini buat ngecek info aja 
        // cout << jml_dewasa_ekonomi << endl;
        // cout << "-----------------" << endl;
        // cout << "sn_dewasa_ekonomi : " << sn_dewasa_ekonomi << endl;
        // cout << "sn_dewasa_bisnis : " << sn_dewasa_bisnis << endl;
        // cout << "sn_dewasa_utama : " << sn_dewasa_utama << endl << endl;


        if (jskls_dewasa == 1)
        {
            cin.ignore();
            do {
                int kurang = 0, // int ini buat nguranin nilainya saat nnt kita milih 2 / 3 di bagian "Apakah Nama Ini Sudah Benar? (y/n)"
                    tambah = 0;
                for (i_dewasa_ekonomi ; i_dewasa_ekonomi <= sn_dewasa_ekonomi; i_dewasa_ekonomi++)
                {
                    do {
                        cout << "           > Masukan Nama (" << i_dewasa_ekonomi << ") : ";
                        getline(cin, nama_dewasa_ekonomi[i_dewasa_ekonomi]);
                    }
                    while (nama_dewasa_ekonomi[i_dewasa_ekonomi].empty());
                    kurang--;
                    tambah++;

                }
                // ini buat ngecek arraynya berfungsi atau enggak
                // for (i_dewasa_ekonomi ; i_dewasa_ekonomi <= sn_dewasa_ekonomi; i_dewasa_ekonomi++)
                // {
                //     cout << nama_dewasa_ekonomi[i_dewasa_ekonomi] << " ";
                // }

                do {
                    cout << endl;
                    cout << "             Apakah Nama Ini Sudah Benar? (y/n)\n";
                    cout << "               (1) Iya/Lanjut\n";
                    cout << "               (2) Tidak/Edit\n";
                    cout << "               (3) kembali\n";
                    cout << "                   Memilih : ";
                    cin >> cek_nama;

                    if (cek_nama=="1"||cek_nama=="Y"||cek_nama=="y"||cek_nama=="IYA"||cek_nama=="Iya"||cek_nama=="iya"||cek_nama=="LANJUT"||cek_nama=="Lanjut"||cek_nama=="lanjut")
                    {
                        // ya lanjut 

                    } else if (cek_nama=="2"||cek_nama=="N"||cek_nama=="n"||cek_nama=="TIDAk"||cek_nama=="Tidak"||cek_nama=="tidak"||cek_nama=="EDIT"||cek_nama=="Edit"||cek_nama=="edit")
                    {
                        i_dewasa_ekonomi += kurang; // buat netral in lagi
                        cout << endl;
                        cin.ignore();
                        // nnti ke ulang ke atas

                    } else if (cek_nama=="3"||cek_nama=="KEMBALI"||cek_nama=="Kembali"||cek_nama=="kembali")
                    {
                        sn_dewasa_ekonomi -= tambah;
                        i_dewasa_ekonomi  -= tambah;
                        jml_dewasa_ekonomi -= tambah;
                        jskls_dewasa_ekonomi -= tambah;
                        
                        cout << endl;
                        goto jenkls_dewasa;
                    }
                    else 
                    {
                        cin.ignore();
                        cout << "                   Silahkan pilih kelas (1), (2) / (3), [enter] untuk melanjutkan";
                        cin.get();
                    }
                    
                } while (!(cek_nama=="1"||cek_nama=="Y"||cek_nama=="y"||cek_nama=="IYA"||cek_nama=="Iya"||cek_nama=="iya"||cek_nama=="LANJUT"||cek_nama=="Lanjut"||cek_nama=="lanjut"||cek_nama=="2"||cek_nama=="N"||cek_nama=="n"||cek_nama=="TIDAk"||cek_nama=="Tidak"||cek_nama=="tidak"||cek_nama=="EDIT"||cek_nama=="Edit"||cek_nama=="edit"));

            } while (!(cek_nama=="1"||cek_nama=="Y"||cek_nama=="y"||cek_nama=="IYA"||cek_nama=="Iya"||cek_nama=="iya"||cek_nama=="LANJUT"||cek_nama=="Lanjut"||cek_nama=="lanjut"));

        } else if (jskls_dewasa == 2)
        {
            cin.ignore();
            do {
                int kurang = 0,
                    tambah = 0;
                for (i_dewasa_bisnis ; i_dewasa_bisnis <= sn_dewasa_bisnis; i_dewasa_bisnis++)
                {
                    do {
                        cout << "           > Masukan Nama (" << i_dewasa_bisnis << ") : ";
                        getline(cin, nama_dewasa_bisnis[i_dewasa_bisnis]);
                    }
                    while (nama_dewasa_bisnis[i_dewasa_bisnis].empty());
                    kurang--;
                    tambah++;

                }
                // ini buat ngecek arraynya berfungsi atau enggak
                // for (i_dewasa_bisnis ; i_dewasa_bisnis <= sn_dewasa_bisnis; i_dewasa_bisnis++)
                // {
                //     cout << nama_dewasa_bisnis[i_dewasa_bisnis] << " ";
                // }

                do {
                    cout << endl;
                    cout << "             Apakah Nama Ini Sudah Benar? (y/n)\n";
                    cout << "               (1) Iya/Lanjut\n";
                    cout << "               (2) Tidak/Edit\n";
                    cout << "               (3) kembali\n";
                    cout << "                   Memilih : ";
                    cin >> cek_nama;

                    if (cek_nama=="1"||cek_nama=="Y"||cek_nama=="y"||cek_nama=="IYA"||cek_nama=="Iya"||cek_nama=="iya"||cek_nama=="LANJUT"||cek_nama=="Lanjut"||cek_nama=="lanjut")
                    {
                        // ya lanjut 

                    } else if (cek_nama=="2"||cek_nama=="N"||cek_nama=="n"||cek_nama=="TIDAk"||cek_nama=="Tidak"||cek_nama=="tidak"||cek_nama=="EDIT"||cek_nama=="Edit"||cek_nama=="edit")
                    {
                        i_dewasa_bisnis += kurang; // buat netral in lagi
                        cout << endl;
                        cin.ignore();
                        // nnti ke ulang ke atas

                    } else if (cek_nama=="3"||cek_nama=="KEMBALI"||cek_nama=="Kembali"||cek_nama=="kembali")
                    {
                        sn_dewasa_bisnis -= tambah;
                        i_dewasa_bisnis  -= tambah;
                        jml_dewasa_bisnis -= tambah;
                        jskls_dewasa_bisnis -= tambah;
                        cout << endl;
                        goto jenkls_dewasa;
                    }
                    else 
                    {
                        cin.ignore();
                        cout << "                   Silahkan pilih kelas (1), (2) / (3), [enter] untuk melanjutkan";
                        cin.get();
                    }
                    
                } while (!(cek_nama=="1"||cek_nama=="Y"||cek_nama=="y"||cek_nama=="IYA"||cek_nama=="Iya"||cek_nama=="iya"||cek_nama=="LANJUT"||cek_nama=="Lanjut"||cek_nama=="lanjut"||cek_nama=="2"||cek_nama=="N"||cek_nama=="n"||cek_nama=="TIDAk"||cek_nama=="Tidak"||cek_nama=="tidak"||cek_nama=="EDIT"||cek_nama=="Edit"||cek_nama=="edit"));

            } while (!(cek_nama=="1"||cek_nama=="Y"||cek_nama=="y"||cek_nama=="IYA"||cek_nama=="Iya"||cek_nama=="iya"||cek_nama=="LANJUT"||cek_nama=="Lanjut"||cek_nama=="lanjut"));

        } else if (jskls_dewasa == 3)
        {
            cin.ignore();
            do {
                int kurang = 0,
                    tambah = 0;
                for (i_dewasa_utama ; i_dewasa_utama <= sn_dewasa_utama; i_dewasa_utama++)
                {
                    do {
                        cout << "           > Masukan Nama (" << i_dewasa_utama << ") : ";
                        getline(cin, nama_dewasa_utama[i_dewasa_utama]);
                    }
                    while (nama_dewasa_utama[i_dewasa_utama].empty());
                    kurang--;
                    tambah++;

                }
                // ini buat ngecek arraynya berfungsi atau enggak
                // for (i_dewasa_utama ; i_dewasa_utama <= sn_dewasa_utama; i_dewasa_utama++)
                // {
                //     cout << nama_dewasa_utama[i_dewasa_utama   ] << " ";
                // }

                do {
                    cout << endl;
                    cout << "             Apakah Nama Ini Sudah Benar? (y/n)\n";
                    cout << "               (1) Iya/Lanjut\n";
                    cout << "               (2) Tidak/Edit\n";
                    cout << "               (3) kembali\n";
                    cout << "                   Memilih : ";
                    cin >> cek_nama;

                    if (cek_nama=="1"||cek_nama=="Y"||cek_nama=="y"||cek_nama=="IYA"||cek_nama=="Iya"||cek_nama=="iya"||cek_nama=="LANJUT"||cek_nama=="Lanjut"||cek_nama=="lanjut")
                    {
                        // ya lanjut 

                    } else if (cek_nama=="2"||cek_nama=="N"||cek_nama=="n"||cek_nama=="TIDAk"||cek_nama=="Tidak"||cek_nama=="tidak"||cek_nama=="EDIT"||cek_nama=="Edit"||cek_nama=="edit")
                    {
                        i_dewasa_utama += kurang; // buat netral in lagi
                        cout << endl;
                        cin.ignore();
                        // nnti ke ulang ke atas

                    } else if (cek_nama=="3"||cek_nama=="KEMBALI"||cek_nama=="Kembali"||cek_nama=="kembali")
                    {
                        sn_dewasa_utama -= tambah;
                        i_dewasa_utama  -= tambah;
                        jml_dewasa_utama -= tambah;
                        jskls_dewasa_utama -= tambah;
                        cout << endl;
                        goto jenkls_dewasa;
                    }
                    else 
                    {
                        cin.ignore();
                        cout << "                   Silahkan pilih kelas (1), (2) / (3), [enter] untuk melanjutkan";
                        cin.get();
                    }
                    
                } while (!(cek_nama=="1"||cek_nama=="Y"||cek_nama=="y"||cek_nama=="IYA"||cek_nama=="Iya"||cek_nama=="iya"||cek_nama=="LANJUT"||cek_nama=="Lanjut"||cek_nama=="lanjut"||cek_nama=="2"||cek_nama=="N"||cek_nama=="n"||cek_nama=="TIDAk"||cek_nama=="Tidak"||cek_nama=="tidak"||cek_nama=="EDIT"||cek_nama=="Edit"||cek_nama=="edit"));

            } while (!(cek_nama=="1"||cek_nama=="Y"||cek_nama=="y"||cek_nama=="IYA"||cek_nama=="Iya"||cek_nama=="iya"||cek_nama=="LANJUT"||cek_nama=="Lanjut"||cek_nama=="lanjut"));
                     
        }

    jenkls_anak:
        cout << endl;
        cout << "  Jenis Kelas - (Anak) \n";                                                                  // anak-anak
        cout << "    (1) Ekonomi\n    (2) Bisnis\n    (3) Kelas Utama\n";
        cout << "        Memilih Jenis Kelas : ";
        cin >> jskls_anak;


        // ini agar mengubah nilai harga saat memilih jenis kelas

        if (jskls_anak == 1)                // anak - ekonomi         
        {
            jskls_anak = 0.5;

        }
        else if (jskls_anak == 2)         // anak - bisnis
        {
            jskls_anak = 1;

        }
        else if (jskls_anak == 3)         // anak = utama
        {
            jskls_anak = 1.5;

        }
        else if (jskls_anak == 0)
        {
            jskls_anak = 0;
            jskls_anak_ekonomi += 0;
            jskls_anak_bisnis + -0;
            jskls_anak_utama += 0;

            goto tambah_tiket_menu;
        }
        else
        {
            cin.ignore();
            cout << "        Silahkan pilih kelas (1), (2) / (3), [enter] untuk melanjutkan";
            cin.get();

            goto jenkls_anak;
        }

        cout << "        Jumlah Anak-anak    : ";
        cin >> jml_anak;

        if (jml_anak == 0) // biar keskip ke page berikutnya
        {
            goto tambah_tiket_menu;

        }


        // ini codingan buat mengetahui jumlah tiket dewasa dan anak di setiap kelas yang dipilih
        if (jskls_anak == 0.5)                  // anak - ekonomi           
        {
            jskls_anak_ekonomi += jml_anak; 
            jml_anak_ekonomi = jml_anak ; 
            sn_anak_ekonomi += jml_anak_ekonomi;


        }
        else if (jskls_anak == 1)           // anak - binis
        {   
            jskls_anak_bisnis += jml_anak;
            jml_anak_bisnis = jml_anak ; 
            sn_anak_bisnis += jml_anak_bisnis;

        }
        else if (jskls_anak == 1.5)           // anak - utama
        {
            jskls_anak_utama += jml_anak;
            jml_anak_utama = jml_anak ; 
            sn_anak_utama += jml_anak_utama;

        }
        else if (jskls_anak == 0)
        {
            jskls_anak = 1;

        }

        // ini codingan buat nama tiket dewasa yang dipesan 
        cout << endl;
        cout << "        Mohon Masukan Nama Anda untuk Proses Pemesanan\n";
        cout << "        (Jumlah inputan nama sama sesuai jumlah tiket anak yg diinputkan)\n";

        if (jskls_anak == 0.5)
        {
            cin.ignore();
            do {
                int kurang = 0,
                    tambah = 0;
                for (i_anak_ekonomi ; i_anak_ekonomi <= sn_anak_ekonomi; i_anak_ekonomi++)
                {
                    do {
                        cout << "           > Masukan Nama (" << i_anak_ekonomi << ") : ";
                        getline(cin, nama_anak_ekonomi[i_anak_ekonomi]);
                    }
                    while (nama_anak_ekonomi[i_anak_ekonomi].empty());
                    kurang--;
                    tambah++;

                }
                // ini buat ngecek arraynya berfungsi atau enggak
                // for (i_anak_ekonomi ; i_anak_ekonomi <= sn_anak_ekonomi; i_anak_ekonomi++)
                // {
                //     cout << nama_anak_ekonomi[i_anak_ekonomi] << " ";
                // }

                do {
                    cout << endl;
                    cout << "             Apakah Nama Ini Sudah Benar? (y/n)\n";
                    cout << "               (1) Iya/Lanjut\n";
                    cout << "               (2) Tidak/Edit\n";
                    cout << "               (3) kembali\n";
                    cout << "                   Memilih : ";
                    cin >> cek_nama;

                    if (cek_nama=="1"||cek_nama=="Y"||cek_nama=="y"||cek_nama=="IYA"||cek_nama=="Iya"||cek_nama=="iya"||cek_nama=="LANJUT"||cek_nama=="Lanjut"||cek_nama=="lanjut")
                    {
                        // ya lanjut 

                    } else if (cek_nama=="2"||cek_nama=="N"||cek_nama=="n"||cek_nama=="TIDAk"||cek_nama=="Tidak"||cek_nama=="tidak"||cek_nama=="EDIT"||cek_nama=="Edit"||cek_nama=="edit")
                    {
                        i_anak_ekonomi += kurang; // buat netral in lagi
                        cout << endl;
                        cin.ignore();
                        // nnti ke ulang ke atas

                    } else if (cek_nama=="3"||cek_nama=="KEMBALI"||cek_nama=="Kembali"||cek_nama=="kembali")
                    {
                        sn_anak_utama -= tambah;
                        i_anak_utama  -= tambah;
                        jml_anak_utama -= tambah;
                        jskls_anak_utama -= tambah;
                        cout << endl;
                        goto jenkls_dewasa;
                    }
                    else 
                    {
                        cin.ignore();
                        cout << "                   Silahkan pilih kelas (1), (2) / (3), [enter] untuk melanjutkan";
                        cin.get();
                    }
                    
                } while (!(cek_nama=="1"||cek_nama=="Y"||cek_nama=="y"||cek_nama=="IYA"||cek_nama=="Iya"||cek_nama=="iya"||cek_nama=="LANJUT"||cek_nama=="Lanjut"||cek_nama=="lanjut"||cek_nama=="2"||cek_nama=="N"||cek_nama=="n"||cek_nama=="TIDAk"||cek_nama=="Tidak"||cek_nama=="tidak"||cek_nama=="EDIT"||cek_nama=="Edit"||cek_nama=="edit"));

            } while (!(cek_nama=="1"||cek_nama=="Y"||cek_nama=="y"||cek_nama=="IYA"||cek_nama=="Iya"||cek_nama=="iya"||cek_nama=="LANJUT"||cek_nama=="Lanjut"||cek_nama=="lanjut"));

        } else if (jskls_anak == 1)
        {
            cin.ignore();
            do {
                int kurang = 0,
                    tambah = 0;
                for (i_anak_bisnis ; i_anak_bisnis <= sn_anak_bisnis; i_anak_bisnis++)
                {
                    do {
                        cout << "           > Masukan Nama (" << i_anak_bisnis << ") : ";
                        getline(cin, nama_anak_bisnis[i_anak_bisnis]);
                    }
                    while (nama_anak_bisnis[i_anak_bisnis].empty());
                    kurang--;
                    tambah++;

                }
                // ini buat ngecek arraynya berfungsi atau enggak
                // for (i_anak_bisnis ; i_anak_bisnis <= sn_anak_bisnis; i_anak_bisnis++)
                // {
                //     cout << nama_anak_bisnis[i_anak_bisnis] << " ";
                // }

                do {
                    cout << endl;
                    cout << "             Apakah Nama Ini Sudah Benar? (y/n)\n";
                    cout << "               (1) Iya/Lanjut\n";
                    cout << "               (2) Tidak/Edit\n";
                    cout << "               (3) kembali\n";
                    cout << "                   Memilih : ";
                    cin >> cek_nama;

                    if (cek_nama=="1"||cek_nama=="Y"||cek_nama=="y"||cek_nama=="IYA"||cek_nama=="Iya"||cek_nama=="iya"||cek_nama=="LANJUT"||cek_nama=="Lanjut"||cek_nama=="lanjut")
                    {
                        // ya lanjut 

                    } else if (cek_nama=="2"||cek_nama=="N"||cek_nama=="n"||cek_nama=="TIDAk"||cek_nama=="Tidak"||cek_nama=="tidak"||cek_nama=="EDIT"||cek_nama=="Edit"||cek_nama=="edit")
                    {
                        i_anak_bisnis += kurang; // buat netral in lagi
                        cout << endl;
                        cin.ignore();
                        // nnti ke ulang ke atas

                    } else if (cek_nama=="3"||cek_nama=="KEMBALI"||cek_nama=="Kembali"||cek_nama=="kembali")
                    {
                        sn_anak_utama -= tambah;
                        i_anak_utama  -= tambah;
                        jml_anak_utama -= tambah;
                        jskls_anak_utama -= tambah;
                        cout << endl;
                        goto jenkls_dewasa;
                    }
                    else 
                    {
                        cin.ignore();
                        cout << "                   Silahkan pilih kelas (1), (2) / (3), [enter] untuk melanjutkan";
                        cin.get();
                    }
                    
                } while (!(cek_nama=="1"||cek_nama=="Y"||cek_nama=="y"||cek_nama=="IYA"||cek_nama=="Iya"||cek_nama=="iya"||cek_nama=="LANJUT"||cek_nama=="Lanjut"||cek_nama=="lanjut"||cek_nama=="2"||cek_nama=="N"||cek_nama=="n"||cek_nama=="TIDAk"||cek_nama=="Tidak"||cek_nama=="tidak"||cek_nama=="EDIT"||cek_nama=="Edit"||cek_nama=="edit"));

            } while (!(cek_nama=="1"||cek_nama=="Y"||cek_nama=="y"||cek_nama=="IYA"||cek_nama=="Iya"||cek_nama=="iya"||cek_nama=="LANJUT"||cek_nama=="Lanjut"||cek_nama=="lanjut"));

        } else if (jskls_anak == 1.5)
        {
            cin.ignore();
            do {
                int kurang = 0,
                    tambah = 0;
                for (i_anak_utama ; i_anak_utama <= sn_anak_utama; i_anak_utama++)
                {
                    do {
                        cout << "           > Masukan Nama (" << i_anak_utama << ") : ";
                        getline(cin, nama_anak_utama[i_anak_utama]);
                    }
                    while (nama_anak_utama[i_anak_utama].empty());
                    kurang--;
                    tambah++;

                }
                // ini buat ngecek arraynya berfungsi atau enggak
                // for (i_anak_utama ; i_anak_utama <= sn_anak_utama; i_anak_utama++)
                // {
                //     cout << nama_anak_utama[i_anak_utama   ] << " ";
                // }

                do {
                    cout << endl;
                    cout << "             Apakah Nama Ini Sudah Benar? (y/n)\n";
                    cout << "               (1) Iya/Lanjut\n";
                    cout << "               (2) Tidak/Edit\n";
                    cout << "               (3) kembali\n";
                    cout << "                   Memilih : ";
                    cin >> cek_nama;

                    if (cek_nama=="1"||cek_nama=="Y"||cek_nama=="y"||cek_nama=="IYA"||cek_nama=="Iya"||cek_nama=="iya"||cek_nama=="LANJUT"||cek_nama=="Lanjut"||cek_nama=="lanjut")
                    {
                        // ya lanjut 

                    } else if (cek_nama=="2"||cek_nama=="N"||cek_nama=="n"||cek_nama=="TIDAk"||cek_nama=="Tidak"||cek_nama=="tidak"||cek_nama=="EDIT"||cek_nama=="Edit"||cek_nama=="edit")
                    {
                        i_anak_utama += kurang; // buat netral in lagi
                        cout << endl;
                        cin.ignore();
                        // nnti ke ulang ke atas

                    } else if (cek_nama=="3"||cek_nama=="KEMBALI"||cek_nama=="Kembali"||cek_nama=="kembali")
                    {
                        sn_anak_utama -= tambah;
                        i_anak_utama  -= tambah;
                        jml_anak_utama -= tambah;
                        jskls_anak_utama -= tambah;
                        cout << endl;
                        goto jenkls_dewasa;
                    }
                    else 
                    {
                        cin.ignore();
                        cout << "                   Silahkan pilih kelas (1), (2) / (3), [enter] untuk melanjutkan";
                        cin.get();
                    }
                    
                } while (!(cek_nama=="1"||cek_nama=="Y"||cek_nama=="y"||cek_nama=="IYA"||cek_nama=="Iya"||cek_nama=="iya"||cek_nama=="LANJUT"||cek_nama=="Lanjut"||cek_nama=="lanjut"||cek_nama=="2"||cek_nama=="N"||cek_nama=="n"||cek_nama=="TIDAk"||cek_nama=="Tidak"||cek_nama=="tidak"||cek_nama=="EDIT"||cek_nama=="Edit"||cek_nama=="edit"));

            } while (!(cek_nama=="1"||cek_nama=="Y"||cek_nama=="y"||cek_nama=="IYA"||cek_nama=="Iya"||cek_nama=="iya"||cek_nama=="LANJUT"||cek_nama=="Lanjut"||cek_nama=="lanjut"));
                     
        }

        

    tambah_tiket_menu:
        cout << endl;
        cout << "        Tambah Tiket Lagi (y/n)? \n";
        cout << "          (1) Iya/Tambah\n";
        cout << "          (2) Tidak/Lanjut\n";
        cout << "              Memilih : ";
        cin >> tambah_tiket;

        if (tambah_tiket == "1" || tambah_tiket == "Y" || tambah_tiket == "y" || tambah_tiket == "IYA" || tambah_tiket == "Iya" || tambah_tiket == "iya" || tambah_tiket == "TAMBAH" || tambah_tiket == "Tambah" || tambah_tiket == "tambah") // kalo memilih 1 berarti dia looping ke atas lagu 
        {
            cout << endl;

        }
        else if (tambah_tiket == "2" || tambah_tiket == "N" || tambah_tiket == "n" || tambah_tiket == "TIDAK" || tambah_tiket == "Tidak" || tambah_tiket == "tidak" || tambah_tiket == "LANJUT" || tambah_tiket == "Lanjut" || tambah_tiket == "lanjut") // kalo memilih 2 berarti dia langsung ke bawah
        {
            cout << endl;

        }
        else
        {
            cin.ignore();
            cout << "              Silahkan pilih (1) atau (2), [enter] untuk melanjutkan";
            cin.get();

            goto tambah_tiket_menu;
        }

        // rumus menentukan jumlah harga tiket
        jml_akumulasi_dewasa = (jskls_dewasa * jml_dewasa * harga_tiket);
        jml_akumulasi_anak = (jskls_anak * jml_anak * harga_tiket);

        jml_akumulasi = jml_akumulasi_dewasa + jml_akumulasi_anak;
        jml_harga += jml_akumulasi;

    } while (tambah_tiket == "1" || tambah_tiket == "Y" || tambah_tiket == "y" || tambah_tiket == "IYA" || tambah_tiket == "Iya" || tambah_tiket == "iya" || tambah_tiket == "TAMBAH" || tambah_tiket == "Tambah" || tambah_tiket == "tambah");


//<------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------->


total_harga_tiket_menu:
    string pilihan_tidak_setuju_total_harga_tiket, total_tiket;

    // menentukan jumlah tiket
    jml_tiket += (jskls_dewasa_ekonomi + jskls_anak_ekonomi) + (jskls_dewasa_bisnis + jskls_anak_bisnis) + (jskls_dewasa_utama + jskls_anak_utama);

    // ini buat info jumlah tiket dewasa untuk syarat pada bagian print tiket nnti
    semua_jml_dewasa += (jskls_dewasa_ekonomi + jskls_dewasa_bisnis + jskls_dewasa_utama);

    // ini buat info jumlah tiket anak yntuk syarat pada bagian print tiket nnti
    semua_jml_anak += (jskls_anak_ekonomi + jskls_anak_bisnis + jskls_anak_utama);

    cin.ignore();
    cout << "        Menentukan Jumlah Tiket dan Jenis Penumpang . . . [enter]";
    cin.get();

    string tidak_ada_tiket;
    if (jml_tiket == 0)     // ini kalo kita jumlah tiketnya o 
    {
        cout << endl;
        cout << "        Anda Belum Memesan Tiket Sama Sekali!, Silahkan Pesan tiket atau keluar?\n";
        cout << "          (1) Pesan Tiket\n";
        cout << "          (2) Kembali Ke Awal\n";
        cout << "          (3) Keluar\n";
        cout << "              Memilih : ";
        cin >> tidak_ada_tiket;

        if (tidak_ada_tiket == "1" || tidak_ada_tiket == "PILIH TIKET" || tidak_ada_tiket == "Pilih Tiket" || tidak_ada_tiket == "pilih tiket")
        {
            // cout << endl;
            system("cls");
            goto jenkls_dewasa;

        }
        else if (tidak_ada_tiket == "2" || tidak_ada_tiket == "KEMBALI" || tidak_ada_tiket == "Kembali" || tidak_ada_tiket == "kembali" || tidak_ada_tiket == "AWAL" || tidak_ada_tiket == "Awal" || tidak_ada_tiket == "awal")
        {
            system("cls");
            cin.ignore();

            goto main_menu;

        }
        else if (tidak_ada_tiket == "3" || tidak_ada_tiket == "KELUAR" || tidak_ada_tiket == "Keluar" || tidak_ada_tiket == "keluar")
        {
            cin.ignore();
            cout << endl << endl;

            return 0;

        }

    }


    // ini buat keterangan lanjut dari tiket yang kita pesan
    cout << endl;
    cout << "         Tiket Ekonomi " << endl;
    cout << "           > Jumlah Dewasa  : " << jskls_dewasa_ekonomi;
    // buat kasih keterangan harga nntinya
    if (jskls_dewasa_ekonomi == 0) 
    {

    } 
    else // klo jumlah tiket nya tidak 0 maka akan muncul cout ini
    {
        cout << " x (1.000.000)";
    }
    cout << endl;

    cout << "             Jumlah Anak2   : " << jskls_anak_ekonomi;
    if (jskls_anak_ekonomi == 0)
    {

    }
    else
    {
        cout << " x (500.000)";
    }
    cout << endl;

    cout << "         Tiket Bisnis " << endl;
    cout << "           > Jumlah Dewasa  : " << jskls_dewasa_bisnis;
    if (jskls_dewasa_bisnis == 0)
    {

    }
    else
    {
        cout << " x (2.000.000)";
    }
    cout << endl;

    cout << "             Jumlah Anak2   : " << jskls_anak_bisnis;
    if (jskls_anak_bisnis == 0)
    {

    }
    else
    {
        cout << " x (1.000.000)";
    }
    cout << endl;

    cout << "         Tiket Utama " << endl;
    cout << "           > Jumlah Dewasa  : " << jskls_dewasa_utama;
    if (jskls_dewasa_utama == 0)
    {

    }
    else
    {
        cout << " x (3.000.000)";
    }
    cout << endl;

    cout << "             Jumlah Anak2   : " << jskls_anak_utama;
    if (jskls_anak_utama == 0)
    {

    }
    else
    {
        cout << " x (1.500.000)";
    }
    cout << endl;

    cout << "        Jumlah Tiket        : " << jml_tiket << "    . . . [enter]";
    cin.get();
    cout << endl;

total_harga_tiket_final:
    // ini menenujukan harga total tiket yang kita pesan    
    cout << "        Total Harga Tiket : " << fixed << setprecision(0) << jml_harga << endl; // ini fungsinya (fixed, setprecision) > iomanip agar total harga jadi tidak 1.5e+06, dan agar bisa jadi 1500000
    cout << "          (1) Setuju\n";
    cout << "          (2) Tidak Setuju\n";
    cout << "              Memilih : ";
    cin >> total_tiket;

    if (total_tiket == "1" || total_tiket == "SETUJU" || total_tiket == "Setuju" || total_tiket == "setuju" || total_tiket == "IYA" || total_tiket == "Iya" || total_tiket == "iya" || total_tiket == "YA" || total_tiket == "Ya" || total_tiket == "ya" || total_tiket == "Y" || total_tiket == "y")
    {
        // cout << "\n=== anda setuju ===\n";
        cout << "_______________________________________________________________________";
        cin.get();
        cin.ignore();
        system("cls");

    }
    else if (total_tiket == "2" || total_tiket == "TIDAK SETUJU" || total_tiket == "Tidak Setuju" || total_tiket == "tidak setuju" || total_tiket == "TIDAK" || total_tiket == "Tidak" || total_tiket == "tidak" || total_tiket == "T" || total_tiket == "t")
    {

        string pilihan_tidak_setuju_total_harga_tiket;

        do
        {
            // cout << "\n=== anda tidak setuju ===\n";

        mengulang_kembali_atau_keluar_menu:
            cout << "______________________________________________________________________\n";
            system("cls");
            cout << "                                         \n";
            cout << "Mengulang Ke-Pemilihan Tiket, Mengulang ke-Awal atau Keluar/selesai? : \n";
            cout << "  (1) Mengulang ke-Pemilihan Tiket\n";
            cout << "  (2) Mengulang ke-Awal\n";
            cout << "  (3) Keluar\n";
            cout << "      Memilih : ";
            cin >> pilihan_tidak_setuju_total_harga_tiket;

            if (pilihan_tidak_setuju_total_harga_tiket == "1" || pilihan_tidak_setuju_total_harga_tiket == "kembali") // ini mengulang ke menu tiket
            {
                cout << "______________________________________________________________________";
                system("cls");
                goto jenkls_menu;

            }
            else if (pilihan_tidak_setuju_total_harga_tiket == "2" || pilihan_tidak_setuju_total_harga_tiket == "awal") // ini mengulang dari awal
            {
                system("cls");
                cin.ignore();

                goto main_menu;

            }
            else if (pilihan_tidak_setuju_total_harga_tiket == "3" || pilihan_tidak_setuju_total_harga_tiket == "keluar") // ini keluar coding
            {
                cin.ignore();
                cout << endl << endl;

                return 0;
            }
            else
            {
                cin.ignore();
                cout << "\nSilahkan pilih (1) (2) / (3), [enter] untuk melanjutkan";
                cin.get();

                goto mengulang_kembali_atau_keluar_menu;
            }
            cout << "_______________________________________________________________________\n";
            system("cls");


        } while (!(pilihan_tidak_setuju_total_harga_tiket == "1" || pilihan_tidak_setuju_total_harga_tiket == "2" || pilihan_tidak_setuju_total_harga_tiket == "3"));

    }
    else
    {
        cin.ignore();
        cout << "              Silahkan pilih (1) atau (2), [enter] untuk melanjutkan";
        cin.get();
        cout << endl;

        goto total_harga_tiket_final;
    }



// <--------------------------------------------------------------------------------------pilih metode pembayaran + hasil tiket(2 orang)------------------------------------------------------------------------------>


metode_pembayaran_menu:
    int met_pembayaran, kode_pmbyr_Mbanking, kode_pmbyr_mitraAgen;
    int ulang_kode = 0;
    string kode;

    // cout << endl;
    cout << "> Pembayaran\n";
    cout << "  Metode Pembayaran (ada dua metode)\n";
    cout << "    (1) M-Banking\n";
    cout << "    (2) Mitra Agen\n";
    cout << "        Pilih Metode Pembayaran : ";
    cin >> met_pembayaran;

    string randomPaymentCode = generateRandomPaymentCode(); // ini fungsi non-void yang disamain dengan variabel randomPaymentCode

    if (met_pembayaran == 1)
    {
        cout << "__________________________________\n";
        system("cls");

        // cout << "\n=== anda memilih m-bangking ===\n\n";
        // cout << endl;
        cout << "> M-Bangking || Method\n";
        cin.ignore();

        cout << "  Tunggu Kode Pembayaran . . . [enter]";
        cin.get();
        cout << endl;


        do {
            // aktifin fungsi di bawah klo mau setiap salah passwordnya akan ganti ke password yang baru
            // string randomPaymentCode = generateRandomPaymentCode();

            // program masukan kode pembayaran acak

            cout << "    Kode Pembayaran : " << randomPaymentCode << endl;

            cout << "    Masukan kode    : ";
            cin >> kode;

            cout << endl << "    > Memvalidasi . . . [enter]";
            cin.get();
            cout << endl;

            ulang_kode++;

            if (kode == randomPaymentCode)
            {
                cin.ignore();
                cout << "    Validasi Pembayaran Berhasil . . . [enter]\n";
                cout << "______________________________________________";
                cin.get();
                system("cls");

                goto menu_pembuatan_tiket;

            }
            else
            {
                if (ulang_kode >= 3)
                {
                    cin.ignore();
                    cout << "    Limit Percobaan Habis, [enter] untuk kembali ke menu metode pembayaran\n";
                    cin.get();

                    goto metode_pembayaran_menu;
                }

                cin.ignore();
                cout << "    !!! Kode Pembayaran salah !!!, [enter] untuk mengulang";
                // cout << "\n______________________________________________________";
                cin.get();
                cout << endl;
            }

        } while (kode != randomPaymentCode);

    }
    else if (met_pembayaran == 2)
    {
        cout << "__________________________________\n";
        system("cls");

        // cout << "\n=== anda memilih mitra ===\n";
        // cout << endl;
        cout << "> Mitra Agen || Method\n";
        cin.ignore();
        
        cout << "  Tunggu Kode Pembayaran . . . [enter]";
        cin.get();
        cout << endl;

        do {
            // aktifin fungsi di bawah, klo mau setiap salah passwordnya akan ganti ke password yang baru
            // string randomPaymentCode = generateRandomPaymentCode();

            // program masukan kode pembayaran acak

            cout << "    Kode Pembayaran : " << randomPaymentCode << endl;

            cout << "    Masukan kode    : ";
            cin >> kode;

            cout << "\n    > Memvalidasi . . . [enter]";
            cin.get();
            cout << endl;

            ulang_kode++;

            if (kode == randomPaymentCode)
            {
                cin.ignore();
                cout << "    Validasi Pembayaran Berhasil . . . [enter]\n";
                cout << "______________________________________________";
                cin.get();
                system("cls");

                goto menu_pembuatan_tiket;

            }
            else
            {
                if (ulang_kode >= 3)
                {
                    cin.ignore();
                    cout << "    Limit Percobaan Habis, [enter] untuk kembali ke menu metode pembayaran\n";
                    cin.get();

                    goto metode_pembayaran_menu;
                }

                cin.ignore();
                cout << "    !!! Kode Pembayaran salah !!!, [enter] untuk mengulang";
                // cout << "\n______________________________________________________";
                cin.get();
                cout << endl;
            }

        } while (kode != randomPaymentCode);

    }
    else
    {
        cin.ignore();
        cout << "        Silahkan pilih (1) atau (2), [enter] untuk melanjutkan";
        cin.get();

        goto metode_pembayaran_menu;
    }


//<------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------->


                                                                                                             // cetak tiket
menu_pembuatan_tiket:
    string print_tiket;
    string pilihan_print_kembali_keluar;

    // cout << endl;
    cout << "> Print Tiket\n";
    cout << "  Tiket Yang Anda Pesan, [enter] untuk melihat";
    cin.get();
    cout << endl;

    // bawah ini memperlihatkan informasi dari memilih jenis perjalanan
    if (jspr == "1" || jspr == "PULANG - PERGI" || jspr == "Pulang - Pergi" || jspr == "pulang - pergi" || jspr == "PULANG PERGI" || jspr == "Pulang Pergi" || jspr == "pulang pergi" || jspr == "PP" || jspr == "pp" || jspr == "PULPER" || jspr == "PulPer" || jspr == "pulper")  // pulang pergi hasil jenis perjalanan
    {
        cout << "    " << asal << " - " << tujuan << " | " << "Berangkat - Pulang" << endl
            << "    ----------------------------" << endl
            << "    Berangkat " << "(" << jspr_tanggal_b << "/" << jspr_bulan_b << "/" << jspr_tahun_b << ")" << endl
            << "    Pulang " << "   (" << jspr_tanggal_p << "/" << jspr_bulan_p << "/" << jspr_tahun_p << ")" << "\n\n";
    }
    else if (jspr == "2" || jspr == "SATU ARAH" || jspr == "Satu Arah" || jspr == "satu arah" || jspr == "SA" || jspr == "Sa" || jspr == "sa")   // satu arah hasil jenis perjalanan
    {
        cout << "    " << asal << " - " << tujuan << " | " << "Satu Arah " << " | " << "(" << jspr_tanggal_sa << "/" << jspr_bulan_sa << "/" << jspr_tahun_sa << ")" << endl << endl;
    }

    // di bawah ini memperlihatkan informasi dari tiket yang kita pesan
    cout << "      Tiket Ekonomi " << endl;
    cout << "        > Jumlah Dewasa  : " << jskls_dewasa_ekonomi << endl;
    if (jskls_dewasa_ekonomi >= 1)
    {
        cout << "          Nama Pemilik Tiket" << endl;
        for (int i_dewasa_ekonomi = 1; i_dewasa_ekonomi <= jskls_dewasa_ekonomi; i_dewasa_ekonomi++)
        {
            cout << "            ~ " << nama_dewasa_ekonomi[i_dewasa_ekonomi] << endl;
        }
        cout << endl;
    }

    cout << "        > Jumlah Anak2   : " << jskls_anak_ekonomi << endl;
    if (jskls_anak_ekonomi >= 1)
    {
        cout << "          Nama Pemilik Tiket" << endl;
        for (int i_anak_ekonomi = 1; i_anak_ekonomi <= jskls_anak_ekonomi; i_anak_ekonomi++)
        {
            cout << "            ~ " << nama_anak_ekonomi[i_anak_ekonomi] << endl;
        }
        cout << endl;
    }

    cout << "      Tiket Bisnis " << endl;
    cout << "        > Jumlah Dewasa  : " << jskls_dewasa_bisnis << endl;
    if (jskls_dewasa_bisnis >= 1)
    {
        cout << "          Nama Pemilik Tiket" << endl;
        for (int i = 1; i <= jskls_dewasa_bisnis; i++)
        {
            cout << "            ~ " << nama_dewasa_bisnis[i] << endl;
        }
        cout << endl;
    }

    cout << "        > Jumlah Anak2   : " << jskls_anak_bisnis << endl;
    if (jskls_anak_bisnis >= 1)
    {
        cout << "          Nama Pemilik Tiket" << endl;
        for (int i_anak_bisnis = 1; i_anak_bisnis <= jskls_anak_bisnis; i_anak_bisnis++)
        {
            cout << "            ~ " << nama_anak_bisnis[i_anak_bisnis] << endl;
        }
        cout << endl;
    }

    cout << "      Tiket Utama " << endl;
    cout << "        > Jumlah Dewasa  : " << jskls_dewasa_utama << endl;
    if (jskls_dewasa_utama >= 1)
    {
        cout << "          Nama Pemilik Tiket" << endl;
        for (int i = 1; i <= jskls_dewasa_utama; i++)
        {
            cout << "            ~ " << nama_dewasa_utama[i] << endl;
        }
        cout << endl;
    }

    cout << "        > Jumlah Anak2   : " << jskls_anak_utama << endl;
    if (jskls_anak_utama >= 1)
    {
        cout << "          Nama Pemilik Tiket" << endl;
        for (int i_anak_utama = 1; i_anak_utama <= jskls_anak_utama; i_anak_utama++)
        {
            cout << "            ~ " << nama_anak_utama[i_anak_utama] << endl;
        }
        cout << endl;
    }

    
    cout << "     Jumlah Tiket        : " << jml_tiket << endl;

    // cuman buat garis di tiket yang anda pesan // sebenernya nga usah ribet gini soalnya hasil coutnya sama tapi dah terlanjur
    if (jspr == "1" || jspr == "PULANG - PERGI" || jspr == "Pulang - Pergi" || jspr == "pulang - pergi" || jspr == "PULANG PERGI" || jspr == "Pulang Pergi" || jspr == "pulang pergi" || jspr == "PP" || jspr == "pp" || jspr == "PULPER" || jspr == "PulPer" || jspr == "pulper")  // pulang pergi hasil jenis perjalanan
    {
        cout << "     -----------------------\n\n";

    }
    else if (jspr == "2" || jspr == "SATU ARAH" || jspr == "Satu Arah" || jspr == "satu arah" || jspr == "SA" || jspr == "Sa" || jspr == "sa")   // satu arah hasil jenis perjalanan
    {
        cout << "     -----------------------\n\n";

    }

    cout << "     Print Tiket?\n";
    cout << "     (1) Iya\n";
    cout << "     (2) Tidak\n";
    cout << "     (3) Kembali\n";
    cout << "         Memilih(1)(2)(3) : ";
    cin >> print_tiket;

    if (print_tiket == "1" || print_tiket == "Iya" || print_tiket == "iya" || print_tiket == "Ya" || print_tiket == "ya" || print_tiket == "Y" || print_tiket == "y")
    {
        if (met_pembayaran == 1)                                                            // ini tiket pulang pergi versi m_banking
        {
            cout << endl;
            cout << "      Hasil: \n";
            cout << "\n      > ini tiket M-banking_ \n";
            // cout << "       Jenis Perjalanannya : " << jspr << endl << endl;

            if (semua_jml_dewasa == 0)
            {
                goto print_anak_m_banking;
            }

            // print tiket // ini ak coba perbaiki

                                                                                                       // tiket m_banking Dewasa

            // ini print tiket klo kita pilih jenis perjalanannya pulang - pergi 
            if (jspr == "1" || jspr == "PULANG - PERGI" || jspr == "Pulang - Pergi" || jspr == "pulang - pergi" || jspr == "PULANG PERGI" || jspr == "Pulang Pergi" || jspr == "pulang pergi" || jspr == "PP" || jspr == "pp" || jspr == "PULPER" || jspr == "PulPer" || jspr == "pulper")
            {
                for (int i_dewasa_ekonomi = 1; i_dewasa_ekonomi <= jskls_dewasa_ekonomi; i_dewasa_ekonomi++) // tiket ekonomi
                {
                    cout << "       ______________________________________________________________________________ \n";
                    cout << "      |ECONOMY CLASS   ||   BOARDING PASS                             GARUDA INDO    |   Tiket Dewasa(Ekonomi) Ke : " << i_dewasa_ekonomi << endl;
                    cout << "      |----------------------------------                                            |\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |  Name > " <<nama_dewasa_ekonomi[i_dewasa_ekonomi] << endl;
                    cout << "      |  Date > (" << jspr_tanggal_b << "/" << jspr_bulan_b << "/" << jspr_tahun_b << ") to (" << jspr_tanggal_p << "/" << jspr_bulan_p << "/" << jspr_tahun_p << ")" << endl;
                    cout << "      |                                                                              |\n";
                    cout << "      |    from                                                                      |\n";
                    cout << "      |  > " << asal << endl;
                    cout << "      |    to                                                                        |\n";
                    cout << "      |  > " << tujuan << endl;
                    cout << "      |_________ _____ __ _                                      _ __ _____ _________|\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |     please be at the boarding gate at least 30 minutes before derpature      |\n";
                    cout << "      |______________________________________________________________________________|\n";

                }


                for (int i_dewasa_bisnis = 1; i_dewasa_bisnis <= jskls_dewasa_bisnis; i_dewasa_bisnis++)  // tiket bisnis  
                {
                    cout << "       ______________________________________________________________________________ \n";
                    cout << "      |BUSINESS CLASS   ||   BOARDING PASS                            GARUDA INDO    |   Tiket Dewasa(Bisnis) Ke : " << i_dewasa_bisnis << endl;
                    cout << "      |-----------------------------------                                           |\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |  Name > " <<nama_dewasa_bisnis[i_dewasa_bisnis] << endl;
                    cout << "      |  Date > (" << jspr_tanggal_b << "/" << jspr_bulan_b << "/" << jspr_tahun_b << ") to (" << jspr_tanggal_p << "/" << jspr_bulan_p << "/" << jspr_tahun_p << ")" << endl;
                    cout << "      |                                                                              |\n";
                    cout << "      |    from                                                                      |\n";
                    cout << "      |  > " << asal << endl;
                    cout << "      |    to                                                                        |\n";
                    cout << "      |  > " << tujuan << endl;
                    cout << "      |_________ _____ __ _                                      _ __ _____ _________|\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |     please be at the boarding gate at least 30 minutes before derpature      |\n";
                    cout << "      |______________________________________________________________________________|\n";

                }


                for (int i_dewasa_utama = 1; i_dewasa_utama <= jskls_dewasa_utama; i_dewasa_utama++)   // tiket utama
                {
                    cout << "       ______________________________________________________________________________ \n";
                    cout << "      |MAIN CLASS   ||   BOARDING PASS                                GARUDA INDO    |   Tiket Dewasa(Utama) Ke : " << i_dewasa_utama << endl;
                    cout << "      |-------------------------------                                               |\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |  Name > " <<nama_dewasa_utama[i_dewasa_utama] << endl;
                    cout << "      |  Date > (" << jspr_tanggal_b << "/" << jspr_bulan_b << "/" << jspr_tahun_b << ") to (" << jspr_tanggal_p << "/" << jspr_bulan_p << "/" << jspr_tahun_p << ")" << endl;
                    cout << "      |                                                                              |\n";
                    cout << "      |    from                                                                      |\n";
                    cout << "      |  > " << asal << endl;
                    cout << "      |    to                                                                        |\n";
                    cout << "      |  > " << tujuan << endl;
                    cout << "      |_________ _____ __ _                                      _ __ _____ _________|\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |     please be at the boarding gate at least 30 minutes before derpature      |\n";
                    cout << "      |______________________________________________________________________________|\n";

                }




                // ini print tiket klo kita pilih jenis perjalanannya satu arah 
            }
            else if (jspr == "2" || jspr == "SATU ARAH" || jspr == "Satu Arah" || jspr == "satu arah" || jspr == "SA" || jspr == "Sa" || jspr == "sa")
            {
                for (int i_dewasa_ekonomi = 1; i_dewasa_ekonomi <= jskls_dewasa_ekonomi; i_dewasa_ekonomi++)    // tiket ekonomi
                {
                    cout << "       ______________________________________________________________________________ \n";
                    cout << "      |ECONOMY CLASS   ||   BOARDING PASS                              GARUDA INDO   |   Tiket Dewasa(Ekonomi) Ke : " << i_dewasa_ekonomi << endl;
                    cout << "      |----------------------------------                                            |\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |  Name > " <<nama_dewasa_ekonomi[i_dewasa_ekonomi] << endl;
                    cout << "      |  Date > (" << jspr_tanggal_sa << "/" << jspr_bulan_sa << "/" << jspr_tahun_sa << ")" << endl;
                    cout << "      |                                                                              |\n";
                    cout << "      |    from                                                                      |\n";
                    cout << "      |  > " << asal << endl;
                    cout << "      |    to                                                                        |\n";
                    cout << "      |  > " << tujuan << endl;
                    cout << "      |_________ _____ __ _                                      _ __ _____ _________|\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |     please be at the boarding gate at least 30 minutes before derpature      |\n";
                    cout << "      |______________________________________________________________________________|\n";

                }


                for (int i_dewasa_bisnis = 1; i_dewasa_bisnis <= jskls_dewasa_bisnis; i_dewasa_bisnis++)
                {
                    cout << "       ______________________________________________________________________________ \n";
                    cout << "      |BUSINESS CLASS   ||   BOARDING PASS                             GARUDA INDO   |   Tiket Dewasa(Bisnis) Ke : " << i_dewasa_bisnis << endl;
                    cout << "      |-----------------------------------                                           |\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |  Name > " <<nama_dewasa_bisnis[i_dewasa_bisnis] << endl;
                    cout << "      |  Date > (" << jspr_tanggal_sa << "/" << jspr_bulan_sa << "/" << jspr_tahun_sa << ")" << endl;
                    cout << "      |                                                                              |\n";
                    cout << "      |    from                                                                      |\n";
                    cout << "      |  > " << asal << endl;
                    cout << "      |    to                                                                        |\n";
                    cout << "      |  > " << tujuan << endl;
                    cout << "      |_________ _____ __ _                                      _ __ _____ _________|\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |     please be at the boarding gate at least 30 minutes before derpature      |\n";
                    cout << "      |______________________________________________________________________________|\n";

                }


                for (int i_dewasa_utama = 1; i_dewasa_utama <= jskls_dewasa_utama; i_dewasa_utama++)
                {
                    cout << "       ______________________________________________________________________________ \n";
                    cout << "      |MAIN CLASS   ||   BOARDING PASS                                 GARUDA INDO   |   Tiket Dewasa(Utama) Ke : " << i_dewasa_utama << endl;
                    cout << "      |-------------------------------                                               |\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |  Name > " <<nama_dewasa_utama[i_dewasa_utama] << endl;
                    cout << "      |  Date > (" << jspr_tanggal_sa << "/" << jspr_bulan_sa << "/" << jspr_tahun_sa << ")" << endl;
                    cout << "      |                                                                              |\n";
                    cout << "      |    from                                                                      |\n";
                    cout << "      |  > " << asal << endl;
                    cout << "      |    to                                                                        |\n";
                    cout << "      |  > " << tujuan << endl;
                    cout << "      |_________ _____ __ _                                      _ __ _____ _________|\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |     please be at the boarding gate at least 30 minutes before derpature      |\n";
                    cout << "      |______________________________________________________________________________|\n";

                }
            }

            // kondisi buat misal nga pesan tiket anak, nnti engak muncul tombal enter di bawah // sama biar enternya berfungsi 
            if (semua_jml_anak == 0) // klo cuman pesan tiket dewasa doang nnt nga bakal muncul cout [enter] 
            {
                cout << endl << endl;
                goto selesai;

            }
            else
            {
                goto jeda_enter_mBanking;
            }

        jeda_enter_mBanking:
            cin.ignore();
            cout << "\n\n_____________________________________________________________________________________________ [enter]";
            cin.get();
            cout << "\n\n";

        print_anak_m_banking:

            // tiket m_banking Anak

// ini print tiket klo kita pilih jenis perjalanannya pulang - pergi 
            if (jspr == "1" || jspr == "PULANG - PERGI" || jspr == "Pulang - Pergi" || jspr == "pulang - pergi" || jspr == "PULANG PERGI" || jspr == "Pulang Pergi" || jspr == "pulang pergi" || jspr == "PP" || jspr == "pp" || jspr == "PULPER" || jspr == "PulPer" || jspr == "pulper")
            {
                for (int i_anak_ekonomi = 1; i_anak_ekonomi <= jskls_anak_ekonomi; i_anak_ekonomi++) // tiket ekonomi
                {
                    cout << "       ______________________________________________________________________________ \n";
                    cout << "      |ECONOMY CLASS   ||   BOARDING PASS                              GARUDA INDO   |   Tiket Anak(Ekonomi) Ke : " << i_anak_ekonomi << endl;
                    cout << "      |----------------------------------                                            |\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |  Name > " <<nama_anak_ekonomi[i_anak_ekonomi] << endl;
                    cout << "      |  Date > (" << jspr_tanggal_b << "/" << jspr_bulan_b << "/" << jspr_tahun_b << ") to (" << jspr_tanggal_p << "/" << jspr_bulan_p << "/" << jspr_tahun_p << ")" << endl;
                    cout << "      |                                                                              |\n";
                    cout << "      |    from                                                                      |\n";
                    cout << "      |  > " << asal << endl;
                    cout << "      |    to                                                                        |\n";
                    cout << "      |  > " << tujuan << endl;
                    cout << "      |_________ _____ __ _                                      _ __ _____ _________|\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |     please be at the boarding gate at least 30 minutes before derpature      |\n";
                    cout << "      |______________________________________________________________________________|\n";

                }


                for (int i_anak_bisnis = 1; i_anak_bisnis <= jskls_anak_bisnis; i_anak_bisnis++)  // tiket bisnis  
                {
                    cout << "       ______________________________________________________________________________ \n";
                    cout << "      |BUSINESS CLASS   ||   BOARDING PASS                             GARUDA INDO   |   Tiket Anak(Bisnis) Ke : " << i_anak_bisnis << endl;
                    cout << "      |-----------------------------------                                           |\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |  Name > " <<nama_anak_bisnis[i_anak_bisnis] << endl;
                    cout << "      |  Date > (" << jspr_tanggal_b << "/" << jspr_bulan_b << "/" << jspr_tahun_b << ") to (" << jspr_tanggal_p << "/" << jspr_bulan_p << "/" << jspr_tahun_p << ")" << endl;
                    cout << "      |                                                                              |\n";
                    cout << "      |    from                                                                      |\n";
                    cout << "      |  > " << asal << endl;
                    cout << "      |    to                                                                        |\n";
                    cout << "      |  > " << tujuan << endl;
                    cout << "      |_________ _____ __ _                                      _ __ _____ _________|\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |     please be at the boarding gate at least 30 minutes before derpature      |\n";
                    cout << "      |______________________________________________________________________________|\n";

                }


                for (int i_anak_utama = 1; i_anak_utama <= jskls_anak_utama; i_anak_utama++)   // tiket utama
                {
                    cout << "       ______________________________________________________________________________ \n";
                    cout << "      |MAIN CLASS   ||   BOARDING PASS                                 GARUDA INDO   |   Tiket Anak(Utama) Ke : " << i_anak_utama << endl;
                    cout << "      |-------------------------------                                               |\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |  Name > " <<nama_anak_utama[i_anak_utama] << endl;
                    cout << "      |  Date > (" << jspr_tanggal_b << "/" << jspr_bulan_b << "/" << jspr_tahun_b << ") to (" << jspr_tanggal_p << "/" << jspr_bulan_p << "/" << jspr_tahun_p << ")" << endl;
                    cout << "      |                                                                              |\n";
                    cout << "      |    from                                                                      |\n";
                    cout << "      |  > " << asal << endl;
                    cout << "      |    to                                                                        |\n";
                    cout << "      |  > " << tujuan << endl;
                    cout << "      |_________ _____ __ _                                      _ __ _____ _________|\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |     please be at the boarding gate at least 30 minutes before derpature      |\n";
                    cout << "      |______________________________________________________________________________|\n";

                }




                // ini print tiket klo kita pilih jenis perjalanannya satu arah 
            }
            else if (jspr == "2" || jspr == "SATU ARAH" || jspr == "Satu Arah" || jspr == "satu arah" || jspr == "SA" || jspr == "Sa" || jspr == "sa")
            {
                for (int i_anak_ekonomi = 1; i_anak_ekonomi <= jskls_anak_ekonomi; i_anak_ekonomi++)    // tiket ekonomi
                {
                    cout << "       ______________________________________________________________________________ \n";
                    cout << "      |ECONOMY CLASS   ||   BOARDING PASS                              GARUDA INDO   |   Tiket Anak(Ekonomi) Ke : " << i_anak_ekonomi << endl;
                    cout << "      |----------------------------------                                            |\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |  Name > " <<nama_anak_ekonomi[i_anak_ekonomi] << endl;
                    cout << "      |  Date > (" << jspr_tanggal_sa << "/" << jspr_bulan_sa << "/" << jspr_tahun_sa << ")" << endl;
                    cout << "      |                                                                              |\n";
                    cout << "      |    from                                                                      |\n";
                    cout << "      |  > " << asal << endl;
                    cout << "      |    to                                                                        |\n";
                    cout << "      |  > " << tujuan << endl;
                    cout << "      |_________ _____ __ _                                      _ __ _____ _________|\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |     please be at the boarding gate at least 30 minutes before derpature      |\n";
                    cout << "      |______________________________________________________________________________|\n";

                }


                for (int i_anak_bisnis = 1; i_anak_bisnis <= jskls_anak_bisnis; i_anak_bisnis++)
                {
                    cout << "       ______________________________________________________________________________ \n";
                    cout << "      |BUSINESS CLASS   ||   BOARDING PASS                             GARUDA INDO   |   Tiket Anak(Bisnis) Ke : " << i_anak_bisnis << endl;
                    cout << "      |-----------------------------------                                           |\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |  Name > " <<nama_anak_bisnis[i_anak_bisnis] << endl;
                    cout << "      |  Date > (" << jspr_tanggal_sa << "/" << jspr_bulan_sa << "/" << jspr_tahun_sa << ")" << endl;
                    cout << "      |                                                                              |\n";
                    cout << "      |    from                                                                      |\n";
                    cout << "      |  > " << asal << endl;
                    cout << "      |    to                                                                        |\n";
                    cout << "      |  > " << tujuan << endl;
                    cout << "      |_________ _____ __ _                                      _ __ _____ _________|\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |     please be at the boarding gate at least 30 minutes before derpature      |\n";
                    cout << "      |______________________________________________________________________________|\n";

                }


                for (int i_anak_utama = 1; i_anak_utama <= jskls_anak_utama; i_anak_utama++)
                {
                    cout << "       ______________________________________________________________________________ \n";
                    cout << "      |MAIN CLASS   ||   BOARDING PASS                                 GARUDA INDO   |   Tiket Anak(Utama) Ke : " << i_anak_utama << endl;
                    cout << "      |-------------------------------                                               |\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |  Name > " <<nama_anak_utama[i_anak_utama] << endl;
                    cout << "      |  Date > (" << jspr_tanggal_sa << "/" << jspr_bulan_sa << "/" << jspr_tahun_sa << ")" << endl;
                    cout << "      |                                                                              |\n";
                    cout << "      |    from                                                                      |\n";
                    cout << "      |  > " << asal << endl;
                    cout << "      |    to                                                                        |\n";
                    cout << "      |  > " << tujuan << endl;
                    cout << "      |_________ _____ __ _                                      _ __ _____ _________|\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |     please be at the boarding gate at least 30 minutes before derpature      |\n";
                    cout << "      |______________________________________________________________________________|\n";

                }
            }

            cout << endl << endl;
            goto selesai;


        }
        else if (met_pembayaran == 2)                                                     // ini tiket pulang pergi versi mitra agen
        {
            cout << endl;
            cout << "      Hasil: ";
            cout << "\n      > ini tiket Mitra Agen_ \n";

            if (semua_jml_dewasa == 0)
            {
                goto print_anak_mitra_agen;
            }

            // tiket Mitra Agen Dewasa

// ini print tiket klo kita pilih jenis perjalanannya pulang - pergi 
            if (jspr == "1" || jspr == "PULANG - PERGI" || jspr == "Pulang - Pergi" || jspr == "pulang - pergi" || jspr == "PULANG PERGI" || jspr == "Pulang Pergi" || jspr == "pulang pergi" || jspr == "PP" || jspr == "pp" || jspr == "PULPER" || jspr == "PulPer" || jspr == "pulper")
            {
                for (int i_dewasa_ekonomi = 1; i_dewasa_ekonomi <= jskls_dewasa_ekonomi; i_dewasa_ekonomi++) // tiket ekonomi
                {
                    cout << "       ______________________________________________________________________________ \n";
                    cout << "      |ECONOMY CLASS   ||   BOARDING PASS                             GARUDA INDO    |   Tiket Dewasa(Ekonomi) Ke : " << i_dewasa_ekonomi << endl;
                    cout << "      |----------------------------------                                            |\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |  Name > " <<nama_dewasa_ekonomi[i_dewasa_ekonomi] << endl;
                    cout << "      |  Date > (" << jspr_tanggal_b << "/" << jspr_bulan_b << "/" << jspr_tahun_b << ") to (" << jspr_tanggal_p << "/" << jspr_bulan_p << "/" << jspr_tahun_p << ")" << endl;
                    cout << "      |                                                                              |\n";
                    cout << "      |    from                                                                      |\n";
                    cout << "      |  > " << asal << endl;
                    cout << "      |    to                                                                        |\n";
                    cout << "      |  > " << tujuan << endl;
                    cout << "      |_________ _____ __ _                                      _ __ _____ _________|\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |     please be at the boarding gate at least 30 minutes before derpature      |\n";
                    cout << "      |______________________________________________________________________________|\n";

                }


                for (int i_dewasa_bisnis = 1; i_dewasa_bisnis <= jskls_dewasa_bisnis; i_dewasa_bisnis++)  // tiket bisnis  
                {
                    cout << "       ______________________________________________________________________________ \n";
                    cout << "      |BUSINESS CLASS   ||   BOARDING PASS                            GARUDA INDO    |   Tiket Dewasa(Bisnis) Ke : " << i_dewasa_bisnis << endl;
                    cout << "      |-----------------------------------                                           |\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |  Name > " <<nama_dewasa_bisnis[i_dewasa_bisnis] << endl;
                    cout << "      |  Date > (" << jspr_tanggal_b << "/" << jspr_bulan_b << "/" << jspr_tahun_b << ") to (" << jspr_tanggal_p << "/" << jspr_bulan_p << "/" << jspr_tahun_p << ")" << endl;
                    cout << "      |                                                                              |\n";
                    cout << "      |    from                                                                      |\n";
                    cout << "      |  > " << asal << endl;
                    cout << "      |    to                                                                        |\n";
                    cout << "      |  > " << tujuan << endl;
                    cout << "      |_________ _____ __ _                                      _ __ _____ _________|\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |     please be at the boarding gate at least 30 minutes before derpature      |\n";
                    cout << "      |______________________________________________________________________________|\n";

                }


                for (int i_dewasa_utama = 1; i_dewasa_utama <= jskls_dewasa_utama; i_dewasa_utama++)   // tiket utama
                {
                    cout << "       ______________________________________________________________________________ \n";
                    cout << "      |MAIN CLASS   ||   BOARDING PASS                                GARUDA INDO    |   Tiket Dewasa(Utama) Ke : " << i_dewasa_utama << endl;
                    cout << "      |-------------------------------                                               |\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |  Name > " <<nama_dewasa_utama[i_dewasa_utama] << endl;
                    cout << "      |  Date > (" << jspr_tanggal_b << "/" << jspr_bulan_b << "/" << jspr_tahun_b << ") to (" << jspr_tanggal_p << "/" << jspr_bulan_p << "/" << jspr_tahun_p << ")" << endl;
                    cout << "      |                                                                              |\n";
                    cout << "      |    from                                                                      |\n";
                    cout << "      |  > " << asal << endl;
                    cout << "      |    to                                                                        |\n";
                    cout << "      |  > " << tujuan << endl;
                    cout << "      |_________ _____ __ _                                      _ __ _____ _________|\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |     please be at the boarding gate at least 30 minutes before derpature      |\n";
                    cout << "      |______________________________________________________________________________|\n";

                }




                // ini print tiket klo kita pilih jenis perjalanannya satu arah 
            }
            else if (jspr == "2" || jspr == "SATU ARAH" || jspr == "Satu Arah" || jspr == "satu arah" || jspr == "SA" || jspr == "Sa" || jspr == "sa")
            {
                for (int i_dewasa_ekonomi = 1; i_dewasa_ekonomi <= jskls_dewasa_ekonomi; i_dewasa_ekonomi++)    // tiket ekonomi
                {
                    cout << "       ______________________________________________________________________________ \n";
                    cout << "      |ECONOMY CLASS   ||   BOARDING PASS                              GARUDA INDO   |   Tiket Dewasa(Ekonomi) Ke : " << i_dewasa_ekonomi << endl;
                    cout << "      |----------------------------------                                            |\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |  Name > " <<nama_dewasa_ekonomi[i_dewasa_ekonomi] << endl;
                    cout << "      |  Date > (" << jspr_tanggal_sa << "/" << jspr_bulan_sa << "/" << jspr_tahun_sa << ")" << endl;
                    cout << "      |                                                                              |\n";
                    cout << "      |    from                                                                      |\n";
                    cout << "      |  > " << asal << endl;
                    cout << "      |    to                                                                        |\n";
                    cout << "      |  > " << tujuan << endl;
                    cout << "      |_________ _____ __ _                                      _ __ _____ _________|\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |     please be at the boarding gate at least 30 minutes before derpature      |\n";
                    cout << "      |______________________________________________________________________________|\n";

                }


                for (int i_dewasa_bisnis = 1; i_dewasa_bisnis <= jskls_dewasa_bisnis; i_dewasa_bisnis++)
                {
                    cout << "       ______________________________________________________________________________ \n";
                    cout << "      |BUSINESS CLASS   ||   BOARDING PASS                             GARUDA INDO   |   Tiket Dewasa(Bisnis) Ke : " << i_dewasa_bisnis << endl;
                    cout << "      |-----------------------------------                                           |\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |  Name > " <<nama_dewasa_bisnis[i_dewasa_bisnis] << endl;
                    cout << "      |  Date > (" << jspr_tanggal_sa << "/" << jspr_bulan_sa << "/" << jspr_tahun_sa << ")" << endl;
                    cout << "      |                                                                              |\n";
                    cout << "      |    from                                                                      |\n";
                    cout << "      |  > " << asal << endl;
                    cout << "      |    to                                                                        |\n";
                    cout << "      |  > " << tujuan << endl;
                    cout << "      |_________ _____ __ _                                      _ __ _____ _________|\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |     please be at the boarding gate at least 30 minutes before derpature      |\n";
                    cout << "      |______________________________________________________________________________|\n";

                }


                for (int i_dewasa_utama = 1; i_dewasa_utama <= jskls_dewasa_utama; i_dewasa_utama++)
                {
                    cout << "       ______________________________________________________________________________ \n";
                    cout << "      |MAIN CLASS   ||   BOARDING PASS                                 GARUDA INDO   |   Tiket Dewasa(Utama) Ke : " << i_dewasa_utama << endl;
                    cout << "      |-------------------------------                                               |\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |  Name > " <<nama_dewasa_utama[i_dewasa_utama] << endl;
                    cout << "      |  Date > (" << jspr_tanggal_sa << "/" << jspr_bulan_sa << "/" << jspr_tahun_sa << ")" << endl;
                    cout << "      |                                                                              |\n";
                    cout << "      |    from                                                                      |\n";
                    cout << "      |  > " << asal << endl;
                    cout << "      |    to                                                                        |\n";
                    cout << "      |  > " << tujuan << endl;
                    cout << "      |_________ _____ __ _                                      _ __ _____ _________|\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |     please be at the boarding gate at least 30 minutes before derpature      |\n";
                    cout << "      |______________________________________________________________________________|\n";

                }
            }

            // kondisi buat misal nga pesan tiket anak, nnti engak muncul tombal enter di bawah // sama biar enternya berfungsi 
            if (semua_jml_anak == 0) // klo cuman pesan tiket dewasa doang nnt nga bakal muncul cout [enter] 
            {
                cout << endl << endl;
                goto selesai;

            }
            else
            {
                goto jeda_enter_mitraAgen;
            }

        jeda_enter_mitraAgen:
            cin.ignore();
            cout << "\n\n_____________________________________________________________________________________________ [enter]";
            cin.get();
            cout << "\n\n";

        print_anak_mitra_agen:

            // tiket Mitra Agen Anak

// ini print tiket klo kita pilih jenis perjalanannya pulang - pergi 
            if (jspr == "1" || jspr == "PULANG - PERGI" || jspr == "Pulang - Pergi" || jspr == "pulang - pergi" || jspr == "PULANG PERGI" || jspr == "Pulang Pergi" || jspr == "pulang pergi" || jspr == "PP" || jspr == "pp" || jspr == "PULPER" || jspr == "PulPer" || jspr == "pulper")
            {
                for (int i_anak_ekonomi = 1; i_anak_ekonomi <= jskls_anak_ekonomi; i_anak_ekonomi++) // tiket ekonomi
                {
                    cout << "       ______________________________________________________________________________ \n";
                    cout << "      |ECONOMY CLASS   ||   BOARDING PASS                              GARUDA INDO   |   Tiket Anak(Ekonomi) Ke : " << i_anak_ekonomi << endl;
                    cout << "      |----------------------------------                                            |\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |  Name > " <<nama_anak_ekonomi[i_anak_ekonomi] << endl;
                    cout << "      |  Date > (" << jspr_tanggal_b << "/" << jspr_bulan_b << "/" << jspr_tahun_b << ") to (" << jspr_tanggal_p << "/" << jspr_bulan_p << "/" << jspr_tahun_p << ")" << endl;
                    cout << "      |                                                                              |\n";
                    cout << "      |    from                                                                      |\n";
                    cout << "      |  > " << asal << endl;
                    cout << "      |    to                                                                        |\n";
                    cout << "      |  > " << tujuan << endl;
                    cout << "      |_________ _____ __ _                                      _ __ _____ _________|\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |     please be at the boarding gate at least 30 minutes before derpature      |\n";
                    cout << "      |______________________________________________________________________________|\n";

                }


                for (int i_anak_bisnis = 1; i_anak_bisnis <= jskls_anak_bisnis; i_anak_bisnis++)  // tiket bisnis  
                {
                    cout << "       ______________________________________________________________________________ \n";
                    cout << "      |BUSINESS CLASS   ||   BOARDING PASS                             GARUDA INDO   |   Tiket Anak(Bisnis) Ke : " << i_anak_bisnis << endl;
                    cout << "      |-----------------------------------                                           |\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |  Name > " <<nama_anak_bisnis[i_anak_bisnis] << endl;
                    cout << "      |  Date > (" << jspr_tanggal_b << "/" << jspr_bulan_b << "/" << jspr_tahun_b << ") to (" << jspr_tanggal_p << "/" << jspr_bulan_p << "/" << jspr_tahun_p << ")" << endl;
                    cout << "      |                                                                              |\n";
                    cout << "      |    from                                                                      |\n";
                    cout << "      |  > " << asal << endl;
                    cout << "      |    to                                                                        |\n";
                    cout << "      |  > " << tujuan << endl;
                    cout << "      |_________ _____ __ _                                      _ __ _____ _________|\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |     please be at the boarding gate at least 30 minutes before derpature      |\n";
                    cout << "      |______________________________________________________________________________|\n";

                }


                for (int i_anak_utama = 1; i_anak_utama <= jskls_anak_utama; i_anak_utama++)   // tiket utama
                {
                    cout << "       ______________________________________________________________________________ \n";
                    cout << "      |MAIN CLASS   ||   BOARDING PASS                                 GARUDA INDO   |   Tiket Anak(Utama) Ke : " << i_anak_utama << endl;
                    cout << "      |-------------------------------                                               |\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |  Name > " <<nama_anak_utama[i_anak_utama] << endl;
                    cout << "      |  Date > (" << jspr_tanggal_b << "/" << jspr_bulan_b << "/" << jspr_tahun_b << ") to (" << jspr_tanggal_p << "/" << jspr_bulan_p << "/" << jspr_tahun_p << ")" << endl;
                    cout << "      |                                                                              |\n";
                    cout << "      |    from                                                                      |\n";
                    cout << "      |  > " << asal << endl;
                    cout << "      |    to                                                                        |\n";
                    cout << "      |  > " << tujuan << endl;
                    cout << "      |_________ _____ __ _                                      _ __ _____ _________|\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |     please be at the boarding gate at least 30 minutes before derpature      |\n";
                    cout << "      |______________________________________________________________________________|\n";

                }




                // ini print tiket klo kita pilih jenis perjalanannya satu arah 
            }
            else if (jspr == "2" || jspr == "SATU ARAH" || jspr == "Satu Arah" || jspr == "satu arah" || jspr == "SA" || jspr == "Sa" || jspr == "sa")
            {
                for (int i_anak_ekonomi = 1; i_anak_ekonomi <= jskls_anak_ekonomi; i_anak_ekonomi++)    // tiket ekonomi
                {
                    cout << "       ______________________________________________________________________________ \n";
                    cout << "      |ECONOMY CLASS   ||   BOARDING PASS                              GARUDA INDO   |   Tiket Anak(Ekonomi) Ke : " << i_anak_ekonomi << endl;
                    cout << "      |----------------------------------                                            |\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |  Name > " <<nama_anak_ekonomi[i_anak_ekonomi] << endl;
                    cout << "      |  Date > (" << jspr_tanggal_sa << "/" << jspr_bulan_sa << "/" << jspr_tahun_sa << ")" << endl;
                    cout << "      |                                                                              |\n";
                    cout << "      |    from                                                                      |\n";
                    cout << "      |  > " << asal << endl;
                    cout << "      |    to                                                                        |\n";
                    cout << "      |  > " << tujuan << endl;
                    cout << "      |_________ _____ __ _                                      _ __ _____ _________|\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |     please be at the boarding gate at least 30 minutes before derpature      |\n";
                    cout << "      |______________________________________________________________________________|\n";

                }


                for (int i_anak_bisnis = 1; i_anak_bisnis <= jskls_anak_bisnis; i_anak_bisnis++)
                {
                    cout << "       ______________________________________________________________________________ \n";
                    cout << "      |BUSINESS CLASS   ||   BOARDING PASS                             GARUDA INDO   |   Tiket Anak(Bisnis) Ke : " << i_anak_bisnis << endl;
                    cout << "      |-----------------------------------                                           |\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |  Name > " <<nama_anak_bisnis[i_anak_bisnis] << endl;
                    cout << "      |  Date > (" << jspr_tanggal_sa << "/" << jspr_bulan_sa << "/" << jspr_tahun_sa << ")" << endl;
                    cout << "      |                                                                              |\n";
                    cout << "      |    from                                                                      |\n";
                    cout << "      |  > " << asal << endl;
                    cout << "      |    to                                                                        |\n";
                    cout << "      |  > " << tujuan << endl;
                    cout << "      |_________ _____ __ _                                      _ __ _____ _________|\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |     please be at the boarding gate at least 30 minutes before derpature      |\n";
                    cout << "      |______________________________________________________________________________|\n";

                }


                for (int i_anak_bisnis = 1; i_anak_bisnis <= jskls_anak_utama; i_anak_bisnis++)
                {
                    cout << "       ______________________________________________________________________________ \n";
                    cout << "      |MAIN CLASS   ||   BOARDING PASS                                 GARUDA INDO   |   Tiket Anak(Utama) Ke : " << i_anak_bisnis << endl;
                    cout << "      |-------------------------------                                               |\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |  Name > " <<nama_anak_utama[i_anak_bisnis] << endl;
                    cout << "      |  Date > (" << jspr_tanggal_sa << "/" << jspr_bulan_sa << "/" << jspr_tahun_sa << ")" << endl;
                    cout << "      |                                                                              |\n";
                    cout << "      |    from                                                                      |\n";
                    cout << "      |  > " << asal << endl;
                    cout << "      |    to                                                                        |\n";
                    cout << "      |  > " << tujuan << endl;
                    cout << "      |_________ _____ __ _                                      _ __ _____ _________|\n";
                    cout << "      |                                                                              |\n";
                    cout << "      |     please be at the boarding gate at least 30 minutes before derpature      |\n";
                    cout << "      |______________________________________________________________________________|\n";

                }
            }

            cout << endl << endl;
            goto selesai;

        }

    }
    else if (print_tiket == "2" || print_tiket == "TIDAK" || print_tiket == "Tidak" || print_tiket == "tidak" || print_tiket == "TDK" || print_tiket == "Tdk" || print_tiket == "tdk" || print_tiket == "T" || print_tiket == "t")
    {
        // string pilihan_print_kembali_keluar;   
    kembali_atau_keluar_print:
        cout << endl;
        cout << "      Mengulang, Kembali atau Keluar/selesai? : \n";
        cout << "        (1) Mengulang ke-Awal\n";
        cout << "        (2) Kembali\n";
        cout << "        (3) Keluar\n";
        cout << "            Memilih : ";
        cin >> pilihan_print_kembali_keluar;

        if (pilihan_print_kembali_keluar=="1"||pilihan_print_kembali_keluar=="MENGULANG"||pilihan_print_kembali_keluar=="Mengulang"||pilihan_print_kembali_keluar=="mengulang"|| pilihan_print_kembali_keluar=="Ulang"||pilihan_print_kembali_keluar=="ulang"||pilihan_print_kembali_keluar=="AWAl"||pilihan_print_kembali_keluar=="Awal"||pilihan_print_kembali_keluar =="awal")  // mengulang
        {
            system("cls");
            cin.ignore();

            goto main_menu;

        }
        else if (pilihan_print_kembali_keluar=="2"||pilihan_print_kembali_keluar=="KEMBALI"||pilihan_print_kembali_keluar=="Kembali"||pilihan_print_kembali_keluar=="kembali")   // kembali
        {
            cout << "_____________________________________\n";
            cin.ignore();
            goto menu_pembuatan_tiket;

        }
        else if (pilihan_print_kembali_keluar=="3"||pilihan_print_kembali_keluar=="KELUAR"||pilihan_print_kembali_keluar=="Keluar"||pilihan_print_kembali_keluar=="keluar")   // keluar
        {
            cin.ignore();
            cout << endl << endl;

            return 0;
        }
        else
        {
            cin.ignore();
            cout << "\n            Silahkan pilih (1) atau (2), [enter] untuk melanjutkan";
            cin.get();

            goto kembali_atau_keluar_print;
        }

    }
    else if (print_tiket == "3" || print_tiket == "KEMBALI" || print_tiket == "Kembali" || print_tiket == "kembali")
    {
        cout << "________________________________________________\n";
        goto metode_pembayaran_menu;
    }
    else
    {
        cout << "         Silahkan pilih (1) (2) / (3), [enter ]untuk melanjutkan\n\n";
        cin.get();

        goto menu_pembuatan_tiket;
    }

selesai:
    return 0;
}
