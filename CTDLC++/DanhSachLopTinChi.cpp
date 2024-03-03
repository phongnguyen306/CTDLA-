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
};

struct DanhSachLopTinChi
{
	LopTinChi* DanhSach[10000]; 
	int SoLuongLop; 
	DanhSachLopTinChi()
	{
		this->SoLuongLop = 0;
	}

	bool ThemLopTinChi(LopTinChi lop) 
	{
		LopTinChi* lopMoi = new LopTinChi(lop.MAMH, lop.HocKy, lop.Nhom);

		if(lop.MALOPTC != 0)
		{
			MALOP = lop.MALOPTC;
			lopMoi->MALOPTC = MALOP;
		}
		else
		{
    		lopMoi->MALOPTC = ++MALOP;
		}

    	if (SoLuongLop >= 10000) {
    	    return false;
    	}

    	DanhSach[SoLuongLop++] = lopMoi;  
    	return true;
	}



	LopTinChi* TimLopTinChi(int MALOPTC ) 
	{

  		for (int i = 0; i < SoLuongLop; i++) 
		{
    		if (MALOPTC == DanhSach[i]->MALOPTC) 
			{
      			return DanhSach[i];
    		}
  		}
 		
		return nullptr;
	}

	void inDanhSachLopTinChi(DanhSachMonHoc *root)
	{
		for(int i = 0; i < SoLuongLop; i++)
		{
			cout << DanhSach[i]->MALOPTC << " " << DanhSach[i]->MAMH <<" "<< TimKiemTheoMAMH(root,DanhSach[i]->MAMH)->data.TENMH << endl;
		}
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

