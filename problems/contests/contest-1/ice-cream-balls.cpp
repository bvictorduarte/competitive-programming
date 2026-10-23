#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long double n;
        cin>>n;
        long long m=((long long)sqrt(1+8*n))/2;
        if((m+1)*(m+1)-(m+1)<=2*(long long)n)
            m++;
        cout<<m+(long long)n-(m*(m-1))/2<<endl;
    }
    return 0;
}