#include<bits/stdc++.h>
using namespace std;
const int maxn=1<<19;
int tam;
int tree[maxn];
int mdc(int a, int b){
    if(a>b)swap(a,b);
    if(a==0)return b;
    return mdc(b-a,a);
}
void update(int x, int k){
    x+=tam/2;
    tree[x]=k;
    for(k/=2;k>=1;k/=2)
        tree[k]=mdc(tree[2*k],tree[2*k+1]);
}
int query(int a, int b){
    int ans=0;
    a+=tam/2;
    b+=tam/2;
    while(a<=b){
        if(a%2==1)ans=mdc(ans,tree[a++]);
        if(b%2==0)ans=mdc(ans,tree[b--]);
        a/=2;b/=2;
    }
    return ans;
}
int main(){
    int n,q;
    cin>>n>>q;
    tam=(1<<((int)log2(n)+2));
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        update(i,a);
    }
    for(int i=0;i<q;i++){
        int op, a, b;;
        cin>>op>>a>>b;
        if(op==1)
            update(a,b);
        else
            cout<<query(a,b)<<endl;
    }
    return 0;
}