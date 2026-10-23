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
        bool yes=true;
        for(int i=1;i<=n;i++)
            cin>>v[i];
        for(int i=1;i<=n-2;i++){
            v[i+1]-=2*v[i];
            v[i+2]-=v[i];
            v[i]=0;
            if(v[i+1]<0||v[i+2]<0){
                cout<<"NO\n";
                yes=false;
                break;
            }
        }
        v[1]=0;
        if(v[n-1]==0&&v[n]==0&&yes)
            cout<<"YES\n";
        else if((v[n-1]!=0||v[n]!=0)&&yes)
            cout<<"NO\n";
    }
    return 0;
}