#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 50;
int a[maxn];
bool mark[maxn];
int main(){
    int t;
    cin >> t;
    while(t--){
        vector<int> ans;
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++)
            mark[i] = false;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            if(!mark[a[i]]){
                mark[a[i]] = true;
                ans.push_back(a[i]);
            }
        }
        for(int i = 1; i <= n; i++)
            if(!mark[i])
                ans.push_back(i);
        for(auto u : ans)
            cout << u << ' ';
        cout << endl;
    }
    return 0;
}