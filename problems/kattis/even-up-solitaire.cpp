#include<bits/stdc++.h>
using namespace std;
int main(){
    stack<int> q1,q2;
    int n,k,ans;
    cin>>n;
    ans=n;
    while(n--){
        cin>>k;
        q1.push(k);
    }
    while(!q1.empty()){
        if(q2.empty()){
            q2.push(q1.top());
            q1.pop();
        }else{
            if((q1.top()+q2.top())%2==0){
                q1.pop();
                q2.pop();
                ans-=2;
            }else{
                q2.push(q1.top());
                q1.pop();
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}