#include <iostream>
#include <string>


using namespace std;

struct SinhVien
{
	string MASV;
	string HO;
	string TEN;
	string PHAI;
	string MALOP;
	int year;
};

struct DanhSachSinhVien
{
	struct Node
	{
		SinhVien sv;
		Node* next;
		Node()
		{
			next = nullptr;
		}
	};

	void AddNodeAtTail(Node* temp, SinhVien newSv)
	{
		Node* newNode = new Node;
		newNode->sv = temp->sv;
		temp->sv = newSv;
		newNode->next = temp->next;
		temp->next = newNode;
		soLuong++;
	}

	Node* head;
	int soLuong;

	DanhSachSinhVien()
	{
		head = new Node;
		soLuong = 0;
	}

	void Add(SinhVien newSv)
	{
		// cout << "x1";
		if (soLuong == 0)
		{
			head->sv = newSv;
			soLuong++;
			return;
		}

		Node* temp = head;
		Node* tempp;
		// do
		// {
		// 	if (CheckForInsert(newSv, temp->sv))
		// 	{
		// 		AddNodeAtTail(temp, newSv);
		// 		return;
		// 	}

		// 	temp = temp->next;
		// } while (temp->next != nullptr);
		// if (CheckForInsert(newSv, temp->sv))
		// 	{
		// 		AddNodeAtTail(temp, newSv);
		// 		return;
		// 	}
		
		while (temp !=nullptr)
		{
			if (CheckForInsert(newSv, temp->sv))
			{
				AddNodeAtTail(temp, newSv);
				return;
			}
			tempp = temp;
			temp = temp->next;
		}
		Node* newNode = new Node();
		newNode->sv = newSv;
		tempp->next = newNode;
		soLuong++;
	}

	bool CheckForInsert(SinhVien sv1, SinhVien sv2)
	{
		//cout << sv1.TEN << " " << sv2.TEN;
		if (sv1.MALOP < sv2.MALOP)
			return true;
		if (sv1.MALOP > sv2.MALOP) return false;

		if (sv1.TEN[0] < sv2.TEN[0])
			return true;
		if (sv1.TEN[0] >sv2.TEN[0]) return false;		
		if (sv1.HO < sv2.HO)
			return true;
			
		return false;
	}

	void InDSSV()
	{
		Node* temp = head;
		for (int i = 0; i < soLuong; i++)
		{
			SinhVien svTemp = temp->sv;
			cout << svTemp.MALOP << " " << svTemp.HO << " " << svTemp.TEN << endl;
			temp = temp->next;
		}
	}


};

// int main() {
// 	DanhSachSinhVien dssv;
// 	SinhVien sv1;
// 	sv1.MALOP = "D22CQCN02-N";
// 	sv1.HO = "Pham Tien";
// 	sv1.TEN = "Dat";

// 	SinhVien sv2;
// 	sv2.MALOP = "D22CQCN02-N";
// 	sv2.HO = "Nguyen";
// 	sv2.TEN = "Phong";

// 	SinhVien sv3;
// 	sv3.MALOP = "D22CQCN02-N";
// 	sv3.HO = "Tran";
// 	sv3.TEN = "Vu";

// 	dssv.Add(sv1);
// 	dssv.Add(sv2);
// 	dssv.Add(sv3);
// 	dssv.InDSSV();

// 	return 0;
// }
