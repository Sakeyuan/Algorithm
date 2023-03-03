/**
 * @file gcd.cpp
 * @author your name (you@domain.com)
 * @brief 欧几里得算法（辗转相除法）
 * @version 0.1
 * @date 2022-10-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
int gcd(int p,int q){
    if(q==0)  return p;
    int r=p%q;
    return gcd(q,r);
}
int gcd_1(int p,int q){
    int r=0;
    while (1)
    {
        if(q==0)  break;
        r=p%q;
        p=q;
        q=r;
    }
    return p;  
}
int main(){
    std::cout<<gcd(35,7)<<std::endl;
    std::cout<<gcd_1(35,7)<<std::endl;
    system("pause");
    return 0;
}