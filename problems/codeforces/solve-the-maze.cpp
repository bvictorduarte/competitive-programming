#include<bits/stdc++.h>
using namespace std;
vector<string> grid;
const int maxn = 55;
const int INF = 0x3f3f3f3f;
int di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1}, n, m, contg = 0;
bool vis[maxn][maxn];
bool valid(int i, int j){
    return i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != '#';
}
bool set_block(){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(grid[i][j] != 'B')
                continue;
            for(int k = 0; k < 4; k++){
                int vi = i + di[k], vj = j + dj[k];
                if(valid(vi, vj)){
                    if(grid[vi][vj] == 'G' || (vi == n - 1 && vj == m - 1 && contg))
                        return true;
                    if(grid[vi][vj] == '.')
                        grid[vi][vj] = '#';
                }
            }
        }
    return false;
}

bool bfs(int si, int sj){
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            vis[i][j] = false;
    vis[si][sj] = true;
    q.push(make_pair(si, sj));
    while(!q.empty()){
        int i = q.front().first, j = q.front().second; q.pop();
        for(int k = 0; k < 4; k++){
            int vi = i + di[k], vj = j + dj[k];
            if(!valid(vi, vj) || vis[vi][vj]) continue;
            vis[vi][vj] = true;
            q.push(make_pair(vi, vj));
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        grid.resize(0);
        contg = 0;
        for(int i = 1; i <= n; i++){
            string row;
            cin >> row;
            grid.push_back(row); 
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j] == 'G' || contg){
                    contg++;
                    break;
                }
        if(set_block()){
            cout << "No\n";
            continue;
        }
        bfs(n - 1, m - 1);
        bool yes = true;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j] == 'G' && !vis[i][j])
                    yes = false;
        if(yes)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}