#include<bits/stdc++.h>
using namespace std;
int main(){
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        string s;
        string t;
        cin >> s >> t;
        int fs1 = n;
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                fs1 = i;
                break;
            }
        }
        int ft1 = n;
        for(int i = 0; i < n; i++){
            if(t[i] == '1'){
                ft1 = i;
                break;
            }
        }
        if(ft1 < fs1)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}