#include<bits/stdc++.h>
using namespace std;
#define MAXN 1050
int a[MAXN][MAXN],s;
int main(){
    int n,m,menor=100000005;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int k=0;k<m;k++)
            cin>>a[i][k];
    }
    for(int i=0;i<m;i++){
        s=0;
        for(int k=0;k<n;k++)
            s+=a[k][i];
        if(menor>s)
            menor=s;
    }
    printf("%d\n", menor);
    return 0;
}
