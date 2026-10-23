#include<bits/stdc++.h>
using namespace std;
const int maxN=2*(1e5)+50;
typedef long long ll;
int n;
ll tree[maxN];
vector<ll> v;
ll query(int k){
    ll sum=0;
    while(k>=1){
        sum+=tree[k];
        k-=(k&-k);
    }
    return sum;
}
void update(int a, int b, ll u){
    b++;
    while(a<=n){
        tree[a]+=u;
        a+=(a&-a);
    }
    while(b<=n){
        tree[b]-=u;
        b+=(b&-b);
    }
}
void set_tree(int a, ll u){
    while(a<=n){
        tree[a]+=u;
        a+=(a&-a);
    }
}
int main(){
    int q;
    cin>>n>>q;
    v.push_back(0);
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        v.push_back(a);
        set_tree(i+1, a-v[i]);
    }
    for(int i=0;i<q;i++){
        int op;
        cin>>op;
        if(op==1){
            int a,b;
            ll u;
            cin>>a>>b>>u;
            update(a,b,u);
        }else{
            int k;
            cin>>k;
            cout<<query(k)<<endl;
        }
    }
    return 0;
}