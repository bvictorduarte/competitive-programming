#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i,c;
    string p;
    stack<char> l;
    cin>>n;
    fflush(stdin);
    while(n--){
        getline(cin,p);
        for(i=0;i<(int)p.size();i++){
            if(p[i]=='{'||p[i]=='}')l.push(p[i]);
        }
    }
    c=0;
    while(!l.empty()){
        if(l.top()=='{')c++;
        if(l.top()=='}')c--;
        l.pop();
    }
    if(c==0)printf("S");
    else printf("N");
    return 0;
}
