//
//  NguonThu.h
//  oop
//
//  Created by Phạm Nguyên on 22/05/2022.
//

#ifndef NguonThu_h
#define NguonThu_h

#include <iostream>
using namespace std;

class ThuNhap
{
private:
    long SoTien;
public:
    ThuNhap()
    {
        this->SoTien=0;
    }
    ThuNhap(long SoTien)
    {
        this->SoTien=SoTien;
    }
    long TinhTien()
    {
        return this->SoTien;
    }
    void GanSoTien(long SoTien)
    {
        this->SoTien=SoTien;
    }
    virtual void nhap()=0;
};

class CoBan: public ThuNhap
{
private:
    string Vo_Chong;
public:
    CoBan():ThuNhap()
    {
        this->Vo_Chong="";
    }
    CoBan(string Vo_Chong, long SoTien): ThuNhap(SoTien)
    {
        this->Vo_Chong=Vo_Chong;
    }
    long TinhTien()
    {
        return ThuNhap::TinhTien();
    }
    void nhap()
    {
        cout<<"Vo/Chong (V/C): ";
        char inp=' ';
        cin>>inp;
        while (inp!='V' && inp!='C' && inp!='v' && inp!='c')
        {
            cin>>inp;
        }
               if (inp=='v' || inp=='V') this->Vo_Chong="Vo";
               if (inp=='c' || inp=='C') this->Vo_Chong="Chong";
        cout<<"So Tien: ";
        long SoTien;
        cin>>SoTien;
        ThuNhap::GanSoTien(SoTien);
    }
    
};

class Chung: public ThuNhap
{
private:
    string CongViec;
public:
    Chung(): ThuNhap()
    {
        this->CongViec="";
    }
    Chung(string CongViec,long SoTien):ThuNhap(SoTien)
    {
        this->CongViec=CongViec;
    }
    long TinhTien()
    {
        return ThuNhap::TinhTien();
    }
    void nhap()
    {
        cout<<"Cong Viec: ";
        cin.ignore();
        getline(cin,this->CongViec);
        cout<<"So Tien: ";
        long SoTien;
        cin>>SoTien;
        ThuNhap::GanSoTien(SoTien);
    }
};



#endif /* NguonThu_h */
