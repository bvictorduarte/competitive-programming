#include<bits/stdc++.h>
using namespace std;
const int maxn=150;
const int INF=0x3f3f3f3f;
vector<pair<int,int>> adj[maxn];
int m[maxn][maxn],dist[maxn][maxn];
bool processed[maxn],removed[maxn][maxn];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            cin>>m[i][j];
            adj[i].push_back(make_pair(j,m[i][j]));
        }
    priority_queue<pair<int,int>> q;
    for(int i=1;i<=n;i++){
        for (int j = 1; j <= n; j++) {
            dist[i][j] = INF;
            processed[j]=false;
        }
        dist[i][i] = 0;
        q.push({0,i});
        while (!q.empty()) {
            int a = q.top().second; q.pop();
            if (processed[a]) continue;
            processed[a] = true;
            for (auto u : adj[a]) {
                int b = u.first, w = u.second;
                if (dist[i][a]+w < dist[i][b]) {
                    dist[i][b] = dist[i][a]+w;
                    q.push({-dist[i][b],b});
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(dist[i][j]!=m[i][j]){
                cout<<"-1"<<endl;
                return 0;
            }
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int k=i+1;k<=n;k++){
            removed[i][k]=removed[k][i]=true;
            for (int j = 1; j <= n; j++) {
                dist[i][j] = INF;
                processed[j]=false;
            }
            dist[i][i] = 0;
            q.push({0,i});
            while (!q.empty()) {
                int a = q.top().second; q.pop();
                if (processed[a]) continue;
                processed[a] = true;
                for (auto u : adj[a]) {
                    int b = u.first, w = u.second;
                    if (!removed[a][b]&&!removed[b][a]&&dist[i][a]+w < dist[i][b]) {
                        dist[i][b] = dist[i][a]+w;
                        q.push({-dist[i][b],b});
                    }
                }
            }
            if(dist[i][k]==m[i][k])
                ans++;
            else
                removed[i][k]=removed[k][i]=false;
        }
    cout<<ans<<endl;
    return 0;
}