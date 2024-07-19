#include <iostream>
#include <string>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
};

class LinkedList
{
    private:
    Node* head;

    public:
    LinkedList() : head(nullptr){}

    void tambahDepan(int data)
    {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    void tambahBelakang(int data)
    {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;

        if (head==nullptr)
        {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next !=nullptr)
        {
            temp = temp->next;
        }
        temp->next=newNode;
    }

    void hapusDepan()
    {
        if (head == nullptr)
        {
            return;
        }

        Node* temp = head;
        temp = head->next;
        delete temp;
    }

    void hapusBelakang()
    {
        if (head==nullptr)
        {
            return;
        }

        if (head->next = nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    void cetak()
    {
        Node* temp = head;
        while (temp!=nullptr)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main()
{
    LinkedList list;
    int data, pilihan;

    do
    {
    cout<<"1. Tambah data di depan"<<endl;
    cout<<"2. Tambah data di belakang"<<endl;
    cout<<"3. Hapus data di depan"<<endl;
    cout<<"4. Hapus data di belakang"<<endl;
    cout<<"5. tampilkan data"<<endl;
    cout<<"6. Keluar"<<endl;
    cout<<"Masukkan pilihan anda:";cin>>pilihan;

    if (pilihan==1 || pilihan==2)
    {
        cout<<"Masukkan data: ";cin>>data;
    }

    switch (pilihan)
    {
        case 1:
        list.tambahDepan(data);
        break;
        case 2:
        list.tambahBelakang(data);
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
        cout<<"Program Selesai"<<endl;
        break;
        default:
        cout<<"Pilihan tidak valid!"<<endl;
    }
    }
    while(pilihan!=6);
return 0;
}