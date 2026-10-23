#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        vector<int> v;
        int n,k,ans=-1;
        cin>>n>>k;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            v.push_back(a);
        }
        sort(v.begin(),v.end());
        int r,l;
        r=l=0;
        while(r<n-1){
            while(r<n-1&&v[r+1]-v[r]<=k)r++;
            ans=max(ans,r-l+1);
            l=++r;
        }
        if(ans!=-1)
            cout<<n-ans<<endl;
        else
            cout<<0<<endl;
    }
    return 0;
}