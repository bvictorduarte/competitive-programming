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
    int m;
    cin>>n>>m;
    v.push_back(0);
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        v.push_back(a);
        set_tree(i+1, a-v[i]);
    }
    for(int i=0;i<m;i++){
        int b;
        cin>>b;
        b++;
        ll q=query(b);
        update(b,b,-query(b));
        update(1,n,q/n);
        ll y=q%n;
        if(y<=n-b)
            update(b+1,b+y,1);
        else{
            update(b+1,n,1);
            update(1,y-(n-b),1);
        }
    }
    cout<<query(1);
    for(int i=2;i<=n;i++)
        cout<<" "<<query(i);
    cout<<endl;
    return 0;
}