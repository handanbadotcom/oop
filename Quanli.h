//
//  Quanli.h
//  oop
//
//  Created by Phạm Nguyên on 23/05/2022.
//

#ifndef Quanli_h
#define Quanli_h

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
                ThuNhap* tmp=new CoBan;
                tmp->nhap();
                NguonThu.push_back(tmp);
            }
            if (input==2)
            {
                
            }
        }
    }
    
    
};

#endif /* Quanli_h */
