#include <iostream>
#include <string>
using namespace std;

// Array-based stack
int maksimalArray = 6;
string arrayMHS[6];
int arrayNIM[6];
string arrayJurusan[6];
int top = 0;

bool apakahPenuh() {
    return top == maksimalArray;
}

bool apakahKosong() {
    return top == 0;
}

void tambahkanMHS(string data, int NIM, string jurusan) {
    if (apakahPenuh()) {
        cout << "Data penuh" << endl;
    } else {
        arrayMHS[top] = data;
        arrayNIM[top] = NIM;
        arrayJurusan[top] = jurusan;
        top++;
    }
}

void hapusMHS() {
    if (apakahKosong()) {
        cout << "Data kosong!!" << endl;
    } else {
        top--;
        arrayMHS[top] = "";
        arrayNIM[top] = 0;
        arrayJurusan[top] = "";
    }
}

void tampilkanDataMHS() {
    if (apakahKosong()) {
        cout << "Data kosong!!" << endl;
    } else {
        cout << "Data stack array: " << endl;
        for (int i = top - 1; i >= 0; i--) {
            if (arrayMHS[i] != "") {
                cout << "Nama Mahasiswa: " << arrayMHS[i] << endl;
                cout << "NIM mahasiswa: " << arrayNIM[i] << endl;
                cout << "Jurusan Mahasiswa: " << arrayJurusan[i] << endl;
                cout << endl;
            }
        }
        cout << "\n" << endl;
    }
}

void intipDataMHS(int posisi) {
    if (apakahKosong()) {
        cout << "Data kosong!!" << endl;
    } else if (posisi > top || posisi <= 0) {
        cout << "Posisi tidak valid!" << endl;
    } else {
        int index = top - posisi;
        cout << "Nama Mahasiswa: " << arrayMHS[index] << endl;
        cout << "NIM mahasiswa: " << arrayNIM[index] << endl;
        cout << "Jurusan Mahasiswa: " << arrayJurusan[index] << endl;
    }
}

void gantiMHS(string data, int NIM, string jurusan, int posisi) {
    if (apakahKosong()) {
        cout << "Data kosong!!" << endl;
    } else if (posisi > top || posisi <= 0) {
        cout << "Posisi tidak valid!" << endl;
    } else {
        int index = top - posisi;
        arrayMHS[index] = data;
        arrayNIM[index] = NIM;
        arrayJurusan[index] = jurusan;
    }
}

int countArray() {
    return top;
}

void hapusDataMHS() {
    for (int i = 0; i < top; i++) {
        arrayMHS[i] = "";
        arrayNIM[i] = 0;
        arrayJurusan[i] = "";
    }
    top = 0;
}

// Linked List-based stack
struct DataMahasiswa {
    string namaMahasiswa;
    int NIM;
    string jurusan;

    DataMahasiswa* prev;
    DataMahasiswa* next;
};

DataMahasiswa* head = NULL;
DataMahasiswa* tail = NULL;
DataMahasiswa* cur;
DataMahasiswa* newNode;
DataMahasiswa* del;
int maksimalLinkedList = 5;

bool isFullMahasiswa() {
    int count = 0;
    cur = head;
    while (cur != NULL) {
        count++;
        cur = cur->next;
    }
    return count == maksimalLinkedList;
}

bool isEmptyMahasiswa() {
    return head == NULL;
}

void createMahasiswa(string namaMahasiswa, int NIM, string jurusan) {
    head = new DataMahasiswa();
    head->namaMahasiswa = namaMahasiswa;
    head->NIM = NIM;
    head->jurusan = jurusan;
    head->prev = NULL;
    head->next = NULL;
    tail = head;
}

void pushMahasiswa(string namaMahasiswa, int NIM, string jurusan) {
    if (isFullMahasiswa()) {
        cout << "Data penuh" << endl;
    } else {
        if (isEmptyMahasiswa()) {
            createMahasiswa(namaMahasiswa, NIM, jurusan);
        } else {
            newNode = new DataMahasiswa();
            newNode->namaMahasiswa = namaMahasiswa;
            newNode->NIM = NIM;
            newNode->jurusan = jurusan;
            newNode->prev = tail;
            tail->next = newNode;
            newNode->next = NULL;
            tail = newNode;
        }
    }
}

void popMahasiswa() {
    if (isEmptyMahasiswa()) {
        cout << "Data kosong!!" << endl;
    } else {
        del = tail;
        if (tail->prev != NULL) {
            tail = tail->prev;
            tail->next = NULL;
        } else {
            head = tail = NULL;
        }
        delete del;
    }
}

