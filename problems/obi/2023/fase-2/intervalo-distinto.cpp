#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 50;
int v[maxn];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    int l = 1, r = 1, ans = 1;
    set<int> cur;
    cur.insert(v[1]);
    while(r < n){
        if(cur.find(v[r + 1]) == cur.end()){
            ++r;
            cur.insert(v[r]);
        }else{
            ans = max(ans, r - l + 1);
            while(v[l] != v[r + 1]){
                cur.erase(cur.find(v[l]));
                ++l;
            }
            ++l;
            ++r;
        }
        if(r == n)
            ans = max(ans, r - l + 1);
    }
    cout << ans << endl;
    return 0;
}