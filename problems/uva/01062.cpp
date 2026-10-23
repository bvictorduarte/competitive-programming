#include<bits/stdc++.h>
using namespace std;
void solve(string s){
    stack<char> stk[30];
    int i=1;
    for(int u=0;u<(int)s.size();u++){
        int m=100,km;
        for(int k=1;k<=i;k++){
            if(u==0)
                stk[1].push(s[u]);
            else if(m>(int)(stk[k].top()-s[u])&&(int)(stk[k].top()-s[u])>=0){
                    m=(int)(stk[k].top()-s[u]);
                    km=k;
            }
        }
        if(m==100&&u!=0)
            stk[++i].push(s[u]);
        else if(m!=100)
            stk[km].push(s[u]);
    }
    cout<<i<<endl;
}
int main(){
    string s;
    int i=1;
    while(cin>>s&&s!="end"){
        cout<<"Case "<<i++<<": ";
        solve(s);
    }
    return 0;
}