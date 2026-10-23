#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 550;
ll dist[maxn][maxn], adj_matrix[maxn][maxn];
bool exist[maxn];
vector<int> erased;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            ll w;
            cin >> w;
            dist[i][j] = w;
        }
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        erased.push_back(a);
    }
    reverse(erased.begin(), erased.end());
    vector<ll> ans;
    for(auto u : erased){
        ll sum = 0;
        exist[u] = true;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++){
                dist[i][j] = min(dist[i][u] + dist[u][j], dist[i][j]);
                if(exist[i] && exist[j])
                    sum += dist[i][j];
            }
        ans.push_back(sum);
    }
    reverse(ans.begin(), ans.end());
    for(auto u : ans)
        cout << u << ' ';
    cout << endl;
    return 0;
}