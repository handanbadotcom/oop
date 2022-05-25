//
//  Quanli.h
//  oop
//
//  Created by Phạm Nguyên on 23/05/2022.
//

#ifndef Quanli_h
#define Quanli_h

#pragma once
#include "NguonThu.h"
#include "ChiTieu.h"
#include "SoTietKiem.h"
#include <vector>
#include <stdio.h>
#include <stdlib.h>


class QuanLi
{
private:
    vector<ThuNhap*> m_ThuNhap;
    vector<ChiTieu*> m_ChiTieu;
    vector<SoTietKiem*> m_SoTietKiem;
    int m_Thang;
    int m_Nam;
    long m_TienDangCo;
    long m_TienTietKiem;
public:
    QuanLi()
    {
        m_Nam=2022;
        m_Thang=5;
        m_TienDangCo=0;
        m_TienTietKiem=0;
    }
    long TinhThuNhap()
    {
        long ChiTieuThang=0;
        long ThuNhap=0;
        for (int i=0;i<m_ThuNhap.size();i++)
        {
            ThuNhap+=m_ThuNhap[i]->GetTien();
        }
        for (int i=0;i<m_ChiTieu.size();i++)
        {
            ChiTieuThang+=m_ChiTieu[i]->GetTien();
        }
        ThuNhap=ThuNhap-ChiTieuThang;
        return ThuNhap;
    }
    void ThemThuNhap()
    {
        cout<<"1: Co ban \n";
        cout<<"2: Chung \n";
        int i=0;
        while (i!=1 and i!=2)
            cin>>i;
        ThuNhap* tmp;
        if (i==1)
             tmp=new CoBan;
        else
             tmp=new Chung;
        tmp->Nhap();
        m_ThuNhap.push_back(tmp);
    }
    void ThemChiTieu()
    {
        ChiTieu* tmp=new ChiTieu;
        tmp->Nhap();
        m_ChiTieu.push_back(tmp);
    }
    void GuiTietKiem(long TienThangNay)
    {
        SoTietKiem* tmp= new SoTietKiem(m_Thang,m_Nam,0,0,TienThangNay);
        tmp->Nhap();
        m_SoTietKiem.push_back(tmp);
        
    }
    void CapNhat()
    {
        long tk=0;
        for (int i=0;i<m_SoTietKiem.size();i++)
        {
            m_SoTietKiem[i]->CapNhat();
            tk=tk+m_SoTietKiem[i]->GetSoTien();
        }
        this->m_TienTietKiem=tk;
        this->m_Thang++;
        if (this->m_Thang>12)
        {
            this->m_Nam++;
            this->m_Thang=1;
        }
        
        m_ChiTieu.clear();
        m_ThuNhap.clear();
        
    }
    void RutTien()
    {
        for (int i=0;i<m_SoTietKiem.size();i++)
        {
            cout<<i+1<<"----------\n";
            m_SoTietKiem[i]->Xuat();
        }
        int tmp=0;
        while (tmp<1 || tmp>m_SoTietKiem.size())
        {
        cout<<"Chon so can rut: ";
        cin>>tmp;
        }
        this->m_TienTietKiem-=m_SoTietKiem[tmp-1]->GetSoTien();
        this->m_TienDangCo+=m_SoTietKiem[tmp-1]->GetSoTien();
        m_SoTietKiem.erase(m_SoTietKiem.begin()+tmp-1);
      
    }
    void Menu()
    {
        while (1)
        {
            cout<<"\n";
            cout<<"----------------\n";
            cout<<"Thang "<<this->m_Thang<<"/"<<this->m_Nam<<"\n";
            cout<<"Tien tiet kiem: "<<this->m_TienTietKiem<<"\n";
            cout<<"Tien dang co: "<<this->m_TienDangCo<<"\n";
            cout<<"-----Menu-------\n";
            cout<<"1:Them nguon thu \n";
            cout<<"2:Them chi tieu \n";
            cout<<"3:Them no \n";
            cout<<"4:Ket thuc thang \n";
            cout<<"5:Rut so tiet kiem \n";
            cout<<"0:Tat chuong trinh \n";
            int input=9;
            while (input<0 || input>5)
            {
                cout<<"Lua chon: ";
                cin>>input;
            }
            if (input==0)
                return;
            if (input==1)
            {
                ThemThuNhap();
            }
            if (input==2)
            {
                ThemChiTieu();
            }
            if (input==4)
            {
                long TienThangNay=TinhThuNhap();
                cout<<"Tien thang nay: "<<TienThangNay<<"\n";
                char YN=' ';
                while (YN!='y' && YN!='n' && YN!='Y' && YN!='N')
                {
                    cout<<"Chap nhan gui tiet kiem(Y/N): ";
                    cin>>YN;
                }
                if (YN=='y' || YN=='Y')
                {
                    GuiTietKiem(TienThangNay);
                }
                else
                {
                    m_TienDangCo=m_TienDangCo+TienThangNay;
                }
                CapNhat();
            }
            if (input==5)
            {
                RutTien();
            }
        }
   
    }
    
    
};

#endif /* Quanli_h */
