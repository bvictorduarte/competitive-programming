#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n=1,x,y,i,t;
    cin>>t;
    while(t>=1){
        cin>>y>>x;
        if(x>=y){
            n=1+x*(x-1);
            if(x%2==0)
                n=n-(x-y);
            else
                n=n+(x-y);
        }else{
            n=1+y*(y-1);
            if(y%2==0)
                n=n+(y-x);
            else
                n=n-(y-x);
        }
        cout<<n<<"\n";
        t--;
    }
    return 0;
}
