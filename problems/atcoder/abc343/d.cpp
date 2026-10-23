#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=2e6+50;
map<ll, ll> mp;
ll points[maxn];
int main(){
    ll n,t,cont=1;
    cin>>n>>t;
    mp[0]=n;
    for(ll i=1;i<=t;i++){
        ll a,b;
        cin>>a>>b;
        if(mp[points[a]]==1)
            cont--;
        mp[points[a]]--;
        points[a]+=b;
        mp[points[a]]++;
        if(mp[points[a]]==1)
            cont++;
        cout<<cont<<endl;
    }
    return 0;
}