#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 50;
int dp[maxn];
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        dp[1] = 0;
        for(int i = 2; i <= k; i++)
            dp[i] = 1;
        for(int i = k + 1; i <= n; i++)
            dp[i] = 1 + dp[i - (k - 1)];
        cout << dp[n] << endl;
    }
    return 0;
}