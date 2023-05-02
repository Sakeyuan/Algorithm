#include<iostream>
#include"Vector.h"
#include<vector>
using namespace yjf::stl;
using namespace std;
int main(){
    Vector<int>v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.erase(v.begin(),v.end());
    v.show();
    return 0;
}