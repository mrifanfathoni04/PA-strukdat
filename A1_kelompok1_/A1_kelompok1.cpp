#include <iostream>
#include <conio.h> //menggunakan fungsi getche()
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;
// struct untuk menyimpan data warga
struct node
{
    string NIK;
    string nama_lengkap;
    string jenis_kelamin;
    string nama_ayah;
    string nama_ibu;
    string password;
    node *next;
};

// fungsi untuk mengembalikan nilai banyak node dari linked-list (banyak data)
int jumlah_data(node *temp)
{
    int jumlah = 0;
    while (temp != NULL)
    {
        jumlah++;
        temp = temp->next;
    }
    return jumlah;
}
//prosedur untuk menambahkan data warga dari file csv ke dalam linked list
void add_data(node **head, node temp_node)
{
    node *nodeBaru = new node;
    nodeBaru->NIK = temp_node.NIK;
    nodeBaru->nama_lengkap = temp_node.nama_lengkap;
    nodeBaru->jenis_kelamin = temp_node.jenis_kelamin;
    nodeBaru->nama_ayah = temp_node.nama_ayah;
    nodeBaru->nama_ibu = temp_node.nama_ibu;
    nodeBaru->password = temp_node.password;
    // proses menambahkan node pada linked list
    nodeBaru->next = NULL;
    // jika linked list kosong
    if (*head == NULL)
    {
        *head = nodeBaru;
        return;
    }
    // jika tidak traversal ke node terakhir
    node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = nodeBaru;
}
//prosedur untuk membaca data warga dari file csv
void read_file_warga(node **head)
{
    string data, data_sementara;
    ifstream file_warga;
    node temp_node;
    int count = 0;
    file_warga.open("file_warga.csv", ios::in);
    if (file_warga.is_open())
    {
        while (getline(file_warga, data))
        {
            count++;
            stringstream temp(data);
            getline(temp, data_sementara, ',');
            temp_node.NIK = data_sementara;
            getline(temp, data_sementara, ',');
            temp_node.nama_lengkap = data_sementara;
            getline(temp, data_sementara, ',');
            temp_node.jenis_kelamin = data_sementara;
            getline(temp, data_sementara, ',');
            temp_node.nama_ayah = data_sementara;
            getline(temp, data_sementara, ',');
            temp_node.nama_ibu = data_sementara;
            getline(temp, data_sementara, '\n');
            temp_node.password = data_sementara;
            add_data(head, temp_node);
        }
    }
    file_warga.close();
}
//prosedur untuk mengedit data warga dari file csv
void update_file_warga(node **head)
{
    node *temp = *head;
    ofstream file_warga;
    file_warga.open("file_warga.csv", ios::out | ios::trunc);

    if (*head != NULL)
    {
        int jumlah = jumlah_data(*head);
        for (int i = 0; i < jumlah; i++)
        {
            file_warga << temp->NIK << ",";
            file_warga << temp->nama_lengkap << ",";
            file_warga << temp->jenis_kelamin << ",";
            file_warga << temp->nama_ayah << ",";
            file_warga << temp->nama_ibu << ",";
            file_warga << temp->password << "\n";
            temp = temp->next;
        }
    }
    file_warga.close();
}
//prosedur untuk membaca data histori login dari file csv
void read_file_histori(node **head)
{
    string data, data_sementara;
    ifstream file_histori;
    node temp_node;
    int count = 0;
    file_histori.open("file_histori.csv", ios::in);
    if (file_histori.is_open())
    {
        while (getline(file_histori, data))
        {
            count++;
            stringstream temp(data);
            getline(temp, data_sementara, ',');
            temp_node.NIK = data_sementara;
            getline(temp, data_sementara, ',');
            temp_node.nama_lengkap = data_sementara;
            getline(temp, data_sementara, ',');
            temp_node.jenis_kelamin = data_sementara;
            getline(temp, data_sementara, ',');
            temp_node.nama_ayah = data_sementara;
            getline(temp, data_sementara, ',');
            temp_node.nama_ibu = data_sementara;
            getline(temp, data_sementara, '\n');
            temp_node.password = data_sementara;
            add_data(head, temp_node);
        }
    }
    file_histori.close();
}
//prosedur untuk mengedit data histori login dari file csv
void update_file_histori(node **head)
{
    node *temp = *head;
    ofstream file_histori;
    file_histori.open("file_histori.csv", ios::out | ios::trunc);

    if (*head != NULL)
    {
        int jumlah = jumlah_data(*head);
        for (int i = 0; i < jumlah; i++)
        {
            file_histori << temp->NIK << ",";
            file_histori << temp->nama_lengkap << ",";
            file_histori << temp->jenis_kelamin << ",";
            file_histori << temp->nama_ayah << ",";
            file_histori << temp->nama_ibu << ",";
            file_histori << temp->password << "\n";
            temp = temp->next;
        }
    }
    file_histori.close();
}

// fungsi untuk mengecek apakah semua nilai pada sebuah string merupakan angka
bool cek_int(string str)
{
    for (int x = 0; x < str.length(); x++)
    {
        if (isdigit(str[x]) == false)
        {
            return false;
        }
    }
    return true;
};
// fungsi untuk mengecek apakah ada angka pada sebuah string
bool cek_str(string str)
{
    for (int x = 0; x < str.length(); x++)
    {
        if (isdigit(str[x]) == true)
        {
            return true;
        }
    }
    return false;
};
// prosedur untuk menampilkan data warga pada linked list
void tampilkan_data(node *head, int jumlah)
{
    if (head == NULL)
    {
        system("CLS");
        cout << "\n";
        cout << "+==================================================================+\n";
        cout << "|                               \033[1;32mDATA\033[0m                               |\n";
        cout << "+==================================================================+\n";
        cout << "|                          TIDAK ADA DATA                          |\n";
        cout << "+==================================================================+\n";
    }
    else
    {
        system("CLS");
        cout << "\n";
        cout << "+==================================================================+\n";
        cout << "|                               \033[1;32mDATA\033[0m                               |\n";
        cout << "+==================================================================+\n";
        for (int i = 0; i < jumlah; i++)
        {
            cout << "|                               \033[1;33m[" << i + 1 << "]\033[0m                                |" << endl;
            cout << "+==================================================================+\n";
            cout << "|NIK            : " << head->NIK << setw(50 - head->NIK.length()) << "|" << endl;
            cout << "|Nama Lengkap   : " << head->nama_lengkap << setw(50 - (head->nama_lengkap).length()) << "|" << endl;
            cout << "|Jenis Kelamin  : " << head->jenis_kelamin << setw(50 - (head->jenis_kelamin).length()) << "|" << endl;
            cout << "|Nama Ayah      : " << head->nama_ayah << setw(50 - (head->nama_ayah).length()) << "|" << endl;
            cout << "|Nama Ibu       : " << head->nama_ibu << setw(50 - (head->nama_ibu).length()) << "|" << endl;
            cout << "|Password       : " << head->password << setw(50 - (head->password).length()) << "|" << endl;
            cout << "+==================================================================+\n";
            head = head->next;
        }
    }
}
// prosedur untuk menampilkan data histori login pada linked list
void tampilkan_histori(node *head_histori, int jumlah)
{
    if (head_histori == NULL)
    {
        system("CLS");
        cout << "\n";
        cout << "+==================================================================+\n";
        cout << "|                          \033[1;32mHISTORI LOGIN\033[0m                           |\n";
        cout << "+==================================================================+\n";
        cout << "|                          TIDAK ADA DATA                          |\n";
        cout << "+==================================================================+\n";
    }
    else
    {
        system("CLS");
        cout << "\n";
        cout << "+==================================================================+\n";
        cout << "|                               \033[1;32mDATA\033[0m                               |\n";
        cout << "+==================================================================+\n";
        for (int i = 0; i < jumlah; i++)
        {
            cout << "|                               \033[1;33m[" << i + 1 << "]\033[0m                                |" << endl;
            cout << "+==================================================================+\n";
            cout << "|Nama Lengkap   : " << head_histori->nama_lengkap << setw(50 - (head_histori->nama_lengkap).length()) << "|" << endl;
            cout << "+==================================================================+\n";
            head_histori = head_histori->next;
        }
    }
}

