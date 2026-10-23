#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 50;
const int MOD = 1e9 + 7;
int dp[maxn], a[maxn];
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        vector<int> divs;
        for(int j = 1; j * j <= a[i]; j++)
            if(a[i] % j == 0){
                divs.push_back(j);
                if(j * j != a[i])
                    divs.push_back(a[i] / j);
            }
        sort(divs.begin(), divs.end());
        reverse(divs.begin(), divs.end());
        for(auto d : divs){
            dp[d] += dp[d - 1];
            dp[d] %= MOD;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans += dp[i];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}