#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e4 + 50;
bool processed[maxn][2];
vector<pair<int, ll>> adj[maxn];
ll dp[maxn][2];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c, v;
    cin >> c >> v;
    for(int i = 1; i <= v; i++){
        int a, b;
        ll w;
        cin >> a >> b >> w;
        adj[a].push_back(make_pair(b, w));
        adj[b].push_back(make_pair(a, w));
    }
    for(int i = 1; i <= c; i++)
        for(int j = 0; j <= 2; j++)
            dp[i][j] = LINF;
    dp[1][0] = 0;
    priority_queue<tuple<ll, int, int>> q;
    q.push(make_tuple(0, 1, 0));
    while (!q.empty()) {
        int a, p;
        ll d;
        tie(d, a, p) = q.top(); q.pop();
        if (processed[a][p]) continue;
            processed[a][p] = true;
        for (auto u : adj[a]) {
            int b = u.first, w = u.second;
            if (dp[a][0]+w < dp[b][1]) {
                dp[b][1] = dp[a][0]+w;
                q.push({-dp[b][1],b, 1});
            }
            if (dp[a][1]+w < dp[b][0]) {
                dp[b][0] = dp[a][1]+w;
                q.push({-dp[b][0], b, 0});
            }
        }
    }
    if(dp[c][0] != LINF)
        cout << dp[c][0] << endl;
    else
        cout << -1 << endl;
    return 0;
}