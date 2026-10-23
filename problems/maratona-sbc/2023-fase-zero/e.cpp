#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> palpites, erros;
bool verifica(ll x){
    if(x == 0 || x > 1e9)
        return false;
    unordered_map<ll, ll> mp;
    for(auto e : erros)
        mp[e]++;
    for(auto p : palpites)
        if(mp[abs(x - p)] == 0)
            return false;
        else
            mp[abs(x - p)]--;
    return true;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    for(ll i = 0; i < n; i++){
        ll p;
        cin >> p;
        palpites.push_back(p);
    }
    for(ll i = 0; i < n; i++){
        ll e;
        cin >> e;
        erros.push_back(e);
    }
    sort(erros.begin(), erros.end());
    sort(palpites.begin(), palpites.end());
    set<ll> ans;
    if(verifica(palpites[0] + erros[n-1]))
        ans.insert(palpites[0] + erros[n-1]);
    if(verifica(palpites[n-1] - erros[n-1]))
        ans.insert(palpites[n-1] - erros[n-1]);
    for(auto u : ans)
        cout << u << endl;
}