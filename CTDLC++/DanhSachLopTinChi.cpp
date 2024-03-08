#include <iostream>
#include <string>
#include "DanhSachDangKy.cpp"
#include "DanhSachMonHoc.cpp"

using namespace std;

int MALOP = 0;// khoi tao tam sau cho doc file data

struct LopTinChi
{
	int MALOPTC;
	string MAMH; 
	int NienKhoa; 
	int HocKy; 
	int Nhom;  
	int SoSVMin;
	int SoSVMax; 
	bool HuyLop;
	DanhSachDangKy* DSDK;

	LopTinChi(){}
	LopTinChi(string MAMH, int HocKy, int Nhom)
	{
		this->MALOPTC = 0;
		this->MAMH = MAMH;
		this->HocKy = HocKy;
		this->Nhom = Nhom;
		this->SoSVMin = 10;
		this->SoSVMax = 100;
		DSDK = new DanhSachDangKy;
	}
	LopTinChi(string MAMH,int NienKhoa, int HocKy, int Nhom, int max, int min)
	{
		this->MALOPTC = 0;
		this->MAMH = MAMH;
		this->NienKhoa = NienKhoa;
		this->HocKy = HocKy;
		this->Nhom = Nhom;
		this->SoSVMin = min;
		this->SoSVMax = max;
		DSDK = new DanhSachDangKy;
	}
};

struct DanhSachLopTinChi
{
	LopTinChi* DanhSach[10000]; 
	int SoLuongLop; 
	DanhSachLopTinChi()
	{
		this->SoLuongLop = 0;
	}

	bool ThemLopTinChi(DanhSachLopTinChi* DSLTC, LopTinChi* lop) 
	{
		if (SoLuongLop >= 10000) {
			return false;
		}

		LopTinChi* lopMoi = new LopTinChi(lop->MAMH,lop->NienKhoa, lop->HocKy, lop->Nhom, lop->SoSVMax, lop->SoSVMin);
		if (lop->MALOPTC != 0) 
			lopMoi->MALOPTC = lop->MALOPTC;
		else 
			lopMoi->MALOPTC = ++MALOP;

		int i = SoLuongLop - 1;
		while (i >= 0 && DSLTC->DanhSach[i]->MALOPTC > lopMoi->MALOPTC) {
			DanhSach[i + 1] = DanhSach[i]; 
			i--;
		}
		DanhSach[i + 1] = lopMoi;

		SoLuongLop++;

		return true;
	}



