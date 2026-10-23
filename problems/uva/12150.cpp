#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    while(n!=0){
        bool positions[1005],possible=true;
        int grid[1005];
        memset(positions,false,sizeof(positions));
        for(int i=1;i<=n;i++){
            int c,p;
            scanf("%d %d", &c, &p);
            if(p+i<1||p+i>n||positions[p+i])
                possible=false;
            else{
                grid[p+i]=c;
                positions[p+i]=true;
            }
        }
        if(possible){
            printf("%d", grid[1]);
            for(int i=2;i<=n;i++)
                printf(" %d", grid[i]);
            printf("\n");
        }else
            printf("-1\n");
        scanf("%d", &n);
    }
    return 0;
}