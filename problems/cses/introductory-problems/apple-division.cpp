#include <bits/stdc++.h>
using namespace std;
vector<long long> v,aux;
long long n,sum=0,m;
long long modulo(long long x){
    if(x>=0)
        return x;
    else return -x;
}
void subset_sum(long long k){
    if(k==n){
        long long cont=0,i=0;
        while(i<(int)aux.size()){
            cont+=aux[i];
            i++;
        }
        m=(long long)min(modulo(sum-2*cont),m);
    }else{
        aux.push_back(v[k]);
        subset_sum(k+1);
        aux.pop_back();
        subset_sum(k+1);
    }
}
int main(){
    cin>>n;
    for(long long i=0;i<n;i++){
        long long k;
        cin>>k;
        v.push_back(k);
        sum+=k;
    }
    m=sum;
    subset_sum(0);
    cout<<m<<endl;
    return 0;
}