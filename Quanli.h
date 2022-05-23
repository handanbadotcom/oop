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
#include <vector>
#include <stdio.h>
#include <stdlib.h>


class QuanLi
{
private:
    vector<ThuNhap*> NguonThu;
    vector<ChiTieu*> NguonRa;
   
    int Thang;
    int Nam;
    long TienThangNay;
    long TienTietKiem;
public:
    QuanLi()
    {
        Nam=2022;
        Thang=5;
        TienThangNay=0;
        TienTietKiem=0;
    }
    void TinhThuNhap()
    {
        long ChiTieuThang=0;
        long ThuNhap=0;
        for (int i=0;i<NguonThu.size();i++)
        {
            ThuNhap+=NguonThu[i]->GetTien();
        }
        for (int i=0;i<NguonRa.size();i++)
        {
            ChiTieuThang+=NguonRa[i]->GetTien();
        }
        TienThangNay=ThuNhap-ChiTieuThang;
    }
    void Menu()
    {
        while (1)
        {
            cout<<"\n";
            cout<<"----------------\n";
            cout<<"Thang "<<this->Thang<<"/"<<this->Nam<<"\n";
            cout<<"Tien tiet kiem: "<<this->TienTietKiem<<"\n";
            cout<<"-----Menu-------\n";
            cout<<"1:Them nguon thu \n";
            cout<<"2:Them chi tieu \n";
            cout<<"3:Them no \n";
            cout<<"4:Ket thuc thang \n";
            cout<<"0:Tat chuong trinh \n";
            cout<<"Lua chon: ";
            int input;
            cin>>input;
            if (input==0)
                return;
            if (input==1)
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
                NguonThu.push_back(tmp);
            }
            if (input==2)
            {
                ChiTieu* tmp=new ChiTieu;
                tmp->Nhap();
                NguonRa.push_back(tmp);
            }
            if (input==4)
            {
                TinhThuNhap();
                cout<<"Tien thang nay: ";
                cout<<this->TienThangNay;
            }
        }
   
    }
    
    
};

#endif /* Quanli_h */
