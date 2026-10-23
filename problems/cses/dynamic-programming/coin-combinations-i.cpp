#include <bits/stdc++.h>
using namespace std;
const int m=1e9+7;
vector<int> coins;
long long solve[1000050];
int main(){
    int n,x;
    cin>>n>>x;
    int k;
    for(int i=0;i<n;i++){
        cin>>k;
        coins.push_back(k);
    }
    solve[0]=1;
    for(int i=1;i<=x;i++){
        solve[i]=0;
        for(int c=0;c<n;c++)
            if(i-coins[c]>=0){
                solve[i]+=solve[i-coins[c]];
                solve[i]%=m;
            }
    }
    cout<<solve[x]<<endl;
    return 0;
}
