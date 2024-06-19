#include <iostream>
using namespace std;

const int maksimalAntrianArray = 5;
int front = 0, back = 0, count = 0;

struct Mahasiswa {
    string nama, jurusan;
    int NIM;
    
};

Mahasiswa antrianMahasiswa[maksimalAntrianArray];

bool isFullArray() {
    return count == maksimalAntrianArray;
}

bool isEmptyArray() {
    return count == 0;
}

void enqueueArray(string nama, int NIM, string jurusan) {
    if (isFullArray()) {
        cout << "Antrian penuh!!" << endl;
    } else {
        antrianMahasiswa[back].nama = nama;
        antrianMahasiswa[back].NIM = NIM;
        antrianMahasiswa[back].jurusan = jurusan;
        back = (back + 1) % maksimalAntrianArray;
        count++;
    }
}

void dequeueArray() {
    if (isEmptyArray()) {
        cout << "Antrian kosong!!" << endl;
    } else {
        front = (front + 1) % maksimalAntrianArray;
        count--;
    }
}

int countArray() {
    return count;
}

void destroyArray() {
    front = back = count = 0;
}

void viewArray() {
    cout << "Jumlah data antrian: " << countArray() << " data." << endl;
    cout << "Data Antrian Mahasiswa: " << endl;
    if (isEmptyArray()) {
        cout << "Antrian kosong!!" << endl;
    } else {
        int j = front;
        for (int i = 0; i < count; i++) {
            cout << (i + 1) << ". Nama: " << antrianMahasiswa[j].nama 
                 << ", NIM: " << antrianMahasiswa[j].NIM 
                 << ", Jurusan: " << antrianMahasiswa[j].jurusan << endl;
            j = (j + 1) % maksimalAntrianArray;
        }
    }
    cout << "\n" << endl;
}

struct Node {
    string nama;
    int NIM;
    string jurusan;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;

void enqueueLinkedList(string nama, int NIM, string jurusan) {
    Node* newNode = new Node();
    newNode->nama = nama;
    newNode->NIM = NIM;
    newNode->jurusan = jurusan;
    newNode->next = NULL;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void dequeueLinkedList() {
    if (head == NULL) {
        cout << "Antrian kosong!!" << endl;
    } else {
        Node* temp = head;
        head = head->next;
        delete temp;
        if (head == NULL) {
            tail = NULL;
        }
    }
}

int countLinkedList() {
    int count = 0;
    Node* cur = head;
    while (cur != NULL) {
        count++;
        cur = cur->next;
    }
    return count;
}


void clearLinkedList() {
    Node* cur = head;
    while (cur != NULL) {
        Node* del = cur;
        cur = cur->next;
        delete del;
    }
    head = tail = NULL;
}


void displayLinkedList() {
    cout << "Data Antrian Mahasiswa : " << endl;
    if (head == NULL) {
        cout << "Antrian kosong!!" << endl;
    } else {
        Node* cur = head;
        int pos = 1;
        while (cur != NULL) {
            cout << pos << ". Nama: " << cur->nama 
                 << ", NIM: " << cur->NIM 
                 << ", Jurusan: " << cur->jurusan << endl;
            cur = cur->next;
            pos++;
        }
    }
    cout << "\n" << endl;
}

int main() {
    
    cout << "Array-Based Queue Test:" << endl;
    enqueueArray("Joni", 90000, "Teknik Mesin");
    enqueueArray("Mamat", 10000, "DKV");
    enqueueArray("Siti", 20000, "ML");
    enqueueArray("Bambang", 24000, "SD");
    enqueueArray("Rudi", 69000, "Sastra Jepang");
    viewArray();

    enqueueArray("Example", 12000, "Anime");
    viewArray();

    dequeueArray();
    viewArray();

    destroyArray();
    viewArray();

    cout << "Banyak data (Array): " << countArray() << endl;

    cout << "Linked List-Based Queue Test:" << endl;
    enqueueLinkedList("Joni", 90000, "Teknik Mesin");
    enqueueLinkedList("Mamat", 10000, "DKV");
    enqueueLinkedList("Siti", 20000, "ML");
    enqueueLinkedList("Bambang", 24000, "SD");
    enqueueLinkedList("Rudi", 69000, "Sastra Jepang");
    displayLinkedList();

    enqueueLinkedList("Example", 12000, "Anime");
    displayLinkedList();

    dequeueLinkedList();
    displayLinkedList();

    clearLinkedList();
    displayLinkedList();

    cout << "Banyak data (Linked List): " << countLinkedList() << endl;

    return 0;
}
