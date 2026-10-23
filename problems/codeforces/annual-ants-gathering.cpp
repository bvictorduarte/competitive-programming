#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int sz[maxn];
vector<int> adj[maxn];
set<int> s[maxn];
int find_sz(int x=1, int p=0){
    sz[x]=1;
    for(auto u:adj[x])
        if(u!=p)
            sz[x]+=find_sz(u,x);
    return sz[x];
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bool yes=true;
    find_sz();
    for(int i=1;i<=n;i++){
        for(auto u:adj[i]){
            if(s[i].find(sz[u])!=s[i].end())
                yes=false;
            else
                s[i].insert(sz[u]);
        }
    }
    if(yes)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}