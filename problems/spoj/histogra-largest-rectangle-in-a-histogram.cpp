#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    while(cin>>n&&n){
        cin>>n;
        stack<pair<ll,ll>> s;
        ll ans=0;
        for(ll i=1;i<=n;i++){
            int a;
            cin>>a;
            while(!s.empty()&&s.top().first>=a){
                auto u=s.top();s.pop();
                ans=max(ans,u.first*(!s.empty()?(i-s.top().second-1):i-1));
            }
            s.push({a,i});
        }
        while(!s.empty()){
            auto u=s.top();s.pop();
            ans=max(ans,u.first*(!s.empty()?(n-s.top().second):n));
        }
        cout<<ans<<endl;
    }
    return 0;
}