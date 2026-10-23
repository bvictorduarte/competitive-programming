#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 50;
int dp[maxn][32], n, q;
void precompute(){
    for(int j = 1; j <= 31; j++)
        for(int i = 1; i <= n; i++)
            dp[i][j] = dp[dp[i][j-1]][j-1];
}
int ancestor(int a, int k){
    for(int j = 0; j <= 31; j++)
        if(k & (1 << j))
            a = dp[a][j];
    return a;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> dp[i][0];
    precompute();
    for(int i = 1; i <= q; i++){
        int a, k;
        cin >> a >> k;
        cout << ancestor(a, k) << endl;
    }
    return 0;
}