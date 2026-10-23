#include<bits/stdc++.h>
using namespace std;
stack<int> s;
int main(){
    int n;
    while(cin>>n&&n)
        s.push(n);
    s.push(0);
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}