#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 50;
const int INF = 0x3f3f3f3f;
int n, m, grid[maxn][maxn];
int di[] = {0, 1}, dj[] = {1, 0};
int dpmin[maxn][maxn], dpmax[maxn][maxn];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++){
                cin >> grid[i][j];
                dpmin[i][j] = INF;
                dpmax[i][j] = -INF;
            }
        dpmin[1][1] = dpmax[1][1] = grid[1][1];
        for(int j = 2; j <= m; j++){
            dpmin[1][j] = min(dpmin[1][j], dpmin[1][j - 1] + grid[1][j]);
            dpmax[1][j] = max(dpmax[1][j], dpmax[1][j - 1] + grid[1][j]);
        }
        for(int i = 2; i <= n; i++){
            dpmin[i][1] = min(dpmin[i][1], dpmin[i - 1][1] + grid[i][1]);
            dpmax[i][1] = max(dpmax[i][1], dpmax[i - 1][1] + grid[i][1]);
        }
        for(int i = 2; i <= n; i++)
            for(int j = 2; j <= m; j++){
                dpmin[i][j] = min(dpmin[i][j - 1] + grid[i][j], dpmin[i - 1][j] + grid[i][j]);
                dpmax[i][j] = max(dpmax[i][j - 1] + grid[i][j], dpmax[i - 1][j] + grid[i][j]);
            }
        if(dpmin[n][m] <= 0 && dpmax[n][m] >= 0 && (n + m - 1) % 2 == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}