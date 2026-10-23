#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    if(s[0]!=s[1]&&s[1]==s[2])
        cout<<"1\n";
    else{
        for(int i=0;i<(int)s.size();i++)
            if(s[i]!=s[0]){
                cout<<i+1;
                break;
            }
    }
    return 0;
}