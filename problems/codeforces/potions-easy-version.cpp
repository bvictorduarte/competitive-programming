#include<bits/stdc++.h>
using namespace std;
const int maxn = 2050;
typedef long long ll;
ll dp[maxn][maxn], a[maxn];
ll v[maxn], ans = -1;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    dp[1][1] = a[1];
    for(int i = 2; i <= n; i++){
        if(dp[i - 1][i - 1] + a[i] >= 0 && dp[i - 1][i - 1] >= 0)
            dp[i][i] = dp[i - 1][i - 1] + a[i];
        else
            dp[i][i] = -1;
        for(int j = 1; j <= i - 1; j++)
            if(dp[i - 1][j - 1] + a[i] >= 0 && dp[i - 1][j - 1] >= 0)
                dp[i][j] = max(dp[i - 1][j - 1] + a[i], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
    }
    for(int i = n; i >= 0; i--)
        if(dp[n][i] >= 0){
            cout << i << endl;
            return 0;
        }
    return 0;
}