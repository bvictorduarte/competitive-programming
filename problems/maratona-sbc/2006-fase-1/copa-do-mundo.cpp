#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, t;
    while(cin >> t >> n && t){
        string s;
        ll a;
        ll sum = 0;
        for(int i = 0; i < t; i++){
            cin >> s >> a;
            sum += a;
        }
        cout<<(3*n-sum)<<endl;
    }
}