#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string grid[8],ans;
        for(int i=0;i<8;i++)
            cin>>grid[i];
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++)
                if(grid[j][i]!='.')
                    ans.push_back(grid[j][i]);
        cout<<ans<<endl;
    }
    return 0;
}