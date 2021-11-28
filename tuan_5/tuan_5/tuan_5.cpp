#include <iostream>
#include <vector>
#include <string>
using namespace std;

class NhanVien
{
protected:
    string HoTen{};
    int Luong{};
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
    float TienCong1SP{};

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
        this->Luong = (int)(this->SoSP * this->TienCong1SP);
    }
};

class NhanVienVanPhong : public NhanVien
{
private:
    float LuongCoBan{};
    int SoNgayLamViec{};

public:
    NhanVienVanPhong() : NhanVien()
    {
        this->LuongCoBan = 0.0;
    }

    void nhap()
    {
        NhanVien::nhap();
        cout << "Luong co ban: ";
        cin >> this->LuongCoBan;
        cout << "So ngay lam viec: ";
        cin >> this->SoNgayLamViec;
    }

    void xuat()
    {
        NhanVien::xuat();
        cout << "Luong co ban: " << this->LuongCoBan << endl;
        cout << "So ngay lam viec: " << this->SoNgayLamViec << endl;
        cout << "Luong: " << this->Luong << endl;
    }

    void tinhLuong()
    {
        this->Luong = (int)(this->SoNgayLamViec * this->LuongCoBan);
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

    void xuat()
    {
        for (int i = 0; i <(int) this->NV.size(); i++)
        {
            cout << endl;
            cout << "STT:" << i + 1 << endl;
            this->NV.at(i)->xuat();
        }
    }

    void tinhLuong()
    {
        for (int i = 0; i <(int) this->NV.size(); i++)
            this->NV.at(i)->tinhLuong();
    }
};

int main()
{
    CongTy cty;
    cty.nhap();
    cty.tinhLuong();
    cty.xuat();
    return 0;
}