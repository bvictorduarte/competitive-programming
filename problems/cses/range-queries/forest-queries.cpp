#include<bits/stdc++.h>
using namespace std;
#define l(p) (p<<1)
#define r(p) (l(p)+1)
typedef long long ll;
const ll maxn=1e3+30;
char s[maxn];
ll grid[maxn][maxn],pref[maxn][maxn];
int n;
void build(){
    for(int i=1;i<=n;i++){
        pref[1][0]=0;
        for(int j=1;j<=n;j++)
            pref[i][j]=pref[i][j-1]+grid[i][j];
    }
}
ll RSQ(int i1, int j1,int i2, int j2){
    ll ans=0;
    for(int i=i1;i<=i2;i++)
        ans+=pref[i][j2]-pref[i][j1-1];
    return ans;
}
int main(){
    int q;
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    scanf("%d%d", &n,&q);
    for(int i=1;i<=n;i++){
        scanf("%s",s);
        for(int k=0;k<n;k++)
            if(s[k]=='*')
                grid[i][k+1]=1;
            else
                grid[i][k+1]=0;
    }
    build();
    while(q--){
        int i1,j1,i2,j2;
        scanf("%d%d%d%d",&i1,&j1,&i2,&j2);
        cout<<RSQ(i1,j1,i2,j2)<<'\n';
    }
    return 0;
}