	LopTinChi* TimLopTinChi(int MALOPTC)
	{
    int left = 0, right = SoLuongLop - 1;

    while (left <= right) 
	{
        int mid = (left + right) / 2;

        if (MALOPTC == DanhSach[mid]->MALOPTC) {
            return DanhSach[mid];
        } else if (MALOPTC < DanhSach[mid]->MALOPTC) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return nullptr;
	}	

	LopTinChi* TimLopTinChiTheoMAMH(string MAMH, int HocKy, int Nhom) 
	{
   		for (int i = 0; i < SoLuongLop; ++i) 
		{	
        	if (MAMH == DanhSach[i]->MAMH && HocKy == DanhSach[i]->HocKy && Nhom == DanhSach[i]->Nhom)
        		return DanhSach[i];
    	}
    	return nullptr;
	}

	void inDanhSachLopTinChi(DanhSachMonHoc *root)
	{
		for(int i = 0; i < SoLuongLop; i++)
		{
			cout << DanhSach[i]->MALOPTC << " " << DanhSach[i]->MAMH <<" "<< TimKiemTheoMAMH(root,DanhSach[i]->MAMH)->data.TENMH <<DanhSach[i]->SoSVMax  <<" "<< DanhSach[i]->SoSVMin <<" "<<DanhSach[i]->HuyLop<< endl;
		}
	}

	void xoaLopTinChi(int MALOPTC)
	{
		LopTinChi* lop = TimLopTinChi(MALOPTC);
		if(lop == nullptr)
		{
			cout << "Lop Tin Chi Khong Ton Tai" << endl;
			return;
		}
		else
		{
			bool check = false;
			int left = 0, right = SoLuongLop - 1;

    		while (left <= right) 
			{
        		int mid = (left + right) / 2;
        		if (MALOPTC == DanhSach[mid]->MALOPTC) 
				{	
					delete(DanhSach[mid]->DSDK);
					
					int j = mid;
					while(j < SoLuongLop - 1)
					{
					DanhSach[j] = DanhSach[j+1];
					j++;
					}

					delete(DanhSach[mid]);
					DanhSach[j] = nullptr;

					check = true;
					break;
        		} 
				else if (MALOPTC < DanhSach[mid]->MALOPTC) 
				{
            		right = mid - 1;
        		} 
				else 
				{
            		left = mid + 1;
        		}
			}
			if(check)
				cout << "Xoa Lop Thanh Cong"<< endl;
			SoLuongLop--;
			return;
		}
	}

	void hieuChinhLopTinChi(DanhSachLopTinChi* DSLTC, int malop)
	{
		LopTinChi* lop1 = DSLTC->TimLopTinChi(malop);
        DSLTC->xoaLopTinChi(malop);
        if(lop1 != NULL)
        {
            cout << lop1->MALOPTC << " " << lop1->MAMH << " " << lop1->NienKhoa<< endl;
			cout << "\tBan muon chi gi?\n\t1. Thay doi mon hoc\n\t2. So luong max min\n\t3. Thoat!\n";
			int i; cin >> i;
			switch (i)
			{
				case 1:
				{
					cout <<"Nhap ma mon hoc muon doi: ";
					string mamh; cin.ignore(); getline(cin, mamh);
					lop1->MAMH = mamh;
					DSLTC->ThemLopTinChi(DSLTC, lop1);
					break;
				}
				case 2:
				{
					cout << lop1->SoSVMax << " " << lop1->SoSVMin << endl;
					cout <<"Theo thu tu nhap max min: ";
					int max, min; cin >> max; cin >> min;
					lop1->SoSVMax = max;
					lop1->SoSVMin = min;
					cout << lop1->SoSVMax << " " << lop1->SoSVMin << endl;
					DSLTC->ThemLopTinChi(DSLTC, lop1);
					break;
				}
				case 3:
				{
					return;
				}
				default:
					break;
			}
        }

		return;
	}

};

// DanhSachLopTinChi dsLopTinChi;

// bool ThemLopTinChi(LopTinChi lop)
// {
// 	lop.MALOPTC = ++MALOP;
// 	if (dsLopTinChi.SoLuongLop >= 10000)
// 	{
// 		return false;
// 	}

// 	dsLopTinChi.DanhSach[dsLopTinChi.SoLuongLop++] = &lop;
// 	return true;
// }

//int main()
//{
//	DanhSachDangKy dssv;
//	SinhVien sv1;
//	sv1.MALOP = "D22CQCN02-N";
//	sv1.HO = "Pham Tien";
//	sv1.TEN = "Dat";
//
//	SinhVien sv2;
//	sv2.MALOP = "D22CQCN02-N";
//	sv2.HO = "ABC";
//	sv2.TEN = "AWSDF";
//
//	SinhVien sv3;
//	sv3.MALOP = "D22CQCN01-N";
//	sv3.HO = "ABCD";
//	sv3.TEN = "AWSDF";
//
//	dssv.Add(sv1);
//	dssv.Add(sv2);
//	dssv.Add(sv3);
//
//	LopTinChi lop1("001", "01", 1);
//	LopTinChi lop2("002", "01", 1);
//	ThemLopTinChi(lop1);
//	ThemLopTinChi(lop2);
//
//	cout << dsLopTinChi.DanhSach[0]->MALOPTC << " ";
//	cout << dsLopTinChi.DanhSach[1]->MALOPTC << " ";
//
//	return 0;
//}

