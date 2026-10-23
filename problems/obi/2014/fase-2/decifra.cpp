#include <bits/stdc++.h>
using namespace std;
int main(){
    string alf, p;
    map<char,char> mp;
    cin>>alf;
    for(int i=0;i<26;i++)
        mp[alf[i]]='a'+i;
    cin>>p;
    for(int i=0;i<(int)p.size();i++)
        p[i]=mp[p[i]];
    cout<<p<<endl;
    return 0;
}