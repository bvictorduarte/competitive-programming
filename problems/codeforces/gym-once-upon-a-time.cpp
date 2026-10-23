#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll find_solve(ll a,ll b,ll& x,ll& y){
    if(!b){
        x=1;
        y=0;
        return a;
    }
    ll x1,y1,g;
    g=find_solve(b,a%b,x1,y1);
    x=y1;
    y=x1-(a/b)*y1;
    return g;
}
ll gcd(ll a,ll b){
    if(!b)return a;
    return gcd(b,a%b);
}
int main(){
    ll n,b,k,a,g;
    while(cin>>n>>b>>a>>k&&!(n==0&&b==0&&k==0&&a==0)){
        ll x,y;
        g=find_solve(a,-b,x,y);
        if((n-k)%g!=0)
            cout<<"Impossible"<<endl;
        else{
            x=x*((n-k)/g);
            g=gcd(a,b);
            ll p=b/g;
            if(x<=0)
                x+=(abs(x)/p+1)*p;
            else
                x-=p*((x-1)/p);
            p=a/g;
            y=(k+a*x-n)/b;
            if(y<0)
                y+=(abs(y)/p+1)*p;
            cout<<n+b*y<<endl;
        }
    }
    return 0;
}