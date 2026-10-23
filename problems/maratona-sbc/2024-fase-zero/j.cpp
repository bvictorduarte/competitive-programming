#include<bits/stdc++.h>
using namespace std;
const int maxn = 550;
vector<string> grid;
int quant[maxn][maxn];
int main(){
    int n, m, k, l;
    cin >> n >> m >> k >> l;
    k--;
    l--;
    for(int i = 0 ; i < n; i++)
        for(int j = 0;j < m; j++)
            quant[i][j] = -1;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        grid.push_back(s);
    }
    int ans = -1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '*')continue;
            int di[] = {k, k, -k, -k, l, l, -l, -l}, dj[] = {l, -l, l, -l, k, -k, k, -k};
            int cont = 0;
            for(int p = 0; p < 8; p++){
                if(i + di[p] >= 0 && i + di[p] < n && j + dj[p] >= 0 && j + dj[p] < m && grid[i + di[p]][j + dj[p]] != '.')
                    cont++;
            }
            quant[i][j] = cont;
            ans = max(ans, cont);
        }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(ans == quant[i][j]){
                cout << i+1 << ' ' << j+1 << endl;
                return 0;
            }
    return 0;
}