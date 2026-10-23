#include<bits/stdc++.h>
using namespace std;
const int maxn = 55;
typedef long long ll;
ll dp[maxn][maxn];
int main(){
    freopen("knight.in", "r", stdin);
    freopen("knight.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    dp[1][1] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            if(i - 2 >= 1 && j - 1 >= 1)
                dp[i][j] += dp[i - 2][j - 1];
            if(i - 1 >= 1 && j - 2 >= 1)
                dp[i][j] += dp[i - 1][j - 2];
        }
    cout << dp[n][m] << endl;
    return 0;
}