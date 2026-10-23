#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d", &t);
    for(int m=1;m<=t;m++){
        char cards[54][3];
        for(int i=1;i<=52;i++)
            scanf("%s", cards[i]);
        int i=27,y=0;
        for(int k=0;k<3;k++){
            int x = (cards[i][0]>'0'&&cards[i][0]<'9') ? cards[i][0]-'0' : 10;
            y+=x;
            i-=(11-x);
        }
        printf("Case %d: %s\n", m, (i>=y) ? cards[y] : cards[27+y-i]);
    }
    return 0;
}