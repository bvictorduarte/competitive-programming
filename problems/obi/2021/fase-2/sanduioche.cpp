#include<bits/stdc++.h>
using namespace std;
set<int> subset;
const int MAXN=25;
int n,cont=0;
vector<int> adj[MAXN];
void subsets(int a){
    if(a==n+1){
        for(auto u:subset){
            for(auto k:adj[u]){
                if(subset.find(k)!=subset.end())
                    return;
            }
        }
        cont++;
        return;
    }
    subset.insert(a);
    subsets(a+1);
    subset.erase(subset.find(a));
    subsets(a+1);
}
int main(){
    int m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    subsets(1);
    cout<<--cont<<endl;
    return 0;
}