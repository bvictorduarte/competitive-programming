#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        vector<int> b,c;
        for(int i=0;i<n;i++){
            int p;
            cin>>p;
            b.push_back(p);
        }
        for(int i=0;i<m;i++){
            int p;
            cin>>p;
            c.push_back(p);
        }
        int ans=0;
        for(auto u:b)
            for(auto v:c)
                if(u+v<=k)
                    ans++;
        cout<<ans<<endl;
    }
    return 0;
}