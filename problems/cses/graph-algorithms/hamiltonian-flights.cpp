#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int maxn = 20;
ll dp[maxn][(1 << maxn)];
vector<int> adj[maxn];
int count_bits(int a){
    int cont = 0;
    for(int i = 0; i < 22; i++)
        if(a & (1 << i))
            cont++;
    return cont;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[--b].push_back(--a);
    }
    dp[0][(1 << 0)] = 1;
    for(int mask = 0; mask < (1 << n); mask++){
        if (!(mask & (1 << 0))) continue;
        for(int i = 0; i < n; i++){
            if(!(mask & (1 << i))) continue;
            for(auto j : adj[i]){
                if(!(mask & (1 << j)))continue;
                dp[i][mask] +=dp[j][mask ^ (1 << i)];
                dp[i][mask] %= MOD;
            }
        }
    }
    cout << dp[n-1][(1 << n) - 1] % MOD << '\n';
    return 0;
}