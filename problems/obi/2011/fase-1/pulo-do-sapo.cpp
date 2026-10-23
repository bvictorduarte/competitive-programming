#include<bits/stdc++.h>
using namespace std;
int pedras[150];
int main(){
    int n,m,p,d;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>p>>d;
        for(int i=p%d;i<=n;i+=d)
            pedras[i]=1;
    }
    for(int i=1;i<=n;i++)
        cout<<pedras[i]<<endl;
    return 0;
}
