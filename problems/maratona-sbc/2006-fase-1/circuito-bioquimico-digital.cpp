#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
int grid[maxn][maxn];
int main(){
    int p, n, c, cont, ans;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin >> p >> n >> c && p && n && c){
        ans = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= p; j++)
                cin >> grid[i][j];
        for(int j = 1; j <= p; j++){
            for(int i = 1; i <= n; i++){
                if(i == 1){
                    if(grid[i][j])
                        cont = 1;
                    else
                        cont = 0;
                }else{
                    if(grid[i][j]){
                        if(grid[i-1][j])
                            cont++;
                        else
                            cont = 1;
                    }else{
                        if(grid[i-1][j] && cont >= c)
                            ans++;
                        cont = 0;
                    }
                }
            }
            if(grid[n][j] && cont >= c)
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}