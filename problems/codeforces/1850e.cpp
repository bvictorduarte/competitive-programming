#include<bits/stdc++.h>
using namespace std;
double mod(double a){
    if(a>=0)return a;
    return -a;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        long long ansll;
        double c,s=0,ans;
        cin>>n>>c;
        for(int i=0;i<n;i++){
            double a;
            cin>>a;
            c-=a*a;
            s+=a;
        }
        ans=(sqrt(s*s+n*c)-s)/(2*n);
        ansll=(long long)((sqrt(s*s+n*c)-s)/(2*n));
        if(mod(ans-ansll)<mod(ans-(ansll+1)))
            cout<<ansll<<endl;
        else
            cout<<ansll+1<<endl;
    }
}