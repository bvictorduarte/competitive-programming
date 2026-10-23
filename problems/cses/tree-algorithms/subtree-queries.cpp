#include<bits/stdc++.h>
using namespace std;
const int maxN=1<<19;
typedef long long ll;
vector<ll> adj[maxN],traversal_array;
int tam_subtree[maxN],tam;
ll posi_traversal_array[maxN],seg_tree[maxN];
void dfs(int x, int parent){
    int sum=1;
    traversal_array.push_back(x);
    for(auto u:adj[x])
        if(u!=parent){
            dfs(u,x);
            sum+=tam_subtree[u];
        }
    tam_subtree[x]=sum;
}
void update(int s, ll x){
    s+=tam/2;
    seg_tree[s]+=x;
    for(s/=2;s>=1;s/=2)
        seg_tree[s]=seg_tree[2*s]+seg_tree[2*s+1];
}
ll query(int a, int b){
    a+=tam/2;b+=tam/2;
    ll sum=0;
    while(a<=b){
        if(a%2==1)sum+=seg_tree[a++];
        if(b%2==0)sum+=seg_tree[b--];
        b/=2;a/=2;
    }
    return sum;
}
int main(){
    int n,q;
    cin>>n>>q;
    tam=(1<<(((int)log2(n))+2));
    vector<ll> v;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    for(int i=0;i<n;i++)
        posi_traversal_array[traversal_array[i]]=i;
    for(int i=0;i<n;i++)
        update(posi_traversal_array[i+1],v[i]-seg_tree[posi_traversal_array[i+1]+tam/2]);
    for(int i=0;i<q;i++){
        int op;
        cin>>op;
        if(op==1){
            int s;
            ll x;
            cin>>s>>x;
            update(posi_traversal_array[s],x-seg_tree[posi_traversal_array[s]+tam/2]);
        }else{
            int a;
            cin>>a;
            cout<<query(posi_traversal_array[a],posi_traversal_array[a]+tam_subtree[a]-1)<<endl;
        }
    }
    return 0;
}