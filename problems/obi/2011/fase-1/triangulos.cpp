#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,m;
    cin>>a>>b>>c;
    m=max(a,b);
    m=max(m,c);
    if(m>=a+b+c-m)
        printf("n\n");
    else if(m*m==a*a+b*b+c*c-m*m)
        printf("r\n");
    else if(m*m>a*a+b*b+c*c-m*m)
        printf("o\n");
    else
        printf("a\n");
    return 0;
}
