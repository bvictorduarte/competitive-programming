#include<bits/stdc++.h>
using namespace std;
int main(){
    string l;
    int t;
    getline(cin,l);
    t=stoi(l);
    /*  Por que não funciona desse jeito:
        cin>>t;
        Ao inves de:
        getline(cin,l);
        t=stoi(l);
    */
    getline(cin,l);
    while(t--){
        stack<string> s;
        string ans;
        while(getline(cin,l)&&l!=""){
            if(l[0]<='9'&&l[0]>='0')
                ans.push_back(l[0]);
            else if(l=="*"||l=="/"){
                while(!s.empty()&&(s.top()=="*"||s.top()=="/")){
                    ans.push_back(s.top()[0]);
                    s.pop();
                }
                s.push(l);
            }else if(l=="+"||l=="-"){
                while(!s.empty()&&s.top()!="("){
                    ans.push_back(s.top()[0]);
                    s.pop();
                }
                s.push(l);
            }else if(l=="(")
                s.push(l);
            else{
                while(s.top()!="("){
                    ans.push_back(s.top()[0]);
                    s.pop();
                }
                s.pop();
            }
        }
        while(!s.empty()){
            ans.push_back(s.top()[0]);
            s.pop();
        }
        cout<<ans<<endl;
        if(t)
            cout<<endl;
    }
    return 0;
}