#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 50;
vector<int> aux;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        aux.resize(0);
        cin >> n;
        string a;
        cin >> a;
        aux.push_back((int)(a[0] - '0'));
        for(int i = 1; i < n; i++){
            if(aux[(int)aux.size() - 1] == 0 && a[i] == '0')
                continue;
            else
                aux.push_back((int)(a[i] - '0'));
        }
        int sum = 0;
        for(auto u : aux)
            if(u == 0)
                sum --;
            else
                sum++;
        if(sum <= 0)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
    return 0;
}