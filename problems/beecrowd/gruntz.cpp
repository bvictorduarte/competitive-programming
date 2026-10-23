#include<bits/stdc++.h>
using namespace std;
const int maxn = 150;
string grid[maxn];
bool vis[maxn][maxn][maxn];
bool ans;
int n, m, km;
char mp[4];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
void dfs(int i, int j, int k){
    if(vis[i][j][k] || ans)
        return;
    vis[i][j][k] = true;
    if(i == 0 || i == n - 1 || j == 0 || j == m - 1)
        ans = true;
    for(int it = 0; it < 4; it++){
        int vi = dx[it] + i, vj = dy[it] + j;
        if(vi < 0 || vi >= n || vj < 0 || vj >= m)
            continue;
        if(grid[vi][vj] == mp[it])
            dfs(vi, vj, k);
        else if(k + 1 <= km && (((grid[vi][vj] == '^' || grid[vi][vj] == 'v') && it <= 1) || ((grid[vi][vj] == '>' || grid[vi][vj] == '<') && it > 1)))
            dfs(vi, vj, k + 1);
    }
}
void reset_vis(){
    for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                for(int k = 0; k <= km; k++)
                    vis[i][j][k] = false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    mp[0] = '^';
    mp[1] = 'v';
    mp[2] = '<';
    mp[3] = '>';
    while(cin >> n >> m >> km && !(!n && !m && !km)){
        for(int i = 0; i < n; i++)
            cin >> grid[i];
        ans = false;
        reset_vis();
        dfs(n / 2, m / 2, 0);
        if(ans)
            cout << "Sim\n";
        else
            cout << "Nao\n";
    }
    return 0;
}