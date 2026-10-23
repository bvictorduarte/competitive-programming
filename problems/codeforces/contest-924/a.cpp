#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,t;
    cin>>t;
    while(t--){
        bool veredict=false;
        cin>>a>>b;
        if(a%2==0){
            int a1=a/2;
            if(!(2*b==a&&a1==b))
                veredict=true;
        }
        if(b%2==0){
            int b1=b/2;
            if(!(2*a==b&&b1==a))
                veredict=true;
        }
        if(veredict)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}