#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 4e5 + 50;
const int LIM = 2e9;
int dist[maxn], n, m, mp[maxn];
int dx[] = {-1, 1};
unordered_map<int, bool> mark;
long long int ans = 0;
int cont = 0;
void bfs(){
    queue<int> q;
    for(int i = 1; i <= n + m; i++)
        dist[i] = INF;
    for(int i = 1; i <= n; i++){
        cont++;
        dist[i] = 0;
        q.push(i);
    }
    while (!q.empty()){
        int v = q.front(); q.pop();
        if(cont >= m + n)
            break;
        for(int i = 0; i < 2; i++) {
            int u = mp[v] + dx[i];
            if(!(u >= -LIM && u <= LIM))
                continue;
            if (mark[u])
                continue;
            mark[u] = true;
            mp[++cont] = u;
            dist[cont] = dist[v] + 1;
            q.push(cont);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    queue<int> q;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        mark[a] = true;
        mp[i] = a;
    }
    bfs();
    for(int i = n + 1; i <= n + m; i++)
        ans += dist[i];
    cout << ans << endl;
    for(int i = n + 1; i <= n + m; i++)
        cout << mp[i] << ' ';
    cout << endl;
}