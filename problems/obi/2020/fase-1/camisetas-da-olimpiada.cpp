#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,cont1=0,cont2=0,l,t1,t2;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &l);
        if(l==1)cont1++;
        else cont2++;
    }
    scanf("%d%d", &t1,&t2);
    if(t1>=cont1&&t2>=cont2)
        printf("S\n");
    else
        printf("N\n");
    return 0;
}
