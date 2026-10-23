#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+50;
vector<int> primes;
bool is_prime(int a){
    int cont=0;
    for(int i=2;i<=a;i++)
        if(a%i==0)cont++;
    if(cont==1)return true;
    return false;
}
void pre_compute(){
    for(int i=2;i*i<maxn;i++)
        if(is_prime(i))primes.push_back(i);
}
int fact(int a){
    if(!a)return 0;
    int ans=1;
    for(auto prime:primes){
        int ver=0;
        while(a%prime==0){
            a/=prime;
            if(!ver)ver=1;
            else ver=0;
        }
        if(ver)ans*=prime;
    }
    ans*=a;
    return ans;
}
int v[maxn];
int main(){
    pre_compute();
    long long n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        v[i]=fact(v[i]);
    }
    sort(v+1,v+n+1);
    long long k=-1,cont=1,ans=0;
    long long j=1;
    while(j<=n&&v[j]==0)
        j++;
    --j;
    ans+=j*(n-j)+(j*(j-1))/2;
    for(int i=j;i<=n;i++){
        if(k!=v[i]){
            ans+=(cont*(cont-1))/2;
            cont=1;
            k=v[i];
        }
        else
            cont++;
    }
    if(cont!=1)
        ans+=(cont*(cont-1))/2;
    cout<<ans<<endl;
    return 0;
}