#include <bits/stdc++.h>
using namespace std;
int main(){
    int d, a, n, t;
    cin >> d >> a >> n;
    if(n >= 15)
        t = (31 - n + 1) * (d + 14 * a);
    else
        t = (31 - n + 1) * (d + (n - 1) * a);
    cout << t << endl;
    return 0;
}
