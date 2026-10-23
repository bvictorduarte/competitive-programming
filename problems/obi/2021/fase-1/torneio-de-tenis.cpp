#include <bits/stdc++.h>
using namespace std;
int main(){
    string op;
    int cont = 0;
    for(int i = 0; i < 6; i++){
        cin >> op;
        if(op == "V")
            cont++;
    }
    if(cont >= 5)
        cout << "1\n";
    else if(cont >= 3)
        cout << "2\n";
    else if(cont >= 1)
        cout << "3\n";
    else
        cout << "-1\n";
    return 0;
}
