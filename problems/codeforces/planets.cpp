#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 50;
typedef long long ll;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
vector<pair<int, ll>> adj[maxn];
vector<ll> ti[maxn];
ll dist[maxn];
bool vis[maxn];
int n, m;

void dijkstra(int s){
    priority_queue<pair<ll, int>> pq;
    for(int i = 1; i <= n; i++)
        dist[i] = LINF;
    dist[s] = 0;
    pq.push(make_pair(0, s));
    while(!pq.empty()){
        int a = pq.top().second;
        pq.pop();
        if (vis[a]) continue;
        vis[a] = true;
        int posi = lower_bound(ti[a].begin(), ti[a].end(), dist[a]) - ti[a].begin();
        ll dab;
        if((posi != (int)ti[a].size() && ti[a][posi] != dist[a]) || (posi == (int)ti[a].size()))
            dab = dist[a];
        else{
            int prox = posi + 1;
            while(prox < (int)ti[a].size() && ti[a][prox] == ti[a][posi] + 1){
                prox++;
                posi++;
            }
            dab = ti[a][posi] + 1;
        }
        for(auto u : adj[a]){
            int b = u.first, w = u.second;
            if(dab + w < dist[b]){
                dist[b] = dab + w;
                pq.push(make_pair(-dist[b], b));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b;
        ll w;
        cin >> a >> b >> w;
        adj[a].push_back(make_pair(b, w));
        adj[b].push_back(make_pair(a, w));
    }
    for(int i = 1; i <= n; i++){
        int k;
        cin >> k;
        for(int j = 1; j <= k; j++){
            int a;
            cin >> a;
            ti[i].push_back(a);
        }
    }
    dijkstra(1);
    //for(int i = 1; i <= n; i++)
        //cout << dist[i] << endl;
    if(dist[n] == LINF)
        cout << -1 << endl;
    else
        cout << dist[n] << endl;
    return 0;
}