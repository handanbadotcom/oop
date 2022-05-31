//
//  No.h
//  oop
//
//  Created by Phạm Nguyên on 25/05/2022.
//

#ifndef No_h
#define No_h

/*class Loan
{
private:
    long long loanI;
    long long loanII;
    double laiNoI;
    vector<double> laiNoII;
    thangnam datePayBackI;
    thangnam datePayBackII;
    int soThangTraNoI;
    int soThangTraNoII;
public:
    Loan()
    {
        this->loanI = 0;
        this->loanII = 0;
        this->laiNoI = 0;
        this->datePayBackI.thang = 0;
        this->datePayBackI.nam = 0;
        this->datePayBackII.thang = 0;
        this->datePayBackII.nam = 0;
        this->soThangTraNoI = 0;
        this->soThangTraNoII = 0;
    }
    void Nhap()
    {
        cout << "\n--------Moi nhap thong tin No I-------------\n";
        cout << "Moi nhap so tien cua no 1:\n";
        long long loanI;
        cin >> loanI;
        this->loanI = loanI;
        cout << "Moi nhap lai cua no 1:\n";
        double laiI;;
        cin >> laiI;
        this->laiNoI = laiI;
        cout << "Moi nhap thang nam tra no 1:\n";
        int thang, nam;
        cout << "----Nhap thang:\n";
        cin >> thang;
        cout << "----Nhap nam:\n";
        cin >> nam;
        this->datePayBackI.thang = thang;
        this->datePayBackI.nam = nam;
        if (nam > 2022)
        {
            this->soThangTraNoI = 12 - 5 + thang;
        }
        else
        {
            this->soThangTraNoI = thang - 5;
        }
        cout << "\n--------Moi nhap thong tin No II-------------\n";
        cout << "Moi nhap so tien cua no 2:\n";
        long long loanII;
        cin >> loanII;
        this->loanII = loanII;
        cout << "Moi nhap thang nam tra no 2:\n";
        int thangII, namII;
        cout << "----Nhap thang:\n";
        cin >> thangII;
        cout << "----Nhap nam:\n";
        cin >> namII;
        this->datePayBackII.thang = thangII;
        this->datePayBackII.nam = namII;
        int sothangtranoII;
        if (namII > 2022)
        {
            this->soThangTraNoII = 12 - 5 + thangII;
        }
        else
        {
            this->soThangTraNoII = thangII - 5;
        }
        cout << "No 2 se tinh lai theo tung thang! Moi nguoi dung nhap :\n";
        for (int i = 1; i <= this->soThangTraNoII; i++)
        {
            double laithang;
            cout << "Thang thu " << i << "(%): ";
            cin >> laithang;
            this->laiNoII.push_back(laithang);
        }
    }
    long long tongTienPhaiTraNoII()
    {
        long long sum = 0;
        for (int i = 0; i < this->soThangTraNoII; i++)
        {
            sum = sum + this->loanII * this->laiNoII[i]/100;
        }
        return this->loanII + sum;
    }
    long long tongTienPhaiTraNoI()
    {
        return this->loanI + this->loanI * this->laiNoI/100 * 3;
    }
};*/
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
    }
    long long tongTienPhaiTraNo()
    {
        return this->m_No + this->m_No * this->m_LaiNo/100 * 3;
    }
    bool DenHan(int thang, int nam)
    {
        return No::DenHan(thang , nam);
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
};
#endif /* No_h */
