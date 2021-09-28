/*
Nama Anggota :
- Nadine Annisa Heartman    [ 140810190004 ]
- Ruth Rebecca Ovelin       [ 140810190054 ]
- Yuela Thahira             [ 140810190064 ]
Kelas        : A
Deskripsi    : Program Enkripsi dan Dekripsi Hill Cipher */

#include <iostream>
#include <math.h>
using namespace std;

float en[3][1], de[3][1], a[3][3], b[3][3], msg[3][1], m[3][3], plain[3][3], cipher[3][3], jumlah, kunci[3][3], n[3][3];
void getKunciMatrix() // Fungsi untuk menginput kunci matrix ukuran 3 x 3 dan plainteks berjumlah 3 huruf
{
    int i, j;
    char mes[3];
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+";
    cout << "\n|                 INPUT KUNCI MATRIX                  |\n";
    cout << "-------------------------------------------------------\n";
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
        {
            cout << "  Input Matrix Ke - [ " << i + 1 << ", " << j + 1 << " ]        : ";
            cin >> a[i][j];
            m[i][j] = a[i][j];
        }
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+";
    cout << "\n  Input Plainteks                   : ";
    cin >> mes;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+";
    for (i = 0; i < 3; i++)
        msg[i][0] = mes[i] - 65;
}

void enkripsi() // Fungsi untuk melakukan enkripsi
{
    int i, j, k;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 1; j++)
            for (k = 0; k < 3; k++)
                en[i][j] = en[i][j] + a[i][k] * msg[k][j];
    cout << "\n|                     ENKRIPSI                        |";
    cout << "\n-------------------------------------------------------";
    cout << "\n  Jadi, Cipherteks nya adalah       : "; // Hasil output berupa cipherteks
    for (i = 0; i < 3; i++)
        cout << (char(fmod(en[i][0], 26) + 65));
}

void inversematrixK() // Fungsi untuk menginvers kunci matrix
{
    int i, j, k;
    float p, q;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
        {
            if (i == j)
                b[i][j] = 1;
            else
                b[i][j] = 0;
        }

    for (k = 0; k < 3; k++)
    {
        for (i = 0; i < 3; i++)
        {
            p = m[i][k];
            q = m[k][k];
            for (j = 0; j < 3; j++)
            {
                if (i != k)
                {
                    m[i][j] = m[i][j] * q - p * m[k][j];
                    b[i][j] = b[i][j] * q - p * b[k][j];
                }
            }
        }
    }

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            b[i][j] = b[i][j] / m[i][i];
    cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+";
    cout << "\n  Hasil Inverse Kunci Matrix        :\n\n";
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            cout << "  " << b[i][j] << "          ";
        cout << "\n";
    }
}

void dekripsi() // Fungsi untuk melakukan dekripsi pada cipherteks
{
    int i, j, k;
    inversematrixK();
    for (i = 0; i < 3; i++)
        for (j = 0; j < 1; j++)
            for (k = 0; k < 3; k++)
                de[i][j] = de[i][j] + b[i][k] * en[k][j];
    cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+";
    cout << "\n|                     DEKRIPSI                        |";
    cout << "\n-------------------------------------------------------";
    cout << "\n  Jadi, Plainteks nya adalah        : "; // Hasil output berupa plainteks
    for (i = 0; i < 3; i++)
        cout << (char)(fmod(de[i][0], 26) + 65);
}

void getMatrix() // Fungsi untuk menginput matrix plainteks dan matriks cipherteks masing - masing berukuran 3 x 3
{
    char plain[3][3], cipher[3][3];
    int i, j;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+";
    cout << "\n|          PROGRAM MENCARI KUNCI K HILL CIPHER        |\n";
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
    cout << "|               INPUT MATRIX PLAINTEKS                |\n";
    cout << "-------------------------------------------------------\n";

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            cout << "  Input Plainteks Ke - [" << i + 1 << ", " << j + 1 << "]       : ";
            cin >> plain[i][j];
            m[i][j] = plain[i][j] - 65;
        }
    }

    cout << "-------------------------------------------------------\n";
    cout << "|               INPUT MATRIX CIPHERTEKS               |\n";
    cout << "-------------------------------------------------------\n";
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            cout << "  Input Cipherteks Ke - [" << i + 1 << ", " << j + 1 << "]      : ";
            cin >> cipher[i][j];
            n[i][j] = cipher[i][j] - 65;
        }
    }
}

void inversematrixP() // Fungsi untuk mencari invers matrix plainteks
{
    int i, j, k;
    float p, q;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
        {
            if (i == j)
                b[i][j] = 1;
            else
                b[i][j] = 0;
        }
    for (k = 0; k < 3; k++)
    {
        for (i = 0; i < 3; i++)
        {
            p = m[i][k];
            q = m[k][k];
            for (j = 0; j < 3; j++)
            {
                if (i != k)
                {
                    m[i][j] = m[i][j] * q - p * m[k][j];
                    b[i][j] = b[i][j] * q - p * b[k][j];
                }
            }
        }
    }
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            b[i][j] = b[i][j] / m[i][i];
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+";
    cout << "\n  Hasil Invers Matrix Plainteks     :\n\n";
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            cout << "  " << b[i][j] << "          ";
        cout << "\n";
    }
}

void cariK() // Fungsi untuk mencari kunci matrix berukuran 3 x 3
{
    int i, j, k;
    inversematrixP();
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 3; k++)
            {
                jumlah = jumlah + n[i][k] * b[k][j];
            }
            kunci[i][j] = jumlah;
            jumlah = 0;
        }
    }

    cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+";
    cout << "\n  Nilai Matrix Kunci K              :\n\n";
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            cout << "  " << kunci[i][j] << "          ";
        }
        cout << endl;
    }
}

int main() // Fungsi untuk menjalankan program
{
    menu:
    int pilih;
    cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
    cout << "|                 PROGRAM HILL CIPHER                 |\n";
    cout << "-------------------------------------------------------\n";
    cout << "|               1. Enkripsi dan Dekripsi              |\n";
    cout << "|               2. Mencari Kunci K                    |\n";
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
    cout << "  Input Pilihan                     : ";
    cin >> pilih;

    switch (pilih)
    {
    case 1:
        getKunciMatrix();
        enkripsi();
        dekripsi();
        goto menu;

    case 2:
        getMatrix();
        cariK();
        goto menu;

    default:
        cout << "-------------------------------------------------------\n";
        cout << "         Input Salah! COBA LAGI YOOOOOKKK\n";
        cout << "-------------------------------------------------------\n";
        goto menu;
    }
    cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
    
}