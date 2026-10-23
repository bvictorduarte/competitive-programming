#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    n=n-5;
    if(n%8==1)
        printf("1\n");
    else if(n%8==2)
        printf("2\n");
    else
        printf("3\n");
    return 0;
}
