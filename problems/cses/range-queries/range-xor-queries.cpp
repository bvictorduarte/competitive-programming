#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define l(p) (p<<1)
#define r(p) (l(p)+1)
const ll maxn=2e5+50;
ll v[maxn],st[4*maxn],lazy[4*maxn],n;
void build(ll p=1, ll L=1, ll R=n){
    lazy[p]=-1;
    if(L==R)
        st[p]=v[L];
    else{
        ll m=(L+R)/2;
        build(l(p),L,m);
        build(r(p),m+1,R);
        st[p]=st[l(p)]^st[r(p)];
    }
}
ll RXQ(ll i, ll j, ll p=1, ll L=1, ll R=n){
    if(i>R||j<L)return 0;
    if(R<=j&&L>=i)return st[p];
    ll m=(L+R)/2;
    return (RXQ(i,j,l(p),L,m)^RXQ(i,j,r(p),m+1,R));
}
int main(){
    ll q;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(ll i=1;i<=n;i++)
        cin>>v[i];
    build();
    for(ll i=1;i<=q;i++){
        ll a,b;
        cin>>a>>b;
        cout<<RXQ(a,b)<<endl;
    }
    return 0;
}