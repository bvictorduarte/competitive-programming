#include<bits/stdc++.h>
using namespace std;
const int maxn = 1 << 20;
vector<pair<int, int>> adj[maxn];
bool vis[maxn];
vector<int> path;
void dfs(int x = 0){
    while(!adj[x].empty()){
        int viz = adj[x].back().first, idx = adj[x].back().second;
        adj[x].pop_back();
        if(vis[idx])continue;
        vis[idx] = true;
        dfs(viz);
    }
    path.push_back(x);
}
int main(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;
    if(n == 1)
        cout << "10\n";
    else{
        int cont = 1;
        for(int node = 0; node < (1 << (n-1)); node++){
            int son = (node << 1) % (1 << (n-1));
            adj[node].push_back(make_pair(son, cont++));
            adj[node].push_back(make_pair(son | 1, cont++));
        }
        dfs();
        reverse(path.begin(), path.end());
        for(int i = 1; i <= n-1; i++)
            cout << '0';
        for(int i = 0; i < (int)path.size()-1; i++){
            int son = (path[i] << 1) % (1 << (n-1));
            if(path[i+1] == son)
                cout << '0';
            else
                cout << '1';
        }
        cout << '\n';
    }
}