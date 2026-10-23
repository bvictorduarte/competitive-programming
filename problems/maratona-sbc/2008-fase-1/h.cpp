#include <bits/stdc++.h>
#define ll long long int
#define rep(a) for(ll i = 0; i<a; i++)

using namespace std;

int main(){
    ll k, n, m, x, y;
    while(cin>>k && k != 0){
        cin>>n>>m;
        rep(k){
            cin>>x>>y;
            if(x < n && y > m) cout<<"NO\n";
            else if(x > n && y > m) cout<<"NE\n";
            else if(x > n && y < m) cout<<"SE\n";
            else if(x < n && y < m) cout<<"SO\n";
            else cout<<"divisa\n";
        }
    }
    return 0;
}