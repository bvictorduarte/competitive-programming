#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 25000000;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    while(cin >> n && n){
        cout<<1;
        for(int i = 2; i*i <= n; i++)
                cout<<' '<<i*i;
        cout<<'\n';
    }
    return 0;
}