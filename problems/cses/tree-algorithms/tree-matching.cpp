#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+50;
vector<int> adj[maxn];
int dp[maxn];
bool usado[maxn];
void dfs(int x,int p){
    for(auto u:adj[x])
        if(u!=p){
            dfs(u,x);
            dp[x]+=dp[u];
            if(!usado[x]&&!usado[u]){
                dp[x]++;
                usado[x]=true;
                usado[u]=true;
            }
        }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    cout<<dp[1]<<endl;
    return 0;
}