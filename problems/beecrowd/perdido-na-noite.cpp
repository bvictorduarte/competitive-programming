#include<bits/stdc++.h>
using namespace std;
const int maxn = 150;
vector<int> adj[maxn];
const double EPS = 1e-9;
const int INF = 2; // it doesn't actually have to be infinity or a big number

int gauss (vector < vector<double> > a, vector<double> & ans) {
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;

    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if (abs (a[i][col]) > abs (a[sel][col]))
                sel = i;
        if (abs (a[sel][col]) < EPS)
            continue;
        for (int i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row) {
                double c = a[i][col] / a[row][col];
                for (int j=col; j<=m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        ++row;
    }

    ans.assign (m, 0);
    for (int i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m] / a[where[i]][i];
    for (int i=0; i<n; ++i) {
        double sum = 0;
        for (int j=0; j<m; ++j)
            sum += ans[j] * a[i][j];
        if (abs (sum - a[i][m]) > EPS)
            return 0;
    }

    for (int i=0; i<m; ++i)
        if (where[i] == -1)
            return INF;
    return 1;
}
int main(){
    int n, a, b, c;
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> n >> a >> b >> c){
        a--; b--; c--;
        for(int i = 0; i < n; i++)
            adj[i].resize(0);
        for(int i = 1; i < n; i++){
            int x, y;
            cin >> x >> y;
            x--; y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<vector<double>> A;
        for(int i = 0; i < n; i++){
            vector<double> row;
            for(int j = 0; j < n + 1; j++)
                row.push_back(0);
            A.push_back(row);
        }
        for(int i = 0; i < n; i++)
            if(i != b && i != c){
                int tam = (int)adj[i].size();
                A[i][i] = tam;
                for(auto u : adj[i]){
                    if(u != b)
                        A[i][u] = -1;
                    else
                        A[i][n] = 1;
                }
            }
        A[b][b] = A[b][n] = A[c][c] = 1;
        vector<double> ans;
        gauss(A, ans);
        printf("%.6lf\n", ans[a]);
    }
    return 0;
}