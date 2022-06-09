//
//  No.h
//  oop
//
//  Created by Phạm Nguyên on 25/05/2022.
//

#ifndef No_h
#define No_h

#pragma once
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
class No
{
protected:
    long long m_No;
    int m_ThangTraNo;
    int m_NamTraNo;
    int m_soThangTraNo;
public:
    No()
    {
        m_No=0;
        m_ThangTraNo=0;
        m_NamTraNo=0;
        m_soThangTraNo=0;
    }
    int DenHan(int thang, int nam)
    {
        if (m_ThangTraNo==thang && m_NamTraNo==nam)
        {
            return 1;
        }
        if (m_ThangTraNo<=thang && m_NamTraNo<=nam)
        {
            return 2;
        }
        return 0;
    }
    void DaTraNo()
    {
        this->m_ThangTraNo=9999999;
        this->m_NamTraNo=99999999;
    }
    void XuatFile(ofstream& out)
    {
        out<<m_No<<" "<<m_ThangTraNo<<" "<<m_NamTraNo<<" "<<m_soThangTraNo<<endl;
    }
    void NhapFile(ifstream& in)
    {
        in>>m_No>>m_ThangTraNo>>m_NamTraNo>>m_soThangTraNo;
    }
};
class NoI: public No
{
private:
    double m_LaiNo;
public:
    NoI():No()
    {
        m_LaiNo=0;
    }
    void Nhap()
    {
        cout << "\n--------Moi nhap thong tin No 1 -------------\n";
        cout << "Moi nhap so tien cua no 1:\n";
        long long No;
        cin >> No;
        this->m_No = No;
        cout << "Moi nhap lai cua no 1:\n";
        double lai;
        cin >> lai;
        this->m_LaiNo = lai;
        cout << "Moi nhap thang nam tra no 1:\n";
        int thang, nam;
        cout << "----Nhap thang:\n";
        cin >> thang;
        cout << "----Nhap nam:\n";
        cin >> nam;
        this->m_ThangTraNo = thang;
        this->m_NamTraNo = nam;
        this->m_soThangTraNo = (nam-2022)*12+(thang-5);
        /*
        this->m_ThangTraNo++;
        if (this->m_ThangTraNo>12)
        {
            this->m_ThangTraNo=1;
            this->m_NamTraNo++;
        }*/
    }
    long long tongTienPhaiTraNo()
    {
        return this->m_No + this->m_No * this->m_LaiNo/100 * m_soThangTraNo/12;
    }
    bool DenHan(int thang, int nam)
    {
        return No::DenHan(thang , nam);
    }
   
    void DaTraNo()
    {
        No::DaTraNo();
    }
    void XuatFile(ofstream& out)
    {
        No::XuatFile(out);
        out<<m_LaiNo<<endl;
    }
    void NhapFile(ifstream& in)
    {
        No::NhapFile(in);
        in>>m_LaiNo;
    }
};


class NoII:public No
{
private:
    vector<double> m_LaiNoII;
public:
     NoII():No()
    {
    }
    void Nhap()
    {
        cout << "\n--------Moi nhap thong tin No II-------------\n";
        cout << "Moi nhap so tien cua no 2:\n";
        long long loanII;
        cin >> loanII;
        this->m_No = loanII;
        cout << "Moi nhap thang nam tra no 2:\n";
        int thangII, namII;
        cout << "----Nhap thang:\n";
        cin >> thangII;
        cout << "----Nhap nam:\n";
        cin >> namII;
        this->m_ThangTraNo = thangII;
        this->m_NamTraNo = namII;
        this->m_soThangTraNo = (namII-2022)*12+(thangII-5);
        
        cout << "No 2 se tinh lai theo tung thang! Moi nguoi dung nhap :\n";
        for (int i = 1; i <= this->m_soThangTraNo; i++)
        {
            double laithang;
            cout << "Thang thu " << i << "(%): ";
            cin >> laithang;
            this->m_LaiNoII.push_back(laithang);
        }
        /*
        this->m_ThangTraNo++;
        if (this->m_ThangTraNo>12)
        {
            this->m_ThangTraNo=1;
            this->m_NamTraNo++;
        }*/
        
    }
    long long tongTienPhaiTraNo()
    {
        long long sum = 0;
        for (int i = 0; i < this->m_soThangTraNo; i++)
        {
            sum = sum + this->m_No * this->m_LaiNoII[i]/100;
        }
        return this->m_No + sum;
    }
    bool DenHan(int thang, int nam)
    {
        return No::DenHan(thang , nam);
    }
    void DaTraNo()
    {
        No::DaTraNo();
    }
    void XuatFile(ofstream& out)
    {
        No::XuatFile(out);
        for (int i = 0; i < this->m_soThangTraNo; i++)
        {
            out<<m_LaiNoII[i]<<" ";
        }
        out<<endl;
    }
    void NhapFile(ifstream& in)
    {
        No::NhapFile(in);
        for (int i = 0; i < this->m_soThangTraNo; i++)
        {
            double j;
            in>>j;
            m_LaiNoII.push_back(j);
            
        }
    }
    
};
#endif /* No_h */
