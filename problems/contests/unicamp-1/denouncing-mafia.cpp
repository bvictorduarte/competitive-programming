#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+50;
int dad[maxn];
queue<int> leaf;
stack<int> ans;
int deg[maxn],val[maxn];
int main(){
    int n,k;
    cin>>n>>k;
    for(int b=2;b<=n;b++){
        int a;
        cin>>a;
        dad[b]=a;
        deg[a]++;
        deg[b]++;
    }
    for(int i=2;i<=n;i++)
        if(deg[i]==1){
            leaf.push(i);
            val[i]=1;
        }
    while(!leaf.empty()){
        int v=leaf.front();leaf.pop();
        if(v==1){
            ans.push(val[v]);
            break;
        }
        deg[dad[v]]--;
        if((deg[dad[v]]<=1&&dad[v]!=1)||(dad[v]==1&&deg[1]==0)){
            val[dad[v]]=val[v]+1;
            leaf.push(dad[v]);
        }
        else
            ans.push(val[v]);
    }
    int resp=0;
    while(k--){
        resp+=ans.top();
        ans.pop();
    }
    cout<<resp<<endl;
    return 0;
}