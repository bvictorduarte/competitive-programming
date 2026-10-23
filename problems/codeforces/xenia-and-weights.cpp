#include<bits/stdc++.h>
using namespace std;
map<int, vector<tuple<int, int, int>>> adj[20][1050];
map<int, tuple<int, int, int>> dad[20][1050];
map<int, bool> vis[20][1050];
string s;
int m;
bool have = false;
tuple<int, int, int> it, st;
void dfs(int a, int b, int cont){
    if(cont == m){
        have = true;
        st = make_tuple(a, b, cont);
        return;
    }
    vis[b][cont][a] = true;
    for(int i = 1; i <= 10; i++){
        if(s[i - 1] == '0' || i == b)
            continue;
        if(cont & 1){
            int a1 = a - i;
            if(a1 * a >= 0 && cont > 0)
                continue;
            if(vis[i][cont + 1][a1]) continue;
            dad[i][cont + 1][a1] = make_tuple(a, b, cont);
            dfs(a1, i, cont + 1);
        }else{
            int a1 = a + i;
            if(a1 * a >= 0 && cont > 0)
                continue;
            if(vis[i][cont + 1][a1]) continue;
            dad[i][cont + 1][a1] = make_tuple(a, b, cont);
            dfs(a1, i, cont + 1);
        }

    }
}
int main(){
    cin >> s;
    cin >> m;
    dfs(0, 0, 0);
    if(!have){
        cout << "NO\n";
        return 0;
    }
    it = st;
    cout << "YES\n";
    vector<int> ans;
    while(get<2>(it) != 0){
        ans.push_back(get<1>(it));
        it = dad[get<1>(it)][get<2>(it)][get<0>(it)];
    }
    reverse(ans.begin(), ans.end());
    for(auto u : ans)
        cout << u << ' ';
    cout << endl;
    return 0;
}