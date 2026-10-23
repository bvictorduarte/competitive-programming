#include<bits/stdc++.h>
using namespace std;
const int MAXN=250;
int h[MAXN],dp[MAXN];
vector<int> adj[MAXN];
int main(){
    int s,t,p;
    vector<pair<int,int>> graph_height;
    cin>>s>>t>>p;
    for(int i=1;i<=s;i++){
        int a;
        cin>>a;
        h[i]=a;
        graph_height.push_back(make_pair(h[i],i));
    }
    for(int i=1;i<=t;i++){
        int a,b;
        cin>>a>>b;
        if(h[a]>h[b])
            adj[b].push_back(a);
        else if(h[b]>h[a])
            adj[a].push_back(b);
    }
    int m=0;
    sort(graph_height.rbegin(),graph_height.rend());
    for(int i=0;i<s;i++){
        if(graph_height[i].first>h[p])continue;
        for(auto u:adj[graph_height[i].second])
            if(h[u]<=h[p])
                dp[graph_height[i].second]=max(dp[graph_height[i].second],1+dp[u]);
        m=max(m,dp[graph_height[i].second]);
    }
    cout<<m<<endl;
    return 0;
}