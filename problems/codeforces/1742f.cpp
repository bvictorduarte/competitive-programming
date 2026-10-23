#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin>>t;
    while(t--){
        int q;
        cin>>q;
        ll a1=1,a2=1,na1=0,na2=0;
        while(q--){
            ll d,k;
            cin>>d>>k;
            string s;
            cin>>s;
            if(d==1)
                for(auto u:s)
                    if(u=='a')a1+=k;
                    else na1+=k;
            else
                for(auto u:s)
                    if(u=='a')a2+=k;
                    else na2+=k;
            if(na2!=0||(a1<a2&&na1==0))
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }


    return 0;
}