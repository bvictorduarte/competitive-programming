#include<bits/stdc++.h>
using namespace std;
const int MAXN=10050;
vector<tuple<long long, long long, long long>> edges;
long long link[MAXN],size[10050];
long long find(long long x){
    while(x!=link[x])
        x=link[x];
    return x;
}
bool same(long long a, long long b){
    return find(a)==find(b);
}
void unite(long long a, long long b){
    a=find(a);
    b=find(b);
    if(size[a]<size[b])swap(a,b);
    size[a]+=size[b];
    link[b]=a;
}
int main(){
    long long n,m,ans=0;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        long long a,b,c;
        cin>>a>>b>>c;
        edges.push_back(make_tuple(c,a,b));
    }
    sort(edges.begin(),edges.end());
    for(long long i=1;i<=n;i++){
        link[i]=i;
        size[i]=1;
    }
    for(auto e:edges){
        long long a,b,c;
        tie(c,a,b)=e;
        if(!same(a,b)){
            ans+=c;
            unite(a,b);
        }
    }
    cout<<ans<<endl;
    return 0;
}