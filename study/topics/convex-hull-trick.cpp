#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
vector<ll> pref,v;
ll n;
struct line{
    ll a,b,x_max;
    bool operator<(ll x) const{
        return x_max<x;
    }
};
deque<line> cht[5];
ll intersection(line x, line y){
    return (x.b-y.b)/(y.a-x.a);
}
void add_back(ll a,ll b,int op){
    if(!cht[op].empty()&&cht[op].back().a==a)cht[op].pop_back();
    while((int)cht[op].size()>=2){
        auto x=cht[op][cht[op].size()-2];
        auto y=cht[op][cht[op].size()-1];
        if(intersection(y,{a,b,0})<=intersection(x,y))
            cht[op].pop_back();
        else break;
    }
    if(!cht[op].empty())
        cht[op].back().x_max=intersection(cht[op].back(),{a,b,0});
    if(op==2)
        cht[2].push_back({a,b,LINF});
    else{
        if(cht[2].empty())
            cht[1].push_back({a,b,LINF});
        else
            cht[1].push_back({a,b,intersection(cht[2].front(),{a,b,0})});
    }
}
/*void add_front(ll a, ll b,int op){
    if(!cht[op].empty()&&cht[op].front().a==a)return;
    while((int)cht[op].size()>=2){
        auto x=cht[op][0];
        auto y=cht[op][1];
        if(intersection(y,{a,b,0})>intersection(x,y))
            cht[op].pop_front();
        else break;
    }
    cht[op].push_front({a,b,LINF});
    if((int)cht[op].size()>1)
        cht[op][0].x_max=intersection(cht[op][0],cht[op][1]);
}*/
ll query(ll i){
    int j1=lower_bound(cht[1].begin(),cht[1].end(),v[i])-cht[1].begin(),j2=lower_bound(cht[2].begin(),cht[2].end(),v[i])-cht[2].begin();
    if(i==1)
        return cht[2][j2].a*v[i]+cht[2][j2].b-i*v[i]+pref[i];
    if(i==n)
        return cht[1][j1].a*v[i]+cht[1][j1].b-i*v[i]+pref[i-1];
    else{
        if(cht[1][(int)cht[1].size()-1].x_max<v[i])
            return cht[2][j2].a*v[i]+cht[2][j2].b-i*v[i]+pref[i];
        else
            return cht[1][j1].a*v[i]+cht[1][j1].b-i*v[i]+pref[i-1];
    }
    return max(cht[1][j1].a*v[i]+cht[1][j1].b-i*v[i]+pref[i-1],cht[2][j2].a*v[i]+cht[2][j2].b-i*v[i]+pref[i]);
}
void ini_cht(ll n){
    for(int j=2;j<=n;j++)
        add_back(j,-pref[j],2);
}
int main(){
    pref.push_back(0);
    v.push_back(0);
    ll s=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        ll a;
        cin>>a;
        s+=a*i;
        v.push_back(a);
        pref.push_back(pref[i-1]+a);
    }
    ll delta=0;
    ini_cht(n);
    for(int i=1;i<=n;i++){
        if(i!=1){
            if(cht[2].front().a==i)cht[2].pop_front();
            add_back(i-1,-pref[i-2],1);
        }
        delta=max(delta,query(i));
    }
    cout<<s+delta<<endl;
    return 0;
}