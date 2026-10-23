#include<bits/stdc++.h>
using namespace std;
int main(){
    string s, c;
    cin >> s >> c;
    int cont = (int)s.size()-(int)c.size()+1;
    for(int i = 1; i <= (int)s.size()-(int)c.size()+1; i++)
        for(int j = 0; j < (int)c.size(); j++)
            if(c[j] == s[i + j -1]){
                cont--;
                break;
            }
    cout << cont << endl;
    return 0;
}