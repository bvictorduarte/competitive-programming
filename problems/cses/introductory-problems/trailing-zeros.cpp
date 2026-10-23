#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,s=1,c=0;
    cin>>n;
    s=5;
    while(n/s>0){
        c+=n/s;
        s=s*5;
    }
    printf("%d\n", c);

}
