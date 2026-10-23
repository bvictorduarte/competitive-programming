#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
const int maxn=2e5+30;
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
ordered_set s;
int v[maxn];
int main(){
    int n,q;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        s.insert(make_pair(v[i],i));
    }
    string op;
    int a,b;
    for(int i=1;i<=q;i++){
        cin>>op>>a>>b;
        if(op=="?"){
            cout<<s.order_of_key(make_pair(b+1,0))-s.order_of_key(make_pair(a,0))<<'\n';
        }else{
            s.erase(s.find(make_pair(v[a],a)));
            s.insert(make_pair(b,a));
            v[a]=b;
        }
    }
    return 0;
}