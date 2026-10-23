#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    if(s[0]=='<'&&s[(int)s.size()-1]=='>'){
        for(int i=1;i<=(int)s.size()-2;i++)
            if(s[i]!='='){
                cout<<"No\n";
                return 0;
            }
        cout<<"Yes\n";
    }
    else
        cout<<"No\n";
    return 0;

}