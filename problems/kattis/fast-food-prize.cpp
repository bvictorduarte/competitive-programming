#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int s[35],p[10][35],k[35];
        memset(s,0,sizeof(s));
        int n,m,k;
        cin>>n>>m;
        for(int u=0;u<n;u++){
            cin>>k[u];
            for(int y=0;y<=k[u];y++)
                cin>>p[u][y];
        }
        for(int u=1;u<=m;u++){
            cin>>s[u];
        }
        for(int)
    }
    return 0;
}