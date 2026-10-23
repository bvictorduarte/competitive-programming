#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[10];
ll sol(ll n){
    ll ans = 0;
    for(int i = 0; i <= 9; i++){
        ans += (n % 10) * dp[i];
        n /= 10;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    dp[0] = 1;
    for(int i = 1; i <= 9; i++)
        dp[i] = 10 * dp[i - 1] + 1;
    int t;
    cin >> t;
    while(t--){
        ll l, r;
        cin >> l >> r;
        cout << sol(r) - sol(l) << endl;
    }
    return 0;
}