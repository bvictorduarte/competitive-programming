#include <bits/stdc++.h>
using namespace std;
int main(){
    queue<int> l1;
    queue<int> l2;
    bool ok = true;
    int m, n, k;
    cin >> n >> m;
    for(int i = 1;i <= n; i++){
        cin >> k;
        l1.push(k);
    }
    for(int i = 1; i <= m; i++){
        cin >> k;
        l2.push(k);
    }
    while(!l1.empty() && !l2.empty()){
        while(l2.front() != l1.front() && !l1.empty())
            l1.pop();
        if(l1.front() == l2.front()){
            l1.pop();
            l2.pop();
        }
    }
    if(l2.empty())
        cout << "S\n";
    else
        cout << "N\n";
}
