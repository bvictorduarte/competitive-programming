#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<ll, ll> freq;
int main(){
    int n;
    ll x, pref_sum = 0, ans = 0;
    cin >> n >> x;
    freq[0] = 1;
    for(int i = 0; i < n; i++){
        ll a;
        cin >> a;
        pref_sum += a;
        ans += freq[pref_sum - x];
        freq[pref_sum]++;
    }
    cout << ans << endl;
    return 0;
}