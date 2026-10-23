#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k,q;
        cin>>n>>k>>q;
        vector<ll> a,b;
        a.push_back(0);
        for(ll i=1;i<=k;i++){
            ll aux;
            cin>>aux;
            a.push_back(aux);
        }
        b.push_back(0);
        for(ll i=1;i<=k;i++){
            ll aux;
            cin>>aux;
            b.push_back(aux);
        }
        for(ll i=1;i<=q;i++){
            ll d;
            cin>>d;
            ll posi=lower_bound(a.begin(),a.end(),d)-a.begin();
            if(posi==0)
                cout<<0<<' ';
            else{
                cout<<((b[posi]-b[posi-1])*(d-a[posi-1]))/(a[posi]-a[posi-1])+b[posi-1]<<' ';
            }
        }
        cout<<endl;
    }
}