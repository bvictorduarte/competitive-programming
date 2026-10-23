#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d,t;
    cin>>t;
    while(t--){
        cin>>a>>b>>c>>d;
        if(a>b)swap(a,b);
        if(c>d)swap(c,d);
        if((a<c&&b>c&&d>b)||(b>d&&d>a&&a>c))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}