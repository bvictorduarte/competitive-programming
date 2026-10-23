#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, sum = 0, x;
    stack<int> t;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(x == 0)
            t.pop();
        else
            t.push(x);
    }
    while(!t.empty()){
        sum += t.top();
        t.pop();
    }
    cout << sum << endl;
    return 0;
}
