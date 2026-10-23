#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<char, int>> v;
    for(int i = 1; i <= n * m; i++){
        string s;
        cin >> s;
        v.push_back(make_pair(s[1], s[0] - '0'));
    }
    sort(v.rbegin(), v.rend());
    for(auto u : v)
        cout << u.second << u.first << endl;
    return 0;
}