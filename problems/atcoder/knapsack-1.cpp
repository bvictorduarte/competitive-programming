#include<bits/stdc++.h>
using namespace std;
const int maxn = 150;
const int maxw = 1e5 + 50;
typedef long long ll;
ll f[maxw], w[maxn], v[maxn];
int main(){
    ll n, wm;
    cin >> n >> wm;
    for(int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];
    for(int i = 1; i <= n; i++)
        for(int j = wm; j >= w[i]; j--)
            f[j] = max(f[j], f[j - w[i]] + v[i]);
    cout << f[wm] << endl;
    return 0;
}