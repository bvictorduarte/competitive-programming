#include <bits/stdc++.h>
using namespace std;
int m[55][55],l[55],c[55];
int main(){
    int n,s,le,ce;
    cin>>n;
    for(int i=0;i<n;i++)
        for(int k=0;k<n;k++)
            cin>>m[i][k];
    for(int i=0;i<n;i++){
        for(int k=0;k<n;k++){
            l[i]+=m[i][k];
            c[i]+=m[k][i];
        }
    }
    s=l[0];
    if(l[0]!=l[1]&&l[1]==l[2])
        s=l[1];
    for(int i=0;i<n;i++)
        if(l[i]!=s)
            le=i;
    for(int i=0;i<n;i++)
        if(c[i]!=s)
            ce=i;
    cout<<s-c[ce]+m[le][ce]<<" "<<m[le][ce];
    return 0;
}