void displayMahasiswa() {
    if (isEmptyMahasiswa()) {
        cout << "Data Mahasiswa kosong" << endl;
    } else {
        cout << "\n\nData Mahasiswa : " << endl;
        cur = tail;
        while (cur != NULL) {
            cout << "Nama Mahasiswa: " << cur->namaMahasiswa << endl;
            cout << "NIM Mahasiswa: " << cur->NIM << endl;
            cout << "Jurusan Mahasiswa: " << cur->jurusan << endl;
            cout << endl;
            cur = cur->prev;
        }
    }
}

void peekMahasiswa(int posisi) {
    if (isEmptyMahasiswa()) {
        cout << "Data Mahasiswa kosong" << endl;
    } else {
        int nomor = 1;
        cur = tail;
        while (nomor < posisi) {
            cur = cur->prev;
            nomor++;
        }
        cout << "Data Mahasiswa Posisi ke-" << posisi << " : " << cur->namaMahasiswa << " - NIM: " << cur->NIM << " - Jurusan: " << cur->jurusan << endl;
    }
}

void changeMahasiswa(string namaMahasiswa, int NIM, string jurusan, int posisi) {
    if (isEmptyMahasiswa()) {
        cout << "Data Mahasiswa kosong" << endl;
    } else {
        int nomor = 1;
        cur = tail;
        while (nomor < posisi) {
            cur = cur->prev;
            nomor++;
        }
        cur->namaMahasiswa = namaMahasiswa;
        cur->NIM = NIM;
        cur->jurusan = jurusan;
    }
}

void destroyMahasiswa() {
    cur = head;
    while (cur != NULL) {
        del = cur;
        head = head->next;
        delete del;
        cur = cur->next;
    }
    head = tail = NULL;
}

int countMahasiswa() {
    int count = 0;
    cur = head;
    while (cur != NULL) {
        count++;
        cur = cur->next;
    }
    return count;
}

int main() {
    // Testing array-based stack
    tambahkanMHS("Kurnia Rezeki Ramadani", 90000, "Teknik Mesin");
    tambahkanMHS("Siti Adil", 10000, "DKV");
    tambahkanMHS("Aji Chan", 20000, "ML");
    tambahkanMHS("Irma Genshin", 24000, "SD");
    tambahkanMHS("Nofel", 69000, "Sastra Jepang");
    tampilkanDataMHS();

    tambahkanMHS("Giski Sagiri", 12000, "Anime");
    tampilkanDataMHS();

    hapusMHS();
    tampilkanDataMHS();

    cout << "Apakah data penuh? : " << (apakahPenuh() ? "Ya" : "Tidak") << endl;
    cout << "Apakah data kosong? : " << (apakahKosong() ? "Ya" : "Tidak") << endl;

    intipDataMHS(2);

    cout << "Banyak data: " << countArray() << endl;

    gantiMHS("Maheza ganteng", 70421, "Kedokteran", 3);
    tampilkanDataMHS();

    hapusDataMHS();

    cout << "Apakah data penuh? : " << (apakahPenuh() ? "Ya" : "Tidak") << endl;
    cout << "Apakah data kosong? : " << (apakahKosong() ? "Ya" : "Tidak") << endl;

    // Testing linked list-based stack
    pushMahasiswa("Kurnia Rezeki Ramadani", 90000, "Teknik Mesin");
    pushMahasiswa("Siti Adil", 10000, "DKV");
    pushMahasiswa("Aji Chan", 20000, "ML");
    pushMahasiswa("Irma Genshin", 24000, "SD");
    pushMahasiswa("Nofel", 69000, "Sastra Jepang");
    displayMahasiswa();

    pushMahasiswa("Giski Sagiri", 12000, "Anime");
    displayMahasiswa();

    popMahasiswa();
    displayMahasiswa();

    cout << "Apakah data penuh? : " << (isFullMahasiswa() ? "Ya" : "Tidak") << endl;
    cout << "Apakah data kosong? : " << (isEmptyMahasiswa() ? "Ya" : "Tidak") << endl;

    peekMahasiswa(2);

    cout << "Banyak data: " << countMahasiswa() << endl;

    changeMahasiswa("Maheza ganteng", 70421, "Kedokteran", 3);
    displayMahasiswa();

    destroyMahasiswa();

    cout << "Apakah data penuh? : " << (isFullMahasiswa() ? "Ya" : "Tidak") << endl;
    cout << "Apakah data kosong? : " << (isEmptyMahasiswa() ? "Ya" : "Tidak") << endl;

    return 0;
}
