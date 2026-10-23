#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define l(p) (p<<1)
#define r(p) (l(p)+1)
const ll maxn=1e5+10;
ll st[4*maxn][3],lazy[4*maxn],n;
void build(ll p=1, ll L=1, ll R=n){
    lazy[p]=0;
    if(L==R){
        st[p][0]=1;
        st[p][1]=st[p][2]=0;
    }
    else{
        ll m=(L+R)/2;
        build(l(p),L,m);
        build(r(p),m+1,R);
        for(ll i=0;i<3;i++)
            st[p][i]=st[l(p)][i]+st[r(p)][i];
    }
}
void propagate(ll p, ll L, ll R){
    if(lazy[p]){
        ll aux[3];
        for(ll i=0;i<3;i++)
            aux[i]=st[p][i];
        for(ll i=0;i<3;i++)
            st[p][(i+lazy[p])%3]=aux[i];
        if(L!=R){
            lazy[l(p)]+=lazy[p];
            lazy[r(p)]+=lazy[p];
        }
        lazy[p]=0;
    }
}
array<ll,3> query(ll i, ll j, ll p=1, ll L=1, ll R=n){
    propagate(p,L,R);
    array<ll,3> u;
    u[0]=u[1]=u[2]=0;
    if(i>R||j<L)return u;
    if(L>=i&&R<=j){
        for(ll k=0;k<3;k++)
            u[k]=st[p][k];
        return u;
    }
    ll m=(L+R)/2;
    array<ll,3> aux;
    aux=query(i,j,l(p),L,m);
    u=query(i,j,r(p),m+1,R);
    for(ll k=0;k<3;k++)
        u[k]+=aux[k];
    return u;
}
void change(ll i, ll j, ll p=1, ll L=1, ll R=n){
    propagate(p,L,R);
    if(i>R||j<L)return;
    if(L>=i&&R<=j){
        lazy[p]=1;
        propagate(p,L,R);
    }else{
        ll m=(L+R)/2;
        change(i,j,l(p),L,m);
        change(i,j,r(p),m+1,R);
        for(ll k=0;k<3;k++)
            st[p][k]=st[l(p)][k]+st[r(p)][k];
    }
}
int main(){
    array<ll,3> ans;
    string op;
    ll a,b;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin>>n){
        ll q;
        cin>>q;
        build();
        for(ll i=0;i<q;i++){
            cin>>op;
            cin>>a>>b;
            if(op=="C"){
                ans=query(a,b);
                cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<"\n";
            }else
                change(a,b);
        }
        cout<<"\n";
    }
    return 0;
}