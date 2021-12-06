//  Một công ty có nhiều nhân viên làm việc. Các nhân viên có thuộc tính chung
//  là Họ tên, tiền lương, giới tính, tuổi. Nhân viên công ty được chia thành
//  hai nhóm là nhân viên sản xuất và nhân viên văn phòng. Nhân viên sản xuất
//  có thuộc tính riêng là số sản phẩm làm được và tiền công một sản phẩm. Nhân
//  viên văn phòng có thuộc tính riêng là mức lương cơ bản một ngày và số ngày 
//  làm việc. Chương trình có thể thêm, sửa, xóa, và xuất thông tin nhân viên.
//  Tiền lương nhân viên sẽ được tính tự động và sẽ xuất ra cùng thông tin nhân
//  viên khi chọn xuất thông tin nhân viên.
// 
//  Chương trình có menu như sau:
//    1 / Them nhan vien moi
//    2 / Thay doi thong tin nhan vien
//    3 / Xoa nhan vien
//    4 / Xuat nhan vien
//    5 / Thoat
//    Ban chon:
// 
//  Khi chọn 2 và 3, nên nhập STT theo STT của nhân viên được hiển thị sau khi đã 
//  chọn: 4 / Xuat nhan vien. Nếu nhập STT lớn hơn số nhân viên hiện có thì chương
//  trình sẽ xuất ra số nhân viên hiện có và yêu cầu nhập lại STT.
//  Các trường hợp còn lại chọn theo hướng dẫn trên màng hình.


#include <iostream>
#include <vector>
#include <string>
using namespace std;

class NhanVien
{
protected:
    string HoTen{};
    float Luong{};
    bool GioiTinh{};
    int Tuoi{};

public:
    NhanVien()
    {
        this->HoTen = "";
        this->Luong = 0;
    }

    virtual void nhap()
    {
        cout << "Ho ten nhan vien: ";
        cin.ignore();
        getline(cin, this->HoTen);
        cout << "Gioi tinh ( Nam (1), Nu (2) ): ";
        int k;
        cin >> k;
        if (k == 1)
            GioiTinh = true;
        else
            GioiTinh = false;
        cout << "Tuoi :";
        int tuoi;
        cin >> tuoi;
        this->Tuoi = tuoi;
    }

    virtual void xuat()
    {
        cout << "Ho ten nhan vien: " << this->HoTen << endl;
        cout << "Gioi tinh : " << (GioiTinh ? "Nam" : "Nu") << endl;
        cout << "Tuoi :" << this->Tuoi << endl;
    }

    virtual void tinhLuong() = 0;
};

class NhanVienSanXuat : public NhanVien
{
private:
    int SoSP{};
    int TienCong1SP{};

public:
    NhanVienSanXuat() : NhanVien()
    {
        this->SoSP = 0;
        this->TienCong1SP = 0;
    }

    void nhap()
    {
        NhanVien::nhap();
        cout << "So san pham: ";
        cin >> this->SoSP;
        cout << "Tien cong 1 san pham: ";
        cin >> this->TienCong1SP;
    }

    void xuat()
    {
        NhanVien::xuat();
        cout << "So san pham: " << this->SoSP << endl;
        cout << "Tien cong 1 san pham: " << this->TienCong1SP << endl;
        cout << "Luong: " << this->Luong << endl;
    }

    void tinhLuong()
    {
        this->Luong = (float)(this->SoSP * this->TienCong1SP);
    }
};

class NhanVienVanPhong : public NhanVien
{
private:
    float LuongCoBan1N{};
    int SoNgayLamViec{};

public:
    NhanVienVanPhong() : NhanVien()
    {
        this->LuongCoBan1N = 0.0;
    }

    void nhap()
    {
        NhanVien::nhap();
        cout << "Luong co ban: ";
        cin >> this->LuongCoBan1N;
        cout << "So ngay lam viec: ";
        cin >> this->SoNgayLamViec;
    }

