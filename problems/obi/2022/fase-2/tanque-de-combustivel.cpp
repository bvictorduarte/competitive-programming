#include<bits/stdc++.h>
using namespace std;
int main(){
    int c,d,t;
    cin>>c>>d>>t;
    if(c*t>=d){
        float a=0;
        printf("%.1f\n", a);
        return 0;
    }
    printf("%.1f\n", (float)(d-t*c)/(float)(c));
    return 0;
}