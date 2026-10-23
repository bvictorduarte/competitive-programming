#include<bits/stdc++.h>
using namespace std;
const int maxN=1<<19;
int tree[maxN];
int tam;
void update(int k, int u){
    k+=tam/2;
    tree[k]+=u;
    for(k/=2;k>=1;k/=2)
        tree[k]=tree[2*k]+tree[2*k+1];
}
int query(int a, int b){
    a+=tam/2;b+=tam/2;
    int sum=0;
    while(a<=b){
        if(a%2==1)sum+=tree[a++];
        if(b%2==0)sum+=tree[b--];
        a/=2;b/=2;
    }
    return sum;
}
int main(){
    int n,q;
    cin>>n>>q;
    tam=1<<((int)log2(n)+2);
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        update(i,a);
    }
    for(int i=0;i<q;i++){
        int op;
        cin>>op;
        if(op){
            int k;
            cin>>k;
            cout<<query(0,--k)<<endl;
        }else{
            int k,p;
            cin>>k>>p;
            update(k-1,p-tree[k-1+tam/2]);
        }
    }
    return 0;
}