#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll find_solve(ll a,ll b,ll& y,ll& x){
    if(!b){
        y=1;
        x=0;
        return a;
    }
    ll x1,y1,g;
    g=find_solve(b,a%b,y1,x1);
    y=x1;
    x=y1-x1*(a/b);
    return g;
}
int main(){
    ll a,b,g,x,y;
    cin>>a>>b;
    g=find_solve(-a,b,y,x);
    if(!(2%g==0))
        cout<<-1<<endl;
    else
        cout<<(2/g)*x<<" "<<(2/g)*y<<endl;
    return 0;
}