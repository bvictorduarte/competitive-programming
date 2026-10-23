#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int v[3];
        for(int i=0;i<3;i++)
            cin>>v[i];
        sort(v,v+3);
        if(v[2]+v[1]>=10)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}