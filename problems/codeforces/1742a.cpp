#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    int t;
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        int d=max(a,b);
        d=max(d,c);
        if(2*d==a+b+c)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }   
    return 0;
}