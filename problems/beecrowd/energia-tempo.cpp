#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxP = 5050;
const int maxF = 25;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
ll e[maxP][maxF], a[maxP][maxF], dist[maxP][maxF];
bool vis[maxP][maxF];
priority_queue<tuple<ll, int, int>> pq;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int F, P;
    ll E, A;
    while(cin >> F >> P >> E >> A && !(!F && !P && !E && !A)){
        while(!pq.empty())
            pq.pop();
        ll ans;
        for(int i = 1; i <= P; i++)
            for(int j = 1; j <= F; j++){
                cin >> e[i][j] >> a[i][j];
                dist[i][j] = LINF;
                vis[i][j] = false;
            }
        dist[1][1] = e[1][1] * a[1][1];
        pq.push(make_tuple(-dist[1][1], 1, 1));
        for(ll i = 2; i <= F; i++){
            dist[1][i] = e[1][i] * a[1][i] + E * A;
            pq.push(make_tuple(-dist[1][i], 1, i));
        }
        while(!pq.empty()){
            int p, f;
            ll d;
            tie(d, p, f) = pq.top();
            d *= (-1);
            pq.pop();
            if(vis[p][f])continue;
            vis[p][f] = true;
            if(p == P){
                ans = d;
                break;
            }
            for(int i = 1; i <= F; i++)
                if(i != f && dist[p+1][i] > dist[p][f] + a[p+1][i] * e[p+1][i] + A * E){
                    dist[p+1][i] = dist[p][f] + a[p+1][i] * e[p+1][i] + A * E;
                    pq.push(make_tuple(-dist[p+1][i], p+1, i));
                }else if(i == f && dist[p+1][i] > dist[p][f] + a[p+1][i] * e[p+1][i]){
                    dist[p+1][i] = dist[p][f] + a[p+1][i] * e[p+1][i];
                    pq.push(make_tuple(-dist[p+1][i], p+1, i));
                }
        }
        cout << ans << endl;
    }
    return 0;
}