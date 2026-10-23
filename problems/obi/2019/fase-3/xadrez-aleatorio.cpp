#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,t;
    cin>>n>>t;
    if(t==0)
        cout<<n<<endl;
    else if(t==1)
        cout<<n*(n-1)<<endl;
    else{
        ll ans=0;
        for(int i=3;i<=n;i++)
            ans+=(n-i+1)*(i-2);
        cout<<ans<<endl;
    }
    return 0;
}