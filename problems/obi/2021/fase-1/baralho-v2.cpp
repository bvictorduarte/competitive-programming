#include <bits/stdc++.h>
using namespace std;
int cont[10][20];
map<char, int> mp;
string s;
int convert(int i){
    return (s[i] - '0') * 10 + (s[i + 1] - '0');
}
int main(){
    mp['C'] = 0;
    mp['E'] = 1;
    mp['U'] = 2;
    mp['P'] = 3;
    cin >> s;
    int n = (int)s.size();
    for(int i = 0; i < n; i += 3)
        cont[mp[s[i + 2]]][convert(i)]++;
    for(int j = 0; j < 4; j++){
        bool erro = false;
        int sum = 0;
        for(int i = 1; i <= 13; i++)
            if(cont[j][i] > 1)
                erro = true;
            else
                sum += cont[j][i];
        if(erro)
            cout << "erro\n";
        else
            cout << 13 - sum << endl;
    }
    return 0;
}
