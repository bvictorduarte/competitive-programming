#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--){
        ll n,s=0,m=0,r=0,k;
        cin>>n>>k;
        vector<ll> a,b;
        for(int i=0;i<n;i++){
            ll p;
            cin>>p;
            a.push_back(p);
        }
        for(int i=0;i<n;i++){
            ll p;
            cin>>p;
            b.push_back(p);
        }
        for(int i=0;i<min(k,n);i++){
            s+=a[i];
            m=max(m,b[i]);
            r=max(r,s+m*(k-i-1));
        }
        cout<<r<<endl;
    }



    return 0;
}