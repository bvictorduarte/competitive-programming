#include<bits/stdc++.h>
using namespace std;
#define l(p) (p<<1)
#define r(p) (l(p)+1)
typedef long long ll;
const ll maxn=2e5+50;
const ll LINF=0x3f3f3f3f3f3f3f3f;
ll v[4*maxn],lazy[4*maxn],st[4*maxn],n;
void build(ll p=1, ll L=1, ll R=n){
    if(L==R)
        st[p]=v[L];
    else{
        ll m=(L+R)/2;
        build(l(p),L,m);
        build(r(p),m+1,R);
        st[p]=min(st[l(p)],st[r(p)]);
    }
}
void propagate(ll p, ll L, ll R){
    if(lazy[p]!=0){
        st[p]=lazy[p];
        if(L==R)
            v[L]=st[p];
        else
            lazy[l(p)]=lazy[r(p)]=lazy[p];
        lazy[p]=0;
    }
}
ll RMQ(ll i, ll j, ll p=1, ll L=1, ll R=n){
    propagate(p,L,R);
    if(i>R||j<L)return LINF;
    if(L>=i&&R<=j)return st[p];
    ll m=(L+R)/2;
    return min(RMQ(i,j,l(p),L,m),RMQ(i,j,r(p),m+1,R));
}
void upd(ll i, ll j, ll k, ll p=1, ll L=1, ll R=n){
    propagate(p,L,R);
    if(i>R||j<L)return;
    if(L>=i&&R<=j){
        lazy[p]=k;
        propagate(p,L,R);
    }else{
        ll m=(L+R)/2;
        upd(i,j,k,l(p),L,m);
        upd(i,j,k,r(p),m+1,R);
        st[p]=min(st[l(p)],st[r(p)]);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll q;
    cin>>n>>q;
    for(ll i=1;i<=n;i++)
        cin>>v[i];
    build();
    for(ll i=1;i<=q;i++){
        ll op;
        cin>>op;
        if(op==1){
            ll k,u;
            cin>>k>>u;
            upd(k,k,u);
        }else{
            ll a,b;
            cin>>a>>b;
            cout<<RMQ(a,b)<<endl;
        }
    }
    return 0;
}