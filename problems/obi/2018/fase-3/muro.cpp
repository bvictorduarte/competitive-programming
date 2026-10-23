#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+50;
const int m=1e9+7;
long long dp[MAXN];
int main(){
    dp[0]=dp[1]=1;
    dp[2]=5;
    dp[3]=11;
    int n;
    cin>>n;
    for(int i=4;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2]*4+dp[i-3]*2;
        dp[i]%=m;
    }
    cout<<dp[n]<<endl;
    return 0;
}