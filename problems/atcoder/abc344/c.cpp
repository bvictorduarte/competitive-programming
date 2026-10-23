#include<bits/stdc++.h>
using namespace std;
int a[105],b[105],c[105];
int mp[300000005];
int main(){
    int n,m,l;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    cin>>m;
    for(int i=1;i<=m;i++)
        cin>>b[i];
    cin>>l;
    for(int i=1;i<=l;i++)
        cin>>c[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            mp[a[i]+b[j]]=1;
    int q;
    cin>>q;
    for(int i=1;i<=q;i++){
        int x,achou=0;
        cin>>x;
        for(int j=1;j<=l;j++)
            if(x-c[j]>=0&&mp[x-c[j]]){
                cout<<"Yes\n";
                achou=1;
                break;
            }
        if(!achou)
            cout<<"No\n";
    }
    return 0;
}