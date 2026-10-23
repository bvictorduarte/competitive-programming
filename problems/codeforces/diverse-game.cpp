#include<bits/stdc++.h>
using namespace std;
const int maxn = 15;
int a[maxn][maxn], b[maxn][maxn];
bool v[maxn * maxn];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                cin >> a[i][j];
        if(m == 1){
            for(int i = 1; i <= n - 1; i++)
                b[i][1] = a[i + 1][1];
            b[n][1] = a[1][1];
        }else{
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m - 1; j++)
                    b[i][j] = a[i][j + 1];
                b[i][m] = a[i][1];
            }
        }
        if(n == 1 && m == 1){
            cout << -1 << endl;
            continue;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++)
                cout << b[i][j] << ' ';
            cout << endl;
        }
    }
}