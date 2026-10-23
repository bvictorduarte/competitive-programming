#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool comp(pair<int,pair<ll,ll>> p1,pair<int,pair<ll,ll>> p2){
    ll n1,n2,d1,d2;
    n1=p1.second.first;d1=p1.second.second;
    n2=p2.second.first;d2=p2.second.second;
    if(n1*d2!=n2*d1)
        return n1*d2<n2*d1;
    return p1.first>p2.first;
}
int main(){
    int n;
    cin>>n;
    vector<pair<int,pair<ll,ll>>> v;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({i+1,{a,a+b}});
    }
    sort(v.rbegin(),v.rend(),comp);
    cout<<v[0].first;
    for(int i=1;i<(int)v.size();i++)
        cout<<" "<<v[i].first;
    cout<<endl;
    return 0;
}