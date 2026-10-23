#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 10;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
bool mark[maxn][maxn], vis[maxn][maxn];
ll dist[maxn][maxn];
int C, R, Cf, Rf, Ct, Rt, W;
int di1[] = {1, -1, 0, 0}, dj1[] = {0, 0, 1, -1};
int di2[] = {2, -2, 0, 0}, dj2[] = {0, 0, 2, -2};
int di3[] = {2, -2, 2, -2}, dj3[] = {2, 2, -2, -2};
int di4[] = {1, -1, 1, -1}, dj4[] = {1, 1, -1, -1};
int di5[] = {1, -1, 2, -2, 1, -1, 2, -2}, dj5[] = {2, 2, 1, 1, -2, -2, -1, -1};
bool is_valid(int i, int j){
    return((i >= 1 && i <= R) && (j >= 1 && j <= C) && !mark[i][j]);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin >> C >> R && !(C == 0 && R == 0)){
        for(int i = 1; i <= R; i++)
            for(int j = 1; j <= C; j++){
                mark[i][j] = false;
                vis[i][j] = false;
                dist[i][j] = LINF;
            }
        cin >> Cf >> Rf >> Ct >> Rt;
        cin >> W;
        for(int i = 0; i < W; i++){
            int C1, R1, C2, R2;
            cin >> C1 >> R1 >> C2 >> R2;
            for(int j = R1; j <= R2; j++)
                for(int k = C1; k <= C2; k++)
                    mark[j][k] = true;
        }
        priority_queue<tuple< ll, int , int>> pq;
        pq.push(make_tuple(0, Rf, Cf));
        dist[Rf][Cf] = 0;
        while(!pq.empty()){
            int i, j;
            ll d;
            tie(d, i, j) = pq.top();pq.pop();
            d = -d;
            if(vis[i][j])continue;
            vis[i][j] = true;
            for(int k = 0; k < 4; k++)
                if(is_valid(i + di1[k], j + dj1[k])){
                    int ui=i + di1[k], uj =  j + dj1[k];
                    ll w = 2;
                    dist[ui][uj] = min(dist[ui][uj], d + w);
                    pq.push(make_tuple(-dist[ui][uj], ui, uj));
                }
            for(int k = 0; k < 4; k++)
                if(is_valid(i + di2[k], j + dj2[k])){
                    int ui=i + di2[k], uj =  j + dj2[k];
                    ll w = 5;
                    dist[ui][uj] = min(dist[ui][uj], d + w);
                    pq.push(make_tuple(-dist[ui][uj], ui, uj));
                }
            for(int k = 0; k < 4; k++)
                if(is_valid(i + di3[k], j + dj3[k])){
                    int ui=i + di3[k], uj =  j + dj3[k];
                    ll w = 7;
                    dist[ui][uj] = min(dist[ui][uj], d + w);
                    pq.push(make_tuple(-dist[ui][uj], ui, uj));
                }
            for(int k = 0; k < 4; k++)
                if(is_valid(i + di4[k], j + dj4[k])){
                    int ui=i + di4[k], uj =  j + dj4[k];
                    ll w = 3;
                    dist[ui][uj] = min(dist[ui][uj], d + w);
                    pq.push(make_tuple(-dist[ui][uj], ui, uj));
                }
            for(int k = 0; k < 8; k++)
                if(is_valid(i + di5[k], j + dj5[k])){
                    int ui=i + di5[k], uj =  j + dj5[k];
                    ll w = 6;
                    dist[ui][uj] = min(dist[ui][uj], d + w);
                    pq.push(make_tuple(-dist[ui][uj], ui, uj));
                }
        }
        if(dist[Rt][Ct] == LINF)
            cout << "impossible\n";
        else
            cout << dist[Rt][Ct] << '\n';
    }
}