#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
long long r[200050],l[200050],d[200050];
vector<ll> v;
int main(){
    ll n,k,sum=0;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>k;
        v.push_back(k);
    }
    sort(v.begin(),v.end());
    for(ll i=0;i<n-1;i++)
        d[i]=v[i+1]-v[i];
    ll i,best;
    l[0]=0;
    r[n-1]=0;
    sum=0;
    for(i=1;i<n;i++){
        sum+=i*d[i-1];
        l[i]=sum;
    }
    sum=0;
    for(i=n-2;i>=0;i--){
        sum+=(n-i-1)*d[i];
        r[i]=sum;
    }
    best=r[0]+l[0];
    for(i=0;i<n;i++)
        best=min(best,r[i]+l[i]);
    cout<<best<<endl;
    return 0;
}
