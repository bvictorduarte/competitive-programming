#include<bits/stdc++.h>
using namespace std;
int main(){
    stack<string> s;
    int n;
    cin>>n;
    while(n--){
        string op;
        cin>>op;
        if(op=="Sleep"){
            string name;
            cin>>name;
            s.push(name);
        }else if(op=="Test")
            if(!s.empty())
                cout<<s.top()<<endl;
            else
                cout<<"Not in a dream\n";
        else
            if(!s.empty())
                s.pop();
    }
}