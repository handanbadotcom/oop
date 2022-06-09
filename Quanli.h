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
#include <fstream>
#include <stdio.h>

#define filename "BaoCao.csv"
#define savefile "Save.txt"



class QuanLi
{
protected:
    vector<ThuNhap*> m_ThuNhap; // danh sách thu nhập bên ngoài và bao gồm chi tiêu, số tiền chi tiêu là số âm, lúc tính tổng sẽ như yêu cầu của thầy là thu nhập chung trừ đi chi tiêu
    vector<ThuNhap*> m_Luong; // danh sách lương 2 vợ chồng, tổng lương còn lại mỗi cuối tháng sẽ đưa vào sổ tiết kiệm
    vector<SoTietKiem*> m_SoTietKiem; //danh sách sổ tk, sổ có -1 là sổ tk gia đình ko có lãi suất
    int m_Thang;
    int m_Nam;
    long m_TienDangCo; // tiền còn lại của tháng vừa rồi
    long m_TienTietKiem; // tổng tiền của m_SoTietKiem
    NoI m_No1;
    NoII m_No2;
    ofstream out;
public:
 
    QuanLi(string fname)
    {
        ifstream in(fname);
        if (in.is_open())
        {
            in>>m_Thang;
            in>>m_Nam;
            in>>m_TienDangCo;
            m_No1.NhapFile(in);
            m_No2.NhapFile(in);
            while (1)
            {
                if (in.eof())
                    break;
                SoTietKiem* tmp=new SoTietKiem(in);
                if (tmp->GetSoTien()>=0)
                m_SoTietKiem.push_back(tmp);
                
            }
            ifstream tmpin(filename);
            if (!tmpin.is_open())
            {
                tmpin.close();
                out.open(filename, std::ios_base::app);
                    out<<", Luong Vo, Luong Chong, Thu nhap chung, Dien/Nuoc, An uong, Khac,Tien thang vua roi, Thu nhap thang nay"<<endl;
            }
            else
                out.open(filename, std::ios_base::app);
            
        }
        else
        {
            m_Nam=2022;
            m_Thang=5;
            m_TienDangCo=0;
            m_TienTietKiem=0;
            m_No1.Nhap();
            m_No2.Nhap();
            ifstream tmpin(filename);
            if (!tmpin.is_open())
            {
                tmpin.close();
                out.open(filename, std::ios_base::app);
                    out<<", Luong Vo, Luong Chong, Thu nhap chung, Dien/Nuoc, An uong, Khac,Tien thang vua roi, Thu nhap thang nay"<<endl;
            }
            else
                out.open(filename, std::ios_base::app);
            
        }
          
    }
    QuanLi()
    {
        m_Nam=2022;
        m_Thang=5;
        m_TienDangCo=0;
        m_TienTietKiem=0;
        m_No1.Nhap();
        m_No2.Nhap();
        out.open(filename, std::ios_base::app);
        if (!out.is_open())
        {
            out<<", Luong Vo, Luong Chong, Thu nhap chung, Dien/Nuoc, An uong, Khac,Tien thang vua roi, Thu nhap thang nay"<<endl;
        }
    }
    void TinhTongVoChong(vector<ThuNhap*> a,long &LuongVo,long& LuongChong)
    {
        long LVo=0;
        long LC=0;
        for (int i=0;i<a.size();i++)
        {
            
            if (a[i]->getString()=="Vo")
                LVo+=a[i]->GetTien();
            else
                LC+=a[i]->GetTien();
        }
        LuongVo=LVo;
        LuongChong=LC;
    }
    void TongChiTieu(vector<ThuNhap*> a, long &DienNuoc, long &AnUong, long &Khac)
    {
        for (int i=0;i<a.size();i++)
        {
            if (a[i]->GetTien()<0)
            {
                if (a[i]->getString()=="Dien nuoc")
                    DienNuoc+=a[i]->GetTien();
                else
                if (a[i]->getString()=="An uong")
                    AnUong+=a[i]->GetTien();
                else
                    Khac+=a[i]->GetTien();
            }
        }
    }
    void TinhTongThuChi(vector<ThuNhap*> a,long &ThuNhap,long &ChiTieu)
    {
        long TongChi=0;
        long TongThu=0;
        for (int i=0;i<a.size();i++)
        {
            if (a[i]->GetTien()<0)
                TongChi+=a[i]->GetTien();
                else
                    TongThu+=a[i]->GetTien();
        }
        ThuNhap=TongThu;
        ChiTieu=TongChi;
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
        }
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
        long ChiTieu=0;
        long ThuNhapChung=0;
        long LuongChong=0;
        long LuongVo=0;
        long DienNuoc=0;
        long AnUong=0;
        long Khac=0;
        TinhTongVoChong(m_Luong,LuongVo,LuongChong);
        TinhTongThuChi(m_ThuNhap, ThuNhapChung, ChiTieu);
        TongChiTieu(m_ThuNhap, DienNuoc, AnUong, Khac);
        m_TienDangCo+=ThuChiThang;
        if (m_TienDangCo<0)
        {
            Luong+=m_TienDangCo;
            m_TienDangCo=0;
        }
        cout<<"Bao cao thang "<<m_Thang<<" nam "<<m_Nam<<endl;
        cout<<"Thu(nguon thu khac)-Chi: "<<ThuChiThang<<endl;
        cout<<"Tinh hinh thu nhap cua thang: ";
        if (ThuChiThang>0)
        {
            cout<<">0"<<endl;
        }
        if (ThuChiThang<0)
        {
            cout<<"=0"<<endl;
        }
        
