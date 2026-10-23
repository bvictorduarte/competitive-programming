#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,r=1;
    scanf("%d", &m);
    while(m--)r=(r*2)%(1000000007);
    printf("%d\n", r);
    return 0;
}
