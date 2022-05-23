//
//  main.cpp
//  oop
//
//  Created by Phạm Nguyên on 21/05/2022.
//

#include <iostream>
#include "NguonThu.h"

int main() {
    
    ThuNhap** a;
    a=new ThuNhap*[2];
    CoBan b;
    Chung c;
    a[0]=&b;
    a[1]=&c;
    a[0]->nhap();
    a[1]->nhap();
    
  
}
