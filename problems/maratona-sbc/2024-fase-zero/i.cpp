#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
string cadeia;
int q[maxn];
bool tem[maxn];
int main(){
    int n, m;
    cin >> n >> m;
    string aux = "p";
    cin >> cadeia;
    cadeia = aux + cadeia;
    cadeia[0] = cadeia[m * n];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(cadeia[(i-1)*m + j] == '1')
                q[i]++;
        }
        if(tem[q[i]]){
            cout << 'N' << endl;
            return 0;
        }else
            tem[q[i]] = true;
    }
    for(int i = 2; i <= m; i++){
        for(int j = 0; j <= m; j++)
            tem[j] = false;
        for(int j = 1; j <= n; j++){
            if(j != n){
                if(cadeia[(j-1) * m + i - 1] == '1')
                    q[j]--;
                if(cadeia[j * m + i - 1] == '1')
                    q[j]++;
            }else{
                if(cadeia[(j-1) * m + i - 1] == '1')
                    q[j]--;
                if(cadeia[i-1] == '1')
                    q[j]++;
            }
            if(tem[q[j]]){
                cout << "N\n";
                return 0;
            }else{
                tem[q[j]] = true;
            }
        }
    }
    cout << "S\n";
    return 0;
}