// fungsi untuk menambahkan NIK pada node
int tambah_NIK(node *nodeBaru, node *head)
{
    nodeBaru->NIK = "";
    node *temp;
    bool terpakai;
    while (true)
    {
        string input;
        system("cls");
        cout << "+==================================================================+\n";
        cout << "|                            \033[1;32mTAMBAH DATA\033[0m                           |\n";
        cout << "+==================================================================+\n";
        cout << "|                 [0] KEMBALI KE MENU SEBELUMNYA                   |\n";
        cout << "+==================================================================+\n";
        cout << "|NIK            : " << setw(50) << "|" << endl;
        cout << "|Nama Lengkap   : " << setw(50) << "|" << endl;
        cout << "|Jenis Kelamin  : " << setw(50) << "|" << endl;
        cout << "|Nama Ayah      : " << setw(50) << "|" << endl;
        cout << "|Nama Ibu       : " << setw(50) << "|" << endl;
        cout << "+==================================================================+\n";
        cout << "Masukkan NIK : ";
        fflush(stdin);
        getline(cin, input);
        // kembali ke menu sebelumnya
        if (input == "0")
        {
            return 0;
        }
        // error handling apabila input kosong
        if (input.length() == 0)
        {
            cout << "+==================================================================+\n";
            cout << "|                     \033[1;31mINPUT TIDAK BOLEH KOSONG\033[0m                     |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }
        if (input.length() != 16)
        {
            cout << "+==================================================================+\n";
            cout << "|                       \033[1;31mINPUT HARUS 16 ANGKA\033[0m                       |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }
        // error handling apabila ada diinputkan selain angka
        if (cek_int(input) == false)
        {
            cout << "+==================================================================+\n";
            cout << "|                     \033[1;31mINPUT HARUS BERUPA ANGKA\033[0m                     |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }
        // mengecek apakah NIK sudah digunakan
        temp = head;
        while (temp != NULL)
        {
            if (temp->NIK == input)
            {
                terpakai = true;
                break;
            }
            temp = temp->next;
        }
        if (terpakai)
        {
            terpakai = false;
            cout << "+==================================================================+\n";
            cout << "|                         \033[1;31mNIK SUDAH TERDATA\033[0m                        |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }
        // menambahkan NIK ke dalam node
        nodeBaru->NIK = input;
        break;
    }
}
// fungsi untuk menambahkan nama_lengkap pada node
int tambah_nama_lengkap(node *nodeBaru)
{
    string input;
    while (true)
    {
        system("cls");
        cout << "+==================================================================+\n";
        cout << "|                            \033[1;32mTAMBAH DATA\033[0m                           |\n";
        cout << "+==================================================================+\n";
        cout << "|                 [0] KEMBALI KE MENU SEBELUMNYA                   |\n";
        cout << "+==================================================================+\n";
        cout << "|NIK            : " << nodeBaru->NIK << setw(50 - nodeBaru->NIK.length()) << "|" << endl;
        cout << "|Nama Lengkap   : " << setw(50) << "|" << endl;
        cout << "|Jenis Kelamin  : " << setw(50) << "|" << endl;
        cout << "|Nama Ayah      : " << setw(50) << "|" << endl;
        cout << "|Nama Ibu       : " << setw(50) << "|" << endl;
        cout << "+==================================================================+\n";
        cout << "Masukkan Nama Lengkap : ";
        fflush(stdin);
        getline(cin, input);
        // kembali ke menu sebelumnya
        if (input == "0")
        {
            return 0;
        }
        // error handling apabila input kosong
        if (input.length() == 0)
        {
            cout << "+==================================================================+\n";
            cout << "|                     \033[1;31mINPUT TIDAK BOLEH KOSONG\033[0m                     |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }
        // error handling apabila ada diinputkan angka
        if (cek_str(input) == true)
        {
            cout << "+==================================================================+\n";
            cout << "|                     \033[1;31mINPUT HARUS SELAIN ANGKA\033[0m                     |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }
        // menambahkan nama lenkgap ke dalam node
        nodeBaru->nama_lengkap = input;
        break;
    }
}
// fungsi untuk menambahkan jenis_kelamin pada node
int tambah_jenis_kelamin(node *nodeBaru)
{
    string input;
    while (true)
    {
        system("cls");
        cout << "+==================================================================+\n";
        cout << "|                            \033[1;32mTAMBAH DATA\033[0m                           |\n";
        cout << "+==================================================================+\n";
        cout << "|                 [0] KEMBALI KE MENU SEBELUMNYA                   |\n";
        cout << "+==================================================================+\n";
        cout << "|NIK            : " << nodeBaru->NIK << setw(50 - nodeBaru->NIK.length()) << "|" << endl;
        cout << "|Nama Lengkap   : " << nodeBaru->nama_lengkap << setw(50 - (nodeBaru->nama_lengkap).length()) << "|" << endl;
        cout << "|Jenis Kelamin  : " << setw(50) << "|" << endl;
        cout << "|Nama Ayah      : " << setw(50) << "|" << endl;
        cout << "|Nama Ibu       : " << setw(50) << "|" << endl;
        cout << "+==================================================================+\n";
        cout << "Masukkan Jenis Kelamin (L/P) : ";
        fflush(stdin);
        getline(cin, input);
        // kembali ke menu sebelumnya
        if (input == "0")
        {
            return 0;
        }
        // error handling apabila input kosong
        if (input.length() == 0)
        {
            cout << "+==================================================================+\n";
            cout << "|                     \033[1;31mINPUT TIDAK BOLEH KOSONG\033[0m                     |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }
        // error handling apabila input selain huruf l dan p
        if (input != "L" && input != "l" && input != "P" && input != "p")
        {
            cout << "+==================================================================+\n";
            cout << "|                        \033[1;31mFORMAT INPUT SALAH\033[0m                        |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }
        // mwmberi value jenis kelamin laki laki apabila diinputkan l dan perempuan apabila p
        if (input == "L" || input == "l")
        {
            nodeBaru->jenis_kelamin = "Laki - Laki";
        }
        else
        {
            nodeBaru->jenis_kelamin = "Perempuan";
        }
        break;
    }
}
// fungsi untuk menambahkan nama ayah pada node
int tambah_nama_ayah(node *nodeBaru)
{
    while (true)
    {
        string input;
        system("cls");
        cout << "+==================================================================+\n";
        cout << "|                            \033[1;32mTAMBAH DATA\033[0m                           |\n";
        cout << "+==================================================================+\n";
        cout << "|                 [0] KEMBALI KE MENU SEBELUMNYA                   |\n";
        cout << "+==================================================================+\n";
        cout << "|NIK            : " << nodeBaru->NIK << setw(50 - nodeBaru->NIK.length()) << "|" << endl;
        cout << "|Nama Lengkap   : " << nodeBaru->nama_lengkap << setw(50 - (nodeBaru->nama_lengkap).length()) << "|" << endl;
        cout << "|Jenis Kelamin  : " << nodeBaru->jenis_kelamin << setw(50 - (nodeBaru->jenis_kelamin).length()) << "|" << endl;
        cout << "|Nama Ayah      : " << setw(50) << "|" << endl;
        cout << "|Nama Ibu       : " << setw(50) << "|" << endl;
        cout << "+==================================================================+\n";
        cout << "Masukkan Nama Ayah : ";
        fflush(stdin);
        getline(cin, input);
        // kembali ke menu sebelumnya
        if (input == "0")
        {
            return 0;
        }
        // error handling apabila input kosong
        if (input.length() == 0)
        {
            cout << "+==================================================================+\n";
            cout << "|                     \033[1;31mINPUT TIDAK BOLEH KOSONG\033[0m                     |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }
        // error handling apabila ada diinputkan angka
        if (cek_str(input) == true)
        {
            cout << "+==================================================================+\n";
            cout << "|                     \033[1;31mINPUT HARUS SELAIN ANGKA\033[0m                     |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }
        // menambahkan nama lenkgap ke dalam node
        nodeBaru->nama_ayah = input;
        break;
    }
}
// fungsi untuk menambahkan nama ibu pada node
int tambah_nama_ibu(node *nodeBaru)
{
    string input;
    while (true)
    {
        system("cls");
        cout << "+==================================================================+\n";
        cout << "|                            \033[1;32mTAMBAH DATA\033[0m                           |\n";
        cout << "+==================================================================+\n";
        cout << "|                 [0] KEMBALI KE MENU SEBELUMNYA                   |\n";
        cout << "+==================================================================+\n";
        cout << "|NIK            : " << nodeBaru->NIK << setw(50 - nodeBaru->NIK.length()) << "|" << endl;
        cout << "|Nama Lengkap   : " << nodeBaru->nama_lengkap << setw(50 - (nodeBaru->nama_lengkap).length()) << "|" << endl;
        cout << "|Jenis Kelamin  : " << nodeBaru->jenis_kelamin << setw(50 - (nodeBaru->jenis_kelamin).length()) << "|" << endl;
        cout << "|Nama Ayah      : " << nodeBaru->nama_ayah << setw(50 - (nodeBaru->nama_ayah).length()) << "|" << endl;
        cout << "|Nama Ibu       : " << setw(50) << "|" << endl;
        cout << "+==================================================================+\n";
        cout << "Masukkan Nama Ibu : ";
        fflush(stdin);
        getline(cin, input);
        // kembali ke menu sebelumnya
        if (input == "0")
        {
            return 0;
        }
        // error handling apabila input kosong
        if (input.length() == 0)
        {
            cout << "+==================================================================+\n";
            cout << "|                     \033[1;31mINPUT TIDAK BOLEH KOSONG\033[0m                     |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }
        // error handling apabila ada diinputkan angka
        if (cek_str(input) == true)
        {
            cout << "+==================================================================+\n";
            cout << "|                     \033[1;31mINPUT HARUS SELAIN ANGKA\033[0m                     |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }
        // menambahkan nama ibu ke dalam node
        nodeBaru->nama_ibu = input;
        break;
    }
    return 1;
}
// fungsi untuk menambahkan data kedalam node
int tambah_data(node *nodeBaru, node *head)
{
    int input;
    input = tambah_NIK(nodeBaru, head);
    if (input == 0)
    {
        return 0;
    }
    input = tambah_nama_lengkap(nodeBaru);
    if (input == 0)
    {
        return 0;
    }
    input = tambah_jenis_kelamin(nodeBaru);
    if (input == 0)
    {
        return 0;
    }
    input = tambah_nama_ayah(nodeBaru);
    if (input == 0)
    {
        return 0;
    }
    input = tambah_nama_ibu(nodeBaru);
    if (input == 0)
    {
        return 0;
    }
    nodeBaru->password = nodeBaru->NIK;
}
// fungsi untuk menambahkan data warga(node) diawal linked list
int tambah_awal(node **head)
{
    int input;
    node *nodeBaru = new node;
    // proses menambahkan data kedalam node
    input = tambah_data(nodeBaru, *head);
    {
        if (input == 0)
        {
            return 0;
        }
    }
    // proses menambahkan node pada linked list
    nodeBaru->next = *head;
    *head = nodeBaru;
    // menampilkan data node yang ditambahkan ke link list
    system("cls");
    cout << "+==================================================================+\n";
    cout << "|                            \033[1;32mTAMBAH DATA\033[0m                           |\n";
    cout << "+==================================================================+\n";
    cout << "|                 [0] KEMBALI KE MENU SEBELUMNYA                   |\n";
    cout << "+==================================================================+\n";
    cout << "|NIK            : " << nodeBaru->NIK << setw(50 - nodeBaru->NIK.length()) << "|" << endl;
    cout << "|Nama Lengkap   : " << nodeBaru->nama_lengkap << setw(50 - (nodeBaru->nama_lengkap).length()) << "|" << endl;
    cout << "|Jenis Kelamin  : " << nodeBaru->jenis_kelamin << setw(50 - (nodeBaru->jenis_kelamin).length()) << "|" << endl;
    cout << "|Nama Ayah      : " << nodeBaru->nama_ayah << setw(50 - (nodeBaru->nama_ayah).length()) << "|" << endl;
    cout << "|Nama Ibu       : " << nodeBaru->nama_ibu << setw(50 - (nodeBaru->nama_ibu).length()) << "|" << endl;
    cout << "+==================================================================+\n";
    cout << "|                     \033[1;32mDATA BERHASIL DITAMBAHKAN\033[0m                    |\n";
    cout << "+==================================================================+\n";
    cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
    getche();
    update_file_warga(head);
}
// fungsi untuk menambahkan data warga(node) diakhir linked list
int tambah_akhir(node **head)
{
    int input;
    node *nodeBaru = new node;
    // proses menambahkan data kedalam node
    input = tambah_data(nodeBaru, *head);
    {
        if (input == 0)
        {
            return 0;
        }
    }
    // proses menambahkan node pada linked list
    nodeBaru->next = NULL;
    // jika linked list kosong
    if (*head == NULL)
    {
        *head = nodeBaru;
        return 1;
    }
    // jika tidak traversal ke node terakhir
    node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = nodeBaru;
    // menampilkan data node yang ditambahkan ke link list
    system("cls");
    cout << "+==================================================================+\n";
    cout << "|                            \033[1;32mTAMBAH DATA\033[0m                           |\n";
    cout << "+==================================================================+\n";
    cout << "|                 [0] KEMBALI KE MENU SEBELUMNYA                   |\n";
    cout << "+==================================================================+\n";
    cout << "|NIK            : " << nodeBaru->NIK << setw(50 - nodeBaru->NIK.length()) << "|" << endl;
    cout << "|Nama Lengkap   : " << nodeBaru->nama_lengkap << setw(50 - (nodeBaru->nama_lengkap).length()) << "|" << endl;
    cout << "|Jenis Kelamin  : " << nodeBaru->jenis_kelamin << setw(50 - (nodeBaru->jenis_kelamin).length()) << "|" << endl;
    cout << "|Nama Ayah      : " << nodeBaru->nama_ayah << setw(50 - (nodeBaru->nama_ayah).length()) << "|" << endl;
    cout << "|Nama Ibu       : " << nodeBaru->nama_ibu << setw(50 - (nodeBaru->nama_ibu).length()) << "|" << endl;
    cout << "+==================================================================+\n";
    cout << "|                     \033[1;32mDATA BERHASIL DITAMBAHKAN\033[0m                    |\n";
    cout << "+==================================================================+\n";
    cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
    getche();
    update_file_warga(head);
}
// fungsi untuk menambahkan data warga(node) pada posisi sepsifik di linked list
int tambah_spesifik(node **head, int jumlah)
{
    node *nodeBaru = new node;
    string input;
    int input_to_int;
    int back;
    // error handling saat input posisi spesifik
    while (true)
    {
        system("cls");
        tampilkan_data(*head, jumlah_data(*head));
        cout << "+==================================================================+\n";
        cout << "|                            \033[1;32mTAMBAH DATA\033[0m                           |\n";
        cout << "+==================================================================+\n";
        cout << "|                 [0] KEMBALI KE MENU SEBELUMNYA                   |\n";
        cout << "+==================================================================+\n";
        cout << "Tambahkan data pada posisi urutan ke : ";
        fflush(stdin);
        getline(cin, input);
        // kembali ke menu sebelumnya
        if (input == "0")
        {
            return 0;
        }
        // error handling apabila input kosong
        if (input.length() == 0)
        {
            cout << "+==================================================================+\n";
            cout << "|                     \033[1;31mINPUT TIDAK BOLEH KOSONG\033[0m                     |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }
        // error handling apabila ada diinputkan selain angka
        if (cek_int(input) == false)
        {
            cout << "+==================================================================+\n";
            cout << "|                     \033[1;31mINPUT HARUS BERUPA ANGKA\033[0m                     |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }
        // mengecek apakah urutan yang dimasukkan valid atau tidak
        input_to_int = stoi(input);
        if (input_to_int < 1 || input_to_int > jumlah + 1)
        {
            cout << "+==================================================================+\n";
            cout << "|                \033[1;31mURUTAN YANG DIMASUKKAN TIDAK VALID\033[0m                |\n";
            cout << "|                      \033[1;31mMASUKKAN URUTAN 1 - " << jumlah + 1 << "\033[0m" << setw(26 - to_string(jumlah + 1).length()) << "|\n";
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }

        // dibawah ini mengecek apakah data diinput pada posisi awal atau akhir
        if (input_to_int == 1)
        {
            back = tambah_awal(head);
            if (back == 0)
            {
                continue;
            }
            return 1;
        }
        if (input_to_int == jumlah + 1)
        {
            back = tambah_akhir(head);
            if (back == 0)
            {
                continue;
            }
            return 1;
        }
        // proses menambah data kedalam node
        back = tambah_data(nodeBaru, *head);
        if (back == 0)
        {
            continue;
        }
        break;
    }
    // proses menambahkan node kedalam linked list
    node *temp = *head;
    for (int i = 1; i < input_to_int - 1; i++)
    {
        temp = temp->next;
    }
    nodeBaru->next = temp->next;
    temp->next = nodeBaru;
    // menampilkan data node yang ditambahkan ke link list
    system("cls");
    cout << "+==================================================================+\n";
    cout << "|                            \033[1;32mTAMBAH DATA\033[0m                           |\n";
    cout << "+==================================================================+\n";
    cout << "|                 [0] KEMBALI KE MENU SEBELUMNYA                   |\n";
    cout << "+==================================================================+\n";
    cout << "|NIK            : " << nodeBaru->NIK << setw(50 - nodeBaru->NIK.length()) << "|" << endl;
    cout << "|Nama Lengkap   : " << nodeBaru->nama_lengkap << setw(50 - (nodeBaru->nama_lengkap).length()) << "|" << endl;
    cout << "|Jenis Kelamin  : " << nodeBaru->jenis_kelamin << setw(50 - (nodeBaru->jenis_kelamin).length()) << "|" << endl;
    cout << "|Nama Ayah      : " << nodeBaru->nama_ayah << setw(50 - (nodeBaru->nama_ayah).length()) << "|" << endl;
    cout << "|Nama Ibu       : " << nodeBaru->nama_ibu << setw(50 - (nodeBaru->nama_ibu).length()) << "|" << endl;
    cout << "+==================================================================+\n";
    cout << "|                     \033[1;32mDATA BERHASIL DITAMBAHKAN\033[0m                    |\n";
    cout << "+==================================================================+\n";
    cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
    getche();
    update_file_warga(head);
}
// menu untuk menambahkan data warga
void menu_tambah_data(node **head)
{
    string pilih;
    while (true)
    {
        system("cls");
        cout << "+==================================================================+\n";
        cout << "|                           \033[1;32mTAMBAH DATA\033[0m                            |\n";
        cout << "+==================================================================+\n";
        cout << "|                   [1] Tambah Data Pertama                        |" << endl;
        cout << "|                   [2] Tambah Data Spesifik                       |" << endl;
        cout << "|                   [3] Tambah Data Terakhir                       |" << endl;
        cout << "|                   [0] Kembali ke menu sebelumnya                 |" << endl;
        cout << "+==================================================================+\n";
        cout << "Masukkan Pilihan : ";
        getline(cin, pilih);

        if (pilih == "1")
        {
            tambah_awal(head);
        }
        else if (pilih == "2")
        {
            tambah_spesifik(head, jumlah_data(*head));
        }
        else if (pilih == "3")
        {
            tambah_akhir(head);
        }
        else if (pilih == "0")
        {
            return;
        }
        else
        {
            cout << "====================================================================\n";
            cout << "|                  \033[1;31mINPUT YANG ANDA MASUKKAN SALAH\033[0m                  |" << endl;
            cout << "====================================================================\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
        }
    }
}
// fungsi untuk menampilkan satu node data warga
void tampilkan_data_ke(node *temp, int posisi)
{

    system("CLS");
    cout << "\n";
    cout << "+==================================================================+\n";
    cout << "|                               \033[1;32mDATA\033[0m                               |\n";
    cout << "+==================================================================+\n";
    if (posisi != -1)
    {
        cout << "|                               \033[1;33m[" << posisi << "]\033[0m                                |" << endl;
    }
    cout << "+==================================================================+\n";
    cout << "|NIK            : " << temp->NIK << setw(50 - temp->NIK.length()) << "|" << endl;
    cout << "|Nama Lengkap   : " << temp->nama_lengkap << setw(50 - (temp->nama_lengkap).length()) << "|" << endl;
    cout << "|Jenis Kelamin  : " << temp->jenis_kelamin << setw(50 - (temp->jenis_kelamin).length()) << "|" << endl;
    cout << "|Nama Ayah      : " << temp->nama_ayah << setw(50 - (temp->nama_ayah).length()) << "|" << endl;
    cout << "|Nama Ibu       : " << temp->nama_ibu << setw(50 - (temp->nama_ibu).length()) << "|" << endl;
    cout << "|Password       : " << temp->password << setw(50 - (temp->password).length()) << "|" << endl;
    cout << "+==================================================================+\n";
}
// prosedur untuk mengubah NIK pada node
void ubah_NIK(node *head, node *temp, int posisi)
{
    string input;
    node *temp2;
    bool terpakai;
    while (true)
    {
        system("cls");
        tampilkan_data_ke(temp, posisi);
        cout << "\n";
        cout << "+==================================================================+\n";
        cout << "|                             \033[1;32mUBAH NIK\033[0m                             |\n";
        cout << "+==================================================================+\n";
        cout << "|                 [0] KEMBALI KE MENU SEBELUMNYA                   |\n";
        cout << "+==================================================================+\n";
        cout << "Masukkan NIK Baru : ";
        fflush(stdin);
        getline(cin, input);
        // kembali ke menu sebelumnya
        if (input == "0")
        {
            return;
        }
        // error handling apabila input kosong
        if (input.length() == 0)
        {
            cout << "+==================================================================+\n";
            cout << "|                     \033[1;31mINPUT TIDAK BOLEH KOSONG\033[0m                     |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }
        if (input.length() != 16)
        {
            cout << "+==================================================================+\n";
            cout << "|                       \033[1;31mINPUT HARUS 16 ANGKA\033[0m                       |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }
        // error handling apabila ada diinputkan selain angka

        if (cek_int(input) == false)
        {
            cout << "+==================================================================+\n";
            cout << "|                     \033[1;31mINPUT HARUS BERUPA ANGKA\033[0m                     |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }
        // mengecek apakah NIK sudah digunakan
        temp2 = head;
        while (temp2 != NULL)
        {
            if (temp2->NIK == input)
            {
                terpakai = true;
                break;
            }
            temp2 = temp2->next;
        }
        if (terpakai)
        {
            terpakai = false;
            cout << "+==================================================================+\n";
            cout << "|                         \033[1;31mNIK SUDAH TERDATA\033[0m                        |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }
        // mengubah NIK di dalam node
        temp->NIK = input;
        cout << "+==================================================================+\n";
        cout << "|                       \033[1;32mDATA BERHASIL DIRUBAH\033[0m                      |\n";
        cout << "+==================================================================+\n";
        cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
        getche();
        return;
    }
}
// prosedur untuk mengubah nama lengkap pada node
void ubah_nama_lengkap(node *temp, int posisi)
{
    while (true)
    {
        string input;
        system("cls");
        tampilkan_data_ke(temp, posisi);
        cout << "\n";
        cout << "+==================================================================+\n";
        cout << "|                         \033[1;32mUBAH NAMA LENGKAP\033[0m                        |\n";
        cout << "+==================================================================+\n";
        cout << "|                 [0] KEMBALI KE MENU SEBELUMNYA                   |\n";
        cout << "+==================================================================+\n";
        cout << "Masukkan Nama Lengkap Baru : ";
        fflush(stdin);
        getline(cin, input);
        // kembali ke menu sebelumnya

        if (input == "0")
        {
            return;
        }
        // error handling apabila input kosong

        if (input.length() == 0)
        {
            cout << "+==================================================================+\n";
            cout << "|                     \033[1;31mINPUT TIDAK BOLEH KOSONG\033[0m                     |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }
        // error handling apabila ada diinputkan angka

        if (cek_int(input) == true)
        {
            cout << "+==================================================================+\n";
            cout << "|                     \033[1;31mINPUT HARUS SELAIN ANGKA\033[0m                     |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }
        // mengubah nama lenkgap di dalam node

        temp->nama_lengkap = input;
        cout << "+==================================================================+\n";
        cout << "|                       \033[1;32mDATA BERHASIL DIRUBAH\033[0m                      |\n";
        cout << "+==================================================================+\n";
        cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
        getche();
        return;
    }
}
// prosedur untuk mengubah jenis kelamin pada node
void ubah_jenis_kelamin(node *temp, int posisi)
{
    while (true)
    {
        string input;
        system("cls");
        tampilkan_data_ke(temp, posisi);
        cout << "\n";
        cout << "+==================================================================+\n";
        cout << "|                         \033[1;32mUBAH JENIS KELAMIN\033[0m                       |\n";
        cout << "+==================================================================+\n";
        cout << "|                 [0] KEMBALI KE MENU SEBELUMNYA                   |\n";
        cout << "+==================================================================+\n";
        cout << "Masukkan Jenis Kelamin Baru (L/P) : ";
        fflush(stdin);
        getline(cin, input);
        // kembali ke menu sebelumnya
        if (input == "0")
        {
            return;
        }
        // error handling apabila input kosong
        if (input.length() == 0)
        {
            cout << "+==================================================================+\n";
            cout << "|                     \033[1;31mINPUT TIDAK BOLEH KOSONG\033[0m                     |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }
        // error handling apabila input selain huruf l dan p
        if (input != "L" && input != "l" && input != "P" && input != "p")
        {
            cout << "+==================================================================+\n";
            cout << "|                        \033[1;31mFORMAT INPUT SALAH\033[0m                        |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }
        // mwmberi value jenis kelamin laki laki apabila diinputkan l dan perempuan apabila p
        if (input == "L" || input == "l")
        {
            temp->jenis_kelamin = "Laki - Laki";
        }
        else
        {
            temp->jenis_kelamin = "Perempuan";
        }
        break;
    }
    cout << "+==================================================================+\n";
    cout << "|                       \033[1;32mDATA BERHASIL DIRUBAH\033[0m                      |\n";
    cout << "+==================================================================+\n";
    cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
    getche();
    return;
}
// prosedur untuk mengubah nama ayah pada node
void ubah_nama_ayah(node *temp, int posisi)
{
    while (true)
    {
        string input;
        system("cls");
        tampilkan_data_ke(temp, posisi);
        cout << "\n";
        cout << "+==================================================================+\n";
        cout << "|                          \033[1;32mUBAH NAMA AYAH\033[0m                          |\n";
        cout << "+==================================================================+\n";
        cout << "|                 [0] KEMBALI KE MENU SEBELUMNYA                   |\n";
        cout << "+==================================================================+\n";
        cout << "Masukkan Nama Ayah Baru : ";
        fflush(stdin);
        getline(cin, input);
        // kembali ke menu sebelumnya
        if (input == "0")
        {
            return;
        }
        // error handling apabila input kosong
        if (input.length() == 0)
        {
            cout << "+==================================================================+\n";
            cout << "|                     \033[1;31mINPUT TIDAK BOLEH KOSONG\033[0m                     |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }
        // error handling apabila ada diinputkan angka
        if (cek_int(input) == true)
        {
            cout << "+==================================================================+\n";
            cout << "|                     \033[1;31mINPUT HARUS SELAIN ANGKA\033[0m                     |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }
        // mengubah nama lenkgap di dalam node
        temp->nama_ayah = input;
        cout << "+==================================================================+\n";
        cout << "|                       \033[1;32mDATA BERHASIL DIRUBAH\033[0m                      |\n";
        cout << "+==================================================================+\n";
        cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
        getche();
        return;
    }
}
// prosedur untuk mengubah nama ibu pada node
void ubah_nama_ibu(node *temp, int posisi)
{
    while (true)
    {
        string input;
        system("cls");
        tampilkan_data_ke(temp, posisi);
        cout << "\n";
        cout << "+==================================================================+\n";
        cout << "|                           \033[1;32mUBAH NAMA IBU\033[0m                          |\n";
        cout << "+==================================================================+\n";
        cout << "|                 [0] KEMBALI KE MENU SEBELUMNYA                   |\n";
        cout << "+==================================================================+\n";
        cout << "Masukkan Nama Ibu Baru : ";
        fflush(stdin);
        getline(cin, input);
        // kembali ke menu sebelumnya
        if (input == "0")
        {
            return;
        }
        // error handling apabila input kosong
        if (input.length() == 0)
        {
            cout << "+==================================================================+\n";
            cout << "|                     \033[1;31mINPUT TIDAK BOLEH KOSONG\033[0m                     |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }
        // error handling apabila ada diinputkan angka
        if (cek_int(input) == true)
        {
            cout << "+==================================================================+\n";
            cout << "|                     \033[1;31mINPUT HARUS SELAIN ANGKA\033[0m                     |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }
        // mengubah nama ibu di dalam node
        temp->nama_ibu = input;
        cout << "+==================================================================+\n";
        cout << "|                       \033[1;32mDATA BERHASIL DIRUBAH\033[0m                      |\n";
        cout << "+==================================================================+\n";
        cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
        getche();
        return;
    }
}
// prosedur untuk mengubah password pada node
void ubah_password(node *temp, int posisi)
{
    while (true)
    {
        string input;
        system("cls");
        tampilkan_data_ke(temp, posisi);
        cout << "\n";
        cout << "+==================================================================+\n";
        cout << "|                           \033[1;32mUBAH PASSWORD\033[0m                          |\n";
        cout << "+==================================================================+\n";
        cout << "|                 [0] KEMBALI KE MENU SEBELUMNYA                   |\n";
        cout << "+==================================================================+\n";
        cout << "Masukkan Password Baru : ";
        fflush(stdin);
        getline(cin, input);
        // kembali ke menu sebelumnya
        if (input == "0")
        {
            return;
        }
        // error handling apabila input kosong
        if (input.length() == 0)
        {
            cout << "+==================================================================+\n";
            cout << "|                     \033[1;31mINPUT TIDAK BOLEH KOSONG\033[0m                     |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }
        // error handling apabila input kurang dari 8 karakter
        if (input.length() < 8)
        {
            cout << "+==================================================================+\n";
            cout << "|                     \033[1;31mINPUT MINIMAL 8 KARAKTER\033[0m                     |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }
        // mengubah password di dalam node
        temp->password = input;
        cout << "+==================================================================+\n";
        cout << "|                       \033[1;32mDATA BERHASIL DIRUBAH\033[0m                      |\n";
        cout << "+==================================================================+\n";
        cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
        getche();
        return;
    }
}
// prosedur untuk mengubah data warga di dalam node
void ubah_data(node **head, node *temp, int posisi)
{
    while (true)
    {
        update_file_warga(head);
        string input;
        int input_to_int;
        system("cls");
        tampilkan_data_ke(temp, posisi);
        cout << "\n";
        cout << "+==================================================================+\n";
        cout << "|                            \033[1;32mUBAH DATA\033[0m                             |\n";
        cout << "+==================================================================+\n";
        cout << "|                    [1] NIK                                       |" << endl;
        cout << "|                    [2] Nama Lengkap                              |" << endl;
        cout << "|                    [3] Jenis Kelamin                             |" << endl;
        cout << "|                    [4] Nama Ayah                                 |" << endl;
        cout << "|                    [5] Nama Ibu                                  |" << endl;
        cout << "|                    [6] Password                                  |" << endl;
        cout << "|                    [0] Kembali ke menu sebelumnya                |\n";
        cout << "+==================================================================+\n";
        cout << "Masukkan Pilihan: : ";
        fflush(stdin);
        getline(cin, input);
        // kembali ke menu sebelumnya
        if (input == "0")
        {
            return;
        }
        // error handling apabila input kosong
        if (input.length() == 0)
        {
            cout << "+==================================================================+\n";
            cout << "|                     \033[1;31mINPUT TIDAK BOLEH KOSONG\033[0m                     |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }
        // error handling apabila ada diinputkan selain angka
        if (cek_int(input) == false)
        {
            cout << "+==================================================================+\n";
            cout << "|                     \033[1;31mINPUT HARUS BERUPA ANGKA\033[0m                     |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }
        input_to_int = stoi(input);
        // error handling saat input tidak valid
        if (input_to_int < 1 || input_to_int > 6)
        {
            cout << "+==================================================================+\n";
            cout << "|                  \033[1;31mINPUT YANG ANDA MASUKKAN SALAH\033[0m                  |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }
        if (input_to_int == 1)
        {
            ubah_NIK(*head, temp, posisi);
        }
        else if (input_to_int == 2)
        {
            ubah_nama_lengkap(temp, posisi);
        }
        else if (input_to_int == 3)
        {
            ubah_jenis_kelamin(temp, posisi);
        }
        else if (input_to_int == 4)
        {
            ubah_nama_ayah(temp, posisi);
        }
        else if (input_to_int == 5)
        {
            ubah_nama_ibu(temp, posisi);
        }
        else if (input_to_int == 6)
        {
            ubah_password(temp, posisi);
        }
    }
}
// menu untuk mengubah data warga
void menu_ubah_data(node **head)
{
    node *temp;
    while (true)
    {
        temp = *head;
        string input;
        int input_to_int;
        system("cls");
        tampilkan_data(temp, jumlah_data(*head));
        if (*head == NULL)
        {
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            return;
        }
        cout << "\n";
        cout << "+==================================================================+\n";
        cout << "|                            \033[1;32mUBAH DATA\033[0m                             |\n";
        cout << "+==================================================================+\n";
        cout << "|                 [0] KEMBALI KE MENU SEBELUMNYA                   |\n";
        cout << "+==================================================================+\n";
        cout << "Pilih Data ke : ";
        fflush(stdin);
        getline(cin, input);
        if (input == "0")
        {
            return;
        }
        if (input.length() == 0)
        {
            cout << "+==================================================================+\n";
            cout << "|                     \033[1;31mINPUT TIDAK BOLEH KOSONG\033[0m                     |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }
        if (cek_int(input) == false)
        {
            cout << "+==================================================================+\n";
            cout << "|                     \033[1;31mINPUT HARUS BERUPA ANGKA\033[0m                     |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }
        input_to_int = stoi(input);

        if (input_to_int < 1 || input_to_int > jumlah_data(*head))
        {
            cout << "+==================================================================+\n";
            cout << "|                     \033[1;31mDATA KE " << input_to_int << " TIDAK DTEMUKAN\033[0m                     |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }
        for (int i = 1; i < input_to_int; i++)
        {
            temp = temp->next;
        }
        ubah_data(head, temp, input_to_int);
    }
}
//menu untuk menghapus data warga(node) di awal linked list
void hapus_awal(node **head)
{
    if (*head == NULL)
    {
        system("cls");
        cout << "+==================================================================+\n";
        cout << "|                            \033[1;32mHAPUS DATA\033[0m                            |\n";
        cout << "+==================================================================+\n";
        cout << "|                          TIDAK ADA DATA                          |\n";
        cout << "+==================================================================+\n";
        cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
        getche();
        return;
    }
    *head = (*head)->next;
    cout << "+==================================================================+\n";
    cout << "|                   \033[1;32mDATA PERTAMA BERHASIL DIHAPUS\033[0m                  |\n";
    cout << "+==================================================================+\n";
    cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
    getche();
    update_file_warga(head);
    return;
}
//menu untuk menghapus data warga(node) di akhir linked list
void hapus_akhir(node **head)
{
    if (*head == NULL)
    {
        system("cls");
        cout << "+==================================================================+\n";
        cout << "|                            \033[1;32mHAPUS DATA\033[0m                            |\n";
        cout << "+==================================================================+\n";
        cout << "|                          TIDAK ADA DATA                          |\n";
        cout << "+==================================================================+\n";
        cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
        getche();
        return;
    }
    if ((*head)->next == NULL)
    {
        *head = NULL;
        cout << "+==================================================================+\n";
        cout << "|                  \033[1;32mDATA TERAKHIR BERHASIL DIHAPUS\033[0m                  |\n";
        cout << "+==================================================================+\n";
        cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
        getche();
        return;
    }
    node *temp = *head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    cout << "+==================================================================+\n";
    cout << "|                  \033[1;32mDATA TERAKHIR BERHASIL DIHAPUS\033[0m                  |\n";
    cout << "+==================================================================+\n";
    cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
    getche();
    update_file_warga(head);
    return;
}
//menu untuk menghapus data warga(node) pada posisi spesifik linked list
void hapus_spesifik(node **head, int jumlah)
{

    if (*head == NULL)
    {
        system("cls");
        cout << "+==================================================================+\n";
        cout << "|                            \033[1;32mHAPUS DATA\033[0m                            |\n";
        cout << "+==================================================================+\n";
        cout << "|                          TIDAK ADA DATA                          |\n";
        cout << "+==================================================================+\n";
        cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
        getche();
        return;
    }
    string input;
    int input_to_int;
    node *temp;
    while (true)
    {
        system("cls");
        tampilkan_data(*head, jumlah_data(*head));
        cout << "\n";
        cout << "+==================================================================+\n";
        cout << "|                            \033[1;32mHAPUS DATA\033[0m                            |\n";
        cout << "+==================================================================+\n";
        cout << "|                 [0] KEMBALI KE MENU SEBELUMNYA                   |\n";
        cout << "+==================================================================+\n";
        cout << "Pilih Data ke : ";
        getline(cin, input);
        if (input == "0")
        {
            return;
        }
        if (input.length() == 0)
        {
            cout << "+==================================================================+\n";
            cout << "|                     \033[1;31mINPUT TIDAK BOLEH KOSONG\033[0m                     |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }
        if (cek_int(input) == false)
        {
            cout << "+==================================================================+\n";
            cout << "|                     \033[1;31mINPUT HARUS BERUPA ANGKA\033[0m                     |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }
        input_to_int = stoi(input);
        if (input_to_int < 1 || input_to_int > jumlah)
        {
            cout << "+==================================================================+\n";
            cout << "|                     \033[1;31mDATA KE " << input_to_int << " TIDAK DTEMUKAN\033[0m                     |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }
        if (input_to_int == 1)
        {
            hapus_awal(head);
            return;
        }
        else if (input_to_int == jumlah)
        {
            hapus_akhir(head);
            return;
        }
        else
        {
            temp = *head;
            for (int i = 1; i < input_to_int - 1; i++)
            {
                temp = temp->next;
            }
            temp->next = temp->next->next;
            cout << "+==================================================================+\n";
            cout << "|                       \033[1;32mDATA BERHASIL DIHAPUS\033[0m                      |\n";
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            update_file_warga(head);
            return;
        }
    }
}
//prosedur untuk memilih posisi data warga(node) yang ingin dihapus
void menu_hapus_data(node **head)
{
    string pilih;
    while (true)
    {
        system("cls");
        tampilkan_data(*head, jumlah_data(*head));
        if (*head == NULL)
        {
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            return;
        }
        cout << endl;
        cout << "+==================================================================+\n";
        cout << "|                           \033[1;32mHAPUS DATA\033[0m                             |\n";
        cout << "+==================================================================+\n";
        cout << "|                   [1] Hapus Data Pertama                         |" << endl;
        cout << "|                   [2] Hapus Data Spesifik                        |" << endl;
        cout << "|                   [3] Hapus Data Terakhir                        |" << endl;
        cout << "|                   [0] Kembali ke menu sebelumnya                 |" << endl;
        cout << "+==================================================================+\n";
        cout << "Masukkan Pilihan : ";
        getline(cin, pilih);

        if (pilih == "1")
        {
            hapus_awal(head);
        }
        else if (pilih == "2")
        {
            hapus_spesifik(head, jumlah_data(*head));
        }
        else if (pilih == "3")
        {
            hapus_akhir(head);
        }
        else if (pilih == "0")
        {
            return;
        }
        else
        {
            cout << "====================================================================\n";
            cout << "|                  \033[1;31mINPUT YANG ANDA MASUKKAN SALAH\033[0m                  |" << endl;
            cout << "====================================================================\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
        }
    }
}
//fungsi untuk membandingkan untuk diurutkan
node *SortedMerge(node *a, node *b, string attrb, string order);
//prosedur untuk membagi linked-list menjadi 2 bagian
void FrontBackSplit(node *source, node **frontRef, node **backRef);
// prosedur untuk melakukan pengurutan dengan mergesort
void MergeSort(node **headRef, string attrb, string order)
{
    node *head = *headRef;
    node *a;
    node *b;
    if ((head == NULL) || (head->next == NULL))
    {
        return;
    }
    FrontBackSplit(head, &a, &b);
    MergeSort(&a, attrb, order);
    MergeSort(&b, attrb, order);
    *headRef = SortedMerge(a, b, attrb, order);
}
//fungsi untuk membandingkan untuk diurutkan
node *SortedMerge(node *a, node *b, string attrb, string order)
{
    node *result = NULL;
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
    if (attrb == "NIK" && order == "asc")
    {
        if (a->NIK <= b->NIK)
        {
            result = a;
            result->next = SortedMerge(a->next, b, attrb, order);
        }
        else
        {
            result = b;
            result->next = SortedMerge(a, b->next, attrb, order);
        }
    }
    if (attrb == "NIK" && order == "desc")
    {
        if (a->NIK >= b->NIK)
        {
            result = a;
            result->next = SortedMerge(a->next, b, attrb, order);
        }
        else
        {
            result = b;
            result->next = SortedMerge(a, b->next, attrb, order);
        }
    }
    if (attrb == "nama" && order == "asc")
    {
        if (a->nama_lengkap <= b->nama_lengkap)
        {
            result = a;
            result->next = SortedMerge(a->next, b, attrb, order);
        }
        else
        {
            result = b;
            result->next = SortedMerge(a, b->next, attrb, order);
        }
    }
    if (attrb == "nama" && order == "desc")
    {
        if (a->nama_lengkap >= b->nama_lengkap)
        {
            result = a;
            result->next = SortedMerge(a->next, b, attrb, order);
        }
        else
        {
            result = b;
            result->next = SortedMerge(a, b->next, attrb, order);
        }
    }
    return (result);
}
//prosedur untuk membagi linked-list menjadi 2 bagian
void FrontBackSplit(node *source, node **frontRef, node **backRef)
{
    node *fast;
    node *slow;
    slow = source;
    fast = source->next;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}
//prosedur untuk menampilkan menu sorting data
void menu_sort_data(node **head)
{
    string pilih;
    while (true)
    {
        system("cls");
        if (*head == NULL)
        {
            cout << "+==================================================================+\n";
            cout << "|                               \033[1;32mDATA\033[0m                               |\n";
            cout << "+==================================================================+\n";
            cout << "|                          TIDAK ADA DATA                          |\n";
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            return;
        }
        tampilkan_data(*head, jumlah_data(*head));
        cout << "+==================================================================+\n";
        cout << "|                          \033[1;32mURUTKAN DATA\033[0m                            |\n";
        cout << "+==================================================================+\n";
        cout << "|                   [1] Sorting berdasarkan NIK (Ascending)        |" << endl;
        cout << "|                   [2] Sorting berdasarkan NIK (Descending)       |" << endl;
        cout << "|                   [3] Sorting berdasarkan Nama (Ascending)       |" << endl;
        cout << "|                   [4] Sorting berdasarkan Nama (Descending)      |" << endl;
        cout << "|                   [0] Kembali ke menu sebelumnya                 |" << endl;
        cout << "+==================================================================+\n";
        cout << "Masukkan Pilihan : ";
        getline(cin, pilih);

        if (pilih == "1")
        {
            MergeSort(head, "NIK", "asc");
            cout << "+==================================================================+\n";
            cout << "|        \033[1;32mDATA BERHASIL DIURUTKAN BERDASARKAN NIK (ASCENDING)\033[0m       |\n";
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
        }
        else if (pilih == "2")
        {
            MergeSort(head, "NIK", "desc");
            cout << "+==================================================================+\n";
            cout << "|       \033[1;32mDATA BERHASIL DIURUTKAN BERDASARKAN NIK (DESCENDING)\033[0m       |\n";
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
        }
        else if (pilih == "3")
        {
            MergeSort(head, "nama", "asc");
            cout << "+==================================================================+\n";
            cout << "|       \033[1;32mDATA BERHASIL DIURUTKAN BERDASARKAN NAMA (ASCENDING)\033[0m       |\n";
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
        }
        else if (pilih == "4")
        {
            MergeSort(head, "nama", "desc");
            cout << "+==================================================================+\n";
            cout << "|       \033[1;32mDATA BERHASIL DIURUTKAN BERDASARKAN NAMA (DESCENDING)\033[0m      |\n";
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
        }
        else if (pilih == "0")
        {
            return;
        }
        else
        {
            cout << "====================================================================\n";
            cout << "|                  \033[1;31mINPUT YANG ANDA MASUKKAN SALAH\033[0m                  |" << endl;
            cout << "====================================================================\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
        }
    }
}
//prosedur untuk menyimpan data warga yang ditemukan saat searching
void found_data(node **head_found, node *found)
{
    node *nodeBaru = new node;
    nodeBaru->NIK = found->NIK;
    nodeBaru->nama_lengkap = found->nama_lengkap;
    nodeBaru->jenis_kelamin = found->jenis_kelamin;
    nodeBaru->nama_ayah = found->nama_ayah;
    nodeBaru->nama_ibu = found->nama_ibu;
    nodeBaru->password = found->password;
    nodeBaru->next = NULL;
    // jika linked list kosong
    if (*head_found == NULL)
    {
        *head_found = nodeBaru;
        return;
    }
    // jika tidak traversal ke node terakhir
    node *temp = *head_found;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = nodeBaru;
}

const int NO_OF_CHARS = 256;
// Fungsi untuk mengisi array badChar[] untuk memberikan informasi
// terakhir kemunculan karakter yang tidak cocok
void badCharHeuristic(string str, int size, int badChar[NO_OF_CHARS])
{
    // Inisialisasi semua nilai di badChar sebagai -1
    for (int i = 0; i < NO_OF_CHARS; i++)
    {
        badChar[i] = -1;
    }
    // Isi nilai aktual dari badChar untuk karakter yang ada dalam str
    for (int i = 0; i < size; i++)
    {
        badChar[(int)str[i]] = i;
    }
}
// Fungsi pencarian string dengan Boyer-Moore Bad Character Heuristic
void search(node *head, string pat, string attrb)
{
    string data;
    node *head_found = NULL;
    int m = pat.size();
    node *temp = head;
    while (temp != NULL)
    {
        if (attrb == "nama")
        {
            data = temp->nama_lengkap;
        }
        if (attrb == "NIK")
        {
            data = temp->NIK;
        }
        transform(pat.begin(), pat.end(), pat.begin(), ::toupper);
        transform(data.begin(), data.end(), data.begin(), ::toupper);
        int n = data.size();
        int badChar[NO_OF_CHARS];
        badCharHeuristic(pat, m, badChar);
        int s = 0; // s adalah shift dari pola sehubungan dengan teks

        while (s <= (n - m))
        {
            int j = m - 1;
            // Kurangi indeks j dari pola sampai karakter dari pola dan teks cocok

            while (j >= 0 && pat[j] == data[s + j])
            {
                j--;
            }
            if (j < 0)
            {
                found_data(&head_found, temp);
                break;
            }
            else
            {
                // Geser pola sehingga karakter yang tidak cocok dalam pola sesuai dengan karakter terakhir yang sama di teks
                s += max(1, j - badChar[data[s + j]]);
            }
        }
        temp = temp->next;
    }
    tampilkan_data(head_found, jumlah_data(head_found));
}
// fungsi untuk melakukan searching berdasarkan nama lengkap
void cari_nama(node *head)
{
    string input;
    int back;
    while (true)
    {
        system("cls");
        cout << "+==================================================================+\n";
        cout << "|                           \033[1;32mCARI DATA\033[0m                              |\n";
        cout << "+==================================================================+\n";
        cout << "|                 [0] KEMBALI KE MENU SEBELUMNYA                   |\n";
        cout << "+==================================================================+\n";
        cout << "Cari Nama : ";
        fflush(stdin);
        getline(cin, input);
        if (input == "0")
        {
            return;
        }
        if (input.length() == 0)
        {
            cout << "+==================================================================+\n";
            cout << "|                     \033[1;31mINPUT TIDAK BOLEH KOSONG\033[0m                     |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }
        if (cek_int(input) == true)
        {
            cout << "+==================================================================+\n";
            cout << "|                     \033[1;31mINPUT HARUS BERUPA HURUF\033[0m                     |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }
        search(head, input, "nama");
        break;
    }
}
// fungsi untuk melakukan searching berdasarkan NIK
void cari_NIK(node *head)
{
    string input;
    int back;
    while (true)
    {
        system("cls");
        cout << "+==================================================================+\n";
        cout << "|                           \033[1;32mCARI DATA\033[0m                              |\n";
        cout << "+==================================================================+\n";
        cout << "|                 [0] KEMBALI KE MENU SEBELUMNYA                   |\n";
        cout << "+==================================================================+\n";
        cout << "Cari NIK : ";
        fflush(stdin);
        getline(cin, input);
        if (input == "0")
        {
            return;
        }
        if (input.length() == 0)
        {
            cout << "+==================================================================+\n";
            cout << "|                     \033[1;31mINPUT TIDAK BOLEH KOSONG\033[0m                     |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }
        if (cek_int(input) == false)
        {
            cout << "+==================================================================+\n";
            cout << "|                     \033[1;31mINPUT HARUS BERUPA ANGKA\033[0m                     |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }
        search(head, input, "NIK");
        break;
    }
}
//prosedur untuk menampilkan menu searching data
void menu_search_data(node *head)
{
    string pilih;
    while (true)
    {
        system("cls");
        if (head == NULL)
        {
            cout << "+==================================================================+\n";
            cout << "|                               \033[1;32mDATA\033[0m                               |\n";
            cout << "+==================================================================+\n";
            cout << "|                          TIDAK ADA DATA                          |\n";
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            return;
        }
        cout << endl;
        cout << "+==================================================================+\n";
        cout << "|                           \033[1;32mCARI DATA\033[0m                              |\n";
        cout << "+==================================================================+\n";
        cout << "|                   [1] Cari berdasarkan NIK                       |" << endl;
        cout << "|                   [2] Cari berdasarkan Nama Lengkap              |" << endl;
        cout << "|                   [0] Kembali ke menu sebelumnya                 |" << endl;
        cout << "+==================================================================+\n";
        cout << "Masukkan Pilihan : ";
        getline(cin, pilih);

        if (pilih == "1")
        {
            cari_NIK(head);
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
        }
        else if (pilih == "2")
        {
            cari_nama(head);
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
        }
        else if (pilih == "0")
        {
            return;
        }
        else
        {
            cout << "====================================================================\n";
            cout << "|                  \033[1;31mINPUT YANG ANDA MASUKKAN SALAH\033[0m                  |" << endl;
            cout << "====================================================================\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
        }
    }
}
//stuct untuk menyimpan data laporan
struct node_laporan
{
    string id;
    string NIK;
    string nama_lengkap;
    string judul_laporan;
    string deskripsi_laporan;
    node_laporan *next;
};
//prosedur untuk tampilan judul laporan dan deskripsi laporan
void string_split(string kalimat)
{
    for (int i = 0; true; i++)
    {

        if (i * 46 > kalimat.length())
        {
            break;
        }
        if (i != 0)
        {
            cout << "|" << setw(21);
        }
        for (int j = (46 * i); j < (46 * (i + 1)); j++)
        {
            if (j == kalimat.length())
            {
                cout << setw(46 * (i + 1) - j + 1) << "|" << endl;
                break;
            }
            if (j == (46 * (i + 1) - 1))
            {
                cout << kalimat[j] << "|" << endl;
            }
            else
            {
                cout << kalimat[j];
            }
        }
    }
}
//fungsi untuk mwngembalikan nilai banyak node pada linked list laporan
int jumlah_laporan(node_laporan *temp)
{
    int jumlah = 0;
    while (temp != NULL)
    {
        jumlah++;
        temp = temp->next;
    }
    return jumlah;
}
//fungsi untuk menambah data laporan ke dalam node
void add_data_laporan(node_laporan **head_laporan, node_laporan temp_node)
{
    node_laporan *nodeBaru = new node_laporan;
    nodeBaru->id = temp_node.id;
    nodeBaru->NIK = temp_node.NIK;
    nodeBaru->nama_lengkap = temp_node.nama_lengkap;
    nodeBaru->judul_laporan = temp_node.judul_laporan;
    nodeBaru->deskripsi_laporan = temp_node.deskripsi_laporan;
    // proses menambahkan node pada linked list
    nodeBaru->next = NULL;
    // jika linked list kosong
    if (*head_laporan == NULL)
    {
        *head_laporan = nodeBaru;
        return;
    }
    // jika tidak traversal ke node terakhir
    node_laporan *temp = *head_laporan;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = nodeBaru;
}
//prosedur untuk membaca data laporan dari file csv
void read_file_laporan(node_laporan **head_laporan)
{
    string data, data_sementara;
    ifstream file_laporan;
    node_laporan temp_node;
    int count = 0;
    file_laporan.open("file_laporan.csv", ios::in);
    if (file_laporan.is_open())
    {
        while (getline(file_laporan, data))
        {
            count++;
            stringstream temp(data);
            getline(temp, data_sementara, ',');
            temp_node.id = data_sementara;
            getline(temp, data_sementara, ',');
            temp_node.NIK = data_sementara;
            getline(temp, data_sementara, ',');
            temp_node.nama_lengkap = data_sementara;
            getline(temp, data_sementara, ',');
            temp_node.judul_laporan = data_sementara;
            getline(temp, data_sementara, '\n');
            temp_node.deskripsi_laporan = data_sementara;
            add_data_laporan(head_laporan, temp_node);
        }
    }
    file_laporan.close();
}
//prosedur untuk mengedit data laporan dari file csv
void update_file_laporan(node_laporan **head_laporan)
{
    node_laporan *temp = *head_laporan;
    ofstream file_laporan;
    file_laporan.open("file_laporan.csv", ios::out | ios::trunc);

    if (*head_laporan != NULL)
    {
        int jumlah = jumlah_laporan(*head_laporan);
        for (int i = 0; i < jumlah; i++)
        {
            file_laporan << temp->id << ",";
            file_laporan << temp->NIK << ",";
            file_laporan << temp->nama_lengkap << ",";
            file_laporan << temp->judul_laporan << ",";
            file_laporan << temp->deskripsi_laporan << "\n";
            temp = temp->next;
        }
    }
    file_laporan.close();
}
//prosedur untuk menampilkan laporan di menu warga
void tampilkan_laporan_warga(node_laporan *head_laporan, int jumlah, node *warga)
{
    int count = 0;
    system("CLS");
    cout << "\n";
    cout << "+==================================================================+\n";
    cout << "|                             \033[1;32mLAPORAN\033[0m                              |\n";
    cout << "+==================================================================+\n";
    for (int i = 0; i < jumlah; i++)
    {
        if (warga->NIK == head_laporan->NIK)
        {
            cout << "|ID Laporan        : " << head_laporan->id << setw(47 - head_laporan->id.length()) << "|" << endl;
            cout << "|Judul Laporan     : ";
            string_split(head_laporan->judul_laporan);
            cout << "|Deskripsi Laporan : ";
            string_split(head_laporan->deskripsi_laporan);
            cout << "+==================================================================+\n";
            count++;
        }
        head_laporan = head_laporan->next;
    }
    if (count == 0)
    {
        system("CLS");
        cout << "+==================================================================+\n";
        cout << "|                             \033[1;32mLAPORAN\033[0m                              |\n";
        cout << "+==================================================================+\n";
        cout << "|                        TIDAK ADA LAPORAN                         |\n";
        cout << "+==================================================================+\n";
    }
}
//prosedur untuk menampilkan laporan di menu admin
void tampilkan_laporan_admin(node_laporan *head_laporan, int jumlah)
{
    if (head_laporan == NULL)
    {
        system("CLS");
        cout << "\n";
        cout << "+==================================================================+\n";
        cout << "|                             \033[1;32mLAPORAN\033[0m                              |\n";
        cout << "+==================================================================+\n";
        cout << "|                        TIDAK ADA LAPORAN                         |\n";
        cout << "+==================================================================+\n";
    }
    else
    {
        system("CLS");
        cout << "\n";
        cout << "+==================================================================+\n";
        cout << "|                             \033[1;32mLAPORAN\033[0m                              |\n";
        cout << "+==================================================================+\n";
        for (int i = 0; i < jumlah; i++)
        {
            cout << "|                               \033[1;33m[" << i + 1 << "]\033[0m                                |" << endl;
            cout << "+==================================================================+\n";
            cout << "|ID Laporan        : " << head_laporan->id << setw(47 - head_laporan->id.length()) << "|" << endl;
            cout << "|NIK               : " << head_laporan->NIK << setw(47 - (head_laporan->NIK).length()) << "|" << endl;
            cout << "|Nama Lengkap      : " << head_laporan->nama_lengkap << setw(47 - (head_laporan->nama_lengkap).length()) << "|" << endl;
            cout << "|Judul Laporan     : ";
            string_split(head_laporan->judul_laporan);
            cout << "|Deskripsi Laporan : ";
            ;
            string_split(head_laporan->deskripsi_laporan);
            cout << "+==================================================================+\n";
            head_laporan = head_laporan->next;
        }
    }
}
//fungsi untuk menambah judul laporan pada node
int tambah_judul_laporan(node_laporan *nodeBaru)
{
    string input;
    while (true)
    {
        system("cls");
        cout << "+==================================================================+\n";
        cout << "|                          \033[1;32mTAMBAH LAPORAN\033[0m                          |\n";
        cout << "+==================================================================+\n";
        cout << "|                 [0] KEMBALI KE MENU SEBELUMNYA                   |\n";
        cout << "+==================================================================+\n";
        cout << "|Judul Laporan     : " << setw(47) << "|" << endl;
        cout << "|Deskripsi Laporan : " << setw(47) << "|" << endl;
        cout << "+==================================================================+\n";
        cout << "Masukkan Judul Laporan : ";
        fflush(stdin);
        getline(cin, input);
        // kembali ke menu sebelumnya
        if (input == "0")
        {
            return 0;
        }
        // error handling apabila input kosong
        if (input.length() == 0)
        {
            cout << "+==================================================================+\n";
            cout << "|                     \033[1;31mINPUT TIDAK BOLEH KOSONG\033[0m                     |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }
        // menambahkan judul laporan ke dalam node
        nodeBaru->judul_laporan = input;
        break;
    }
}
//fungsi untuk menambah deskripsi laporan pada node
int tambah_deskripsi_laporan(node_laporan *nodeBaru)
{
    string input;
    while (true)
    {
        system("cls");
        cout << "+==================================================================+\n";
        cout << "|                          \033[1;32mTAMBAH LAPORAN\033[0m                          |\n";
        cout << "+==================================================================+\n";
        cout << "|                 [0] KEMBALI KE MENU SEBELUMNYA                   |\n";
        cout << "+==================================================================+\n";
        cout << "|Judul Laporan     : ";
        string_split(nodeBaru->judul_laporan);
        cout << "|Deskripsi Laporan : " << setw(47) << "|" << endl;
        cout << "+==================================================================+\n";
        cout << "Masukkan Deskripsi Laporan : ";
        fflush(stdin);
        getline(cin, input);
        // kembali ke menu sebelumnya
        if (input == "0")
        {
            return 0;
        }
        // error handling apabila input kosong
        if (input.length() == 0)
        {
            cout << "+==================================================================+\n";
            cout << "|                     \033[1;31mINPUT TIDAK BOLEH KOSONG\033[0m                     |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }
        // menambahkan deskripsi laporan ke dalam node
        nodeBaru->deskripsi_laporan = input;
        break;
    }
}
//prosedur untuk menambah data laporan ke dalam node
int tambah_data_laporan(node_laporan *head_laporan, node_laporan *nodeBaru, node *warga)
{
    int input;
    nodeBaru->id = to_string(jumlah_laporan(head_laporan) + 1);
    nodeBaru->NIK = warga->NIK;
    nodeBaru->nama_lengkap = warga->nama_lengkap;
    input = tambah_judul_laporan(nodeBaru);
    if (input == 0)
    {
        return 0;
    }

    input = tambah_deskripsi_laporan(nodeBaru);
    if (input == 0)
    {
        return 0;
    }
}
//prosedur untuk menambah data laporan ke dalam linked list
int tambah_laporan(node_laporan **head_laporan, node *warga)
{
    int input;
    node_laporan *nodeBaru = new node_laporan;
    // proses menambahkan data kedalam node
    input = tambah_data_laporan(*head_laporan, nodeBaru, warga);
    {
        if (input == 0)
        {
            return 0;
        }
    }
    // proses menambahkan node pada linked list
    nodeBaru->next = NULL;
    // jika linked list kosong
    if (*head_laporan == NULL)
    {
        *head_laporan = nodeBaru;
        system("cls");
        cout << "+==================================================================+\n";
        cout << "|                          \033[1;32mTAMBAH LAPORAN\033[0m                          |\n";
        cout << "+==================================================================+\n";
        cout << "|                 [0] KEMBALI KE MENU SEBELUMNYA                   |\n";
        cout << "+==================================================================+\n";
        cout << "|Judul Laporan     : ";
        string_split(nodeBaru->judul_laporan);
        cout << "|Deskripsi Laporan : ";
        string_split(nodeBaru->deskripsi_laporan);
        cout << "+==================================================================+\n";
        cout << "|                   \033[1;32mLAPORAN BERHASIL DITAMBAHKAN\033[0m                   |\n";
        cout << "+==================================================================+\n";
        cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
        getche();
        update_file_laporan(head_laporan);
        return 1;
    }
    // jika tidak traversal ke node terakhir
    node_laporan *temp = *head_laporan;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = nodeBaru;
    // menampilkan data node yang ditambahkan ke link list
    system("cls");
    cout << "+==================================================================+\n";
    cout << "|                          \033[1;32mTAMBAH LAPORAN\033[0m                          |\n";
    cout << "+==================================================================+\n";
    cout << "|                 [0] KEMBALI KE MENU SEBELUMNYA                   |\n";
    cout << "+==================================================================+\n";
    cout << "|Judul Laporan     : ";
    string_split(nodeBaru->judul_laporan);
    cout << "|Deskripsi Laporan : ";
    string_split(nodeBaru->deskripsi_laporan);
    cout << "+==================================================================+\n";
    cout << "|                   \033[1;32mLAPORAN BERHASIL DITAMBAHKAN\033[0m                   |\n";
    cout << "+==================================================================+\n";
    cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
    getche();
    update_file_laporan(head_laporan);
}
//prosedur untuk menampilkan menu laporan warga
void menu_laporan_warga(node_laporan **head_laporan, node *warga)
{
    string pilih;
    while (true)
    {
        system("cls");
        cout << "+==================================================================+\n";
        cout << "|                        \033[1;32mMENU LAPORAN WARGA\033[0m                        |\n";
        cout << "+==================================================================+\n";
        cout << "|                   [1] Buat Laporan                               |" << endl;
        cout << "|                   [2] Lihat Laporan Saya                         |" << endl;
        cout << "|                   [0] Kembali ke menu sebelumnya                 |" << endl;
        cout << "+==================================================================+\n";
        cout << "Masukkan Pilihan : ";
        getline(cin, pilih);

        if (pilih == "1")
        {
            tambah_laporan(head_laporan, warga);
        }
        else if (pilih == "2")
        {
            tampilkan_laporan_warga(*head_laporan, jumlah_laporan(*head_laporan), warga);
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
        }
        else if (pilih == "0")
        {
            return;
        }
        else
        {
            cout << "+==================================================================+\n";
            cout << "|                  \033[1;31mINPUT YANG ANDA MASUKKAN SALAH\033[0m                  |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
        }
    }
}
//fungsi untuk membandingkan untuk diurutkan
node_laporan *SortedMergel(node_laporan *a, node_laporan *b, string attrb, string order);
//prosedur untuk membagi linked-list menjadi 2 bagian
void FrontBackSplitl(node_laporan *source, node_laporan **frontRef, node_laporan **backRef);
//fungsi untuk mengurutkan data menggunakan mergesort
void MergeSortl(node_laporan **headRef, string attrb, string order)
{
    node_laporan *head = *headRef;
    node_laporan *a;
    node_laporan *b;
    if ((head == NULL) || (head->next == NULL))
    {
        return;
    }
    FrontBackSplitl(head, &a, &b);
    MergeSortl(&a, attrb, order);
    MergeSortl(&b, attrb, order);
    *headRef = SortedMergel(a, b, attrb, order);
}
//fungsi untuk membandingkan untuk diurutkan
node_laporan *SortedMergel(node_laporan *a, node_laporan *b, string attrb, string order)
{
    node_laporan *result = NULL;
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
    // buat ganti ascending dan descending dibawah sini ya
    if (attrb == "id" && order == "asc")
    {
        if (stoi(a->id) <= stoi(b->id))
        {
            result = a;
            result->next = SortedMergel(a->next, b, attrb, order);
        }
        else
        {
            result = b;
            result->next = SortedMergel(a, b->next, attrb, order);
        }
    }
    if (attrb == "id" && order == "desc")
    {
        if (stoi(a->id) >= stoi(b->id))
        {
            result = a;
            result->next = SortedMergel(a->next, b, attrb, order);
        }
        else
        {
            result = b;
            result->next = SortedMergel(a, b->next, attrb, order);
        }
    }
    if (attrb == "judul" && order == "asc")
    {
        if (a->judul_laporan <= b->judul_laporan)
        {
            result = a;
            result->next = SortedMergel(a->next, b, attrb, order);
        }
        else
        {
            result = b;
            result->next = SortedMergel(a, b->next, attrb, order);
        }
    }
    if (attrb == "judul" && order == "desc")
    {
        if (a->judul_laporan >= b->judul_laporan)
        {
            result = a;
            result->next = SortedMergel(a->next, b, attrb, order);
        }
        else
        {
            result = b;
            result->next = SortedMergel(a, b->next, attrb, order);
        }
    }
    return (result);
}
//prosedur untuk membagi linked-list menjadi 2 bagian
void FrontBackSplitl(node_laporan *source, node_laporan **frontRef, node_laporan **backRef)
{
    node_laporan *fast;
    node_laporan *slow;
    slow = source;
    fast = source->next;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

void menu_sort_laporan(node_laporan **head_laporan)
{
    string pilih;
    while (true)
    {
        system("cls");
        if (*head_laporan == NULL)
        {
            cout << "+==================================================================+\n";
            cout << "|                             \033[1;32mLAPORAN\033[0m                              |\n";
            cout << "+==================================================================+\n";
            cout << "|                        TIDAK ADA LAPORAN                         |\n";
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            return;
        }
        tampilkan_laporan_admin(*head_laporan, jumlah_laporan(*head_laporan));
        cout << "+==================================================================+\n";
        cout << "|                        \033[1;32mURUTKAN LAPORAN\033[0m                           |\n";
        cout << "+==================================================================+\n";
        cout << "|                   [1] Sorting berdasarkan ID (Ascending)         |" << endl;
        cout << "|                   [2] Sorting berdasarkan ID (Descending)        |" << endl;
        cout << "|                   [3] Sorting berdasarkan Judul (Ascending)      |" << endl;
        cout << "|                   [4] Sorting berdasarkan Judul (Descending)     |" << endl;
        cout << "|                   [0] Kembali ke menu sebelumnya                 |" << endl;
        cout << "+==================================================================+\n";
        cout << "Masukkan Pilihan : ";
        getline(cin, pilih);

        if (pilih == "1")
        {
            MergeSortl(head_laporan, "id", "asc");
            cout << "+==================================================================+\n";
            cout << "|      \033[1;32mLAPORAN BERHASIL DIURUTKAN BERDASARKAN ID (ASCENDING)\033[0m       |\n";
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
        }
        else if (pilih == "2")
        {
            MergeSortl(head_laporan, "id", "desc");
            cout << "+==================================================================+\n";
            cout << "|     \033[1;32mLAPORAN BERHASIL DIURUTKAN BERDASARKAN ID (DESCENDING)\033[0m       |\n";
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
        }
        else if (pilih == "3")
        {
            MergeSortl(head_laporan, "judul", "asc");
            cout << "+==================================================================+\n";
            cout << "|     \033[1;32mLAPORAN BERHASIL DIURUTKAN BERDASARKAN JUDUL (ASCENDING)\033[0m     |\n";
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
        }
        else if (pilih == "4")
        {
            MergeSortl(head_laporan, "judul", "desc");
            cout << "+==================================================================+\n";
            cout << "|     \033[1;32mLAPORAN BERHASIL DIURUTKAN BERDASARKAN JUDUL (DESCENDING)\033[0m    |\n";
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
        }
        else if (pilih == "0")
        {
            return;
        }
        else
        {
            cout << "====================================================================\n";
            cout << "|                  \033[1;31mINPUT YANG ANDA MASUKKAN SALAH\033[0m                  |" << endl;
            cout << "====================================================================\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
        }
    }
}

void found_datal(node_laporan **head_found, node_laporan *found)
{
    node_laporan *nodeBaru = new node_laporan;
    nodeBaru->id = found->id;
    nodeBaru->NIK = found->NIK;
    nodeBaru->nama_lengkap = found->nama_lengkap;
    nodeBaru->judul_laporan = found->judul_laporan;
    nodeBaru->deskripsi_laporan = found->deskripsi_laporan;
    nodeBaru->next = NULL;
    // jika linked list kosong
    if (*head_found == NULL)
    {
        *head_found = nodeBaru;
        return;
    }
    // jika tidak traversal ke node terakhir
    node_laporan *temp = *head_found;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = nodeBaru;
}

// Fungsi untuk mengisi array badChar[] untuk memberikan informasi
// terakhir kemunculan karakter yang tidak cocok
void badCharHeuristicl(string str, int size, int badChar[NO_OF_CHARS])
{
    // Inisialisasi semua nilai di badChar sebagai -1
    for (int i = 0; i < NO_OF_CHARS; i++)
    {
        badChar[i] = -1;
    }
    // Isi nilai aktual dari badChar untuk karakter yang ada dalam str
    for (int i = 0; i < size; i++)
    {
        badChar[(int)str[i]] = i;
    }
}
// Fungsi pencarian string dengan Boyer-Moore Bad Character Heuristic
void searchl(node_laporan *head, string pat, string attrb)
{
    string data;
    node_laporan *head_found = NULL;
    int m = pat.size();
    node_laporan *temp = head;
    while (temp != NULL)
    {
        if (attrb == "judul")
        {
            data = temp->judul_laporan;
        }
        if (attrb == "id")
        {
            data = temp->id;
        }
        transform(pat.begin(), pat.end(), pat.begin(), ::toupper);
        transform(data.begin(), data.end(), data.begin(), ::toupper);
        int n = data.size();
        int badChar[NO_OF_CHARS];
        badCharHeuristic(pat, m, badChar);
        int s = 0; // s adalah shift dari pola sehubungan dengan teks

        while (s <= (n - m))
        {
            int j = m - 1;
            // Kurangi indeks j dari pola sampai karakter dari pola dan teks cocok

            while (j >= 0 && pat[j] == data[s + j])
            {
                j--;
            }
            if (j < 0)
            {
                found_datal(&head_found, temp);
                break;
            }
            else
            {
                // Geser pola sehingga karakter yang tidak cocok dalam pola sesuai dengan karakter terakhir yang sama di teks
                s += max(1, j - badChar[data[s + j]]);
            }
        }
        temp = temp->next;
    }
    tampilkan_laporan_admin(head_found, jumlah_laporan(head_found));
}

void cari_judul(node_laporan *head_laporan)
{
    string input;
    int back;
    while (true)
    {
        system("cls");
        cout << "+==================================================================+\n";
        cout << "|                           \033[1;32mCARI DATA\033[0m                              |\n";
        cout << "+==================================================================+\n";
        cout << "|                 [0] KEMBALI KE MENU SEBELUMNYA                   |\n";
        cout << "+==================================================================+\n";
        cout << "Cari Nama : ";
        fflush(stdin);
        getline(cin, input);
        if (input == "0")
        {
            return;
        }
        if (input.length() == 0)
        {
            cout << "+==================================================================+\n";
            cout << "|                     \033[1;31mINPUT TIDAK BOLEH KOSONG\033[0m                     |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }

        searchl(head_laporan, input, "judul");
        break;
    }
}

void cari_id(node_laporan *head_laporan)
{
    string input;
    int back;
    while (true)
    {
        system("cls");
        cout << "+==================================================================+\n";
        cout << "|                           \033[1;32mCARI DATA\033[0m                              |\n";
        cout << "+==================================================================+\n";
        cout << "|                 [0] KEMBALI KE MENU SEBELUMNYA                   |\n";
        cout << "+==================================================================+\n";
        cout << "Cari NIK : ";
        fflush(stdin);
        getline(cin, input);
        if (input == "0")
        {
            return;
        }
        if (input.length() == 0)
        {
            cout << "+==================================================================+\n";
            cout << "|                     \033[1;31mINPUT TIDAK BOLEH KOSONG\033[0m                     |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }
        if (cek_int(input) == false)
        {
            cout << "+==================================================================+\n";
            cout << "|                     \033[1;31mINPUT HARUS BERUPA ANGKA\033[0m                     |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            continue;
        }
        searchl(head_laporan, input, "id");
        break;
    }
}

void menu_search_data(node_laporan *head_laporan)
{
    string pilih;
    while (true)
    {
        system("cls");
        if (head_laporan == NULL)
        {
            cout << "+==================================================================+\n";
            cout << "|                             \033[1;32mLAPORAN\033[0m                              |\n";
            cout << "+==================================================================+\n";
            cout << "|                        TIDAK ADA LAPORAN                         |\n";
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            return;
        }
        cout << endl;
        cout << "+==================================================================+\n";
        cout << "|                         \033[1;32mCARI LAPORAN\033[0m                             |\n";
        cout << "+==================================================================+\n";
        cout << "|                   [1] Cari berdasarkan ID Laporan                |" << endl;
        cout << "|                   [2] Cari berdasarkan Judul Laporan             |" << endl;
        cout << "|                   [0] Kembali ke menu sebelumnya                 |" << endl;
        cout << "+==================================================================+\n";
        cout << "Masukkan Pilihan : ";
        getline(cin, pilih);

        if (pilih == "1")
        {
            cari_id(head_laporan);
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
        }
        else if (pilih == "2")
        {
            cari_judul(head_laporan);
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
        }
        else if (pilih == "0")
        {
            return;
        }
        else
        {
            cout << "====================================================================\n";
            cout << "|                  \033[1;31mINPUT YANG ANDA MASUKKAN SALAH\033[0m                  |" << endl;
            cout << "====================================================================\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
        }
    }
}

void menu_laporan_admin(node_laporan **head_laporan)
{
    string pilih;
    while (true)
    {
        system("cls");
        tampilkan_laporan_admin(*head_laporan, jumlah_laporan(*head_laporan));
        cout << "+==================================================================+\n";
        cout << "|                        \033[1;32mMENU LAPORAN ADMIN\033[0m                        |\n";
        cout << "+==================================================================+\n";
        cout << "|                   [1] Urutkan Laporan                            |" << endl;
        cout << "|                   [2] Cari Laporan                               |" << endl;
        cout << "|                   [0] Kembali ke menu sebelumnya                 |" << endl;
        cout << "+==================================================================+\n";
        cout << "Masukkan Pilihan : ";
        getline(cin, pilih);

        if (pilih == "1")
        {
            menu_sort_laporan(head_laporan);
        }
        else if (pilih == "2")
        {
            menu_search_data(*head_laporan);
        }
        else if (pilih == "0")
        {
            return;
        }
        else
        {
            cout << "+==================================================================+\n";
            cout << "|                  \033[1;31mINPUT YANG ANDA MASUKKAN SALAH\033[0m                  |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
        }
    }
}
void menu_data_warga(node **head)
{
    {
        string pilih;
        while (true)
        {
            system("cls");
            cout << "+==================================================================+\n";
            cout << "|                            \033[1;32mDATA WARGA\033[0m                            |\n";
            cout << "+==================================================================+\n";
            cout << "|                   [1] Tambah Data                                |" << endl;
            cout << "|                   [2] Tampilkan Data                             |" << endl;
            cout << "|                   [3] Ubah Data                                  |" << endl;
            cout << "|                   [4] Hapus Data                                 |" << endl;
            cout << "|                   [5] Urutkan Data                               |" << endl;
            cout << "|                   [6] Cari Data                                  |" << endl;
            cout << "|                   [0] Kembali ke menu sebelumnya                 |" << endl;
            cout << "+==================================================================+\n";
            cout << "Masukkan Pilihan : ";
            getline(cin, pilih);

            if (pilih == "1")
            {
                menu_tambah_data(head);
            }
            else if (pilih == "2")
            {
                tampilkan_data(*head, jumlah_data(*head));
                cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
                getche();
            }
            else if (pilih == "3")
            {
                menu_ubah_data(head);
            }
            else if (pilih == "4")
            {
                menu_hapus_data(head);
            }
            else if (pilih == "5")
            {
                menu_sort_data(head);
            }
            else if (pilih == "6")
            {
                menu_search_data(*head);
            }
            else if (pilih == "0")
            {
                return;
            }
            else
            {
                cout << "+==================================================================+\n";
                cout << "|                  \033[1;31mINPUT YANG ANDA MASUKKAN SALAH\033[0m                  |" << endl;
                cout << "+==================================================================+\n";
                cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
                getche();
            }
        }
    }
}

void menu_warga(node **head, node_laporan **head_laporan, node *warga)
{
    string pilih;
    while (true)
    {
        system("cls");
        cout << "+==================================================================+\n";
        cout << "|                            \033[1;32mMENU WARGA\033[0m                            |\n";
        cout << "+==================================================================+\n";
        cout << "|                   [1] Lihat Data Saya                            |" << endl;
        cout << "|                   [2] Ubah Data Saya                             |" << endl;
        cout << "|                   [3] Lihat Data Warga RT                        |" << endl;
        cout << "|                   [4] Menu Laporan                               |" << endl;
        cout << "|                   [0] Kembali ke menu sebelumnya                 |" << endl;
        cout << "+==================================================================+\n";
        cout << "Masukkan Pilihan : ";
        getline(cin, pilih);

        if (pilih == "1")
        {
            tampilkan_data_ke(warga, -1);
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
        }
        else if (pilih == "2")
        {
            ubah_data(head, warga, -1);
        }
        else if (pilih == "3")
        {
            tampilkan_data(*head, jumlah_data(*head));
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
        }
        else if (pilih == "4")
        {
            menu_laporan_warga(head_laporan, warga);
        }
        else if (pilih == "0")
        {
            return;
        }
        else
        {
            cout << "+==================================================================+\n";
            cout << "|                  \033[1;31mINPUT YANG ANDA MASUKKAN SALAH\033[0m                  |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
        }
    }
}
void histori_login(node **head_histori, node *warga)
{
    node *nodeBaru = new node;
    nodeBaru->NIK = warga->NIK;
    nodeBaru->nama_lengkap = warga->nama_lengkap;
    nodeBaru->jenis_kelamin = warga->jenis_kelamin;
    nodeBaru->nama_ayah = warga->nama_ayah;
    nodeBaru->nama_ibu = warga->nama_ibu;
    nodeBaru->password = warga->password;
    nodeBaru->next = NULL;
    // jika linked list kosong
    if (*head_histori == NULL)
    {
        *head_histori = nodeBaru;
        return;
    }
    // jika tidak
    // traversal ke node terakhir
    node *temp = *head_histori;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = nodeBaru;
    if(jumlah_data(*head_histori)==6){
        *head_histori = (*head_histori)->next;
    }
}
bool login_admin()
{
    string nama = "admin";
    string password = "admin";
    int percobaan_ke = 1;
    while (true)
    {
        system("CLS");
        string input_nama = "";
        string input_password = "";
        cout << "+==================================================================+\n";
        cout << "|                            \033[1;32mLOGIN ADMIN\033[0m                           |\n";
        cout << "+==================================================================+\n";
        cout << "|                  Username :                                      |\n";
        cout << "|                  Password :                                      |\n";
        cout << "+==================================================================+\n";
        cout << "Masukkan Username : ";
        fflush(stdin);
        getline(cin, input_nama);
        system("CLS");
        cout << "+==================================================================+\n";
        cout << "|                            \033[1;32mLOGIN ADMIN\033[0m                           |\n";
        cout << "+==================================================================+\n";
        cout << "|                  Username : " << input_nama << setw(39 - input_nama.length()) << "|\n";
        cout << "|                  Password :                                      |\n";
        cout << "+==================================================================+\n";
        cout << "Masukkan Password : ";
        fflush(stdin);
        getline(cin, input_password);
        if (input_nama == nama && input_password == password)
        {
            system("CLS");
            cout << "+==================================================================+\n";
            cout << "|                            \033[1;32mLOGIN ADMIN\033[0m                           |\n";
            cout << "+==================================================================+\n";
            cout << "|                  Username : " << input_nama << setw(39 - input_nama.length()) << "|\n";
            cout << "|                  Password : " << setfill('*') << setw(input_password.length() + 1) << " ";
            cout << setfill(' ') << setw(38 - input_password.length()) << "|\n";
            cout << "+==================================================================+\n";
            cout << "|                     \033[1;32mANDA TELAH BERHASIL LOGIN\033[0m                    |\n";
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
            return true;
        }
        else if (percobaan_ke == 3)
        {
            system("CLS");
            cout << "+==================================================================+\n";
            cout << "|                            \033[1;32mLOGIN ADMIN\033[0m                           |\n";
            cout << "+==================================================================+\n";
            cout << "|                 \033[1;31mANDA SUDAH SALAH SEBANYAK " << percobaan_ke << " KALI\033[0m                 |" << endl;
            cout << "+==================================================================+\n";
            cout << "                 \033[1;41m...Otomatis keluar dari program...\033[0m";
            exit(0);
        }
        else
        {
            percobaan_ke += 1;
            while (true)
            {
                string input;
                system("CLS");
                cout << "+==================================================================+\n";
                cout << "|                            \033[1;32mLOGIN ADMIN\033[0m                           |\n";
                cout << "+==================================================================+\n";
                cout << "|                  Username : " << input_nama << setw(39 - input_nama.length()) << "|\n";
                cout << "|                  Password : " << setfill('*') << setw(input_password.length() + 1) << " ";
                cout << setfill(' ') << setw(38 - input_password.length()) << "|\n";
                cout << "+==================================================================+\n";
                cout << "|                     \033[1;31mUSERNAME/PASSWORD SALAH\033[0m                      |" << endl;
                cout << "|                 \033[1;31mANDA SUDAH SELAH SEBANYAK " << percobaan_ke - 1 << " KALI\033[0m                 |" << endl;
                cout << "+==================================================================+\n";
                cout << "|                   [0] Kembali ke menu sebelumnya                 |" << endl;
                cout << "|                   [1] Lanjutkan Login Admin                      |" << endl;
                cout << "+==================================================================+\n";
                cout << "Masukkan Pilihan : ";
                fflush(stdin);
                getline(cin, input);

                if (input == "0")
                {
                    return false;
                }
                else if (input == "1")
                {
                    break;
                }
                else
                {
                    cout << "+==================================================================+\n";
                    cout << "|                  \033[1;31mINPUT YANG ANDA MASUKKAN SALAH\033[0m                  |" << endl;
                    cout << "+==================================================================+\n";
                    cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
                    getche();
                }
            }
        }
    }
}

node *login_warga(node **head, node_laporan **head_laporan, node **head_histori)
{
    system("CLS");
    int percobaan_ke = 1;
    bool login;
    node *temp;
    while (true)
    {
        system("CLS");
        string input_NIK;
        string input_password;
        cout << "+==================================================================+\n";
        cout << "|                           \033[1;32mLOGIN WARGA\033[0m                            |\n";
        cout << "+==================================================================+\n";
        cout << "|                  NIK      :                                      |\n";
        cout << "|                  Password :                                      |\n";
        cout << "+==================================================================+\n";
        cout << "Masukkan Username : ";
        fflush(stdin);
        getline(cin, input_NIK);
        system("CLS");
        cout << "+==================================================================+\n";
        cout << "|                           \033[1;32mLOGIN WARGA\033[0m                            |\n";
        cout << "+==================================================================+\n";
        cout << "|                  NIK      : " << input_NIK << setw(39 - input_NIK.length()) << "|\n";
        cout << "|                  Password :                                      |\n";
        cout << "+==================================================================+\n";
        cout << "Masukkan Password : ";
        fflush(stdin);
        getline(cin, input_password);
        temp = *head;
        for (int x = 1; x <= jumlah_data(*head); x++)
        {
            if (input_NIK == temp->NIK && input_password == temp->password)
            {
                system("CLS");
                cout << "+==================================================================+\n";
                cout << "|                           \033[1;32mLOGIN WARGA\033[0m                            |\n";
                cout << "+==================================================================+\n";
                cout << "|                  Username : " << input_NIK << setw(39 - input_NIK.length()) << "|\n";
                cout << "|                  Password : " << setfill('*') << setw(input_password.length() + 1) << " ";
                cout << setfill(' ') << setw(38 - input_password.length()) << "|\n";
                cout << "+==================================================================+\n";
                cout << "|                     \033[1;32mANDA TELAH BERHASIL LOGIN\033[0m                    |\n";
                cout << "+==================================================================+\n";
                cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
                getche();
                histori_login(head_histori, temp);
                update_file_histori(head_histori);
                return temp;
            }
            temp = temp->next;
        }
        if (percobaan_ke == 3)
        {
            system("CLS");
            cout << "+==================================================================+\n";
            cout << "|                           \033[1;32mLOGIN WARGA\033[0m                            |\n";
            cout << "+==================================================================+\n";
            cout << "|                 \033[1;31mANDA SUDAH SALAH SEBANYAK " << percobaan_ke << " KALI\033[0m                 |" << endl;
            cout << "+==================================================================+\n";
            cout << "                 \033[1;41m...Otomatis keluar dari program...\033[0m";
            exit(0);
        }
        else
        {
            percobaan_ke += 1;
            while (true)
            {
                string input;
                system("CLS");
                cout << "+==================================================================+\n";
                cout << "|                           \033[1;32mLOGIN WARGA\033[0m                            |\n";
                cout << "+==================================================================+\n";
                cout << "|                       \033[1;31mNIK/PASSWORD SALAH\033[0m                         |" << endl;
                cout << "|                 \033[1;31mANDA SUDAH SELAH SEBANYAK " << percobaan_ke - 1 << " KALI\033[0m                 |" << endl;
                cout << "+==================================================================+\n";
                cout << "|                   [0] Kembali ke menu sebelumnya                 |" << endl;
                cout << "|                   [1] Lanjutkan Login Warga                      |" << endl;
                cout << "+==================================================================+\n";
                cout << "Masukkan Pilihan : ";
                fflush(stdin);
                getline(cin, input);
                if (input == "0")
                {
                    return NULL;
                }
                else if (input == "1")
                {
                    break;
                }
                else
                {
                    cout << "+==================================================================+\n";
                    cout << "|                  \033[1;31mINPUT YANG ANDA MASUKKAN SALAH\033[0m                  |" << endl;
                    cout << "+==================================================================+\n";
                    cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
                    getche();
                }
            }
        }
    }
}

void menu_admin(node **head, node_laporan **head_laporan,node**head_histori)
{
    {
        string pilih;
        while (true)
        {
            system("cls");
            cout << "+==================================================================+\n";
            cout << "|                             \033[1;32mMENU ADMIN\033[0m                           |\n";
            cout << "+==================================================================+\n";
            cout << "|                   [1] Data Warga                                 |" << endl;
            cout << "|                   [2] Lihat Laporan Warga                        |" << endl;
            cout << "|                   [3] Histori 10 Login Terakhir                  |" << endl;
            cout << "|                   [0] Kembali ke menu sebelumnya                 |" << endl;
            cout << "+==================================================================+\n";
            cout << "Masukkan Pilihan : ";
            getline(cin, pilih);

            if (pilih == "1")
            {
                menu_data_warga(head);
            }
            else if (pilih == "2")
            {
                menu_laporan_admin(head_laporan);
            }
            else if (pilih == "3")
            {
                tampilkan_histori(*head_histori,jumlah_data(*head_histori));
                                cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
                getche();

            }
            else if (pilih == "0")
            {
                return;
            }
            else
            {
                cout << "+==================================================================+\n";
                cout << "|                  \033[1;31mINPUT YANG ANDA MASUKKAN SALAH\033[0m                  |" << endl;
                cout << "+==================================================================+\n";
                cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
                getche();
            }
        }
    }
}

int main()
{
    node *HEAD = NULL;
    node_laporan *head_laporan = NULL;
    node *head_histori = NULL;
    read_file_warga(&HEAD);
    read_file_laporan(&head_laporan);
    read_file_histori(&head_histori);
    string pilih;
    bool login = false;
    node *warga = NULL;
    while (true)
    {
        system("cls");
        cout << "+==================================================================+\n";
        cout << "|                        \033[1;32mPENDATAAN WARGA RT\033[0m                        |\n";
        cout << "+==================================================================+\n";
        cout << "|                   [1] Login Sebagai Admin                        |" << endl;
        cout << "|                   [2] Login Sebagai Warga                        |" << endl;
        cout << "|                   [0] Keluar dari program                        |" << endl;
        cout << "+==================================================================+\n";
        cout << "Masukkan Pilihan : ";
        getline(cin, pilih);

        if (pilih == "1")
        {
            login = login_admin();
            if (login == false)
            {
                continue;
            }
            menu_admin(&HEAD, &head_laporan,&head_histori);
        }
        else if (pilih == "2")
        {
            warga = login_warga(&HEAD, &head_laporan, &head_histori);
            if (warga == NULL)
            {
                continue;
            }
            menu_warga(&HEAD, &head_laporan, warga);
        }
        else if (pilih == "0")
        {
            exit(0);
        }
        else
        {
            cout << "+==================================================================+\n";
            cout << "|                  \033[1;31mINPUT YANG ANDA MASUKKAN SALAH\033[0m                  |" << endl;
            cout << "+==================================================================+\n";
            cout << "        \033[1;42m...Tekan apa saja pada keyboard untuk Melanjutkan...\033[0m";
            getche();
        }
    }
    return 0;
}
