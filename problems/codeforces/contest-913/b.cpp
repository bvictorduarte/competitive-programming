#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        vector<pair<int,char>> uc,lc;
        cin>>s;
        for(int i=0;i<(int)s.size();i++){
            if(s[i]>='a'&&s[i]<='z'){
                if(s[i]!='b')
                    lc.push_back({i,s[i]});
                else if(!lc.empty())
                    lc.pop_back();
            }else{
                if(s[i]!='B')
                    uc.push_back({i,s[i]});
                else if(!uc.empty())
                    uc.pop_back();
            }
        }
        int tam=(int)lc.size();
        tam--;
        while(tam>=0){
            uc.push_back(lc[tam]);
            tam--;
        }
        sort(uc.begin(),uc.end());
        for(auto u:uc){
            char a=u.second;
            cout<<a;
        }
        cout<<endl;
    }
}