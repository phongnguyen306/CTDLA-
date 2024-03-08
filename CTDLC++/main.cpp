#include "DocGhiXoaFile.cpp"

int main()
{
    DanhSachMonHoc *DSMH = NULL;
    DSMH = docFileDanhSachMonHoc(DSMH);
    DanhSachSinhVien *DSSV; 
    DSSV = docFileDanhSachSinhVien(DSSV);
    DanhSachLopTinChi *DSLTC;
    DSLTC = docFileDanhSachLopTinChi(DSLTC);
    docFileDanhSachDangKy(DSLTC);   
    
    //=== xu ly du lieu tai day ===
    menu:
    cout << "===Menu===" << endl
        << "1. Cap Nhat Lop Tin Chi." << endl
        << "2. In danh sach sinh vien dang ky theo lop tin chi" << endl
        << "3. Nhap sinh vien" << endl
        << "4. " << endl
        << "5.Thoat " << endl;
    int i; cin >> i;

    switch (i)
    {
        case 1:
        {//cau a
            capnhat:
            cout << "1. Cap Nhat Lop Tin Chi." << endl
                << "\t1. Them lop tin chi" << endl
                << "\t2. Xoa lop tin chi" << endl
                << "\t3. Hieu chinh" << endl
                << "\t4. Den menu" <<endl;
            int tmp; cin >> tmp;
            switch (tmp)
            {
                case 1:
                {
                    nhapmamh:
                    string mamh; cin.ignore(); getline(cin, mamh);
                    int hocky; cin >> hocky;
                    int nhom; cin >> nhom;

                    while (TimKiemTheoMAMH(DSMH, mamh) == NULL)
                    {
                        cout << "Mon hoc nay khong ton tai"<< endl;
                        goto capnhat;
                    }

                    if(DSLTC->TimLopTinChiTheoMAMH(mamh, hocky, nhom) == nullptr)
                    {
                        LopTinChi lopmoi(mamh,hocky,nhom);
                        DSLTC->ThemLopTinChi(DSLTC, &lopmoi);
                    }
                    else
                    {
                        cout << "Mon hoc da ton tai vui long them lop khac" << endl;
                        goto capnhat;
                    }
                    cout << "Them thanh cong!" << endl;
                    goto menu;
                }

                    break;
                case 2:
                {
                    int maloptc; cin >> maloptc;
                    DSLTC->xoaLopTinChi(maloptc);
                    goto menu;
                    break;
                }
                case 3:
                {
                    DSLTC->inDanhSachLopTinChi(DSMH);
                    cout << endl;
                    cout << "Ban muon hieu chinh lop tin chi nao vui long nhap maloptc: ";
                    int malop; cin >> malop;
                    DSLTC->hieuChinhLopTinChi(DSLTC, malop);
                    DSLTC->inDanhSachLopTinChi(DSMH);
                    goto capnhat;
                }
                case 4:
                {
                    goto menu;
                    break;
                }
                default:
                    cout << "Ban da nhap sai!"<<endl;
                    goto capnhat;
                    break;
            }
        //Ket thuc cau a
        }
        case 5:
            goto thoat;
            break;
        default:
            cout << "Ban da nhap sai!" << endl;
            goto menu;
            break;
    }



    //=== ket thuc xu ly du lieu ===
    thoat:
    xoaDuLieuFileDanhSachMonHoc();
    ghiFileDanhSachMonHoc(DSMH);
    xoaDuLieuFileDanhSachSinhVien();
    ghiFileDanhSachSinhVien(DSSV);
    xoaDuLieuFileDanhSachLopTinChi();
    ghiFileDanhSachLopTinChi(DSLTC);
    xoaDuLieuFileDanhSachDangKy();
    ghiFileDanhSachDangKy(DSLTC);
    delete DSMH;
    delete DSSV;
    delete DSLTC;

    return 0;
    
}