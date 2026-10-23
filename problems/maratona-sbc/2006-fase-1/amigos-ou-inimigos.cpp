#include<bits/stdc++.h>
using namespace std;
const int maxn = 65540;
int val[maxn];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    for(int rep = 1; rep <= N; rep++){
        int a, b, k;
        cin >> a >> b;
        int cont = 0;
        int y = 0, x = 0;
        int dx = -1, dy = 1, delta = 1;
        if(b != 0){
            val[0] = -b;
            cont++;
        }
        while(1){
            for(int i = 1; i <= delta; i++){
                x += dx;
                if(y == a * x + b)continue;
                val[cont] = y - a * x - b;
                cont ++;
                if(cont > maxn)break;
            }
            if(cont > maxn)break;
            for(int i = 1; i <= delta; i++){
                y += dy;
                if(y == a * x + b)continue;
                val[cont] = y - a * x - b;
                cont ++;
                if(cont > maxn)break;
            }
            if(cont > maxn)break;
            dx *= -1;
            dy *= -1;
            delta++;
        }
        cin >> k;
        cout << "Caso " << rep << '\n';
        while(k--){
            int m, n;
            cin>> m >> n;
            if(val[m] * val[n] < 0)
                cout << "Lados opostos da fronteira\n";
            else
                cout << "Mesmo lado da fronteira\n"; 
        }
    }
    return 0;
}