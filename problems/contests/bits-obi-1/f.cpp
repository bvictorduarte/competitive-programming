#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=3e5+50;
const ll m=1e6+7;
ll f[maxn],pref_f[maxn];
int main(){
    int t;
    cin>>t;
    while(t--){
        ll k,n;
        cin>>k>>n;
        for(ll i=1;i<k;i++){
            f[i]=i;
            pref_f[i]=pref_f[i-1]+i;
            pref_f[i]%=m;
            f[i]%=m;
        }
        f[k]=(pref_f[k-1]%m);
        pref_f[k]=(pref_f[k-1]+f[k])%m;
        f[k+1]=pref_f[k]%m;
        pref_f[k+1]=(pref_f[k]+f[k+1])%m;
        for(ll i=k+2;i<=n;i++){
            f[i]=(pref_f[i-1]-pref_f[i-1-k])%m; 
            f[i]=(f[i]+m)%m;
            pref_f[i]=(pref_f[i-1]+f[i])%m;
        }
        cout<<f[n-1]<<endl;
    }
}