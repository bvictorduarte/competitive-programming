#include<bits/stdc++.h>
using namespace std;
map<pair<int, int>, bool> mp, vis;
map<pair<int, int>, int> dist;
int dj[] = {0, 0, 1, 1, 1, -1 , -1, -1}, di[] = {1, -1, 0, 1, -1, 0, 1, -1};
const int INF = 0x3f3f3f3f;
int n;
void bfs(int sj, int si){
    queue<pair<int, int>> q;
    vis[{sj, si}] = true;
    dist[{sj, si}] = 0;
    q.push({sj, si});
    while(!q.empty()){
        int vj = q.front().first, vi = q.front().second;
        q.pop();
        for(int k = 0; k < 8; k++){
            int uj = vj + dj[k], ui = vi + di[k];
            if(!mp[{uj, ui}] || vis[{uj, ui}]) continue;
            vis[{uj, ui}] = true;
            dist[{uj, ui}] = dist[{vj, vi}] + 1;
            q.push({uj, ui});
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int sj, si, tj, ti;
    cin >> sj >> si >> tj >> ti;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int r, c1, c2;
        cin >> r >> c1 >> c2;
        for(int j = c1; j <= c2; j++){
            mp[{r, j}] = true;
            dist[{r, j}] = INF;
        }
    }
    bfs(sj, si);
    if(dist[{tj, ti}] == INF)
        cout << -1 << endl;
    else
        cout << dist[{tj, ti}] << endl;
    return 0;
}