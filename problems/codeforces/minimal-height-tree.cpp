#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 50;
int n, idx;
int v[maxn], a[maxn];
void pre_process(){
    a[1] = 1;
    int cont = 0;
    idx = 2;
    for(int i = 2; i <= n; i++){
        if(v[i] > v[i - 1]){
            cont++;
            if(i == n)
                a[idx] = cont;
        }
        else{
            a[idx++] = cont;
            cont = 1;
        }
    }
    if(cont == 1)
        a[idx] = 1; 
}
int solve(){
    int cont = 0, cur = 0, prev = 1;
    for(int i = 2; i <= n; i++){
        prev--;
        cur += a[i];
        if(prev == 0){
            cont++;
            prev = cur;
            cur = 0;
        }
    }
    return cont;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> v[i];
        pre_process();
        cout << solve() << endl;
    }
}