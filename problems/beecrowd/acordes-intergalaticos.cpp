#include<bits/stdc++.h>
using namespace std;
#define l(p) (p << 1)
#define r(p) l(p) + 1
const int maxn = 1e5 +50;
int st[4 * maxn][9], lazy[4 * maxn];
int n;
void propagate(int p, int L, int R){
    if(!lazy[p]) return;
    int aux[9];
    for(int i = 0; i < 9; i++)
        aux[i] = st[p][i];
    for(int i = 0; i < 9; i++)
        st[p][(i+lazy[p])%9] = aux[i];
    if(L != R){
        lazy[l(p)] += lazy[p];
        lazy[r(p)] += lazy[p];
    }
    lazy[p] = 0;
}
void build(int p = 1, int L = 0, int R = n - 1){
    if(L == R)
        st[p][1] = 1;
    else{
        int m = (L + R) / 2;
        build(l(p), L, m);
        build(r(p), m+1, R);
        st[p][1] = st[l(p)][1] + st[r(p)][1];
    }
}
array<int, 9> RFQ(int i, int j, int p = 1, int L = 0, int R = n - 1){
    propagate(p, L, R);
    array<int, 9> u;
    for(int k = 0; k < 9; k++)
        u[k] = 0;
    if(i > R || j < L) return u;
    if(i <= L && j >= R){
        for(int k = 0; k < 9; k++)
            u[k] = st[p][k];
        return u;
    }
    array<int, 9> aux;
    int m = (L + R) / 2;
    aux = RFQ(i, j, l(p), L, m);
    u = RFQ(i, j, r(p), m + 1, R);
    for(int k = 0; k < 9; k++)
        u[k] += aux[k];
    return u;
}
void update(int i, int j, int val, int p = 1, int L = 0, int R = n-1){
    if(i > R || j < L) return;
    if(i <= L && j >= R){
        lazy[p] += val;
        propagate(p, L, R);
    }else{
        propagate(p, L, R);
        int m = (L + R) / 2;
        update(i, j, val, l(p), L, m);
        update(i, j, val, r(p), m + 1, R);
        for(int k = 0; k < 9; k++)
            st[p][k] = st[l(p)][k] + st[r(p)][k];
    }
}
int query(int i, int j){
    int max_f = -1, f_max;
    array<int, 9> q = RFQ(i, j);
    for(int f = 0; f < 9; f++){
        if(max_f <= q[f]){
            max_f = q[f];
            f_max = f;
        }
    }
    return f_max;
}
int main(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int q;
    cin >> n >> q;
    build();
    for(int i = 1; i <= q; i++){
        int a, b;
        cin >> a >> b;
        update(a, b, query(a, b));
    }
    for(int i = 0; i < n; i++)
        cout << query(i, i) << endl;
    return 0;
}