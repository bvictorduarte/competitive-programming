#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 50;
int freq[maxn];
int main(){
    int n, c;
    cin >> n >> c;
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        freq[a]++;
    }
    int ans = 0;
    for(int i = 1; i <= maxn - 50; i++)
        ans = max(ans, freq[i]);
    cout << ans << endl;
    return 0;
}