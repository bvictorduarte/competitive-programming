#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool v[9];
pair<ll,ll> p[10];
ll d(pair<ll,ll> a,pair<ll,ll> b){
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}
ll dif(ll a,ll b){
    return a-b;
}
bool lin(pair<ll,ll> a,pair<ll,ll> b,pair<ll,ll> c){
    if(a.first*b.second+a.second*c.first+b.first*c.second-c.first*b.second-a.first*c.second-b.first*a.second==0)
        return true;
    else
        return false;
}
int main(){
    ll x,y;
    for(int i=1;i<=7;i++){
        cin>>x>>y;
        p[i]=make_pair(x,y);
    }
    if(d(p[2],p[3])<d(p[2],p[1])+d(p[3],p[1]))
        v[1]=true;
    if(d(p[1],p[2])==d(p[1],p[3]))
        v[2]=true;
    if(lin(p[2],p[3],p[4])&&lin(p[5],p[3],p[4]))
        v[3]==true;
    if(p[2].first+p[3].first==p[4].first+p[5].first&&p[2].second+p[3].second==p[4].second+p[5].second)
        v[4]==true;
    if(d(p[2],p[3])>d(p[4],p[5]))
        v[5]=true;
    if(d(p[2],p[6])==d(p[2],p[4])+d(p[4],p[6])&&d(p[3],p[7])==d(p[5],p[3])+d(p[5],p[7]))
        v[6]=true;
    if(d(p[4],p[6])==d(p[5],p[7]))
        v[7]=true;
    
    return 0;
}