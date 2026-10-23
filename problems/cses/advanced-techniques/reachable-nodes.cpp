#include <bits/stdc++.h>
using namespace std;
const int MAXN=5*(1e4)+50;
vector<int> adj[MAXN],adjr[MAXN],top_sort;
bitset<MAXN> ans[MAXN];
int in_degree[MAXN];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adjr[b].push_back(a);
        in_degree[b]++;
    }
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i=1;i<=n;i++)
        if(in_degree[i]==0)
            q.push(i);
    while(!q.empty()){
        int x=q.top();q.pop();
        top_sort.push_back(x);
        for(auto u:adj[x]){
            in_degree[u]--;
            if(in_degree[u]>0)continue;
            q.push(u);
        }
    }
    for(int i=n-1;i>=0;i--){
        int x=top_sort[i];
        ans[x][x]=1;
        for(auto u:adjr[x])
            ans[u]|=ans[x];
    }
    cout<<ans[1].count();
    for(int i=2;i<=n;i++)
        printf(" %d", ans[i].count());
    cout<<endl;
    return 0;
}