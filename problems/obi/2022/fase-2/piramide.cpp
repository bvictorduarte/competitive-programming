#include<bits/stdc++.h>
using namespace std;
int grid[150][150];
int main(){
    int n;
    cin>>n;
    int l=1,r=n,c=0;
    while(r>=l){
        c++;
        for(int i=l;i<=r;i++)
            grid[l][i]=c;
        for(int i=l;i<=r;i++)
            grid[r][i]=c;
        for(int i=l;i<=r;i++)
            grid[i][l]=c;
        for(int i=l;i<=r;i++)
            grid[i][r]=c;
        r--;
        l++;
    }
    for(int i=1;i<=n;i++){
        for(int k=1;k<=n;k++){
            cout<<grid[i][k]<<" ";
        }
        cout<<endl;
    }
}