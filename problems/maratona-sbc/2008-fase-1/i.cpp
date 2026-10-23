#include<bits/stdc++.h>
using namespace std;
const int maxn=650;
const int INF=0x3f3f3f3f;
int n,m,grid[maxn][maxn],tam_seq[maxn][maxn];
int solve_histogram(int j,int l,int r){
    stack<pair<int,int>> s;
    int solve=-1;
    for(int i=l;i<=r;i++){
        while(!s.empty()&&s.top().first>=tam_seq[i][j]){
            pair<int,int> cur=s.top();s.pop();
            solve=max(solve,cur.first*(!s.empty()?(i-s.top().second-1):i-l));
        }
        solve=max(solve,tam_seq[i][j]*(!s.empty()?(i-s.top().second):i-l+1));
        int tam;
        if(i!=r){
            int low=(lower_bound(grid[i]+j,grid[i]+j+tam_seq[i][j]-1,grid[i+1][j])-grid[i]);
            if(low==j+tam_seq[i][j]-1&&grid[i][low]<grid[i+1][j])
                tam=low-j+1;
            else
                tam=low-j;
        }else
            tam=tam_seq[i][j];
        while(!s.empty()&&s.top().first>=tam){
                pair<int,int> cur=s.top();s.pop();
                solve=max(solve,cur.first*(!s.empty()?(i-s.top().second-1):i-l));
            }
        s.push({tam,i});
    }
    while(!s.empty()){
        pair<int,int> cur=s.top();s.pop();
        solve=max(solve,cur.first*(!s.empty()?(r-s.top().second):r-l+1));
    }
    return solve;
}
int main(){
    while(cin>>n>>m&&n&&m){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>grid[i][j];
        for(int i=1;i<=n;i++){
            grid[i][m+1]=-INF;
            for(int j=m;j>=1;j--){
                if(grid[i][j]<grid[i][j+1])
                    tam_seq[i][j]=tam_seq[i][j+1]+1;
                else
                    tam_seq[i][j]=1;
            }
        }
        int ans=-1;
        for(int j=1;j<=m;j++){
            int r;
            for(int l=1;l<=n;l=r+1){
                r=l;
                while(r+1<=n&&grid[r+1][j]>grid[r][j])
                    r++;
                ans=max(ans,solve_histogram(j,l,r));
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}