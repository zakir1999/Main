#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;while (t--)
    {

        
        bool flag=false;
        for(int i=0;i<8;i++){
            string s;
            cin>>s;
            int countr=0;
            for(int j=0;j<8;j++){
                if(s[j]=='R')countr++;
            }
            if(countr==8){
                flag=true; 
            }   
        }
        if(flag)cout<<"R"<<endl;
        else cout<<"B"<<endl;
        
    }

    return 0;
    
}