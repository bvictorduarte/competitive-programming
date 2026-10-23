#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LINF=0x3f3f3f3f3f3f3f3fLL;
int main(){
    ll a,b,c,d,mink1=LINF;
    cin>>a>>b>>c>>d;
    if(c%a!=0){
        cout<<-1<<endl;
        return 0;
    }
    ll n;
    for(ll k=1;k*k<=c/a;k++)
        if((c/a)%k==0){
            n=k*a;
            if(n%b==0||d%n==0)continue;
            mink1=min(mink1,k);
            n=((c/a)/k)*a;
            if(n%b==0||d%n==0)continue;
            mink1=min(mink1,k);
        }
    if(mink1==LINF)
        cout<<-1<<endl;
    else
        cout<<mink1*a<<endl;
    return 0;
}