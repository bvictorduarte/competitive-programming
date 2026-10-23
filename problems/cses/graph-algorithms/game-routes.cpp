#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+50;
const int k=1e9+7;
vector<int> adj[maxn],topsort;
int dp[maxn],in_degree[maxn],n,m;
queue<int> q;
void find_topsort(){
    for(int i=1;i<=n;i++)
        if(in_degree[i]==0)
            q.push(i);
    while(!q.empty()){
        int a=q.front();q.pop();
        topsort.push_back(a);
        for(auto u:adj[a]){
            in_degree[u]--;
            if(!in_degree[u])
                q.push(u);
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        in_degree[b]++;
    }
    find_topsort();
    int ind;
    for(int i=0;i<n;i++)
        if(topsort[i]==n)
            ind=i;
    dp[topsort[ind]]++;
    for(int i=ind;i>=0;i--)
        for(auto u:adj[topsort[i]]){
            dp[topsort[i]]+=dp[u]%k;
            dp[topsort[i]]%=k;
        }
    cout<<dp[1]<<endl;
    return 0;
}