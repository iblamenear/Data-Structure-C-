#include <iostream>
#include <string>
using namespace std;
#define MAX 30

class Pakaian
{
    public:
    string nama;
    string ukuran;
};

class Stack
{
    private:
    int top;
    Pakaian arr[MAX];

    public:
    Stack()
    {
        top = -1;
    }

    bool isFull()
    {
        return (top==MAX -1);
    }

    bool isEmpty()
    {
        return (top==-1);
    }

    void push(Pakaian data)
    {
        if (isFull())
        {
            cout<<"Stack Penuh!"<<endl;
        }
        else
        {
            arr[++top] = data;
            cout<<"Pushed "<<data.nama<<" (Ukuran: "<<data.ukuran<<") ke Stack"<<endl;
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            cout<<"Stack Kosong!"<<endl;
        }
        else
        {
            cout<<"Popped "<<arr[top].nama<<" (Ukuran: "<<arr[top].ukuran<<") dari Stack"<<endl;
            top--;
        }
    }

    void clear()
    {
        top = -1;
        cout<<"Stack Telah Dibersihkan"<<endl;
    }

    void cetak()
    {
        if (isEmpty())
        {
            cout<<"Stack Kosong!"<<endl;
        }
        else
        {
            cout<<"Isi Stack: "<<endl;
            for (int i = 0;i<=top;i++)
            {
                cout<<"- "<<arr[i].nama<<" (Ukuran: "<<arr[i].ukuran<<")"<<endl;
            }
            cout<<endl;
        }
    }
};


int main()
{
    Stack stack;
    Pakaian pakaian;
    int pilihan;

    do
    {
        cout<<"1. Push Stack"<<endl;
        cout<<"2. Pop Stack"<<endl;
        cout<<"3. Tampilkan isi Stack"<<endl;
        cout<<"4. Clear Stack"<<endl;
        cout<<"5. Keluar"<<endl;
        cout<<"Masukkan Pilihan Anda: ";cin>>pilihan;
        cin.ignore();
        
        switch(pilihan)
        {
            case 1:
            cout<<"Masukkan Nama Pakaian: ";getline(cin, pakaian.nama);
            cout<<"Masukkan Ukuran Pakaian: ";getline(cin, pakaian.ukuran);
            stack.push(pakaian);
            break;
            case 2:
            stack.pop();
            break;
            case 3:
            stack.cetak();
            break;
            case 4:
            stack.clear();
            break;
            case 5:
            cout<<"Program Selesai"<<endl;
            default:
            cout<<"Pilihan tidak valid!"<<endl;
        }
    }
    while(pilihan!=5);
    return 0;
}