#include<bits/stdc++.h>
using namespace std;
int main(){
    int c,a;
    cin>>c>>a;
    if(c-1>=a)
        printf("1\n");
    else if(a%(c-1)==0)
        printf("%d\n", a/(c-1));
    else
        printf("%d\n",a/(c-1)+1);
    return 0;
}
