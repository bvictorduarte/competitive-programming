#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=1000000000000000050;
ll exp(ll a, ll b){
    ll ans=1;
    for(ll i=1;i<=b;i++)
        ans*=a;
    return ans;
}
int main(){
    ll n;
    cin>>n;
    vector<ll> cubes_palindromes;
    for(ll i=1;i*i*i<=maxn;i++){
        ll a=i*i*i,b=0;
        ll aux=a,cont=-1;
        while(aux>0){
            aux/=10;
            cont++;
        }
        aux=a;
        while(cont>=0){
            b+=(aux%10)*exp(10,cont);
            aux/=10;
            cont--;
        }
        if(a==b)
            cubes_palindromes.push_back(a);
    }
    if(n==1){
        cout<<1<<endl;
        return 0;
    }else if(n>=cubes_palindromes[(int)cubes_palindromes.size()-1]){
        cout<<cubes_palindromes[(int)cubes_palindromes.size()-1]<<endl;
        return 0;
    }
    for(int i=1;i<(int)cubes_palindromes.size();i++)
        if(cubes_palindromes[i]>n){
            cout<<cubes_palindromes[i-1]<<endl;
            return 0;
        }
}