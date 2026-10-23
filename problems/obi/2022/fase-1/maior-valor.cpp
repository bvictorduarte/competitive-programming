#include <bits/stdc++.h>
using namespace std;
int soma(int x){
    int sum = 0;
    while(x > 0){
        sum += x % 10;
        x = x / 10;
    }
    return sum;
}
int main(){
    int n, m, s, i;
    bool achou = false;
    cin >> n >> m >> s;
    for(i = m; i >= n; i--){
        if(soma(i) == s){
            achou = true;
            break;
        }
    }
    if(achou)
        cout << i << endl;
    else
        cout << -1 << endl;
    return 0;
}
