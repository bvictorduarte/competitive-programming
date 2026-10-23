#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+50;
int st[4*maxn],n,depth[maxn],parent[maxn],head[maxn],heavy[maxn],posi[maxn],t=1,v[maxn];
vector<int> adj[maxn];
void update(int k, int a){
    k+=n;
    st[k]=a;
    for(k/=2;k>=1;k/=2)
        st[k]=max(st[2*k],st[2*k+1]);
}
int rmq(int a, int b){
    int ans=-1;
    a+=n;
    b+=n;
    while(a<=b){
        if(a%2==1)ans=max(ans,st[a++]);
        if(b%2==0)ans=max(ans,st[b--]);
        a/=2;
        b/=2;
    }
    return ans;
}
int dfs(int x=1, int p=1){
    int sz=1;
    int max_sz_u=0;
    parent[x]=p;
    depth[x]=depth[p]+1;
    for(auto u:adj[x])
        if(u!=p){
            int sz_u=dfs(u,x);
            sz+=sz_u;
            if(sz_u>max_sz_u){
                heavy[x]=u;
                max_sz_u=sz_u;
            }
        }
    return sz;
}
void decompose(int x=1, int h=1){
    head[x]=h;
    posi[x]=t++;
    if(heavy[x])
        decompose(heavy[x],h);
    for(auto u:adj[x])
        if(u!=parent[x]&&u!=heavy[x])
            decompose(u,u);
}
int query(int a, int b){
    int ans=-1;
    while(head[a]!=head[b]){
        if(depth[head[a]]<depth[head[b]])swap(a,b);
        ans=max(ans,rmq(posi[head[a]],posi[a]));
        a=parent[head[a]];
    }
    if(depth[a]<depth[b])swap(a,b);
    ans=max(ans,rmq(posi[b],posi[a]));
    return ans;
}
void ini_seg(){
    for(int i=1;i<=n;i++)
        update(posi[i],v[i]);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs();
    decompose();
    ini_seg();
    vector<int> ans;
    for(int i=1;i<=q;i++){
        int op,a,b;
        cin>>op>>a>>b;
        if(op==1)
            update(posi[a],b);
        else
            ans.push_back(query(a,b));
    }
    if(!ans.empty())
        cout<<ans[0];
    for(int i=1;i<(int)ans.size();i++)
        cout<<" "<<ans[i];
    cout<<'\n';
    return 0;
}