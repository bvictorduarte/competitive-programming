#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+50;
string v[maxn];
vector<int> ans;
queue<int> q[maxn];
void dfs(int a){
    ans.push_back(a);
    if(q[a].empty())
        return;
    while(!q[a].empty()){
        int u=q[a].front();
        q[a].pop();
        dfs(u);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    int a,b;
    for(int i=1;i<=n-1;i++){
        cin>>a>>b;
        q[a].push(b);
    }
    dfs(a);
    for(auto u:ans)
        cout<<v[u];
    cout<<endl;
    return 0;
}