#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;
vector<pair<int, int>> adj[150];
priority_queue<pair<int, int>> q;
int distancia[150];
bool visited[150];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].push_back(make_pair(b,w));
        adj[b].push_back(make_pair(a,w));
    }
    for(int i=2;i<=n;i++)
        distancia[i]=INF;
    q.push(make_pair(0,1));
    while(!q.empty()){
        int a=q.top().second;q.pop();
        if(visited[a])continue;
        visited[a]=true;
        for(auto u:adj[a]){
            int b=u.first,w=u.second;
            if(distancia[b]>distancia[a]+w){
                distancia[b]=distancia[a]+w;
                q.push(make_pair(-distancia[b],b));
            }
        }
    }
    cout<<distancia[n]<<endl;
    return 0;
}