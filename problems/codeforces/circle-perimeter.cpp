#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll t;
    while(t--){
        ll r,cont=0;
        for(ll x=1;x<r+1;x++){
            ll e=r*r-x*x,d=e+2*r+1;
            ll tam=r+2;
            ll y=0;
            for(ll b=tam/2;b>=1;b/=2)
                while(y*y<d&&y+b<=tam)
                    y+=b;
            
        }
    }
    return 0;
}