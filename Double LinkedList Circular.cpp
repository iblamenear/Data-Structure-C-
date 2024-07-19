#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* prev;
};

class DoubleLinkedListCircular
{
    private:
    Node* head;

    public:
    DoubleLinkedListCircular() : head(nullptr){}

    void insertDepan(int data)
    {
        Node* newNode = new Node{data, nullptr, nullptr};
        if(!head)
        {
            head = newNode;
            newNode->prev = newNode;
            newNode->next = newNode;
        }
        else
        {
            newNode->next = head;
            newNode->prev = head->prev;
            head->prev->next = newNode;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertBelakang(int data)
    {
        if(!head)
        {
            insertDepan(data);
        }
        else
        {
            Node* newNode = new Node{data, nullptr, nullptr};
            newNode->next = head;
            newNode->prev = head->prev;
            head->prev->next = newNode;
            head->prev = newNode;
        }
    }

    void hapusDepan()
    {
        if(!head)
        {
            cout<<"List kosong, tidak ada yang bisa dihapus"<<endl;
            return;
        }
        else if(head->next==head)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node* temp = head;
            head = head->next;
            head->prev = temp->prev;
            temp->prev->next = head;
            delete temp;
        }
    }

    void hapusBelakang()
    {
        if (!head)
        {
            cout<<"List kosong, tidak ada yang bisa dihapus"<<endl;
            return;
        }
        else if(head->next ==head)
        {
            delete head;
            head=nullptr;
        }
        else
        {
            Node* last = head->prev;
            last->prev->next = head;
            head->prev = last->prev;
            delete last;
        }
    }

    void cetak()
    {
        if (!head)
        {
            cout<<"List kosong"<<endl;
            return;
        }
        Node* temp = head;
        do
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        while (temp!=head);
        cout<<endl;
    }
};

int main()
{
    DoubleLinkedListCircular dllc;
    int data, pilihan;

    do
    {
        cout<<"1. Masukkan data di depan"<<endl;
        cout<<"2. Masukkan data di belakang"<<endl;
        cout<<"3. Hapus data di depan"<<endl;
        cout<<"4. Hapus data di belakang"<<endl;
        cout<<"5. Tampilkan data"<<endl;
        cout<<"6. Keluar"<<endl;
        cout<<"Masukkan pilihan Anda: ";cin>>pilihan;

        if(pilihan==1 || pilihan==2)
        {
            cout<<"Masukkan data: ";cin>>data;
        }

            switch (pilihan)
            {
                case 1:
                dllc.insertDepan(data);
                break;
                case 2:
                dllc.insertBelakang(data);
                break;
                case 3:
                dllc.hapusDepan();
                break;
                case 4:
                dllc.hapusBelakang();
                break;
                case 5: 
                dllc.cetak();
                break;
                case 6:
                cout<<"Program selesai"<<endl;
                break;
                default:
                cout<<"Pilihan tidak valid!"<<endl;
                break;
            }
    }
    while(pilihan!=6);
    return 0;
}