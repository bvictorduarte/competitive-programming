#include<bits/stdc++.h>
using namespace std;
const int maxn = 150;
int pi[150], pb[150];
int main(){
    int t;
    cin >> t;
    while(t--){
        int maxa = 1000000000;
        int d, o, b;
        cin >> d >> o >> b;
        for(int j = 0; j < o; j++)
            cin >> pi[j];
        for(int i = 1; i <= b; i++){
            int q;
            cin >> q;
            pb[i] = 0;
            for(int j = 1; j <= q; j++){
                int a, c;
                cin >> a >> c;
                pb[i] += pi[a] * c;
            }
            maxa = min(pb[i], maxa);
        }
        cout << d / maxa << endl;
    }
}