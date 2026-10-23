#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 50;
const int INF = 0x3f3f3f3f;
int n;
int v[maxn];
int dist[maxn][5];
bool vis[maxn][5];
void dijkstra(){
    priority_queue<tuple<int, int, int>> pq;
    for(int i = 0; i <= n; i++){
        dist[i][0] = dist[i][1] = INF;
        vis[i][0] = vis[i][1] = false;
    }
    dist[0][1] = 0;
    pq.push(make_tuple(0, 0, 1));
    while(!pq.empty()){
        int a, f;
        int trash;
        tie(trash, a, f) = pq.top();
        pq.pop();
        if (vis[a][f]) continue;
        vis[a][f] = true;
        if(1 + a > n)
            continue;
        int w = 0;
        if(f == 1 && v[a + 1] == 1)
            w = 1;
        if(dist[a][f] + w < dist[a + 1][f ^ 1]){
            dist[a + 1][f ^ 1] = dist[a][f] + w;
            pq.push(make_tuple(-dist[a + 1][f ^ 1], a + 1, f ^ 1));
        }
        if(2 + a > n)
            continue;
        if(f == 1 && v[a + 2] == 1)
            w++;
        if(dist[a][f] + w < dist[a + 2][f ^ 1]){
            dist[a + 2][f ^ 1] = dist[a][f] + w;
            pq.push(make_tuple(-dist[a + 2][f ^ 1], a + 2, f ^ 1));
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> v[i];
        dijkstra();
        cout << min(dist[n][0], dist[n][1]) << endl;
    }
    return 0;
}