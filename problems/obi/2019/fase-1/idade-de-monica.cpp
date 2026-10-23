#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b,c,m;
    scanf("%d%d%d", &n, &a, &b);
    m=max(a,b);
    c=n-a-b;
    m=max(m,c);
    printf("%d\n", m);
    return 0;
}
