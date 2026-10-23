#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
ll z=1e18;
ll sum(ll a){
    ll s=0;
    for(auto u:v){
        s+=a/u;
        if(s>=z)
            break;
    }
    return s;
}
int main(){
    ll t,ans=0;
    int n;
    cin>>n>>t;
    for(int i=0;i<n;i++){
        ll k;
        cin>>k;
        v.push_back(k);
    }
    for(ll b=z;b>=1;b/=2){
        while(ans+b<=z&&t>sum(ans+b))
            ans+=b;
    }
    cout<<ans+1<<endl;
    return 0;
}