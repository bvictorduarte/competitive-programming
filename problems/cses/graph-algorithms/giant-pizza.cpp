#include<bits/stdc++.h>
using namespace std;
const int maxn  = 1e5 + 50;
vector<int> ord, adj[2 * maxn][2];
bool visited[2 * maxn][2];
int comp[2 * maxn], c = 0;
string ans;
void add_disjunction(int a, bool na, int b, bool nb) {
    // na and nb signify whether a and b are to be negated 
    a = 2*a ^ na;
    b = 2*b ^ nb;
    int neg_a = a ^ 1;
    int neg_b = b ^ 1;
    adj[neg_a][0].push_back(b);
    adj[neg_b][0].push_back(a);
    adj[b][1].push_back(neg_a);
    adj[a][1].push_back(neg_b);
}
void dfs(int x, int f){
    visited[x][f] = true;
    if(f)
        comp[x] = c;
    for(auto u : adj[x][f])
        if(!visited[u][f])
            dfs(u, f);
    if(!f)
        ord.push_back(x);
}
int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        string op1, op2;
        int t1, t2;
        cin >> op1 >> t1 >> op2 >> t2;
        bool na, nb;
        if(op1 == "+")
            na = true;
        else
            na = false;
        if(op2 == "+")
            nb = true;
        else
            nb = false;
        add_disjunction(t1, na, t2, nb);
    }
    for(int i = 2; i <= 2 * m + 1; i++)
        if(!visited[i][0])
            dfs(i, 0);
    reverse(ord.begin(),ord.end());
    for(auto u : ord)
        if(!visited[u][1]){
            c++;
            dfs(u, 1);
        }
    for(int i = 1; i <= m; i++){
        if(comp[2 * i] == comp[2 * i + 1]){
            cout << "IMPOSSIBLE\n" << endl;
            return 0;
        }else if(comp[2 * i] < comp[2 * i + 1])
            ans.push_back('+');
        else
            ans.push_back('-');
        ans.push_back(' ');
    }
    cout << ans << endl;
    return 0;
}