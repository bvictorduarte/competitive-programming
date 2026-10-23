#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int left_buddy[maxn],right_buddy[maxn];
int main(){
    int b,s;
    scanf("%d %d", &s, &b);
    while(b!=0){
        left_buddy[1]=0;
        for(int i=2;i<=s;i++)
            left_buddy[i]=i-1;
        right_buddy[s]=0;
        for(int i=1;i<=s-1;i++)
            right_buddy[i]=i+1;
        for(int i=0;i<b;i++){
            int l,r;
            scanf("%d%d", &l,&r);
            right_buddy[left_buddy[l]]=right_buddy[r];
            left_buddy[right_buddy[r]]=left_buddy[l];
            if(left_buddy[l])
                printf("%d ", left_buddy[l]);
            else
                printf("* ");
            if(right_buddy[r])
                printf("%d\n", right_buddy[r]);
            else
                printf("*\n");
        }
        printf("-\n");
        scanf("%d %d", &s, &b);
    }
    return 0;
}