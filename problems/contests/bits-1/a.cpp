#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        ll s=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            ll a;
            cin>>a;
            s+=a;
        }
        ll llsqrt=0,b;
        for(b=(ll)sqrt(LINF);b>=1;b/=2)
            while((llsqrt+b)*(llsqrt+b)<s)llsqrt+=b;
        llsqrt++;
        if(llsqrt*llsqrt==s)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}