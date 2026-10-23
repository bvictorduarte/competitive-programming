#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin >> n){
        if(n < 0)
            cout << "NO\n";
        else if(n != 0){
            bool tem = false;
            for(int i = 0; i * i <= n; i++){
                int a = n - i * i;
                int k = 0;
                for(int b = (101 / 2); b >= 1; b /= 2)
                    while((k + b) <= 101 && (k + b) * (k + b) < a) k += b;
                k++;
                if(k * k == a){
                    cout << "YES\n";
                    tem = true;
                    break;
                }
            }
            if(!tem)
                cout << "NO\n";
        }else
            cout << "YES\n";
    }
}