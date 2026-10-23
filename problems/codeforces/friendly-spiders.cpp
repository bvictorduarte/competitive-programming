#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 50;
const int INF = 0x3f3f3f3f;
//int sieve[maxn], N, mp[maxn], spd[maxn];
int sieve[maxn], mp[maxn], spd[maxn], N;
vector<int> adj[2 * maxn];

void make_sieve(){
    sieve[1] = 1;
    for(int i = 2; i <= maxn; i++){
        if(sieve[i] == 0){
            mp[i] = ++N;
            for(int j = i; j <= maxn; j += i)
                sieve[j] = i;
        }
    }
}

int dist[2 * maxn], par[2 * maxn];
bool vis[2 * maxn];
void bfs(int s){
    queue<int> q;
    for(int i = 1; i <= N; i++)
        dist[i] = INF;
    vis[s] = true;
    dist[s] = 0;
    par[s] = s;
    q.push(s);
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(auto u : adj[v]){
            if(vis[u]) continue;
            vis[u] = true;
            par[u] = v;
            dist[u] = dist[v] + 1;
            q.push(u);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    N = n;
    make_sieve();
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        spd[i] = a;
        while(sieve[a] != 1){
            adj[i].push_back(mp[sieve[a]]);
            adj[mp[sieve[a]]].push_back(i);
            a /= sieve[a];
        }
    }
    int s, t;
    cin >> s >> t;
    bfs(s);
    if(dist[t] == INF)
        cout << -1 << endl;
    else{
        cout << (dist[t] / 2) + 1 << endl;
        int it = t;
        vector<int> ans;
        while(it != s){
            if(it > n)
                it = par[it];
            ans.push_back(it);
            it = par[it];
        }
        if((dist[t] / 2) + 1 == 1)
            ans.push_back(s);
        reverse(ans.begin(), ans.end());
        for(auto a : ans)
            cout << a << ' ';
        cout << endl;
    }
    return 0;
}