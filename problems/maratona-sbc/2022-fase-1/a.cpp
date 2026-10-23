#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int cont = 0;
        if(i > 0 && s[i - 1] == 'a' && s[i] == 'a')
            cont++;
        if(i < n - 1 && s[i + 1] == 'a' && s[i] == 'a')
            cont++;
        if(cont > 0)
            ans++;
    }
    cout << ans << endl;
    return 0;
}