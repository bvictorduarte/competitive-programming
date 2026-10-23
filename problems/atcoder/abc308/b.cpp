#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    vector<string> c,d;
    map<string,int> mp;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string input;
        cin>>input;
        c.push_back(input);
    }
    d.push_back("aaaa");
    for(int i=1;i<=m;i++){
        string input;
        cin>>input;
        d.push_back(input);
    }
    int p0;
    cin>>p0;
    for(int i=1;i<=m;i++){
        int a;
        cin>>a;
        mp[d[i]]=a;
    }
    int ans=0;
    for(auto s:c){
        bool found=false;
        for(int i=1;i<=m;i++){
            string k=d[i];
            if(s==k){
                ans+=mp[s];
                found=true;
                break;
            }
        }
        if(!found)
            ans+=p0;
    }
    cout<<ans<<endl;
    return 0;
}