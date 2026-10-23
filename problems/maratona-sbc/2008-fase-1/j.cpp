#include<bits/stdc++.h>
using namespace std;
int main(){
    double ev1,ev2,at,d;
    while(cin>>ev1>>ev2>>at>>d&&ev1&&ev2&&at&&d){
        double p=(at/6),q=1-p,ans,n1=ceil(ev1/d),n2=ceil(ev2/d);
        if(at==3)
            ans=n1/(n1+n2);
        else
            ans=(1-pow(q/p,n1))/(1-pow(q/p,n1+n2));
        printf("%.1lf\n", ans*100);
    }
    return 0;
}