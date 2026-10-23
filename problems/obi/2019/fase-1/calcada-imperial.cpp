#include<bits/stdc++.h>
using namespace std;
#define MAXN 550
int main(){
    int v[MAXN],n,i,k,j,v1=0,v2,m=-100,v3,cont;
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d", &v[i]);
    }
    for(i=1;i<=n;i++){
        for(k=1;k<=n;k++){
            cont=0;
            v3=0;
            v1=0;
            for(j=0;j<n;j++){
                if(v[j]==i&&v1==0){
                    v1++;
                    v2=i;
                    cont++;
                }else if(v[j]==k&&v1==0){
                    v1++;
                    v2=k;
                    cont++;
                }else if(v[j]==i&&i!=v2){
                    v2=i;
                    cont++;
                }else if(v[j]==k&&k!=v2){
                    v2=k;
                    cont++;
                }
            }
            if(m<=cont)m=cont;
        }
    }
    printf("%d\n", m);
    return 0;
}
