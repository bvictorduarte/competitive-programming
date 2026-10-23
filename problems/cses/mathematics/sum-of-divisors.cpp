#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll m=1e9+7;
ll ap_sum(ll x){
    return (((x%m)*((x+1)%m))/2)%m;
}
int main(){
    ll n,ans=0;
    cin>>n;
    ll l;
    for(l=1;l*l<=n;l++){
        ans+=(l%m)*((n/l)%m);
        ans%=m;
    }
    for(ll i=(ll)sqrt(n);i>=1;i--){
        ll r=n/i;
        ans+=(ap_sum(r))*(i%m);
        ans-=(ap_sum(l-1))*(i%m);
        ans=(ans+m)%m;
        l=r+1;
    }
    cout<<ans<<endl;
    return 0;
}