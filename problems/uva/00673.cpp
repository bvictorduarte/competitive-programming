#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string str;
    getline(cin,str);
    while(n--){
        bool is_ok=true;
        stack<char> s;
        getline(cin,str);
        for(auto u:str)
            if(u=='('||u=='[')
                s.push(u);
            else if(s.empty()||(u==')'&&s.top()!='(')||(u==']'&&s.top()!='['))
                is_ok=false;
            else
                s.pop();
        if(is_ok&&s.empty())
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
}