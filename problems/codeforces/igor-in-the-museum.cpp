#include<bits/stdc++.h>
using namespace std;
const int maxc = 1e6 + 50;
const int maxn = 1e3 + 50;
int n, m, k, di[] = {0, 0, 1, -1}, dj[] = {1, -1, 0, 0}, comp[maxn][maxn], c = 0;
set<tuple<int, int, int>> vcomp[maxc];
vector<string> g;
bool vis[maxn][maxn];
void dfs(int i, int j){
    vis[i][j] = true;
    for(int k = 0; k < 4; k++){
        int vi = i + di[k], vj = j + dj[k];
        if(vi >= 0 && vi < n && vj >= 0 && vj < m  && !vis[vi][vj]){
            if(g[vi][vj] == '.'){
                comp[vi][vj] = comp[i][j];
                dfs(vi, vj);
            }
            else
                vcomp[comp[i][j]].insert(make_tuple(vi, vj, k));
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        string row;
        cin >> row;
        g.push_back(row);
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(!vis[i][j] && g[i][j] == '.'){
                comp[i][j] = ++c;
                dfs(i, j);
            }
    for(int i = 1; i <= k; i++){
        int x, y;
        cin >> x >> y;
        cout << (int)vcomp[comp[--x][--y]].size() << endl;
    }
    return 0;
}