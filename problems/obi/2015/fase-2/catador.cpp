#include<bits/stdc++.h>
using namespace std;
const int maxN=1<<19;
typedef long long ll;
ll tree[maxN];
vector<ll> v;
ll tam;
void update(ll k, ll u){
    k+=tam/2;
    while(k>=1){
        tree[k]+=u;
        k/=2;
    }
}
ll query(ll b){
    ll a=0, sum=0;
    a+=tam/2;
    b+=tam/2;
    while(b>=a){
        if(a%2==1)sum+=tree[a++];
        if(b%2==0)sum+=tree[b--];
        a/=2;b/=2;
    }
    return sum;
}
int main(){
    ll n,m;
    cin>>n>>m;
    tam=1<<((ll)log2(n)+2);
    v.push_back(0);
    for(ll i=0;i<n;i++){
        ll a;
        cin>>a;
        v.push_back(a);
        update(i,a-v[i]);
    }
    for(ll i=0;i<m;i++){
        ll k,u,a,b;
        cin>>k;
        u=query(--k);
        if(u>0){
            a=k-u;
            b=k+u+1;
            if(a<=0)
                a=0;
            update(a,-1);
            if(b<tam/2)
                update(b,1);
        }
    }
    ll sum=0;
    for(ll i=0;i<n;i++){
        ll u=query(i);
        if(u>0)
            sum+=u;
    }
    cout<<sum<<endl;
    return 0;
}