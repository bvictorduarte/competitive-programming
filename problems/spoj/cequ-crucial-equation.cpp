#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b){
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
}
int main(){
    int t,i=1;
    cin>>t;
    while(i++<=t){
        ll a,b,c;
        cin>>a>>b>>c;
        cout<<"Case "<<i-1<<": ";
        if(c%gcd(a,b)==0)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
}