#include<bits/stdc++.h>
using namespace std;
int main(){
    int l,c,m;
    scanf("%d%d", &l,&c);
    m=l*c+(l-1)*(c-1);
    printf("%d\n%d\n", m,2*(c+l-2));
    return 0;
}
