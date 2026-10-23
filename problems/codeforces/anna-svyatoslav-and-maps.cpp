#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 150;
const int maxm = 1e6 + 50;
int dist1[maxn][maxn];
vector<int> adj[maxn];
int p[maxm];
vector<pair<int, int>> edges;
int n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < n; j++){
            if(s[j] == '1'){
                dist1[i][j + 1] = 1;
                edges.push_back(make_pair(i, j + 1));
            }else if(i != j + 1)
                dist1[i][j + 1] = INF;
        }
    }
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dist1[i][j] = min(dist1[i][j], dist1[i][k] + dist1[k][j]);
    int m;
    cin >> m;
    for(int i = 1; i <= m; i++)
        cin >> p[i];
    stack<int> s;
    s.push(p[1]);
    for(int i = 2; i <= m; i++){
        while(1){
            if((int)s.size() == 1) break;
            int pi = s.top(); s.pop();
            if(dist1[s.top()][pi] + dist1[pi][p[i]] != dist1[s.top()][p[i]]){
                s.push(pi);
                break;
            }
        }
        s.push(p[i]);
    }
    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    cout << (int)ans.size() << endl;
    reverse(ans.begin(), ans.end());
    for(auto u : ans)
        cout << u << ' ';
    cout << endl;
    return 0;
}