//
//  ChiTieu.h
//  oop
//
//  Created by Phạm Nguyên on 23/05/2022.
//

#ifndef ChiTieu_h
#define ChiTieu_h

#pragma once
#include <iostream>
using namespace std;
class ChiTieu
{
private:
    string Ten;
    long SoTien;
public:
    ChiTieu()
    {
        this->Ten="";
        this->SoTien=0;
    }
    ChiTieu(string Ten, long SoTien)
    {
        this->Ten=Ten;
        this->SoTien=SoTien;
    }
    void Nhap()
    {
        cout<<"Ten Chi Tieu: ";
        cin.ignore();
        getline(cin,this->Ten);
        cout<<"So Tien: ";
        long SoTien;
        cin>>SoTien;
        this->SoTien=SoTien;
    }
    long GetTien()
    {
        return this->SoTien;
    }
    
};

#endif /* ChiTieu_h */
