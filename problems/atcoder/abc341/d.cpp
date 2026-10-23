#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
ll n,m,k,lc;
ll gcd(ll a, ll b){
    if(b==0)return a;
    return gcd(b,a%b);
}
bool solve(ll a){
    return (a/n)+(a/m)-2*(a/lc)>=k;
}
int main(){
    cin>>n>>m>>k;
    lc=n*m/gcd(n,m);
    ll ans=0;
    for(ll b=LINF/2;b>=1;b/=2){
        while(!solve(ans+b))ans+=b;
    }
    cout<<ans+1<<endl;
    return 0;
}