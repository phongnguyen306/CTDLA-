// #pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "DanhSachDangKy.cpp"
#include "DanhSachLopTinChi.cpp"
#include "DanhSachSinhVien.cpp"

DanhSachMonHoc* docFileDanhSachMonHoc(DanhSachMonHoc* DSMH);
DanhSachSinhVien* docFileDanhSachSinhVien(DanhSachSinhVien* DSSV);
DanhSachLopTinChi* docFileDanhSachLopTinChi(DanhSachLopTinChi* DSLTC);

int main()
{
    
    DanhSachMonHoc *DSMH = NULL;
    DSMH = docFileDanhSachMonHoc(DSMH);
    DanhSachSinhVien *DSSV; 
    DSSV = docFileDanhSachSinhVien(DSSV);
    DanhSachLopTinChi *DSLCT;
    DSLCT = docFileDanhSachLopTinChi(DSLCT);
    DSLCT->inDanhSachLopTinChi(DSMH);

    delete DSMH;
    delete DSSV;
    delete DSLCT;

    return 0;
    
}

DanhSachMonHoc* docFileDanhSachMonHoc(DanhSachMonHoc* DSMH)
{
    ifstream infile;
    infile.open("data\\danhSachMonHoc.txt", ios::in);
    string data;
    if(!infile)
    {
        cout << "Khong Tim Thay File" << endl;
        return DSMH;
    }
    while (infile.good())
    {
        MH mh;
        getline(infile, data);
        if(data.size() == 0){break;}
        stringstream ss(data);
        string tmp;
        int i = 0;
        vector<string> chuoi;

        while (getline(ss,tmp,'@'))
            chuoi.push_back(tmp);
            
        mh.MAMH = chuoi[0];
        mh.TENMH = chuoi[1];
        mh.STCLT = stoi(chuoi[2]);
        mh.STCTH = stoi(chuoi[3]);

        DSMH = insertDanhSachMonHoc(DSMH ,mh);
    }
    infile.close();
    return DSMH;
}

DanhSachSinhVien* docFileDanhSachSinhVien(DanhSachSinhVien* DSSV)
{
    DSSV = new DanhSachSinhVien();
    ifstream infile;
    infile.open("data\\danhSachSinhVien.txt", ios::in);
    string data;
    if(!infile)
    {
        cout << "Khong Tim Thay File" << endl;
        return DSSV;
    }
    while (infile.good())
    {
        SinhVien sv;
        getline(infile, data);
        if(data.size() == 0){break;}
        stringstream ss(data);
        string tmp;
        vector<string> chuoi;

        while (getline(ss,tmp,'@'))
            chuoi.push_back(tmp);

        sv.MASV = chuoi[0];
        sv.HO = chuoi[1];
        sv.TEN = chuoi[2];
        sv.PHAI = chuoi[3];
        sv.MALOP = chuoi[4];
        sv.year = stoi(chuoi[5]);
        DSSV->Add(sv);
    }
    infile.close();
    return DSSV;
}   

