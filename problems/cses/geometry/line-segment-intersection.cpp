#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef complex<ll> P;
#define Y imag()
#define X real()
ll cp(P a, P b){
    return (conj(a)*b).Y;
}
ll mod(ll a){
    if(a>=0)
        return a;
    return -a;
}
bool sinais_opostos(ll a, ll b){
    if((a<0&&b>0)||(a>0&&b<0))
        return true;
    return false;
}
bool overlap(P p[]){
    if(cp(p[2]-p[1],p[2]-p[0])==0&&cp(p[3]-p[1],p[3]-p[0])==0){
        ll x1=mod(p[0].X),x2=mod(p[1].X),x3=mod(p[2].X),x4=mod(p[3].X);
        if(x1>x2)
            swap(x1,x2);
        if(x3>x4)
            swap(x3,x4);
        if((x1<x3&&mod(x1-x3)<mod(x1-x2)&&mod(x1-x2)>mod(x2-x3))||(x3<x1&&mod(x3-x1)<mod(x3-x4)&&mod(x1-x4)<mod(x3-x4)))
            return true;
    }
    return false;
}
bool common_vertex(P p[]){
    if(p[0]==p[2]||p[0]==p[3]||p[1]==p[2]||p[1]==p[3])
        return true;
    return false;
}
bool common_point(P p[]){
    if(sinais_opostos(cp(p[2]-p[0],p[2]-p[1]),cp(p[3]-p[0],p[3]-p[1]))&&sinais_opostos(cp(p[0]-p[2],p[0]-p[3]),cp(p[1]-p[2],p[1]-p[3])))
        return true;
    else if((cp(p[2]-p[1],p[2]-p[0])==0&&(mod((p[2]-p[1]).X)+mod((p[2]-p[0]).X)==mod((p[0]-p[1]).X)&&mod((p[2]-p[0]).Y)+mod((p[2]-p[1]).Y)==mod((p[0]-p[1]).Y)))||
    (cp(p[3]-p[1],p[3]-p[0])==0&&(mod((p[3]-p[1]).X)+mod((p[3]-p[0]).X)==mod((p[0]-p[1]).X)&&mod((p[3]-p[1]).Y)+mod((p[3]-p[0]).Y)==mod((p[0]-p[1]).Y)))||
    (cp(p[0]-p[2],p[0]-p[3])==0&&(mod((p[0]-p[2]).X)+mod((p[0]-p[3]).X)==mod((p[2]-p[3]).X)&&mod((p[0]-p[2]).Y)+mod((p[0]-p[3]).Y)==mod((p[2]-p[3]).Y)))||
    (cp(p[1]-p[2],p[1]-p[3])==0&&(mod((p[1]-p[2]).X)+mod((p[1]-p[3]).X)==mod((p[2]-p[3]).X)&&mod((p[1]-p[2]).Y)+mod((p[1]-p[3]).Y)==mod((p[2]-p[3]).Y))))
        return true;
    return false;
}
int main(){
    P p[4];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        ll a, b;
        for(int k=0;k<4;k++){
            cin>>a>>b;
            p[k]={a,b};
        }
        cout<<cp(p[2]-p[1],p[2]-p[0])<<endl<<cp(p[3]-p[1],p[3]-p[0]);
        if(overlap(p)||common_point(p)||common_vertex(p))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
//Caso errado
//-2 -5 7 -5 -3 -5 -4 -5