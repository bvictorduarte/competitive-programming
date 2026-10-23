#include <bits/stdc++.h>
using namespace std;
const int maxn = 150;
int m[maxn][maxn];
int main(){
    int n, x, y, sl = 0, sl2 = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> m[i][j];
            if(m[i][j] == 0){
                x = i;
                y = j;
            }
        }
    }
    for(int i = 1; i <= n; i++)
        sl += m[x][i];
    if(x > 1)
        for(int i = 1; i <= n; i++)
            sl2 += m[x - 1][i];
    else if(x < n)
        for(int i = 1; i <= n; i++)
            sl2 += m[x + 1][i];
    cout << sl2 - sl << endl << x << endl << y << endl;
    return 0;
}