DanhSachLopTinChi* docFileDanhSachLopTinChi(DanhSachLopTinChi* DSLTC)
{
    DSLTC = new DanhSachLopTinChi();
    ifstream infile;
    infile.open("data\\danhSachLopTinChi.txt", ios::in);
    string data;
    if(!infile)
    {
        cout << "Khong Tim Thay File" << endl;
        return DSLTC;
    }

    while (infile.good())
    {
        LopTinChi loptc;
        getline(infile, data);
        if(data.size() == 0){break;}
        stringstream ss(data);
        string tmp;
        vector<string> chuoi;

        while (getline(ss,tmp,'@'))
            chuoi.push_back(tmp);

        loptc.MALOPTC = stoi(chuoi[0]);
        loptc.MAMH = chuoi[1];
        loptc.NienKhoa = stoi(chuoi[2]);
        loptc.HocKy = stoi(chuoi[3]);
        loptc.Nhom = stoi(chuoi[4]);
        loptc.SoSVMin = stoi(chuoi[5]);
        loptc.SoSVMax = stoi(chuoi[6]);
        loptc.HuyLop = stoi(chuoi[7]);
        loptc.DSDK = nullptr;

        DSLTC->ThemLopTinChi(loptc);
        
    }
    infile.close();
    return DSLTC;
}
// int main()
// {
//     //----thao tac file-------
// void DocFileMH(PTRMH &DSMH) {
// 	ifstream infile;
// 	string data;
// 	infile.open("DSMH.txt", ios::in);
// 	if (!infile) { GhiChu("Khong tim thay file", 35, 27, 79, 2000); return; } //Khong tim thay file
// 	while (infile.good())
// 	{
// 		NodeMH mh;
// 		getline(infile, data);
// 		if (data.size() == 0) { break; } //Da co file nhung chua co du lieu
// 		strcpy(mh.mmh, data.c_str());
// 		getline(infile, data);		strcpy(mh.tmh, data.c_str());
// 		getline(infile, data);		strcpy(mh.stclt, data.c_str());
// 		getline(infile, data);		strcpy(mh.stcth, data.c_str());
// 		InsertNode_MH(DSMH, mh);
// 	}
// 	infile.close();
// }
// void GhiFile_LNR(ofstream &file, PTRMH DSMH)
// {
// 	if (DSMH != NULL)
// 	{
// 		GhiFile_LNR(file, DSMH->left);
// 		file << DSMH->data.mmh << endl
// 			<< DSMH->data.tmh << endl
// 			<< DSMH->data.stclt << endl
// 			<< DSMH->data.stcth << endl;
// 		GhiFile_LNR(file, DSMH->right);
// 	}
// }
// void GhiFileMH(PTRMH DSMH) {
// 	ofstream outfile;
// 	outfile.open("DSMH.txt", ios::out);
// 	GhiFile_LNR(outfile, DSMH);
// 	outfile.close();
// }
// void DocFileDSLTC(Dslop &DSLTC)
// {
// 	ifstream infile;
// 	infile.open("DSLTC.txt", ios::in);
// 	if (!infile)
// 	{
// 		cout << "\nFile Khong Ton Tai!";
// 		return;
// 	}
// 	int i = 0;
// 	Ltc lopTc;
// 	while (infile.good())
// 	{
// 		infile >> lopTc.malopTc;
// 		infile.ignore();
// 		infile.getline(lopTc.mmh, 11);
// 		infile.getline(lopTc.nienkhoa, 5);
// 		infile.getline(lopTc.hocki, 2);
// 		infile.getline(lopTc.nhom, 2);
// 		infile.getline(lopTc.nsvmax, 4);
// 		if (infile.eof()) break;
// 		if (i<MAXLTC)
// 		{
// 			InsertLTC(DSLTC, lopTc, DSLTC.n);
// 			i++;
// 		}
// 	}
// 	infile.close();
// }
// void GhiFileDSLTC(Dslop DSLTC)
// {
// 	ofstream outfile;
// 	outfile.open("DSLTC.txt");
// 	for (int i = 0; i<DSLTC.n; i++)
// 	{
// 		outfile << DSLTC.nodeltc[i]->malopTc << endl;
// 		outfile << DSLTC.nodeltc[i]->mmh << endl;
// 		outfile << DSLTC.nodeltc[i]->nienkhoa << endl;
// 		outfile << DSLTC.nodeltc[i]->hocki << endl;
// 		outfile << DSLTC.nodeltc[i]->nhom << endl;
// 		outfile << DSLTC.nodeltc[i]->nsvmax << endl;
// 	}
// 	outfile.close();
// }
// void DocFileSV(ListLop &ds)
// {
// 	int temp, vitri;
// 	char a[20];
// 	string data;
// 	ifstream infile;
// 	infile.open("DSSV.txt", ios::in);
// 	if (!infile) { return; }
// 	while (infile.good())
// 	{
// 		NodeSV sv;
// 		getline(infile, data);
// 		if (data.size() == 0) { break; }
// 		strcpy(a, data.c_str());
// 		temp = KTMaLop(ds, a, ds.n);
// 		if (temp != -1)
// 		{
// 			vitri = temp;
// 		}
// 		else {
// 			strcpy(sv.mssv, data.c_str());
// 			getline(infile, data);		strcpy(sv.ho, data.c_str());
// 			getline(infile, data);		strcpy(sv.ten, data.c_str());
// 			getline(infile, data);		strcpy(sv.phai, data.c_str());
// 			getline(infile, data);		strcpy(sv.sdt, data.c_str());
// 			Insert_TailSV(ds.dsl[vitri].DSSV, sv);
// 		}
// 	}
// 	infile.close();
// }
// void GhiFileSV(ListLop ds)
// {
// 	ofstream outfile;
// 	outfile.open("DSSV.txt", ios::out);
// 	for (int i = 0; i < ds.n; i++)
// 	{
// 		if (ds.dsl[i].DSSV != NULL) //Kiem tra Lop có Sinh Vien moi' nap. vao`
// 		{
// 			outfile << ds.dsl[i].malop << endl;
// 			for (PTRSV p = ds.dsl[i].DSSV; p != NULL; p = p->next)
// 			{
// 				outfile << p->data.mssv << endl
// 					<< p->data.ho << endl
// 					<< p->data.ten << endl
// 					<< p->data.phai << endl
// 					<< p->data.sdt << endl;
// 			}
// 		}
// 	}
// 	outfile.close();
// }
// void DocFileLop(ListLop &ds)
// {
// 	for (int i = 0; i < MAXLOP; i++)	//Khoi tao Mang rong~
// 	{
// 		ds.dsl[i].malop[0] = NULL;
// 		ds.dsl[i].tenlop[0] = NULL;
// 		ds.dsl[i].nienkhoa[0] = NULL;
// 		ds.dsl[i].DSSV = NULL;
// 	}
// 	fstream infile; string data;
// 	infile.open("DSLOP.txt", ios::in);
// 	if (!infile) { GhiChu("Khong tim thay file", 35, 12, 79, 2000); return; } //Khong tim thay file 
// 	while (infile.good())
// 	{
// 		getline(infile, data);
// 		if (data.size() == 0) { break; } // Khi da co file va du lieu rong~
// 		strcpy(ds.dsl[ds.n].malop, data.c_str());
// 		getline(infile, data);
// 		strcpy(ds.dsl[ds.n].tenlop, data.c_str());
// 		getline(infile, data);
// 		strcpy(ds.dsl[ds.n].nienkhoa, data.c_str());
// 		ds.dsl[ds.n].DSSV = NULL;	//Khoi tao con tro dau` DSSV NULL
// 		ds.n++;
// 	}
// 	infile.close();
// }
// void GhiFileLop(ListLop ds)
// {
// 	int n = 0;
// 	ofstream outfile;
// 	outfile.open("DSLOP.txt", ios::out);
// 	while (n < ds.n)
// 	{
// 		outfile << ds.dsl[n].malop << endl
// 			<< ds.dsl[n].tenlop << endl
// 			<< ds.dsl[n].nienkhoa << endl;
// 		n++;
// 	}
// 	outfile.close();
// }
// void DocFileDSDK(Dslop &DSLTC)
// {
// 	int temp, vitri;
// 	string data;
// 	char a[11];
// 	int malopTc;
// 	ifstream infile;
// 	infile.open("DSDK.txt", ios::in);
// 	if (!infile) { return; }
// 	while (infile.good())
// 	{
// 		NodeDK svdk;
// 		getline(infile, data);
// 		if (data.size() == 0) { break; }
// 		strcpy(a, data.c_str());
// 		malopTc = atoi(a);
// 		temp = Search_malopTc(DSLTC, malopTc, DSLTC.n);
// 		if (temp != -1)
// 		{
// 			vitri = temp;
// 		}
// 		else {
// 			strcpy(svdk.mssv, data.c_str());
// 			getline(infile, data);		strcpy(svdk.diem, data.c_str());
// 			Insert_NodeDk(DSLTC.nodeltc[vitri]->DSDK, svdk);

// 		}
// 	}
// 	infile.close();
// }
// void GhiFileDK(Dslop DSLTC)
// {
// 	ofstream outfile;
// 	outfile.open("DSDK.txt", ios::out);
// 	for (int i = 0; i < DSLTC.n; i++)
// 	{
// 		if (DSLTC.nodeltc[i]->DSDK != NULL) //Kiem tra Lop có Sinh Vien moi' nap. vao`
// 		{
// 			outfile << DSLTC.nodeltc[i]->malopTc << endl;
// 			for (PTRDK p = DSLTC.nodeltc[i]->DSDK; p != NULL; p = p->next)
// 			{
// 				outfile << p->data.mssv << endl
// 					<< p->data.diem << endl;
// 			}
// 		}
// 	}
// 	outfile.close();
// }

//     cout << "x";
// }