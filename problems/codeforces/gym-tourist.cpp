#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=1e5+50;
const ll LINF=0x3f3f3f3f3f3f3f3fLL;
ll t[maxn],x[maxn],dp[maxn],aux[maxn];
pair<ll,ll> v[maxn];
void set_aux(ll fim){
    sort(v+1,v+fim+1);
    for(ll i=1;i<=fim;i++)
        aux[i]=v[i].second;
}
ll find_LIS(ll ini,ll fim, ll m){
    dp[0]=-LINF;
    ll maxl=0;
    for(int i=ini;i<=fim;i++){
        if(aux[i]<m)continue;
        ll pos=upper_bound(dp,dp+maxl,aux[i])-dp;
        if(dp[pos]>aux[i])
            dp[pos]=aux[i];
        else{
            dp[pos+1]=aux[i];
            maxl++;
        }
    }
    return maxl;
}
int main(){
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++)
        cin>>x[i]>>t[i];
    ll vel;
    cin>>vel;
    for(ll i=1;i<=n;i++)
        v[i]=make_pair(x[i]+vel*t[i],-x[i]+vel*t[i]);
    set_aux(n);
    ll resp2=find_LIS(1,n,-LINF);
    v[n+1]=make_pair(0,0);
    set_aux(n+1);
    ll i0=0;
    for(ll i=1;i<=n+1;i++)
        if(v[i]==make_pair(0ll,0ll)){
            i0=i;
        }
    cout<<find_LIS(i0,n+1,0)-1<<" "<<resp2<<endl;
    return 0;
}