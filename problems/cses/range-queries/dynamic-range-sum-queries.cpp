//            With BIT tree
#include<bits/stdc++.h>
using namespace std;
const int MAXN=2*(1e5)+50;
typedef long long ll;
ll prefix_sum[MAXN],tree[MAXN],v[MAXN];
ll sum1(int k){
    ll ans=0;
    while(k>=1){
        ans+=tree[k];
        k-=(k&-k);
    }
    return ans;
}
int main(){
    int n,q;
    cin>>n>>q;
    prefix_sum[0]=0;
    for(int i=1;i<=n;i++){
        ll a;
        cin>>a;
        v[i]=a;
        prefix_sum[i]=prefix_sum[i-1]+a;
    }
    for(int i=1;i<=n;i++)
        tree[i]=prefix_sum[i]-prefix_sum[i-(i&-i)];
    for(int i=0;i<q;i++){
        int op;
        scanf("%d", &op);
        if(op==1){
            int k;
            ll u;
            cin>>k>>u;
            int r=u-v[k];
            v[k]=u;
            while(k<=n){
                tree[k]+=r;
                k+=(k&-k);
            }
        }else{
            int a,b;
            scanf("%d %d", &a, &b);
            cout<<sum1(b)-sum1(a-1)<<endl;
        }
    }
    return 0;
}
/*          With Segtree
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1<<19;
const int logN=19;
typedef long long ll;
ll tree[MAXN];
void add(int k,ll x,int tam){
    k+=tam/2;
    tree[k]+=x;
    for(k/=2;k>=1;k/=2)
        tree[k]+=x;
}
ll query(int a,int b, int tam){
    a+=tam/2;
    b+=tam/2;
    ll sum=0;
    while(a<=b){
        if(a%2==1)sum+=tree[a++];
        if(b%2==0)sum+=tree[b--];
        a/=2;
        b/=2;
    }
    return sum;
}
int main(){
    int n,q;
    cin>>n>>q;
    int tam=1<<((int)log2(n)+2);
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        add(i,a,tam);
    }
    for(int i=0;i<q;i++){
        int op;
        scanf("%d", &op);
        if(op==1){
            int k;
            ll u;
            cin>>k>>u;
            k--;
            add(k,u-tree[k+tam/2],tam);
        }else{
            int a,b;
            scanf("%d %d", &a, &b);
            cout<<query(--a,--b,tam)<<endl;
        }
    }
    return 0;
}
*/