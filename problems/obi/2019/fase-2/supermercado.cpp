#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    float pmin;
    cin>>n;
    float p,g;
    cin>>p>>g;
    pmin=1000.0*p/g;
    for(int i=1;i<n;i++){
        scanf("%f%f", &p,&g);
        if(pmin>1000.0*p/g)
            pmin=1000.0*p/g;
    }
    printf("%.2f", pmin);
    return 0;
}