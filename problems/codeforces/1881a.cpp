#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,m,cont=0;
    bool yes=false;
    cin>>n>>m;
    string x,s;
    cin>>x>>s;
    string comp=x;
    while(int(comp.size())<int(s.size())&&!yes){
        comp+=comp;
        cont++;
    }
    for(int j=0;j<=int(comp.size())-int(s.size())&&!yes;j++){
        yes=true;
        int p=0;
        for(int i=j;i<j+int(s.size());i++){
            if(comp[i]!=s[p]){
                yes=false;
                break;
            }
            p++;
        }
    }
    if(!yes){
        comp+=comp;
        cont++;
        for(int j=0;j<=int(comp.size())-int(s.size())&&!yes;j++){
            yes=true;
            int p=0;
            for(int i=j;i<j+int(s.size());i++){
              if(comp[i]!=s[p]){
                  yes=false;
                   break;
               }
               p++;
            }
        }
    }
    if(yes)
        cout<<cont<<endl;
    else
        cout<<-1<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}