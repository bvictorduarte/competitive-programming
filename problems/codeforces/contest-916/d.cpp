#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+50;
int v[5][maxn],pos_max[5][5];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<5;i++)
            for(int j=0;j<5;j++)
                pos_max[i][j]=0;
        for(int k=1;k<=3;k++)
            for(int i=1;i<=n;i++)
                cin>>v[k][i];
        for(int j=1;j<=3;j++)
            for(int i=1;i<=2;i++){
                for(int k=1;k<=n;k++)
                    if(k!=pos_max[j][i-1]&&v[j][pos_max[j][i]]<v[j][k])
                        pos_max[j][i]=k;
            }
        for(int j=1;j<=3;j++)
            for(int k=1;k<=n;k++)
                if(k!=pos_max[j][1]&&k!=pos_max[j][2]&&v[j][pos_max[j][3]]<v[j][k])
                    pos_max[j][3]=k;
        int sum=0,ans=0;
        for(int i=1;i<=3;i++)
            for(int k=1;k<=3;k++){
                sum=v[1][pos_max[1][i]];
                if(pos_max[2][k]!=pos_max[1][i])
                    for(int j=1;j<=3;j++){
                        sum=v[1][pos_max[1][i]]+v[2][pos_max[2][k]];
                        if(pos_max[2][k]!=pos_max[3][j]&&pos_max[1][i]!=pos_max[3][j]){
                            sum+=v[3][pos_max[3][j]];
                            ans=max(ans,sum);
                        }
                    }
            }
        cout<<ans<<endl;
    }
}