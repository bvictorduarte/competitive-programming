#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
string a[50005], o[50005];
map<string, bool> d;
int main () {
    ll n,j=0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        d[a[i]] = false;
    }
    for (int i = 0; i < n; i++) {
        cin >> o[i];
    }
    cout << o[0];
    for (int i = 1; i<n;i++){
        while (d[o[j]]) {
            j++;
        }
        cout << ' ' << o[j];
        d[a[i]] = true;
    }
    cout << '\n';
    return 0;
}