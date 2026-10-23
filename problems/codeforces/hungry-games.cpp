#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 50;
vector<ll> pref;
ll dp[maxn];
int main(){
    int t;
    cin >> t;
    while(t--){
        ll n, x;
        cin >> n >> x;
        pref.resize(0);
        pref.push_back(0);
        for(int i = 1; i <= n; i++){
            ll a;
            cin >> a;
            pref.push_back(pref[i - 1] + a);
        }
        for(int i = n; i >= 1; i--){
            int j = upper_bound(pref.begin() + i, pref.end(), x + pref[i - 1]) - pref.begin();
            if(upper_bound(pref.begin() + i, pref.end(), x + pref[i - 1]) == pref.end())
                dp[i] = n - i + 1;
            else if(j <= n)
                dp[i] = dp[j + 1] + j - i;
        }
        ll ans = 0;
        for(int i = 1; i <= n; i++){
            ans += dp[i];
            dp[i] = 0;
        }
        cout << ans << endl;
    }
    return 0;
}