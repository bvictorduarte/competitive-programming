#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll m=1e9+7;
ll bin_pow(ll a,ll b, ll m){
    if(b==0)
        return 1%m;
    ll u=bin_pow(a,b/2,m);
    u=(u*u)%m;
    if(b%2)
        u=(u*a)%m;
    return u;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ll a,b,c;
        cin>>a>>b>>c;
        b=bin_pow(b,c,m-1);
        cout<<bin_pow(a,b,m)<<endl;
    }
    return 0;
}