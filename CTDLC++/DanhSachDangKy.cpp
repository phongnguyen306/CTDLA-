#pragma once
#include <iostream>
#include <string>

using namespace std;
struct DangKy
{
	string MASV;
	float DIEM;
	bool huyDangKy;

	DangKy(){}

	DangKy(string MASV, float Diem) 
	{
    this->MASV = MASV;
    this->DIEM = Diem;
    this->huyDangKy = false;
	}
	
};

struct Node {
    DangKy dataDK;
    Node* next;

    Node(DangKy dataDK) {
        this->dataDK = dataDK;
        next = nullptr;
    }
};

struct DanhSachDangKy {
    Node* head;

    DanhSachDangKy() {
        head = nullptr;
    }

    // Thêm vào đầu danh sách
    void themDau(DangKy dataDK) {
        Node* newNode = new Node(dataDK);
        newNode->next = head;
        head = newNode;
    }

    // Thêm vào cuối danh sách
    void themCuoi(DangKy dataDK) {
        Node* newNode = new Node(dataDK);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Xóa node đầu
    void xoaDau() {
        if (head == nullptr) {
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Xóa node cuối
    void xoaCuoi() {
        if (head == nullptr) {
            return;
        }

        if (head->next == nullptr) {
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        Node* lastNode = temp->next;
        temp->next = nullptr;
        delete lastNode;
    }


    // Tìm kiếm node theo MASV
    DangKy* timKiem(string MASV) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->dataDK.MASV == MASV) {
                return &temp->dataDK;
            }
            temp = temp->next;
        }

        return nullptr;
    }

    // In danh sách
    void inDanhSach() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->dataDK.MASV << " " << temp->dataDK.DIEM << " " << temp->dataDK.huyDangKy << endl;
            temp = temp->next;
        }
    }
};