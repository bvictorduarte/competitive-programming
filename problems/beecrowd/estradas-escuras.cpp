#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+50;
int link[maxn],s[maxn];
int find(int a){
    while(link[a]!=a)
        a=link[a];
    return a;
}
bool same(int a, int b){
    return find(a)==find(b);
}
void unite(int a, int b){
    a=find(a);
    b=find(b);
    if(s[a]>s[b])
        swap(a,b);
    s[b]+=s[a];
    link[a]=b;
}
int main(){
    int n,m;
    while(cin>>n>>m&&n){
        vector<pair<ll,pair<int,int>>> edges;
        ll ans=0;
        for(int i=0;i<n;i++){
            link[i]=i;
            s[i]=1;
        }
        for(int i=0;i<m;i++){
            ll w;
            int b,c;
            cin>>b>>c>>w;
            edges.push_back(make_pair(w,make_pair(b,c)));
            ans+=w;
        }
        sort(edges.begin(),edges.end());
        for(auto edge:edges){
            int b=edge.second.first,c=edge.second.second;
            if(!same(b,c)){
                unite(b,c);
                ans-=edge.first;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}