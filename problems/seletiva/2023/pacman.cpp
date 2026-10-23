#include <bits/stdc++.h>
using namespace std;
string grid[150];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>grid[i];
    int ans=0,aux=0;
    for(int i=0;i<n;i++){
        if(i%2==0){
            for(int k=0;k<n;k++){
                if(grid[i][k]=='o')
                    aux++;
                if(grid[i][k]=='A')
                    aux=0;
                ans=max(ans,aux);
            }
        }
        else{
            for(int k=n-1;k>=0;k--){
                if(grid[i][k]=='o')
                    aux++;
                if(grid[i][k]=='A')
                    aux=0;
                ans=max(ans,aux);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}