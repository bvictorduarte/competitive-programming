#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    while(getline(cin,s)){
        deque<string> ans;
        int tam=(int)s.size();
        bool active_home=false;
        string home;
        for(int i=0;i<tam;i++){
            if(active_home){
                if(s[i]=='['){
                    if(!home.empty())
                        ans.push_front(home);
                    home.clear();
                }else if(s[i]==']'){
                    if(!home.empty())
                        ans.push_front(home);
                    home.clear();
                    active_home=false;
                }else{
                    home.push_back(s[i]);
                    if(i==tam-1)
                        ans.push_front(home);
                }
            }else if(s[i]!=']'){
                if(s[i]=='[')
                    active_home=true;
                else{
                    string aux;
                    aux.push_back(s[i]);
                    ans.push_back(aux);
                }
            }
        }
        while(!ans.empty()){
            cout<<ans.front();
            ans.pop_front();
        }
        cout<<endl;
    }
    return 0;
}