#include<bits/stdc++.h>
using namespace std;
int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int v[1010],n;
        memset(v,0,sizeof(v));
        cin>>n;
        for(int i=1;i<=n;i++){
            int k;
            cin>>k;
            v[k]=i;
        }
        int ans=-1;
        for(int i=1;i<=1000;i++)
            for(int j=1;j<=1000;j++)
                if(v[i]!=0&&v[j]!=0&&gcd(i,j)==1)
                    ans=max(ans,v[i]+v[j]);
        cout<<ans<<endl;
    }
    return 0;
}