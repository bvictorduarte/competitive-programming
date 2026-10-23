#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
int main(){
    ll n;
    cin >> n;
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    ll f = (n % MOD), sum = (n % MOD);
    for(int i = n - 1; i >= 2; i--){
        f = (f * (i % MOD)) % MOD;
        sum = (sum + f) % MOD;
    }
    ll fat = 1;
    for(int i = 1; i <= n; i++)
        fat = (fat * (i % MOD)) % MOD;
    cout << (((((n % MOD) * fat) % MOD) - sum) + MOD) % MOD << endl;;
    return 0;
}