        if (Luong<0)
        {
            cout<<"Thong bao pha san"<<endl;
            exit(0);
        }
        cout<<"Luong con lai: "<<Luong<<endl;
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
            SoTietKiem* tmp= new SoTietKiem(m_Thang,m_Nam,-1,0,Luong);
            m_SoTietKiem.push_back(tmp);
        }
        out<<"Thang "<<m_Thang<<" Nam "<<m_Nam<<", "<<LuongVo<<", "<<LuongChong<<", "<<ThuNhapChung<<", "<<DienNuoc<<", "<<AnUong<<", "<<Khac<<", "<<m_TienDangCo<<", "<<Luong<<endl;
    }
   
   
    void TinhToan()
    {
        
        // hàm tính toán ưu tiên trả nợ gần hạn nhất
        // cách hoạt động là chương trình mô phỏng lặp lại kết thúc tháng sẽ tự thêm sổ tiết kiệm của tháng vừa rồi đến khi mà đến hạn nợ gần nhất
        //thì trả nợ rồi lại thêm sổ tiếp tục vào đến khi hết hạn nợ sau
        vector<SoTietKiem*> Tk;
        long Tien=m_TienDangCo;
        
        //tạo bản sao của m_SoTietKiem
        for (int i=0;i<m_SoTietKiem.size();i++)
        {
            SoTietKiem* tmp=new SoTietKiem(m_SoTietKiem[i]);
            Tk.push_back(tmp);
        }
        //
        int Thang=m_Thang;
        int Nam=m_Nam;
        SoTietKiem* SoMoiNhat=new SoTietKiem(Tk[Tk.size()-1]); // sổ tiết kiệm mới nhất
        
        //lặp thêm sổ của tháng vừa rồi đến khi đến hạn, mỗi lần thêm sổ mới thì các sổ cũ sẽ tự động cập nhật tiền
        while (!m_No2.DenHan(Thang, Nam))
        {
            SoTietKiem* tmp=new SoTietKiem(SoMoiNhat); // thêm sổ mới nhất vào
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
        
        //kiểm tra và trả nợ 2
        long TienNo2=m_No2.tongTienPhaiTraNo();
        if (Tien+TongTietKiem(Tk)>=TienNo2)
        {
            while (Tien<TienNo2)
            {
                Tien+=Tk[0]->GetSoTien();
                Tk.erase(Tk.begin());
            }
            Tien-=TienNo2;
            cout<<"Du doan co kha nang tra no 2"<<endl;
        }
        else
        {
            cout<<"Du doan khong co kha nang tra no 2"<<endl;
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
       
        //kiểm tra và trả nợ 1
        long TienNo1=m_No1.tongTienPhaiTraNo();
        if (Tien+TongTietKiem(Tk)>=TienNo1)
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
        for (int i=0;i<Tk.size();i++)
        {
            Tk[i]=NULL;
        }
    }
    void TraNo()
    {
        long TienNo2=m_No2.tongTienPhaiTraNo();
        long TienNo1=m_No1.tongTienPhaiTraNo();
        if (m_No2.DenHan(m_Thang, m_Nam)>0)
        {
            if (m_TienDangCo+TongTietKiem(m_SoTietKiem)>TienNo2)
            {
                while (m_TienDangCo<TienNo2)
                {
                    m_TienDangCo+=m_SoTietKiem[0]->GetSoTien();
                    m_SoTietKiem.erase(m_SoTietKiem.begin());
                }
                m_TienDangCo-=TienNo2;
                cout<<"Da tra no 2"<<endl;
                m_No2.DaTraNo();
            }
            else
            {
                cout<<"No 2 qua han tra"<<endl;
            }
        }
        
        if (m_No1.DenHan(m_Thang, m_Nam)>0)
        {
                if (m_TienDangCo+TongTietKiem(m_SoTietKiem)>TienNo1)
                {
                    while (m_TienDangCo<TienNo1)
                    {
                        m_TienDangCo+=m_SoTietKiem[0]->GetSoTien();
                        m_SoTietKiem.erase(m_SoTietKiem.begin());
                    }
                    m_TienDangCo-=TienNo1;
                    cout<<"Da tra no 1"<<endl;
                    m_No1.DaTraNo();
                }
                else
                {
                    cout<<"No 1 qua han tra"<<endl;
                }
        }
            
    }
    void XuatFile(string name)
    {
        ofstream out(name);
        out<<m_Thang<<" "<<m_Nam<<" "<<m_TienDangCo<<" "<<endl;
        m_No1.XuatFile(out);
        m_No2.XuatFile(out);
        for(int i=0;i<m_SoTietKiem.size();i++)
        {
            m_SoTietKiem[i]->XuatFile(out);
        }
        out<<-1;
    }
    void Menu()
    {
        while (1)
        {
            cout<<"\n";
            cout<<"----------------\n";
            cout<<"Thang "<<this->m_Thang<<"/"<<this->m_Nam<<"\n";
            cout<<"Tien tiet kiem: "<<TongTietKiem(m_SoTietKiem)<<"\n";
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
            {
                out.close();
                return;
            }
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
                XuatFile("save.txt");
            }
            if (input==4)
            {
                RutTien();
            }
           
            
        }
   
    }
    ~QuanLi()
    {
        for (int i=0;i<m_Luong.size();i++)
        {
            m_Luong[i]=NULL;
        }
        for (int i=0;i<m_SoTietKiem.size();i++)
        {
            m_SoTietKiem[i]=NULL;
        }
        for (int i=0;i<m_ThuNhap.size();i++)
        {
            m_ThuNhap[i]=NULL;
        }
        
    }
};


#endif /* Quanli_h */
