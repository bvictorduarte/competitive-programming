#include<bits/stdc++.h>
using namespace std;
string s[4];
int main(){
    char ans = '0';
    s[3] = "0";
    cin >> s[1];
    s[2] = s[1];
    cin >> s[3];
    if(s[1] != s[3])
        ans = 'A';
    string ult;
    cin >> ult;
    if(ult == s[2] && ans == '0')
        ans = 'B';
    else if(ans == '0')
        ans = 'C';
    cout << ans << endl;
    return 0;
}