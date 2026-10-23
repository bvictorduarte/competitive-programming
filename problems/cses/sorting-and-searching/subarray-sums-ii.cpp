#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,ll> freq;
int main(){
    int n;
    ll x,pref_sum=0,cont=0;
    cin>>n>>x;
    freq[0]=1;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        pref_sum+=a;
        cont+=freq[pref_sum-x];
        freq[pref_sum]++;
    }
    cout<<cont<<endl;
    return 0;
}