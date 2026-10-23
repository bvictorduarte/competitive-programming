#include <bits/stdc++.h>
using namespace std;
const int maxn = 550;
int est[maxn][maxn];
int main(){
    int m, n;
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            cin >> est[i][j];
    int p, t, tam, cont = 0;
    cin >> p;
    for(int i = 1; i <= p; i++){
        cin >> t >> tam;
        if(est[t][tam] != 0){
            est[t][tam]--;
            cont++;
        }
    }
    cout << cont << endl;
    return 0;
}
