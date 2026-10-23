#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
vector<int> colors;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,c;
        cin>>a>>c;
        if(mp[c])
            mp[c]=min(mp[c],a);
        else
            mp[c]=a;
        colors.push_back(c);
    }
    int ans=-1;
    for(auto u:colors)
        ans=max(ans,mp[u]);
    cout<<ans<<endl;

    return 0;
}