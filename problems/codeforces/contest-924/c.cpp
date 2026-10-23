#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int x,n;
        cin>>n>>x;
        int i=(n-x)/2,p=2,e,d=1;
        while(i!=1){
            e=0;
            while((i%p)==0){
                e++;
                i=i/p;
            }
            d=d*(e+1);
            p++;
        }
        cout<<d<<endl;
        int ans=d;
        p=2;d=1;
        i=(n-x-2)/2;
        while(i!=1){
            e=0;
            while((i%p)==0){
                e++;
                i=i/p;
            }
            d=d*(e+1);
            p++;
        }
        cout<<d<<endl;
        ans+=d;
        cout<<--ans<<endl;
    }
    return 0;
}