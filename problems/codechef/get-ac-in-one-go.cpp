#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b;
ll gcd(ll a,ll b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int main(){
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>a>>b;
        if(gcd(a,b)==1)
            cout<<a*b-a-b+1<<'\n';
        else
            cout<<-1<<'\n';
    }
    return 0;
}