#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,p=2,e,d=1;
    cin>>n;
    while(n!=1){
        e=0;
        while((n%p)==0){
            e++;
            n=n/p;
        }
        d=d*(e+1);
        p++;
    }
    cout<<d<<"\n";
    return 0;
}
