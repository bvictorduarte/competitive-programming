#include <bits/stdc++.h>
using namespace std;
string linha[550];
vector<int> adj[250050];
int comp[250050];
void dfs(int x){
    for(int i=0;i<(int)adj[x].size();i++){
        int s=adj[x][i];
        if(comp[s]==1)continue;
        comp[s]=1;
        dfs(s);
    }
}
int main(){
    int n,p;
    freopen("input.txt", "r", stdin);
    scanf("%d%d", &n,&p);
    for(int i=1;i<=n;i++)
        cin>>linha[i];
    for(int i=1;i<=n;i++){
        for(int j=0;j<n;j++){
            if(i>1&&(linha[i-1][j]-'0')<=p)
                adj[(i-1)*n+j].push_back((i-2)*n+j);
            if(i<n&&(linha[i+1][j]-'0')<=p)
                adj[(i-1)*n+j].push_back((i)*n+j);
            if(j>0&&(linha[i][j-1]-'0')<=p)
                adj[(i-1)*n+j].push_back((i-1)*n+j-1);
            if(j<n-1&&(linha[i][j+1]-'0')<=p)
                adj[(i-1)*n+j].push_back((i-1)*n+j+1);
        }
    }
    if((linha[1][0]-'0')>p){
        for(int i=1;i<=n;i++)
            cout<<linha[i]<<"\n";
    }else{
        comp[0]=1;
        dfs(0);
        for(int i=1;i<=n;i++){
            for(int j=0;j<n;j++){
                if(comp[(i-1)*n+j]==1){
                    printf("*");
                }else{
                    printf("%c", linha[i][j]);
                }
            }
            printf("\n");
        }

    }
    return 0;
}
