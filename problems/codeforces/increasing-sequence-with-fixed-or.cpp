#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll cur = n;
        ll cont = 0;
        vector<ll> ans;
        ll aux = 0, prev = 0;
        while(cur != 0){
            if((cur | prev) == n){
                cont++;
                ans.push_back(cur);
            }
            prev = cur;
            aux = cur ^ n;
            if(aux >= cur)
                break;
            for(ll i = 63; i >= 0; i--)
                if((n & (1LL << i)) && aux + (1LL << i) < cur && !(aux & (1LL << i)))
                    aux += (1LL << i);
            cur = aux;
        }
        reverse(ans.begin(), ans.end());
        cout << cont << endl;
        for(auto u : ans)
            cout << u << ' ';
        cout << endl;
    }
}