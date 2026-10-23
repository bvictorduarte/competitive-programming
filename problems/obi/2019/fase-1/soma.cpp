#include <bits/stdc++.h>
using namespace std;
#define MAXN 500050LL
long long v[MAXN],acum[MAXN];
int main(){
    long long n,k,l,r,s=0,cont=0;
    long long i;
    cin>>n>>k;
    for(i=0;i<n;i++){
        cin>>v[i];
        s+=v[i];
        acum[i]=s;
        //printf("%d\n", acum[i]);
    }
    l=0;
    r=0;
    while(r>=l&&r<=n-1){
        if(acum[r]-acum[l]+v[l]==k){
            cont++;
            r++;
        }
        else if(acum[r]-acum[l]+v[l]<k)r++;
        else l++;
        if(v[l]>k&&l==r&&r<n-1)r++;
        //printf("L: %d   R:  %d   CONT:  %d\n\n", l,r,cont);
    }
    printf("%d\n", cont);
    return 0;
}
