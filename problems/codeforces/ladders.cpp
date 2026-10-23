#include<bits/stdc++.h>
using namespace std;
const int maxn = 150;
int dp[maxn], a[maxn];
int main(){
    freopen("ladder.in", "r", stdin);
    freopen("ladder.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    dp[1] = a[1];
    if(n == 1){
        cout << dp[1] << endl;
        return 0;
    }
    dp[2] = max(a[1] + a[2], a[2]);
    for(int i = 3; i <= n; i++)
        dp[i] = max(dp[i - 1] + a[i], dp[i - 2] + a[i]);
    cout << dp[n] << endl;
    return 0;
}