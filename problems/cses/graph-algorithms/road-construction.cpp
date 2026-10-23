#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+50;
int n_conex,n_max=1;
int lk[maxn],sz[maxn];
int find(int a){
    while(lk[a]!=a)
        a=lk[a];
    return a;
}
bool same(int a, int b){
    return find(a)==find(b);
}
void unite(int a,int b){
    if(same(a,b))
        return;
    a=find(a);
    b=find(b);
    if(sz[a]>=sz[b])
        swap(a,b);
    sz[b]+=sz[a];
    if(sz[b]>n_max)
        n_max=sz[b];
    n_conex--;
    lk[a]=b;
}
int main(){
    int n,m;
    cin>>n>>m;
    n_conex=n;
    for(int i=1;i<=n;i++){
        sz[i]=1;
        lk[i]=i;
    }
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        unite(a,b);
        cout<<n_conex<<" "<<n_max<<endl;
    }
    return 0;
}