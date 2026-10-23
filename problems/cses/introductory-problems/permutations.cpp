#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i;
    cin>>n;
    if(n==2||n==3)printf("NO SOLUTION\n");
    else if(n!=4){
        if(n%2==0){
            for(i=n;i>=2;i-=2)
                printf("%d ", i);
            for(i=n-1;i>=1;i-=2){
                if(i!=1)
                    printf("%d ", i);
                else
                    printf("%d\n", i);
            }
        }else{
            for(i=n-1;i>=2;i-=2)
                printf("%d ", i);
            for(i=n;i>=1;i-=2){
                if(i!=1)
                    printf("%d ", i);
                else
                    printf("%d\n", i);
            }
        }
    }
    else printf("2 4 1 3\n");
    return 0;
}
