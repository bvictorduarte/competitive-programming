#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6;
int main(){
    int a,b;
    cin>>a>>b;
    for(int i=1;i<=a+b;i++)
        if(2*a+2*b==a*i+4*i-2*i*i&&(a+b)%i==0){
            int m=i,n=(a+b)/i;
            if(min(m,n)-2>0){
                cout<<min(m,n)<<" "<<max(m,n)<<endl;
                return 0;
            }
        }
    cout<<-1<<" "<<-1<<endl;
    return 0;
}