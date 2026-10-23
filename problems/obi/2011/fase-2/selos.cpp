#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    double nf=sqrt((double)n);
    int lim=(int)nf+1;
    for(int i=2;i<=lim;i++){
        if(n%i==0){
            cout<<"S\n";
            return 0;
        }
    }
    cout<<"N\n";
    return 0;
}