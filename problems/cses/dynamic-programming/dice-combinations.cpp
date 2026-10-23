#include <bits/stdc++.h>
using namespace std;
long long v[1000050];
const int m=1e9+7;
int main(){
    long long n;
    cin>>n;
    v[0]=1;
    for(long long i=1;i<=n;i++)
        for(long long k=1;k<=6;k++){
            if(i-k>=0){
                v[i]+=v[i-k];
                v[i]=v[i]%m;
            }
        }
    cout<<v[n]<<endl;
    return 0;
}