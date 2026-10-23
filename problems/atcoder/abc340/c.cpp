#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    cin>>n;
    ll ans=n,k=n,s=1;
    while(k!=3&&k!=2){
        ans+=n;
        k/=2;
        s*=2;
    }
    ans+=2*(n-2*s);
    cout<<ans<<endl;
    return 0;
}