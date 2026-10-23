#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+50;
int v[maxn];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,sum=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>v[i];
            sum+=v[i];
        }
        int f=sum/n;sum=0;
        bool yes=true;
        for(int i=1;i<=n;i++){
            sum+=v[n+1-i];
            if(sum>i*f)
                yes=false;
        }
        if(yes)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }


    return 0;
}