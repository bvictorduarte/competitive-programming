#include<bits/stdc++.h>
using namespace std;
#define MAXN 50050
vector<int> lista[MAXN];
int comp[MAXN];

void dfs(int x){
    int i;
    for(i=0;i<(int)lista[x].size();i++){
        if(comp[lista[x][i]]==-1){
            comp[lista[x][i]]=comp[x];
            dfs(lista[x][i]);
        }
    }
}
int main(){
    int n,m,ncomp=0,i,a,b;
    scanf("%d%d", &n,&m);
    for(i=1;i<=m;i++){
        scanf("%d%d", &a, &b);
        lista[a].push_back(b);
        lista[b].push_back(a);
    }
    for(i=1;i<=n;i++)comp[i]=-1;
    for(i=1;i<=n;i++){
        if(comp[i]==-1){
            ncomp++;
            comp[i]=ncomp;
            dfs(i);
        }
    }
    printf("%d\n", ncomp);
    return 0;
}
