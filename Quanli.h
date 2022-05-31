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
#include "SoTietKiem.h"
#include <vector>
#include "No.h"
//#include "TinhToan.h"



class QuanLi
{
protected:
    vector<ThuNhap*> m_ThuNhap;
    vector<ThuNhap*> m_Luong;
 //   vector<ThuNhap*> m_ChiTieu;
    vector<SoTietKiem*> m_SoTietKiem;
    int m_Thang;
    int m_Nam;
    long m_TienDangCo;
    long m_TienTietKiem;
    NoI m_No1;
    NoII m_No2;
public:
    QuanLi()
    {
        m_Nam=2022;
        m_Thang=5;
        m_TienDangCo=0;
        m_TienTietKiem=0;
        m_No1.Nhap();
        m_No2.Nhap();
    }
    /*
    QuanLi Clone()
    {
        QuanLi tmp;
        tmp.m_ThuNhap=m_ThuNhap;
        tmp.m_No1=m_No1;
        tmp.m_No2=m_No2;
        tmp.m_Nam=m_Nam;
        tmp.m_Thang=m_Thang;
        tmp.m_Luong=m_Luong;
        tmp.m_SoTietKiem=m_SoTietKiem;
        tmp.m_TienDangCo=m_TienDangCo;
        tmp.m_TienTietKiem=m_TienTietKiem;
        return tmp;
    }
    QuanLi(const QuanLi &a)
    {
        m_ThuNhap=a.m_ThuNhap;
        m_No1=a.m_No1;
        m_No2=a.m_No2;
        m_Nam=a.m_Nam;
        m_Thang=a.m_Thang;
        m_Luong=a.m_Luong;
        m_SoTietKiem=a.m_SoTietKiem;
        m_TienDangCo=a.m_TienDangCo;
        m_TienTietKiem=a.m_TienTietKiem;
    }
    */
    long TinhTong(vector<ThuNhap*> a)
    {
        long Tong=0;
        for (int i=0;i<a.size();i++)
        {
            Tong+=a[i]->GetTien();
        }
        return Tong;
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
        {
             tmp=new CoBan;
             tmp->Nhap();
             m_Luong.push_back(tmp);
        }
        else
        {
             tmp=new Chung;
            tmp->Nhap();
            m_ThuNhap.push_back(tmp);
        }
    }
    void ThemChiTieu()
    {
        ThuNhap* tmp=new ChiTieu;
        tmp->Nhap();
        m_ThuNhap.push_back(tmp);
    }
    void GuiTietKiem(long Tien)
    {
        SoTietKiem* tmp= new SoTietKiem(m_Thang,m_Nam,0,0,Tien);
        tmp->Nhap();
        m_SoTietKiem.push_back(tmp);
        
    }
    void CapNhat()
    {
        long tk=0;
        for (int i=0;i<m_SoTietKiem.size();i++)
        {
            m_SoTietKiem[i]->CapNhat();
            if (m_SoTietKiem[i]->DenKyHan())
            {
                cout<<"So den han"<<endl;
                m_SoTietKiem[i]->Xuat();
                char YN=' ';
                while (YN!='y' && YN!='n' && YN!='Y' && YN!='N')
                {
                    cout<<"Tiep tuc gui tiet kiem(Y/N): ";
                    cin>>YN;
                }
                if (YN=='y' || YN=='Y')
                {
                    m_SoTietKiem[i]->Nhap();
                }
                else
                {
                    m_SoTietKiem[i]->TietKiemGD();
                }
            }
            tk=tk+m_SoTietKiem[i]->GetSoTien();
        }
        this->m_TienTietKiem=tk;
        this->m_Thang++;
        if (this->m_Thang>12)
        {
            this->m_Nam++;
            this->m_Thang=1;
        }
        m_ThuNhap.clear();
        m_Luong.clear();
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
    void BaoCaoThang()
    {
        long ThuChiThang=TinhTong(m_ThuNhap);
        long Luong=TinhTong(m_Luong);
        m_TienDangCo+=ThuChiThang;
        if (m_TienDangCo<0)
        {
            Luong+=m_TienDangCo;
            m_TienDangCo=0;
        }
        cout<<"Con lai cua thang nay: "<<ThuChiThang<<endl;
        cout<<"Them vao thu chi thang sau: "<<m_TienDangCo<<endl;
        cout<<"Thu nhap co ban: "<<Luong<<endl;
        if (Luong<0)
        {
            char a;
            cout<<"Thong bao pha san";
            cin>>a;
            return;
        }
        char YN=' ';
        while (YN!='y' && YN!='n' && YN!='Y' && YN!='N')
        {
            cout<<"Chap nhan gui tiet kiem(Y/N): ";
            cin>>YN;
        }
        if (YN=='y' || YN=='Y')
        {
            GuiTietKiem(Luong);
        }
        else
        {
            SoTietKiem* tmp= new SoTietKiem(m_Thang,m_Nam,-1,0,ThuChiThang);
            m_SoTietKiem.push_back(tmp);
        }
    }
    long TongTietKiem(vector<SoTietKiem*> tk)
    {
        long tmp=0;
        for (int i=0;i<tk.size();i++)
        {
            tmp+=tk[i]->GetSoTien();
        }
        return tmp;
    }
    void TinhToan()
    {
        vector<SoTietKiem*> Tk;
        long Tien=m_TienDangCo;
        //copy lại sổ tk
        for (int i=0;i<m_SoTietKiem.size();i++)
        {
            SoTietKiem* tmp=new SoTietKiem(m_SoTietKiem[i]);
            Tk.push_back(tmp);
        }
        //
        int Thang=m_Thang;
        int Nam=m_Nam;
        SoTietKiem* SoMoiNhat=new SoTietKiem(Tk[Tk.size()-1]);
        
        while (!m_No2.DenHan(Thang, Nam))
        {
            SoTietKiem* tmp=new SoTietKiem(SoMoiNhat);
            Tk.push_back(tmp);
            for (int i=0;i<Tk.size();i++)
            {
                Tk[i]->TuDongGiaHan();
            }
            Thang++;
            if (Thang>12)
            {
                Nam++;
                Thang=1;
            }
        }
        long TienNo2=m_No2.tongTienPhaiTraNo();
        if (Tien+TongTietKiem(Tk)>TienNo2)
        {
            while (Tien<TienNo2)
            {
                Tien+=Tk[0]->GetSoTien();
                Tk.erase(Tk.begin());
            }
            Tien-=TienNo2;
            cout<<"Co kha nang tra no 2"<<endl;
        }
        else
        {
            cout<<"Khong co kha nang tra no 2"<<endl;
        }
        while (!m_No1.DenHan(Thang, Nam))
        {
            SoTietKiem* tmp=new SoTietKiem(SoMoiNhat);
            Tk.push_back(tmp);
            for (int i=0;i<Tk.size();i++)
            {
                Tk[i]->TuDongGiaHan();
            }
            Thang++;
            if (Thang>12)
            {
                Nam++;
                Thang=1;
            }
        }
       
        long TienNo1=m_No1.tongTienPhaiTraNo();
        if (Tien+TongTietKiem(Tk)>TienNo1)
        {
            while (Tien<TienNo1)
            {
                Tien+=Tk[0]->GetSoTien();
                Tk.erase(Tk.begin());
            }
            Tien-=TienNo1;
            cout<<"Du doan co kha nang tra no 1"<<endl;
        }
        else
        {
                cout<<"Du doan khong co kha nang tra no 1"<<endl;
        }
    }
    void TraNo()
    {
        long TienNo2=m_No2.tongTienPhaiTraNo();
        long TienNo1=m_No1.tongTienPhaiTraNo();
        if (m_No2.DenHan(m_Thang, m_Nam)>0)
        {
            if (TongTietKiem(m_SoTietKiem)>TienNo2)
            {
                while (m_TienDangCo<TienNo2)
                {
                    m_TienDangCo+=m_SoTietKiem[0]->GetSoTien();
                    m_SoTietKiem.erase(m_SoTietKiem.begin());
                }
                m_TienDangCo-=TienNo2;
                cout<<"Da tra no 2"<<endl;
            }
            else
            {
                cout<<"No 2 qua han tra"<<endl;
            }
        }
        
        if (m_No1.DenHan(m_Thang, m_Nam)>0)
        {
                if (TongTietKiem(m_SoTietKiem)>TienNo1)
                {
                    while (m_TienDangCo<TienNo1)
                    {
                        m_TienDangCo+=m_SoTietKiem[0]->GetSoTien();
                        m_SoTietKiem.erase(m_SoTietKiem.begin());
                    }
                    m_TienDangCo-=TienNo1;
                    cout<<"Da tra no 1"<<endl;
                }
                else
                {
                    cout<<"No 1 qua han tra"<<endl;
                }
        }
            
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
            cout<<"3:Ket thuc thang \n";
            cout<<"4:Rut so tiet kiem \n";
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
            if (input==3)
            {
                BaoCaoThang();
                TinhToan();
                CapNhat();
                TraNo();
            }
            if (input==4)
            {
                RutTien();
            }
           
            
        }
   
    }
};


#endif /* Quanli_h */
