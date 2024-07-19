#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Karyawan
{
    public:
    string nama;
    int gaji;
    double rate;
    Karyawan *kiri, *kanan;
};

Karyawan* newNode(string nama, int gaji)
{
    Karyawan* node = new Karyawan();
    node->nama = nama;
    node->gaji = gaji;
    node->rate = 0.0;
    node->kiri = node->kanan = NULL;
    return node;
};

Karyawan* insert(Karyawan* root, string nama, int gaji)
{
    if (root==NULL)
    {
        return newNode(nama, gaji);
    }

    if (gaji<root->gaji)
    {
        root->kiri = insert(root->kiri, nama, gaji);
    }
    else if (gaji>root->gaji)
    {
        root->kanan = insert(root->kanan, nama, gaji);
    }
    return root;
};

void hitungRate(Karyawan* node)
{
    if (node==NULL) return;

    node->rate = node->gaji/1000000.0;

    hitungRate(node->kiri);
    hitungRate(node->kanan);
}

int main()
{
    Karyawan* root = NULL;
    int jumlahKaryawan;

    cout<<"Masukkan Jumlah Karyawan: ";cin>>jumlahKaryawan;

    for (int i = 0; i<jumlahKaryawan; i++)
    {
        string nama;
        int gaji;
        cout<<"\nKaryawan #"<<i+1<<": \n";
        cout<<"Nama: ";cin>>nama;
        cout<<"Gaji: ";cin>>gaji;
        root = insert(root, nama, gaji);
    }
    hitungRate(root);
    cout<<"\nData Karyawan dan Rate Gaji: \n ";
    return 0;
}