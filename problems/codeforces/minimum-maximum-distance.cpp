#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxN=2e5+50;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
pair<ll,int> dist_downward[maxN];
ll dist_upward[maxN],dist_downward2[maxN];
vector<ll> adj[maxN];
void compute_downwards(int x, int parent){
    if((int)adj[x].size() == 1 && adj[x][0] == parent) return;
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
    int n, t, k;
    cin >> t;
    while(t--){
        cin>>n>>k;
        for(int i = 1; i <= n; i++){
            dist_downward[i] = make_pair(-1, -1);
            dist_downward2[i] = -5;
            dist_upward[i] = -1;
            adj[i].resize(0);
        }
        for(int i = 1; i <= k; i++){
            int a;
            cin >> a;
            dist_downward[a] = make_pair(0, -1);
            dist_downward2[a] = 0;
        }
        for(int i=0;i<n-1;i++){
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        compute_downwards(1,0);
        compute_downwards2(1,0);
        compute_upwards(1,0);
        /*ll ans = LINF;
        for(int i = 1; i <= n; i++)
            ans = min(ans, max(dist_upward[i],dist_downward[i].first));
        cout << ans << endl;*/
        for(int i = 1; i <= n; i++)
            cout << dist_downward[i].first << ' ';
        cout << endl;
        for(int i = 1; i <= n; i++)
            cout << dist_downward2[i] << ' ';
        cout << endl;
        for(int i = 1; i <= n; i++)
            cout << dist_upward[i] << ' ';
        cout << endl;
    }
    return 0;
}