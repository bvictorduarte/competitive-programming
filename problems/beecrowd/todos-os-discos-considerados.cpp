#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 50;
int n;
int ideg[maxn], aideg[maxn], vis[maxn];
bool cycle;
vector<int> ts;
set<pair<int, int>> ts1, ts2;
vector<int> adj[maxn];
void dfs(int x){
    if(vis[x] == 1){
        cycle = true;
        return;
    }else if(vis[x] == 2)
        return;
    vis[x] = 1;
    for(auto u : adj[x])
        dfs(u);
    vis[x] = 2;
}
int main(){
    int n1, n2, d;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin >> n1 >> n2 >> d && !(!n1 && !n2 && !d)){
        n = n1 + n2;
        ts.resize(0);
        ts1.clear();
        ts2.clear();
        for(int i = 1; i <= n; i++){
            adj[i].resize(0);
            ideg[i] = 0;
            aideg[i] = 0;
            vis[i] = 0;
        }
        for(int i = 1; i <= d; i++){
            int a, b;
            cin >> a >> b;
            adj[b].push_back(a);
            ideg[a]++;
            aideg[a]++;
        }
        priority_queue<int,vector<int>,greater<int>> q;
        for(int i = 1; i <= n; i++){
            if(!vis[i])
                dfs(i);
            if(ideg[i] == 0)
                q.push(i);
        }
        while(!q.empty()){
            int x = q.top();
            q.pop();
            ts.push_back(x);
            if(x <= n1)
                ts1.insert(make_pair(aideg[x], x));
            else
                ts2.insert(make_pair(aideg[x], x));
            for(auto u : adj[x]){
                ideg[u]--;
                if(ideg[u] > 0)
                    continue;
                q.push(u);
            }
        }
        for(int i = 1; i <= n; i++)
            ideg[i] = aideg[i];
        int cur = 0, cont = 0;
        while(!ts1.empty() && !ts2.empty()){
            if(cur == 0 && (*ts1.begin()).first == 0){
                cur = 1;
                cont++;
                continue;
            }else if(cur == 0){
                cur = 2;
                cont++;
                continue;
            }
            else if(cur == 1){
                if(aideg[(*ts1.begin()).second] != 0){
                    cur = 2;
                    cont++;
                    continue;
                }else{
                    int v = (*ts1.begin()).second;
                    ts1.erase(ts1.begin());
                    for(auto u : adj[v]){
                        if(u > n1){
                            ts2.erase(make_pair(aideg[u], u));
                            aideg[u]--;
                            ts2.insert(make_pair(aideg[u], u));
                        }else{
                            ts1.erase(make_pair(aideg[u], u));
                            aideg[u]--;
                            ts1.insert(make_pair(aideg[u], u));
                        }
                    }
                }
            }else{
                if(aideg[(*ts2.begin()).second] != 0){
                    cur = 1;
                    cont++;
                    continue;
                }else{
                    int v = (*ts2.begin()).second;
                    ts2.erase(ts2.begin());
                    for(auto u : adj[v]){
                        if(u > n1){
                            ts2.erase(make_pair(aideg[u], u));
                            aideg[u]--;
                            ts2.insert(make_pair(aideg[u], u));
                        }else{
                            ts1.erase(make_pair(aideg[u], u));
                            aideg[u]--;
                            ts1.insert(make_pair(aideg[u], u));
                        }
                    }
                }
            }
        }
        int ans = cont + 2;
        ts1.clear();
        ts2.clear();
        for(int i = 1; i <= n; i++)
            aideg[i] = ideg[i];
        for(auto x : ts)
            if(x <= n1)
                ts1.insert(make_pair(aideg[x], x));
            else
                ts2.insert(make_pair(aideg[x], x));
        cont = 0;
        cur = 0;
        while(!ts1.empty() && !ts2.empty()){
            if(cur == 0 && (*ts2.begin()).first == 0){
                cur = 2;
                cont++;
                continue;
            }else if(cur == 0){
                cur = 1;
                cont++;
                continue;
            }
            else if(cur == 1){
                if(aideg[(*ts1.begin()).second] != 0){
                    cur = 2;
                    cont++;
                    continue;
                }else{
                    int v = (*ts1.begin()).second;
                    ts1.erase(ts1.begin());
                    for(auto u : adj[v]){
                        if(u > n1){
                            ts2.erase(make_pair(aideg[u], u));
                            aideg[u]--;
                            ts2.insert(make_pair(aideg[u], u));
                        }else{
                            ts1.erase(make_pair(aideg[u], u));
                            aideg[u]--;
                            ts1.insert(make_pair(aideg[u], u));
                        }
                    }
                }
            }else{
                if(aideg[(*ts2.begin()).second] != 0){
                    cur = 1;
                    cont++;
                    continue;
                }else{
                    int v = (*ts2.begin()).second;
                    ts2.erase(ts2.begin());
                    for(auto u : adj[v]){
                        if(u > n1){
                            ts2.erase(make_pair(aideg[u], u));
                            aideg[u]--;
                            ts2.insert(make_pair(aideg[u], u));
                        }else{
                            ts1.erase(make_pair(aideg[u], u));
                            aideg[u]--;
                            ts1.insert(make_pair(aideg[u], u));
                        }
                    }
                }
            }
        }
        ans = min(ans, cont + 2);
        cout << ans << endl;
    }
    return 0;
}