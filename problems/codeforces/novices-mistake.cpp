#include<bits/stdc++.h>
using namespace std;
int alg(int n){
    int j = 1;
    while(n / 10 > 0){
        n /= 10;
        j++;
    }
    return j;
}
string transf(int n){
    if(n == 0)
        return "0";
    stack<char> s;
    while(n > 0){
        s.push(n % 10);
        n /= 10;
    }
    string ans = "";
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

bool verify(int n, int tam, int nab){
    string sn = transf(n);
    string num = "";
    for(int i = 1; i <= tam / alg(n); i++)
        num += sn;
    for(int i = 0; i < tam % alg(n); i++)
        num += sn[i];
    return num == transf(nab);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, cont = 0;
        cin >> n;
        int alg_n = alg(n);
        for(int b = 1; b <= 10000; b++)
            for(int i = 1; i <= 5; i++)
                if((i + b) % alg_n == 0){
                    int a = (i + b) / alg_n;
                    if(a * n == b || alg(n * a - b) != i || a > 10000)
                        continue;
                    if(verify(n, alg(n * a - b), n * a - b))
                        cont++;
                }
        cout << cont << endl;
        for(int b = 1; b <= 10000; b++)
            for(int i = 1; i <= 5; i++)
                if((i + b) % alg_n == 0){
                    int a = (i + b) / alg_n;
                    if(a * n == b || alg(n * a - b) != i || a > 10000)
                        continue;
                    if(verify(n, alg(n * a - b), n * a - b))
                        cout << a << ' ' << b << endl;
                }
    }
}