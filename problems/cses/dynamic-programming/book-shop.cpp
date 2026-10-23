#include <bits/stdc++.h>
using namespace std;
int p[1050],np[1050],dp[100050][1050];
int main(){
    int n,x;
    vector<pair<int,int>> v;
    cin>>n>>x;
    for(int i=0;i<n;i++)
        scanf("%d", &p[i]);
    for(int i=0;i<n;i++){
        scanf("%d", &np[i]);
        v.push_back(make_pair(p[i],np[i]));
    }
    sort(v.begin(),v.end());
    for(int i=1;i<=x;i++){
        if(i-v[0].first>=0)
            dp[i][0]=v[0].second;
        for(int j=1;j<n;j++)
            if(i-v[j].first>=0)
                dp[i][j]=max(dp[i][j-1],dp[i-v[j].first][j-1]+v[j].second);
            else
                dp[i][j]=dp[i][j-1];
    }
    cout<<dp[x][n-1]<<endl;
    return 0;
}