#include<bits/stdc++.h>
using namespace std;
const int maxm=2050;
const int INF=0x3f3f3f3f;
bool visited[maxm];
int dist[maxm];
int main(){
    int m;
    dist[0]=0;
    while(cin>>m&&m){
        string ini,fim;
        tuple<string,string,string> v[maxm];
        vector<pair<int,int>> adj[maxm];
        for(int i=1;i<=m;i++){
            visited[i]=false;
            dist[i]=INF;
        }
        visited[2010]=false;
        dist[2010]=INF;
        cin>>ini>>fim;
        for(int i=1;i<=m;i++){
            string l1,l2,p;
            cin>>l1>>l2>>p;
            v[i]={p,l1,l2};
        }
        for(int i=1;i<=m;i++)
            for(int j=i+1;j<=m;j++){
                string l11,l21,p1,l12,l22,p2;
                tie(p1,l11,l21)=v[i];
                tie(p2,l12,l22)=v[j];
                if((l11==l12||l11==l22||l21==l12||l21==l22)&&p1[0]!=p2[0]){
                    adj[i].push_back({j,(int)p1.size()});
                    adj[j].push_back({i,(int)p2.size()});
                }
            }
        for(int i=1;i<=m;i++){
            string l1,l2,p;
            tie(p,l1,l2)=v[i];
            if(l1==ini||l2==ini)
                adj[0].push_back({i,0});
            if(l1==fim||l2==fim)
                adj[i].push_back({2010,(int)p.size()});
        }
        priority_queue<pair<int,int>> q;
        q.push({0,0});
        visited[0]=false;
        while(!q.empty()){
            int v=q.top().second;q.pop();
            if(visited[v])continue;
            visited[v]=true;
            for(auto p:adj[v]){
                int w=p.second,u=p.first;
                if(dist[u]>dist[v]+w){
                    dist[u]=dist[v]+w;
                    q.push({-dist[u],u});
                }
            }
        }
        if(dist[2010]!=INF)
            cout<<dist[2010]<<endl;
        else
            cout<<"impossivel\n";
    }
}