#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        double ans;
        scanf("%lf", &ans);
        cout<<(long long)((sqrt(1+8*ans)-1)/2)<<endl;
    }
    return 0;
}