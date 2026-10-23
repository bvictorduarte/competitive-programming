#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 105;
const int maxk = (1<<10) + 10;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
vector<pair<int, int>> p;
double dp[maxn][maxk], dist[maxn][maxn];
double comp_dist(pair<int, int> p1, pair<int, int> p2){
    double x1 = p1.first, y1 = p1.second, x2 = p2.first, y2 = p2.second;
    return sqrt((x1-x2) * (x1-x2) + (y1-y2) * (y1-y2));
}
int main(){
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        p.push_back(make_pair(x, y));
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            dist[i][j] = comp_dist(p[i], p[j]);
    for(int o = 0; o < n; o++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                if(dist[i][j] == LINF || dist[i][o] == LINF || dist[o][j] == LINF) continue;
                dist[i][j] = min(dist[i][j], dist[i][o] + dist[o][j]);
            }
    for(int i = 0; i < n; i++)
        for(int mask = 0; mask < (1<<k); mask++)
            dp[i][mask] = LINF;
    for(int i = 0; i < k; i++)
            dp[i][(1<<i)] = 0;
    for(int mask = 0; mask < (1<<k); mask++){
        for(int i = 0; i < n; i++){
            for(int ss = mask; ss > 0; ss = (ss - 1) & mask){
                if(dp[i][ss] < LINF && dp[i][mask - ss] < LINF && i >=k)
                    dp[i][mask] = min(dp[i][mask], dp[i][ss] + dp[i][mask - ss]);
            }
            if(dp[i][mask] < LINF)
                for(int j = 0; j < n; j++)
                    if(dp[i][mask] < LINF && dist[i][j] < LINF)
                        dp[j][mask] = min(dp[j][mask], dp[i][mask] + dist[i][j]);
        }
    }
    double ans = LINF;
    for(int i = 0; i < n; i++)
        ans = min(ans, dp[i][(1<<k) - 1]);
    printf("%.5lf\n", ans);
    return 0;
}