#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll abes(ll a){
    if(a>=0)return a;
    else return -a;
}
int main(){
    ll n,a;
    cin>>n>>a;
    ll aux=sqrt(a);
    ll ans;
    for(ll i=2*n;i>=1;i--)
        if(i==aux)continue;
        else if(abes(i*i-aux*aux)%(2*n+1)==0){
            ans=i;
            break;
        }
    cout<<ans*ans<<endl;
    return 0;
}