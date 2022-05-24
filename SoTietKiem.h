//
//  SoTietKiem.h
//  oop
//
//  Created by Phạm Nguyên on 24/05/2022.
//

#ifndef SoTietKiem_h
#define SoTietKiem_h


class SoTietKiem
{
private:
    int KyHan;
    int ThangConLai;
    float LaiSuat;
    long SoTien;
public:
    SoTietKiem()
    {
        this->KyHan=0;
        this->LaiSuat=0;
        this->SoTien=0;
        this->ThangConLai=this->KyHan;
    }
    SoTietKiem(int KyHan, float LaiSuat, long SoTien)
    {
        this->KyHan=KyHan;
        this->LaiSuat=LaiSuat;
        this->SoTien=SoTien;
        this->ThangConLai=this->KyHan;
    }
    void Nhap()
    {
        cout<<"1. 6 thang - 6% \n";
        cout<<"2. 12 thang - 6.6% \n";
        int inp=0;
        while (inp!=1 && inp!=2)
        {
            cout<<"Moi chon: ";
            cin>>inp;
        }
        if (inp==1)
        {
            this->KyHan=6;
            this->LaiSuat=6;
            this->ThangConLai=6;
        }
        else
        {
            this->KyHan=12;
            this->LaiSuat=6.6;
            this->ThangConLai=12;
        }
    }
    void CapNhat()
    {
        if (this->ThangConLai==0)
            return;
        if (this->ThangConLai>0)
            this->ThangConLai--;
        if (this->ThangConLai==0)
        SoTien=SoTien+SoTien*LaiSuat*KyHan/12;
    }
    long GetSoTien()
    {
        return this->SoTien;
    }
};

#endif /* SoTietKiem_h */