#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        if(n < m || (n >= m && (n - m) % 2 !=0))
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}