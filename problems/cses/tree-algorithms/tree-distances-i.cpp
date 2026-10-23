#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxN=2e5+50;
pair<ll,int> dist_downward[maxN];
ll dist_upward[maxN],dist_downward2[maxN];
vector<ll> adj[maxN];
void compute_downwards(int x, int parent){
    if((int)adj[x].size()==1&&adj[x][0]==parent){
        dist_downward[x].first=0;
        dist_downward[x].second=-1;
    }
    for(auto u:adj[x])
        if(u!=parent){
            compute_downwards(u,x);
            if(dist_downward[x].first<dist_downward[u].first+1){
                dist_downward[x].first=dist_downward[u].first+1;
                dist_downward[x].second=u;
            }
        }
}
void compute_downwards2(int x, int parent){
        for(auto u:adj[x]){
            if(u!=parent){
                if(dist_downward[x].second!=u)
                    dist_downward2[x]=max(dist_downward2[x],dist_downward[u].first+1);
                compute_downwards2(u,x);
            }
        }
}
void compute_upwards(int x, int parent){
    for(auto u:adj[x]){
        if(u!=parent){
            ll m;
            if(dist_downward[x].second==u)
                m=dist_downward2[x];
            else
                m=dist_downward[x].first;
            dist_upward[u]=max(dist_upward[x]+1,m+1);
            compute_upwards(u,x);
        }

    }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(dist_downward,-1,sizeof(dist_downward));
    compute_downwards(1,0);
    dist_upward[1]=0;
    compute_downwards2(1,0);
    dist_upward[1]=0;
    compute_upwards(1,0);
    cout<<max(dist_upward[1],dist_downward[1].first);
    for(int i=2;i<=n;i++)
        cout<<" "<<max(dist_upward[i],dist_downward[i].first);
    cout<<endl;
    return 0;
}