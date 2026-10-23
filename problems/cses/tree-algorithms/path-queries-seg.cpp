#include<bits/stdc++.h>
using namespace std;
#define l(p) (p<<1)
#define r(p) l(p)+1
const int maxn=1e6;
typedef long long int ll;
int n,posi[maxn],tin,tam_sub[maxn];
ll st[4*maxn],lazy[4*maxn],v[maxn],dist[maxn];
vector<int> adj[maxn];
void dfs(int x, int p){
    posi[x]=tin++;
    dist[posi[x]]=dist[posi[p]]+v[x];
    for(auto u:adj[x])
        if(u!=p){
            dfs(u,x);
            tam_sub[x]+=tam_sub[u];
        }
    tam_sub[x]++;
}
void build(int p=1, int L=0, int R=n-1){
    if(L==R)
        st[p]=dist[L];
    else{
        int m=(L+R)/2;
        build(l(p),L,m);
        build(r(p),m+1,R);
        st[p]=st[l(p)]+st[r(p)];
    }
}
void propagate(int p, int L, int R){
    if(lazy[p]){
        st[p]+=lazy[p]*(R-L+1);
        if(L==R)
            dist[L]+=lazy[p];
        else{
            lazy[l(p)]+=lazy[p];
            lazy[r(p)]+=lazy[p];
        }
        lazy[p]=0;
    }
}
ll RSQ(int i, int j, int p=1, int L=0, int R=n-1){
    propagate(p,L,R);
    if(i>R||j<L)
        return 0;
    else if(L>=i&&R<=i)
        return st[p];
    int m=(L+R)/2;
    return (RSQ(i,j,l(p),L,m)+RSQ(i,j,r(p),m+1,R));
}
void update(int i, int j, int a, int p=1, int L=0, int R=n-1){
    propagate(p,L,R);
    if(i>R||j<L)return;
    if(L>=i&&R<=j){
        lazy[p]+=1LL*a;
        propagate(p,L,R);
    }else{
        int m=(L+R)/2;
        update(i,j,a,l(p),L,m);
        update(i,j,a,r(p),m+1,R);
        st[p]=st[l(p)]+st[r(p)];
    }
}
int main(){
    int q;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=1;i<=n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    build();
    for(int i=1;i<=q;i++){
        int op;
        cin>>op;
        if(op==1){
            int s,x;
            cin>>s>>x;
            update(posi[s],posi[s]+tam_sub[s]-1,x-v[s]);
            v[s]=x;
        }else{
            int s;
            cin>>s;
            cout<<RSQ(posi[s],posi[s])<<endl;
        }
    }
    return 0;
}