#include <bits/stdc++.h>
#define ll long long int
#define rep(a) for(ll i = 0; i<a; i++)

using namespace std;

const ll MAX_N = 2e5+20;

ll num[MAX_N], pos[MAX_N];

int main(){
    cin.tie(0);
    ll n;
    while(cin>>n && n!=0){
        rep(n){
            cin>>num[i+1];
            pos[num[i+1]] = i+1;
        }
        ll ans = 0;
        rep(n){
            if(num[i+1] == i+1) continue;
            ans++;
            ll a = pos[i+1], b = num[i+1];
            pos[i+1] = i+1;
            pos[num[i+1]] = a;
            num[i+1] = i+1;
            num[a] = b;
        }
        cout<<((ans%2 == 0)?"Carlos":"Marcelo")<<'\n';
    }
    return 0;
}