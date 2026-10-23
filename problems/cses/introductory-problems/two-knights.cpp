#include<bits/stdc++.h>
using namespace std;
long long int pot(long long int a, long long int b){
    long long int i,s=1;
    for(i=0;i<b;i++){
        s=s*a;
    }
    return s;
}
int main(){
    long long int n,r,i=1;
    scanf("%lld", &n);
    while(i<=n){
        if(i==1)printf("0\n");
        if(i==2)printf("6\n");
        if(i==3)printf("28\n");
        if(i>3){
            r=(pot(i,4)-9*pot(i,2)+24*i-16)/2;
            printf("%lld\n", r);
        }
        i++;
    }
    return 0;
}
