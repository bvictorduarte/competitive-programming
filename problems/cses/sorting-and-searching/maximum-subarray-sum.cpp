#include <bits/stdc++.h>
using namespace std;
long long vet[200050];
int main(){
    long long n,sum=0,best=0;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>vet[i];
    sum=vet[0];
    best=sum;
    for(int i=1;i<n;i++){
        sum=max(vet[i],sum+vet[i]);
        best=max(best,sum);
    }
    cout<<best<<endl;
    return 0;
}
