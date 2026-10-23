#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[8];
    for(int i=0;i<4;i++)
        cin>>a[i];
    if(a[0]==a[3])
        printf("F\n");
    else
        printf("V\n");
    return 0;
}
