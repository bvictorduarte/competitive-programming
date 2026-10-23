#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string inp;
        cin>>inp;
        stack<char> s;
        int cont=0;
        for(auto u:inp)
            if(!s.empty()&&s.top()=='<'&&u=='>'){
                cont++;
                s.pop();
            }else if(u=='<')
                s.push('<');
        cout<<cont<<endl;
    }
}