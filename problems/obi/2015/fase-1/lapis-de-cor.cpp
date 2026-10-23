#include<bits/stdc++.h>
using namespace std;
const int maxN=1e3+10;
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
string grid[maxN];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>grid[i];
    for(int i=1;i<=9;i++)
        for(int k=0;k<n;k++)
            for(int j=0;j<n;j++)
                if(i!=9){
                    if(grid[k][j]=='0'+i-1)
                        for(int m=0;m<4;m++)
                            if(k+dx[m]<n&&k+dx[m]>=0&&j+dy[m]<n&&j+dy[m]>=0&&grid[k+dx[m]][j+dy[m]]=='*')
                                grid[k+dx[m]][j+dy[m]]='0'+i;
                }
                else
                    if(grid[k][j]=='*')
                        grid[k][j]='9';
    for(int i=0;i<n;i++)
        cout<<grid[i]<<endl;
}