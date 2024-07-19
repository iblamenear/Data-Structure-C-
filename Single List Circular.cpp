#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

class ListCircular
{
    private:
    Node* head;

    public:
    ListCircular()
    {
        head = nullptr;
    }

    void insertDepan(int data)
    {
        Node* newNode = new Node;
        newNode->data = data;

        if(head==nullptr)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            Node* temp = head;
            while(temp->next!=head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
        cout<<"Data "<<data<<" berhasil ditambahkan di depan gerbong"<<endl;
    }

    void insertBelakang(int data)
    {
        Node* newNode = new Node;
        newNode->data = data;

        if (head==nullptr)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            Node* temp = head;
            while (temp->next!=head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
        cout<<"Data "<<data<<" berhasil ditambahkan di belakang gerbong"<<endl;
    }

    void hapusDepan()
    {
        if (head==nullptr)
        {
            cout<<"Gerbong kosong, tidak ada yang bisa dihapus"<<endl;
            return;
        }

        Node* temp = head;
        while(temp->next = head)
        {
            temp = temp->next;
        }

        if(temp==head)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            temp->next = head->next;
            delete head;
            head = temp->next;
        }
        cout<<"Data di depan berhasil dihapus"<<endl;
    }

    void hapusBelakang()
    {
        if (head==nullptr)
        {
            cout<<"Gerbong kosong, tidak ada yang bisa dihapus"<<endl;
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;
        while (temp->next!=head)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp ==head)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            prev->next = head;
            delete temp;
        }
        cout<<"Data di belakang berhasil dihapus"<<endl;
    }

    void cetak()
    {
        if (head==nullptr)
        {
            cout<<"Gerbong kosong"<<endl;
            return;
        }

        Node* temp = head;
        do
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        while(temp!=head);
        cout<<endl;
    }
};

int main()
{
    ListCircular list;
    int data, pilihan;
    do
    {
        cout<<"1. Masukkan data di depan"<<endl;
        cout<<"2. Masukkan data di belakang"<<endl;
        cout<<"3. Hapus data di depan"<<endl;
        cout<<"4. Hapus data di depan"<<endl;
        cout<<"5. Tampilkan data"<<endl;
        cout<<"6. Keluar"<<endl;

        if (pilihan==1 || pilihan==2)
        {
            cout<<"Masukkan data: ";cin>>data;
        }

        switch (pilihan)
        {
            case 1:
            list.insertDepan(data);
            break;
            case 2:
            list.insertBelakang(data);
            break;
            case 3:
            list.hapusDepan();
            break;
            case 4:
            list.hapusBelakang();
            break;
            case 5:
            list.cetak();
            break;
            case 6:
            cout<<"Program selesai"<<endl;
            default:
            cout<<"Pilihan tidak valid!"<<endl;
        }
    }
    while(pilihan!=6);
    return 0;
}