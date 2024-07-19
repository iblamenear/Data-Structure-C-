#include <iostream>
#include <string>
using namespace std;

class Node
{
    public:
    int data;
    Node* prev;
    Node* next;
};

class DoubleLinkedList
{
    private:
    Node* head;

    public:
    DoubleLinkedList()
    {
        head = nullptr;
    }

    void insertDepan(int data)
    {
        Node* newNode = new Node();
        newNode->data = data;

        if (head==nullptr)
        {
            head = newNode;
            newNode->prev = nullptr;
            newNode->next = nullptr;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            newNode->prev = nullptr;
            head = newNode;
        }
    }

    void insertBelakang(int data)
    {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;

        if (head==nullptr)
        {
            newNode->prev = nullptr;
            head = newNode;
            return;
        }

        Node* last = head;
        while (last->next!=nullptr)
        {
            last = last->next;
        }
        last->next = newNode;
        newNode->prev = last;
    }

    void hapusDepan()
    {
        if (head==nullptr)
        {
            cout<<"List kosong, tidak ada yang dapat dihapus"<<endl;
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head!=nullptr)
        {
            head->prev = nullptr;
        }
        delete temp;
        cout<<"Elemen di depan telah dihapus"<<endl;
    }

    void hapusBelakang()
    {
        if (head==nullptr)
        {
            cout<<"List kosong, tidak ada yang dapat dihapus"<<endl;
            return;
        }

        Node* temp = head;

        if(head->next = nullptr)
        {
            head = nullptr;
        }
        else
        {
            while(head->next!=nullptr)
            {
                temp = temp->next;
            }
            temp->prev->next =nullptr;
        }
        delete temp;
        cout<<"Elemen di belakang telah dihapus"<<endl;
    }

    void display()
    {
        Node* temp = head;
        while(temp!=nullptr)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main()
{
    DoubleLinkedList dll;
    int data, pilihan;

    do
    {
        cout<<"1. Masukkan data di depan"<<endl;
        cout<<"2. Masukkan data di Belakang"<<endl;
        cout<<"3. Hapus data di depan"<<endl;
        cout<<"4. Hapus data di belakang"<<endl;
        cout<<"5. Tampilkan data"<<endl;
        cout<<"6. Keluar"<<endl;
        cout<<"Masukkan pilihan anda: ";cin>>pilihan;

        if (pilihan==1 || pilihan==2)
        {
            cout<<"Masukkan data: ";cin>>data;
        }

        switch(pilihan)
        {
            case 1:
            dll.insertDepan(data);
            break;
            case 2:
            dll.insertBelakang(data);
            break;
            case 3:
            dll.hapusDepan();
            break;
            case 4:
            dll.hapusBelakang();
            break;
            case 5:
            dll.display();
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