#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 50;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
int n, m;
int di[] = {0, 0, 0, 1, -1}, dj[] = {0, 1, -1, 0, 0};
char grid[maxn][maxn];
ll dist[maxn][maxn][5];
bool vis[maxn][maxn][5];
bool valid(int i, int j){
    return i <= n && i >= 1 && j >= 1 && j <= m && grid[i][j] != '*';
}
void dijkstra(int si, int sj){
    priority_queue<pair<ll, tuple<int, int, int>>> pq;
    for(int i = 1; i <= n; i++)
         for(int j = 1; j <= m; j++)
            for(int k = 1; k <= 4; k++)
                dist[i][j][k] = LINF;
    for(int i = 1; i <= 4; i++){
        dist[si][sj][i] = 0;
        pq.push(make_pair(0, make_tuple(si, sj, i)));
    }
    while(!pq.empty()){
        int ai, aj, d;
        tie(ai, aj, d) = pq.top().second;
        pq.pop();
        if(vis[ai][aj][d]) continue;
        vis[ai][aj][d] = true;
        for(int k = 1; k <= 4; k++){
            int bi = ai + di[k], bj = aj + dj[k];
            if(!valid(bi, bj))
                continue;
            int w = k == d ? 0 : 1;
            if(dist[ai][aj][d] + w < dist[bi][bj][k]){
                dist[bi][bj][k] = dist[ai][aj][d] + w;
                pq.push(make_pair(-dist[bi][bj][k], make_tuple(bi, bj, k)));
            }
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        scanf("%s", grid[i] + 1);
    int si, sj, ti, tj;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(grid[i][j] == 'S'){
                si = i;
                sj = j;
            }else if(grid[i][j] == 'T'){
                ti = i;
                tj = j;
            }
    dijkstra(si, sj);
    ll ans = LINF;
    for(int i = 1; i <= 4; i++)
        ans = min(ans, dist[ti][tj][i]);
    if(ans <= 2)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}