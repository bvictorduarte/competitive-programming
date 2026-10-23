#include<bits/stdc++.h>
using namespace std;
map<char, long long> mp;
int main(){
    string s;
    cin>>s;
    for(auto u:s)
        mp[u]++;
    long long ans=0;
    for(int i=0;i<26;i++)
        if(mp[(char)('a'+i)]>=2){
            ans=1;
        }
    for(int i=0;i<25;i++){
        for(int j=i+1;j<26;j++)
            ans+=mp[(char)('a'+i)]*mp[(char)('a'+j)];
    }
    cout<<ans<<endl;
    return 0;
}