    void xuat()
    {
        NhanVien::xuat();
        cout << "Luong co ban: " << this->LuongCoBan1N << endl;
        cout << "So ngay lam viec: " << this->SoNgayLamViec << endl;
        cout << "Luong: " << this->Luong << endl;
    }

    void tinhLuong()
    {
        this->Luong = this->SoNgayLamViec * this->LuongCoBan1N;
    }
};

class CongTy
{
private:
    vector<NhanVien*> NV;

public:
    void nhap()
    {
        cout << "Nhap so nhan vien: ";
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "Nhan vien van phong (1), nhan vien san xuat (2): ";
            int k;
            cin >> k;
            NhanVien* nv;
            if (k == 1)
                nv = new NhanVienVanPhong;
            else
                nv = new NhanVienSanXuat;
            nv->nhap();
            this->NV.push_back(nv);
        }
    }

    void xoa()
    {
        if (this->NV.size() == 0)
            cout << "Chua co thong tin nhan vien!" << endl;
        else
        {
            int vitrixoa;
            do
            {
                cout << "Nhap STT nhan vien can xoa :";
                cin >> vitrixoa;
                if (vitrixoa >(int) this->NV.size())
                    cout << "Danh sach chi co " << this->NV.size() << " nhan vien!" << endl;
            } while (vitrixoa > (int) this->NV.size());
            this->NV.erase(this->NV.begin() + vitrixoa - 1);
        }
    }

    void sua()
    {
        if (this->NV.size() == 0)
            cout << "Chua co thong tin nhan vien!" << endl;
        else
        {
            int vitrisua;
            do
            {
                cout << "Nhap STT nhan vien can sua :";
                cin >> vitrisua;
                if (vitrisua > (int)this->NV.size())
                    cout << "Danh sach chi co " << this->NV.size() << " nhan vien!" << endl;
            } while (vitrisua > (int)this->NV.size());
            this->NV.at(vitrisua - 1)->nhap();
        }
    }

    void xuat()
    {
        if (this->NV.size() == 0)
            cout << "Chua co thong tin nhan vien!" << endl;
        else
        {
            for (int i = 0; i < (int)this->NV.size(); i++)
            {
                cout << "STT:" << i + 1 << endl;
                this->NV.at(i)->xuat();
                cout << endl;
            }
        }
    }

    void tinhLuong()
    {
        for (int i = 0; i < (int)this->NV.size(); i++)
            this->NV.at(i)->tinhLuong();
    }
};

int main()
{
    CongTy cty;
    int chon;
    do
    {
        cout << "1/ Them nhan vien moi" << endl;
        cout << "2/ Thay doi thong tin nhan vien" << endl;
        cout << "3/ Xoa nhan vien" << endl;
        cout << "4/ Xuat nhan vien" << endl;
        cout << "5/ Thoat" << endl;
        cout << "Ban chon: ";
        cin >> chon;
        cout << endl;
        switch (chon)
        {
        case 1:
            cty.nhap();
            int chon1;
            cout << "Bam 5 de thoat: ";
            cin >> chon1;
            if (chon1 == 5)
            {
                system("cls");
                break;
            }
        case 2:
            cty.sua();
            int chon2;
            cout << "Bam 5 de thoat: ";
            cin >> chon2;
            if (chon2 == 5)
            {
                system("cls");
                break;
            }
        case 3:
            cty.xoa();
            int chon3;
            cout << "Bam 5 de thoat: ";
            cin >> chon3;
            if (chon3 == 5)
            {
                system("cls");
                break;
            }
        case 4:
            cty.tinhLuong();
            cty.xuat();
            int chon4;
            cout << "Bam 5 de thoat: ";
            cin >> chon4;
            if (chon4 == 5)
            {
                system("cls");
                break;
            }
        case 5:
            system("cls");
            break;
        }
    } while (chon != 5);
    return 0;
}