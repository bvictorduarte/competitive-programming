#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll m=1e9+7;
ll mod_pow(ll x, int n, ll m){
    if(n==0)
        return 1;
    ll u=mod_pow(x,n/2,m);
    u=(u*u)%m;
    if(n%2==1)
        u=(u*x)%m;
    return u;
}
int  main(){
    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<mod_pow(a,b,m)<<endl;
    }
    return 0;
}
