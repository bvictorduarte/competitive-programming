#include <bits/stdc++.h>
using namespace std;
const int maxn = 1050;
int adj_matrix[maxn][maxn];
int main(){
    int s, t;
    cin >> s >> t;
    int x, y;
    for(int i = 1; i <= t; i++){
        cin >> x >> y;
        adj_matrix[x][y] = 1;
        adj_matrix[y][x] = 1;
    }
    int p, n, l, r, cont = 0;
    bool ok;
    cin >> p;
    for(int i = 1; i <= p; i++){
        cin >> n;
        ok = true;
        cin >> l;
        for(int j = 2; j <= n; j++){
            cin >> r;
            if(adj_matrix[l][r] == 0)
                ok = false;
            l = r;
        }
        if(ok)
            cont++;
    }
    cout << cont << endl;
    return 0;
}
