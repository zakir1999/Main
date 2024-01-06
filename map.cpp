#include<iostream>
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    ll t;cin>>t;while (t--)
   {
        ll n;cin>>n;
        map<ll,ll>a;
        map<ll,ll>::iterator it;
       ll d;
        for(ll i=1;i<=n;i++){
            cin>>d;
            it=a.find(d);
            if(it!=a.end()){
                it->second++;
            }
            else 
            a.insert(make_pair(d,1));
        }
        ll sum=0;
         for(it=a.begin();it!=a.end();it++){
             sum+=((it->second)*((it->second)-1))/2;
           }
        cout<<sum<<endl;
           
    }
    
}