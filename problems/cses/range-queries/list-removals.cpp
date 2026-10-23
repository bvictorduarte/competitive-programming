#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
const int maxn=2e5+30;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
ordered_set s;
int v[maxn];
int main(){
    int n;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        s.insert(i);
    }
    int p;
    for(int i=1;i<n;i++){
        cin>>p;
        cout<<v[(*s.find_by_order(p-1))]<<' ';
        s.erase(s.find_by_order(p-1));
    }
    cin>>p;
    cout<<v[(*s.find_by_order(p-1))]<<'\n';
    return 0;
}