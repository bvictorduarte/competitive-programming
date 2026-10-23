#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    cout<<n;
    while(n!=1){
        cout<<" ";
        if(n%2==0)n=n/2;
        else n=n*3+1;
        cout<<n;
    }
    cout<<"\n";
    return 0;
}
