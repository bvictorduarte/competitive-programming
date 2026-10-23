#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=2e5+50;
#define l(p) (p<<1)
#define r(p) (p<<1)+1
ll st[4*maxn],v[4*maxn],n,lazy[4*maxn];
void propagate(ll p, ll L, ll R){
    if(lazy[p]!=0){
        st[p]+=lazy[p]*(R-L+1);
        if(L!=R){
            lazy[l(p)]+=lazy[p];
            lazy[r(p)]+=lazy[p];
        }
        else
            v[L]=lazy[p];
        lazy[p]=0;
    }
}
void build(ll p=1,ll L=1, ll R=n){
    if(L==R)
        st[p]=v[L];
    else{
        ll m=(L+R)/2;
        build(l(p),L,m);
        build(r(p),m+1,R);
        st[p]=st[l(p)]+st[r(p)];
    }
}
ll RSQ(ll i, ll j, ll p=1, ll L=1, ll R=n){
    propagate(p,L,R);
    if(i>R||j<L)return 0;
    if(L>=i&&R<=j)return st[p];
    ll m=(L+R)/2;
    return RSQ(i,j,l(p),L,m)+RSQ(i,j,r(p),m+1,R);
}
void update(ll i, ll j, ll val, ll p=1, ll L=1, ll R=n){
    propagate(p,L,R);
    if(i>R||j<L)return;
    if((L>=i)&&(R<=j)){
        lazy[p]+=val;
        propagate(p,L,R);
    }
    else{
        ll m=(L+R)/2;
        update(i,j,val,l(p),L,m);
        update(i,j,val,r(p),m+1,R);
        st[p]=st[l(p)]+st[r(p)];
    }
}
int main(){
    ll q;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    cin>>q;
    for(ll i=1;i<=n;i++){
        ll a;
        cin>>a;
        update(i,i,a);
    }
    while(q--){
        ll op;
        cin>>op;
        if(op==1){
            ll a,b,k;
            cin>>a>>b>>k;
            update(a,b,k);
        }else{
            ll k;
            cin>>k;
            cout<<RSQ(k,k)<<endl;
        }
    }
    return 0;
}