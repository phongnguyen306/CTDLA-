#pragma once
#include <iostream>
#include <string>

//#include "loptinchi.cpp"

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

struct DanhSachDangKy
{
	struct Node
	{
		DangKy dataDK;
		Node* next;
	};

	void insertNode(Node* temp, DangKy newSv)
	{
		Node* newNode = new Node;
		newNode->dataDK = temp->dataDK;
		temp->dataDK = newSv;
		newNode->next = temp->next;
		temp->next = newNode;
	}
};