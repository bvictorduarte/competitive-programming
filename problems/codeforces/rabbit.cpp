#include<bits/stdc++.h>
using namespace std;
const int maxn = 1050;
int dp[maxn];
int main(){
    freopen("lepus.in", "r", stdin);
    freopen("lepus.out", "w", stdout);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 2; i <= n; i++)
        dp[i] = -1050;
    for(int i = 2; i <= n; i++){
        if(s[i - 1] == 'w')
            continue;
        if(i - 1 >= 1 && dp[i - 1] >= 0){
            if(s[i - 1] == '"')
                dp[i] = max(dp[i], dp[i - 1] + 1);
            else
                dp[i] = max(dp[i], dp[i - 1]);
        }
        if(i - 3 >= 1 && dp[i - 3] >= 0){
            if(s[i - 1] == '"')
                dp[i] = max(dp[i], dp[i - 3] + 1);
            else
                dp[i] = max(dp[i], dp[i - 3]);
        }
        if(i - 5 >= 1 && dp[i - 5] >= 0){
            if(s[i - 1] == '"')
                dp[i] = max(dp[i], dp[i - 5] + 1);
            else
                dp[i] = max(dp[i], dp[i - 5]);
        }
    }
    if(dp[n] != -1050)
        cout << dp[n] << endl;
    else
        cout << -1 << endl;
    return 0;
}