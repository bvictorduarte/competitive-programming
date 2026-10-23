#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+50;
int l[maxn],s[maxn];
bool yes[maxn];
vector<pair<pair<int,int>,pair<int,int>>> edges;
int find(int x){
    while(x!=l[x])
        x=l[x];
    return x;
}
bool same(int a,int b){
    return find(a)==find(b);
}
void unite(int a,int b){
    a=find(a);
    b=find(b);
    if(s[a]>s[b])
        swap(a,b);
    l[a]=b;
    s[b]+=s[a];
}
int main(){
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        l[i]=i;
        s[i]=1;
    }
    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        edges.push_back(make_pair(make_pair(w,1),make_pair(a,b)));
    }
    for(int i=0;i<q;i++){
        int a,b,w;
        cin>>a>>b>>w;
        edges.push_back(make_pair(make_pair(w,i+2),make_pair(a,b)));
    }
    sort(edges.begin(),edges.end());
    for(auto edge:edges){
        int op=edge.first.second,a=edge.second.first,b=edge.second.second;
        if(!same(a,b)){
            if(op==1)
                unite(a,b);
            else
                yes[--op]=true;
        }
    }
    for(int i=1;i<=q;i++)
        if(yes[i])
            cout<<"Yes\n";
        else
            cout<<"No\n";
    return 0;
}