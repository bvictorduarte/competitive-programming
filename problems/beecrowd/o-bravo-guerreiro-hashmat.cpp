#include<bits/stdc++.h>
using namespace std;
long long mod(long long a){
    if(a<0)return -a;
    return a;
}
int main(){
    long long n,m;
    while(cin>>n>>m)
        cout<<mod(n-m)<<endl;
    return 0;
}