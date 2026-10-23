#include<bits/stdc++.h>
using namespace std;
const int maxn = 550;
int d[maxn];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        for(int i = 1; i <= q; i++)
            cin >> d[i];
        for(int i = 1; i <= n - 1; i++)
            cout << i << ' ' << i + 1 << endl;
        int cur_dist = n - 1;
        for(int i = 1; i <= q; i++)
            if(d[i] == cur_dist)
                cout << -1 << ' ' << -1 << ' ' << -1 << ' ' << endl;
            else{
                cout << n << ' ' << cur_dist << ' ' << d[i] << endl;
                cur_dist = d[i];
            }
    }
    return 0;
}