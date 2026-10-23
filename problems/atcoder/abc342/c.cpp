#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    map<char,char> mp;
    for(int i=0;i<26;i++)
        mp[(char)('a'+i)]=(char)('a'+i);
    string s;
    cin>>s;
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        string c,d;
        cin>>c>>d;
        for(int k=0;k<26;k++)
            if(mp[(char)('a'+k)]==c[0])
                mp[(char)('a'+k)]=d[0];
    }
    for(int i=0;i<n;i++)
        s[i]=mp[s[i]];
    cout<<s<<endl;
}