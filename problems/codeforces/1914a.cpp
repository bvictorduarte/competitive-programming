#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int v[30]={0},n,ans=0;
        string s;
        cin>>n>>s;
        for(auto u:s)
            v[u-'A'+1]++;
        for(int i=1;i<=26;i++)
            if(v[i]>=i)
                ans++;
        cout<<ans<<endl;        
    }
    return 0;
}