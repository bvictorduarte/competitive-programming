#include<bits/stdc++.h>
using namespace std;
bool solve(int n){
    stack<int> stk;
    queue<int> q;
    int p=1;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        if(k==0&&i==0)
            return false;
        q.push(k);
    }
    while(p<=n){
        stk.push(p);
        while(!q.empty()&&!stk.empty()&&q.front()==stk.top()){
            q.pop();
            stk.pop();
        }
        p++;
    }
    if(stk.empty())
        cout<<"Yes\n";
    else
        cout<<"No\n";
    return true;
}
int main(){
    int n;
    cin>>n;
    if(n==0)return 0;
    while(solve(n));
    while(cin>>n&&n){
        cout<<endl;
        while(solve(n));
    }
    cout<<endl;
    return 0;
}