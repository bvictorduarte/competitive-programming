#include<bits/stdc++.h>
using namespace std;
const int maxn = 150;
typedef long long ll;
const int MOD = 1e4;
typedef vector<vector<ll>> matrix;
matrix dp[40];
void set_matrix(matrix &m, int n){
    for(int i = 0; i < n; i++){
        vector<ll> row;
        for(int j = 0; j < n; j++)
            row.push_back(0);
        m.push_back(row);
    }
}
matrix multiply(matrix a, matrix b, int n){
    matrix ans;
    set_matrix(ans, n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0 ; k < n; k++){
                ans[i][j] += (a[i][k] % MOD) * (b[k][j] % MOD);
                ans[i][j] %= MOD;
            }
    return ans;
}
void precompute(matrix adj){
    dp[0] = adj;
    for(int i = 1; i <= 31; i++)
        dp[i] = multiply(dp[i - 1], dp[i - 1], (int)adj.size());
}
matrix solve(int n, int l){
    matrix ans;
    set_matrix(ans, n);
    for(int i = 0; i < n; i++)
        ans[i][i] = 1;
    for(int i = 31; i >= 0; i--)
        if(l & (1 << i))
            ans = multiply(ans, dp[i], n);
    return ans;
}
int main(){
    int n, l;
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> n >> l){
        matrix adj;
        set_matrix(adj, n);
        int s, t;
        cin >> s >> t;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= 4; j++){
                int a;
                cin >> a;
                adj[i - 1][a - 1]++;
            }
        }
        precompute(adj);
        matrix ans = solve(n, l);
        cout << ans[s - 1][t - 1] << endl;
    }
    return 0;
}