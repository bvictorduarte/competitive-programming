#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e4 + 50;
ll deg[maxn];
int main(){
    ll n, m;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin >> n >> m && !(!n && !m)){
        for(int i = 1; i <= n; i++)
            deg[i] = 0;
        for(int i = 1; i <= m; i++){
            ll a, b;
            cin >> a >> b;
            deg[a]++;
            deg[b]++;
        }
        vector<ll> seq_deg;
        for(int i = 1; i <= n; i++)
            seq_deg.push_back(deg[i]);
        sort(seq_deg.rbegin(), seq_deg.rend());
        ll m_max = 1;
        while(m_max <= n && seq_deg[m_max - 1] >= m_max - 1)
            m_max++;
        m_max--;
        ll s1 = 0, s2 = 0;
        for(int i = 1; i <= m_max; i++)
            s1 += seq_deg[i - 1];
        for(int i = m_max + 1; i <= n; i++)
            s2 += seq_deg[i - 1];
        if(s1 == m_max * (m_max - 1) + s2)
            cout << "Y\n";
        else
            cout << "N\n";
    }
    return 0;
}