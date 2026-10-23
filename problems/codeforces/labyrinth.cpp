#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e3 + 50;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
int n, m;
string g[maxn];
int di[] = {-1, 1, 0, 0}, dj[] = {0, 0, 1, -1};
ll distr[maxn][maxn], distl[maxn][maxn];
bool visr[maxn][maxn], visl[maxn][maxn];
void dijkstrar(int si, int sj){
    priority_queue<tuple<ll, int, int>> pq;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            distr[i][j] = LINF;
    distr[si][sj] = 0;
    pq.push(make_tuple(0, si, sj));
    while(!pq.empty()){
        int ci = get<1>(pq.top()), cj = get<2>(pq.top());
        pq.pop();
        if (visr[ci][cj]) continue;
        visr[ci][cj] = true;
        for(int k = 0; k < 4; k++){
            int vi = ci + di[k], vj = cj + dj[k];
            if(!(vi >= 0 && vi < n && vj >= 0 && vj < m && g[vi][vj] == '.'))
                continue;
            if(k == 3 && distr[ci][cj] + 1 < distr[vi][vj]){
                distr[vi][vj] = distr[ci][cj] + 1;
                pq.push(make_tuple(-distr[vi][vj], vi, vj));
            }else if(distr[ci][cj] < distr[vi][vj]){
                distr[vi][vj] = distr[ci][cj];
                pq.push(make_tuple(-distr[vi][vj], vi, vj));
            }
        }
    }
}

void dijkstral(int si, int sj){
    priority_queue<tuple<ll, int, int>> pq;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            distl[i][j] = LINF;
    distl[si][sj] = 0;
    pq.push(make_tuple(0, si, sj));
    while(!pq.empty()){
        int ci = get<1>(pq.top()), cj = get<2>(pq.top());
        pq.pop();
        if (visl[ci][cj]) continue;
        visl[ci][cj] = true;
        for(int k = 0; k < 4; k++){
            int vi = ci + di[k], vj = cj + dj[k];
            if(!(vi >= 0 && vi < n && vj >= 0 && vj < m && g[vi][vj] == '.'))
                continue;
            if(k == 2 && distl[ci][cj] + 1 < distl[vi][vj]){
                distl[vi][vj] = distl[ci][cj] + 1;
                pq.push(make_tuple(-distl[vi][vj], vi, vj));
            }else if(distl[ci][cj] < distl[vi][vj]){
                distl[vi][vj] = distl[ci][cj];
                pq.push(make_tuple(-distl[vi][vj], vi, vj));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int r, c;
    ll x, y;
    cin >> n >> m;
    cin >> r >> c;
    cin >> x >> y;
    for(int i = 0; i < n; i++){
        string row;
        cin >> row;
        g[i] = row;
    }
    int ans = 0;
    dijkstrar(r - 1, c - 1);
    dijkstral(r - 1, c - 1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visr[i][j] || !visl[i][j])
                continue;
            if(distl[i][j] <= y && distr[i][j] <= x)
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}