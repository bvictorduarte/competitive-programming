#include <bits/stdc++.h>
using namespace std;
vector<int> coins;
const int INF=1e9+7;
int solve[1000050];
int main()
{
    int n,x;
    cin>>n>>x;
    int k;
    for(int i=0;i<n;i++){
        scanf("%d", &k);
        coins.push_back(k);
    }
    solve[0]=0;
    for(int i=1;i<=x;i++){
        solve[i]=INF;
        for(int c=0;c<n;c++)
            if(i-coins[c]>=0)
                solve[i]=min(solve[i-coins[c]]+1,solve[i]);
    }
    if(solve[x]!=INF)
        cout<<solve[x]<<endl;
    else
        cout<<-1<<endl;
    return 0;
}
