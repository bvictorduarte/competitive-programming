#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    cin>>n;
    if(n%10==0||n<0)
        cout<<n/10;
    else if(n>0)
        cout<<n/10+1<<endl;
    return 0;
}