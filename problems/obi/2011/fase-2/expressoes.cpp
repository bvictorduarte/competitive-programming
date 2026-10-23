#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,i,j,v;
    stack<char> p;
    string l;
    cin>>t;
    j=t;
    while(j--){
        cin>>l;
        v=1;
        for(i=0;i<(int)l.size();i++){
            if(l[i]=='{'||l[i]=='['||l[i]=='(')p.push(l[i]);
            else{
                if(p.empty()||(p.top()=='{'&&l[i]!='}')||(p.top()=='('&&l[i]!=')')||(p.top()=='['&&l[i]!=']')){
                    v=0;
                    break;
                }
                p.pop();
            }
        }
        printf((v&&p.empty()) ? "S\n" : "N\n");
        while(!p.empty())p.pop();
    }
    return 0;
}
