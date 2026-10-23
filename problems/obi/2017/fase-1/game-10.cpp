#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,d,a;
    scanf("%d%d%d",&n,&d,&a);
    printf("%d\n", (a>d) ? (n-a+d) : (d-a));
    return 0;
}
