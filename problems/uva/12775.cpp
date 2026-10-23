#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=1e8;
ll gcd(ll a,ll b,ll &x,ll&y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    ll x1,y1,g;
    g=gcd(b,a%b,x1,y1);
    x=y1;
    y=x1-(a/b)*y1;
    return g;
}
ll count_solves(ll a,ll b,ll c){
    ll x,y,g;
    g=gcd(a,b,x,y);
    if(c%g!=0||(x<=0&&y<=0))
        return 0;
    x*=(c/g);
    y*=(c/g);
    ll lcm=(a*b)/g;
    ll dx=lcm/a,dy=lcm/b;
    if(x<0){
        ll n=(-x)/dx;
        if((-x)%dx!=0)
            ++n;
        if(y-n*dy<0)
            return 0;
        y-=n*dy;
        return 1+(y/dy);
    }else if(y<0){
        ll n=(-y)/dy;
        if((-y)%dy!=0)
            ++n;
        if(x-n*dx<0)
            return 0;
        x-=n*dx;
        return 1+(x/dx);
    }
    ll n=(x/dx);
    y+=(n*dy);
    return 1+(y/dy);
}
int main(){
    int t;
    cin>>t;
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=1;i<=t;i++){
        ll a,b,c,d,ans=0;
        cin>>a>>b>>c>>d;
        for(ll i=0;d-i>=0;i+=c)
            ans+=count_solves(a,b,d-i);
        cout<<"Case "<<i<<": "<<ans<<"\n";
    }
    return 0;
}