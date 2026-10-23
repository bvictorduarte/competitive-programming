#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+50;
const int INF=0x3f3f3f3f;
int v[maxn],dp[maxn];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    int maxl=0;
    dp[0]=-INF;
    for(int i=1;i<=n;i++){
        int pos=lower_bound(dp,dp+maxl,v[i])-dp;
        if(dp[pos]>=v[i])
            dp[pos]=v[i];
        else{
            dp[pos+1]=v[i];
            maxl++;
        }
    }
    cout<<maxl<<endl;
    return 0;
}