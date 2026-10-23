#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+50;
int v[maxn];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>v[i];
        int fs=0, fp=0;
        for(int i=1;i<=n;i++)
            if(v[1]==v[i])fp++;
            else break;
        for(int i=n;i>=1;i--)
            if(v[n]==v[i])fs++;
            else break;
        if(v[n]==v[1]&&fs!=n)
            cout<<n-fs-fp<<endl;
        else if(v[n]==v[1])
            cout<<0<<endl;
        else
            cout<<n-max(fs,fp)<<endl;
    }


    return 0;
}