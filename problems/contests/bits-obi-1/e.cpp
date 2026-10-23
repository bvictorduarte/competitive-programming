#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=1e4+50;
const ll LINF=0x3f3f3f3f3f3f3f3fLL;
ll v[maxn],c[maxn],tempo_termino[maxn];
int main(){
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>v[i];
        tempo_termino[i]=LINF;
    }
    for(ll i=1;i<=m;i++)
        cin>>c[i];
    ll t=0;
    for(ll i=1;i<=m;i++){
        for(ll j=1;j<=n;j++)
            if(tempo_termino[j]==LINF){
                tempo_termino[j]=t+v[j]*c[i];
                break;
            }
        ll t_min=LINF;
        for(int j=1;j<=n;j++){
            t_min=min(t_min,tempo_termino[j]);
            if(tempo_termino[j]==LINF){
                t_min=t;
                break;
            }
        }
        for(int j=1;j<=n;j++)
            if(tempo_termino[j]==t_min)
                tempo_termino[j]=LINF;
        t=t_min;
    }
    ll t_max=-1;
    for(int i=1;i<=n;i++){
        if(tempo_termino[i]==LINF)
            tempo_termino[i]=0;
        t_max=max(t_max,tempo_termino[i]);
    }
    if(t_max==0)
        cout<<t<<endl;
    else
        cout<<t_max<<endl;
    return 0;
}