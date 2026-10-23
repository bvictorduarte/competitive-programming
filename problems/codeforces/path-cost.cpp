#include<bits/stdc++.h>
using namespace std;
const int maxn = 9;
typedef long long ll;
ll dp[maxn][maxn], grid[maxn][maxn];
int main(){
    freopen("king2.in", "r", stdin);
    freopen("king2.out", "w", stdout);
    for(int i = 8; i >= 1; i--)
        for(int j = 1; j <= 8; j++)
            cin >> grid[i][j];
    for(int i = 1; i <= 8; i++)
        for(int j = 1; j <= 8; j++){
            if(!(i == 1 && j == 1))
                dp[i][j] = 1000000;
            if(i - 1 >= 1 && j - 1 >= 1)
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + grid[i][j]);
            if(i - 1 >= 1)
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + grid[i][j]);
            if(j - 1 >= 1)
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + grid[i][j]);
        }
    cout << dp[8][8] << endl;
    return 0;
}