#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+50;
const int maxs = 1e5 + 50;
int dp[maxn][maxs], w[maxn], v[maxn];
int main(){
    int wm, n;
    cin >> n >> wm;
    for(int i = 0; i <= n; i++){
        for(int j = 1; j <= maxs; j++)
            dp[i][j] = wm + 1;
    }
    for(int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
        dp[i][v[i]] = min(w[i], dp[i][v[i]]);
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= maxs; j++)
            if(j >= v[i] + 1)
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
            else
                dp[i][j] = min(dp[i][j], dp[i - 1][j]);
    for(int j = maxs; j >= 1; j--)
        if(dp[n][j] <= wm){
            cout << j << endl;
            return 0;
        }
    cout << 0 << endl;
    return 0;
}