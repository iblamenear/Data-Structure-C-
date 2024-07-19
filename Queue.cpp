#include <iostream>
#include <queue>
using namespace std;

class Pelanggan
{
    public:
    string nama;
    int waktuDatang;
};

void insert(queue<Pelanggan>& antrian)
{
    Pelanggan pelangganBaru;
    cout<<"Masukkan nama pelanggan: ";getline(cin, pelangganBaru.nama);
    cout<<"Masukkan waktu kedatangan: ";cin>>pelangganBaru.waktuDatang;
    cin.ignore();

    antrian.push(pelangganBaru);
    cout<<pelangganBaru.nama<<" masuk antrian. \n";
}

void hapus(queue<Pelanggan>& antrian)
{
    if (antrian.empty())
    {
        cout<<"Antrian kosong. \n";
        return;
    }
    Pelanggan pelangganKeluar = antrian.front();
    antrian.pop();
    cout<<pelangganKeluar.nama<<" keluar antrian. \n";
}

void cetak(const queue<Pelanggan>& antrian)
{
    queue<Pelanggan> tempQueue = antrian;
    if (tempQueue.empty())
    {
        cout<<"Antrian kosong. \n";
        return;
    }
    cout<<"Isi Antrian: \n";
    while(!tempQueue.empty())
    {
        Pelanggan pelanggan = tempQueue.front();
        cout<<"- "<<pelanggan.nama<<" (waktu kedatangan: Pukul "<<pelanggan.waktuDatang<<")\n";
        tempQueue.pop();
    }
}


int main()
{
    queue<Pelanggan> antrianMinimarket;
    int pilihan;
    
    do
    {
        cout<<"1. Tambah Pelanggan"<<endl;
        cout<<"2. Layani Pelanggan"<<endl;
        cout<<"3. Cetak Antrian"<<endl;
        cout<<"4. Keluar"<<endl;
        cout<<"Pilihan Anda: ";cin>>pilihan;
        cin.ignore();

        switch (pilihan)
        {
            case 1:
            insert(antrianMinimarket);
            break;
            case 2:
            hapus(antrianMinimarket);
            break;
            case 3:
            cetak(antrianMinimarket);
            break;
            case 4:
            cout<<"Program Selesai"<<endl;
            break;
            default:
            cout<<"Pilihan tidak valid!"<<endl;
        }
    }
    while(pilihan!=4);
    return 0;
}