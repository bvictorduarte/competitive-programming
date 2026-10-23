#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e3+50;
const ll LINF=0x3f3f3f3f3f3f3f3f;
ll dist[maxn];
int n,m,p[maxn];
vector<tuple<int,int,ll>> edges;
vector<int> adj[maxn];
int bellman_ford(){
    int x;
    for(int i=1;i<=n;i++)
        dist[i]=LINF;
    dist[1]=0;
    for(int i=1;i<=n;i++){
        x=0;
        for(auto e:edges){
            int a,b;
            ll w;
            tie(a,b,w)=e;
            //if(dist[a]<LINF){ Isso só usa quando quiser as distâncias da componente
            if(dist[b]>dist[a]+w){
                dist[b]=max(-LINF,dist[a]+w);
                p[b]=a;
                x=b;
            }
            //}
        }
    }
    return x;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        ll w;
        cin>>a>>b>>w;
        edges.push_back(make_tuple(a,b,w));
        adj[a].push_back(b);
    }
    int x=bellman_ford();
    if(x){
        cout<<"YES\n";
        for(int i=1;i<=n;i++)
            x=p[x];
        vector<int> path;
        for(int cur=x;;cur=p[cur]){
            path.push_back(cur);
            if(cur==x&&(int)path.size()>1)
                break;
        }
        reverse(path.begin(),path.end());
        for(auto u:path)
            cout<<u<<' ';
        cout<<'\n';
    }
    else
        cout<<"NO\n";

    return 0;
}