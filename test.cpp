   #include<iostream>
   #include<string>
   using namespace std; 
    bool isValid(string s) {
        bool flag=false;
        for(int i=0;i<s.size();i++){
            bool f=false;
            for(int j=i+1;j<s.size();++j){
                if(s[i]==s[j]) f=true;
            }
            if(f) flag=true;
        }
        return flag;
    }
    int main(){
        string s="()";
        s.find("s");
        isValid(s);
        return 0 ;
    }