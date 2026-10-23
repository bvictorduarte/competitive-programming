#include <bits/stdc++.h>
using namespace std;
vector<int> contas;
int main(){
    int v, ans = 0;
    cin >> v;
    for(int i = 1; i <= 3; i++){
        int a;
        cin >> a;
        contas.push_back(a);
    }
    sort(contas.begin(), contas.end());
    for(int i = 0; i < 3; i++){
        if(v - contas[i] >= 0)
            ans++;
        v -= contas[i];
    }
    cout << ans << endl;
}
