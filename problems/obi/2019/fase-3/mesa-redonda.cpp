#include<bits/stdc++.h>
using namespace std;
int v[4];
int main(){
    int a,b;
    cin>>a>>b;
    v[a%3]=1;
    if(v[b%3])
        v[(b%3+1)%3]=1;
    else
        v[b%3]=1;
    for(int i=0;i<3;i++)
        if(v[i]==0)
            cout<<i<<endl;
    return 0;
}