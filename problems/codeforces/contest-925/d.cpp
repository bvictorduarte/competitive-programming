#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+50;
typedef long long ll;
ll v[maxn];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        ll x,y;
        multiset<pair<ll,ll>> sr;
        cin>>n>>x>>y;
        for(int i=1;i<=n;i++){
            cin>>v[i];
            sr.insert({v[i]%x,v[i]%y});
        }
        ll ans=0;
        for(int i=1;i<=n;i++){
            ll rx=v[i]%x,ry=v[i]%y;
            ans+=sr.count({(x-rx)%x,ry});
            if((x-rx)%x==rx)
                ans--;
        }
        cout<<ans/2<<endl;
    }
    return 0;
}