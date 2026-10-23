#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 50;
vector<int> ord, adj[2 * maxn][2];
bool visited[2 * maxn][2];
int comp[2 * maxn], mark[maxn];
int n, c = 0;
bool ver;
void add_disjunction(int a, bool na, int b, bool nb){
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
bool solve_2SAT(){
    for(int i = 2; i <= 2 * n + 1; i++)
        if(!visited[i][0])
            dfs(i, 0);
    reverse(ord.begin(),ord.end());
    c = 0;
    for(auto u : ord)
        if(!visited[u][1]){
            c++;
            dfs(u, 1);
        }
    for(int i = 1; i <= n; i++)
        if(comp[2 * i] == comp[2 * i + 1])
            return false;
    return true;
}
void print_solve(){
    for(int i = 1; i <= n; i++)
        if(comp[2 * i] < comp[2 * i + 1]){
            if(mark[i] == 0)
                ver = true;
            //cout << i << " eh true\n";
        }
        else{
            if(mark[i] == 1)
                ver = true;
            //cout << i << " eh false\n";
        }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int p;
    while(cin >> p >> n && !(!p && !n)){
        ver = false;
        for(int i = 1; i <= n; i++)
            mark[i] = 2;
        for(int i = 1; i <= 2 * n + 1; i++){
            adj[i][0].resize(0);
            adj[i][1].resize(0);
            visited[i][0] = visited[i][1] = false;
        }
        ord.resize(0);
        for(int i = 1; i <= p; i++){
            int a, b;
            cin >> a >> b;
            if(a != 0 && b != 0)
                add_disjunction(a, true, b, true);
            else if(a != 0 || b != 0){
                if(a < b)
                    swap(a, b);
                if(mark[a] != 0)
                    mark[a] = 1;
                else
                    ver = true;
            }
            cin >> a >> b;
            if(a != 0 && b != 0)
                add_disjunction(a, false, b, false);
            else if(a != 0 || b != 0){
                if(a < b)
                    swap(a, b);
                if(mark[a] != 1)
                    mark[a] = 0;
                else
                    ver = true;
            }
        }
        if(ver){
            cout << "no\n";
            continue;
        }
        if(solve_2SAT()){
            print_solve();
            if(!ver)
                cout << "yes\n";
            else
                cout << "no\n";
        }
        else
            cout << "no\n";
    }
}