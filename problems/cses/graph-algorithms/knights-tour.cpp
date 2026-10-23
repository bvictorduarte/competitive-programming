#include<bits/stdc++.h>
using namespace std;
const int maxn = 10;
int di[] = {2, 2, -2, -2, 1, 1, -1, -1}, dj[] = {1, -1, 1, -1, 2, -2, 2, -2}, deg[maxn][maxn], n = 8, ans[maxn][maxn];
bool vis[maxn][maxn];
bool valid(int i, int j){
    return i >= 1 && i <= n && j >= 1 && j <= n && !vis[i][j];
}
void build_degrees(){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            for(int k = 0; k < 8; k++)
                if(valid(i + di[k], j + dj[k]))
                    deg[i][j]++;
}
void mark(int idx, int i, int j){
    vis[i][j] = true;
    ans[i][j] = idx;
    for(int k = 0; k < 8; k++){
        int vi = i + di[k], vj = j + dj[k];
        deg[vi][vj]--;
    }
}
void unmark(int i, int j){
    vis[i][j] = false;
    ans[i][j] = 0;
    for(int k = 0; k < 8; k++){
        int vi = i + di[k], vj = j + dj[k];
        deg[vi][vj]++;
    }
}
bool solve(int idx, int i, int j){
    mark(idx, i, j);
    if(idx == 64) return true;
    vector<pair<int, pair<int, int>>> op;
    for(int k = 0; k < 8; k++){
        int vi = i + di[k], vj = j + dj[k];
        if(!valid(vi, vj)) continue;
        op.push_back(make_pair(deg[vi][vj], make_pair(vi, vj)));
    }
    sort(op.begin(), op.end());
    for(auto t : op)
        if(solve(idx + 1, t.second.first, t.second.second))
            return true;
    unmark(i, j);
    return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    build_degrees();
    int x, y;
    cin >> x >> y;
    solve(1, y, x);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            cout << ans[i][j] << ' ';
        cout << '\n';
    }
}