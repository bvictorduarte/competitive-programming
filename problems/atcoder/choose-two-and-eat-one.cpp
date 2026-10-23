#include<bits/stdc++.h>
using namespace std;
const int maxn=550;
typedef long long ll;
int l[maxn],s[maxn];
ll val[maxn],pre_compx[31],pre_compy[31],m;
vector<pair<ll,pair<int,int>>> edges;
void precomp(){
    for(int i=1;i<=30;i++){
        pre_compx[i]=pre_compx[i-1]*pre_compx[i-1];
        pre_compy[i]=pre_compy[i-1]*pre_compy[i-1];
        pre_compx[i]%=m;
        pre_compy[i]%=m;
    }
}
ll compscore(ll x, ll y){
    ll x1=1,y1=1;
    for(int i=0;i<=30;i++)
        if(y&(1<<i)){
            x1*=pre_compx[i];
            x1%=m;
        }
    for(int i=0;i<=30;i++)
        if(x&(1<<i)){
            y1*=pre_compy[i];
            y1%=m;
        }
    return (x1+y1)%m;
}
int find(int x){
    while(x!=l[x])
        x=l[x];
    return x;
}
bool same(int a, int b){
    return find(a)==find(b);
}
void unite(int a,int b){
    a=find(a);
    b=find(b);
    if(s[b]>s[a])swap(a,b);
    l[b]=a;
    s[a]+=s[b];
}
int main(){
    int n;
    ll ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        l[i]=i;
        s[i]=1;
    }
    for(int i=1;i<=n;i++)
        cin>>val[i];
    for(int i=1;i<n;i++){
        pre_compx[0]=val[i];
        for(int j=i+1;j<=n;j++){
            pre_compy[0]=val[j];
            precomp();
            ll w=compscore(val[i],val[j]);
            edges.push_back(make_pair(w,make_pair(i,j)));
        }
    }
    sort(edges.rbegin(),edges.rend());
    for(auto edge:edges){
        ll w=edge.first,a=edge.second.first,b=edge.second.second;
        if(!same(a,b)){
            unite(a,b);
            ans+=w;
        }
    }
    cout<<ans<<endl;
    return 0;
}