#include <bits/stdc++.h>
using namespace std;
char grid[1050][1050];
int solve[1050][1050];
const int m=1e9+7;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int k=1;k<=n;k++)
            scanf(" %c", &grid[i][k]);
    if(grid[1][1]!='*')
        solve[1][1]=1;
    for(int i=1;i<=n;i++)
        for(int k=1;k<=n;k++)
            if(grid[i][k]!='*'&&!(i==k&&i==1)){
                solve[i][k]=solve[i-1][k]+solve[i][k-1];
                solve[i][k]%=m;
            }
    cout<<solve[n][n]<<endl;
    return 0;
}
