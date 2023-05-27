#include <iostream>
#include <math.h>
bool isPrime(int n){
    if(n < 2) return false;
    for(int i=2 ;i<=sqrt(n);++i){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int n=0;

    std::cout<<"输入-1结束\n";
    std::cin>>n;
    while (n > 0)
    {
        if(isPrime(n)){
            std::cout<<n<<"是素数"<<std::endl;
        }else{
            std::cout<<n<<"不是素数"<<std::endl;
        }
        std::cin>>n;
    }

    return 0;
}