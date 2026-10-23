#include<bits/stdc++.h>
using namespace std;
int mdc(long long a ,long long b){
    if(a==b)return a;
    if(a>b)
        return mdc(b,a-b);
    else
        return mdc(a,b-a);
}
int main(){
    long long n,m,i;
    cin>>n>>m;
    for(i=m;i>=1;i--)
        if(mdc(i,n)==1)break;
    cout<<i;
    return 0;
}
