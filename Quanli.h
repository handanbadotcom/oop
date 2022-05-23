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

class QuanLi
{
private:
    vector<ThuNhap*> NguonThu;
    vector<ChiTieu*> NguonRa;
    int Thang;
    int Nam;
    long TienThangNay;
public:
    QuanLi()
    {
        Nam=2022;
        Thang=5;
    }
    
    
};

#endif /* Quanli_h */
