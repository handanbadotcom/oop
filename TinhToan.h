//
//  TinhToan.h
//  oop
//
//  Created by Phạm Nguyên on 29/05/2022.
//

#ifndef TinhToan_h
#define TinhToan_h
#include "Quanli.h"

class TinhToan
{
private:
    vector<ThuNhap*> m_ThuNhap;
    vector<ThuNhap*> m_Luong;
    vector<SoTietKiem*> m_SoTietKiem;
    int m_Thang;
    int m_Nam;
    long m_TienDangCo;
    long m_TienTietKiem;
    NoI m_No1;
    NoII m_No2;
public:
    TinhToan(  vector<ThuNhap*> m_ThuNhap, vector<ThuNhap*> m_Luong, vector<SoTietKiem*> m_SoTietKiem, int m_Thang, int m_Nam, long m_TienDangCo, long m_TienTietKiem, NoI m_No1, NoII m_No2)
    {
        this->m_ThuNhap=m_ThuNhap;
        this->m_No1=m_No1;
        this->m_No2=m_No2;
        this->m_Nam=m_Nam;
        this->m_Thang=m_Thang;
        this->m_Luong=m_Luong;
        this->m_SoTietKiem=m_SoTietKiem;
        this->m_TienDangCo=m_TienDangCo;
        this->m_TienTietKiem=m_TienTietKiem;
    }
};


#endif /* TinhToan_h */
