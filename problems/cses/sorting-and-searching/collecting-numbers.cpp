#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
int main(){
    int n,ans;
    cin>>n;
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        mp[k]=i;
    }
    ans=1;
    for(int i=1;i<=n-1;i++)
        if(mp[i]>mp[i+1])
            ans++;
    cout<<ans<<endl;
    return 0;
}