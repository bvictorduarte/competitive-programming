#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
/*int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long ans=1;
        for(int i=2;i*i<=n;i++){
            long long cont=1;
            while(n%i==0){
                cont++;
                n/=i;
            }
            ans*=cont;
        }
        if(n!=1)
            ans*=2;
        cout<<ans<<endl;
    }
    return 0;
}*/
int first_prime[maxn],cont[maxn];
void sieve_of_eratosthenes(){
    for(int x=2;x<=maxn;x++){
        if(first_prime[x])continue;
        for(int i=x;i<=maxn;i+=x)
            first_prime[i]=x;
    }
}
int main(){
    int n;
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    cin>>n;
    sieve_of_eratosthenes();
    while(n--){
        int x;
        cin>>x;
        set<int> s;
        while(x!=1){
            s.insert(first_prime[x]);
            cont[first_prime[x]]++;
            x=x/first_prime[x];
        }
        long long ans=1;
        for(auto u:s){
            ans*=(long long)(cont[u]+1);
            cont[u]=0;
        }
        s.clear();
        cout<<ans<<endl;
    }
    return 0;
}