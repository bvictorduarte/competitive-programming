#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e7;
typedef long long ll;
ll dp[maxn];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a;
    ll b;
    cin >> a >> b;
    dp[0] = 1;
    for(int i = 1; i < (int)a.size(); i++)
        dp[i] = (10 * dp[i - 1]) % b;
    ll sum = 0;
    for(int i = 0; i < (int)a.size(); i++){
        sum += ((a[i] - '0') * dp[(int)a.size() - i - 1]);
        sum %= b;
    }
    cout << sum % b << endl;
    return 0;
}