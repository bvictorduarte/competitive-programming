#include <bits/stdc++.h>
using namespace std;
int gosta[100050];
int tocadas[100050],odeia[100050];
int main(){
    int atual,n,m,g,o;
    scanf("%d%d%d", &n,&m,&atual);
    for(int i=0;i<n;i++){
        scanf("%d%d", &g, &o);
        if(odeia[o]==0){
            gosta[o]=g;
            odeia[o]=1;
        }
    }
    int cont=0;
    tocadas[atual]=1;
    while(odeia[atual]==1){
        cont++;
        atual=gosta[atual];
        if(tocadas[atual]==1){
            printf("-1\n");
            return 0;
        }
        tocadas[atual]=1;
    }
    printf("%d\n", cont);
    return 0;
}
