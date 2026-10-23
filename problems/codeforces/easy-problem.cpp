#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int cont = 0;
        for(int i = 1; i <= n - 1; i++)
            for(int j = 1; j <= n - 1; j++)
                if(i + j == n)
                    cont++;
        cout << cont << endl;
    }
    return 0;
}