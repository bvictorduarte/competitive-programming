#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+50;
vector<int> adj[maxn],solve,filhos[maxn];
map<pair<int,int>, int> mp;
bool visited[maxn],marc[maxn];
int cont=0;
int n,m,k;
pair<int,int> first;
void dfs(int x){
    for(auto u:adj[x]){
        if(!visited[u]){
            visited[u]=true;
            filhos[x].push_back(u);
            dfs(u);
        }
    }
    for(auto u:filhos[x]){
        if(cont<k){
            if(marc[u])continue;
            marc[u]=true;;
            if(!marc[x]){
                marc[x]=true;
                cont+=2;
            }
            else marc[x]=false;
            solve.push_back(mp[{x,u}]);
        }
    }
}
int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        mp[{a,b}]=i;
        mp[{b,a}]=i;
    }
    for(int i=1;i<=n;i++)
        if(!visited[i]){
            visited[i]=true;
            dfs(i);
        }
    if(cont!=k){
        cout<<"No\n";
        return 0;
    }
    cout<<"Yes\n";
    cout<<(int)solve.size()<<endl;
    if((int)solve.size()>0)
        cout<<solve[0];
    for(int i=1;i<(int)solve.size();i++)
        cout<<" "<<solve[i];
    cout<<endl;
    return 0;
}