#include <bits/stdc++.h>
using namespace std;
const int m=1e9+7;
vector<int> coins;
int dp[1000050];
int main(){
    int n,x;
    int k;
    cin>>n>>x;
    for(int i=0;i<n;i++){
        scanf("%d", &k);
        coins.push_back(k);
    }
    sort(coins.begin(),coins.end());
    dp[0]=1;
    for(auto c:coins){
        for(int i=1;i<=x;i++)
            if(i-c>=0){
                dp[i]+=dp[i-c];
                dp[i]%=m;
            }
    }
    cout<<dp[x]<<endl;
    return 0;
}
