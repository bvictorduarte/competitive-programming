#include<bits/stdc++.h>
using namespace std;
int b[20];
int main(){
    int i,n,s=1,j,m;
    scanf("%d", &n);
    i=n;
    while(i--)s=s*2;
    m=s;
    while(m--){
        if(m!=s-1){
            for(i=0;i<n;i++){
                if(i==0)b[i]++;
                else{
                    if(b[i-1]==2){
                        b[i-1]=0;
                        b[i]++;
                    }
                }
            }
        }
        for(j=0;j<n;j++)printf("%d",b[n-1-j]);
        printf("\n");
    }
    return 0;
}
