#include <bits/stdc++.h>
using namespace std;
set<int> pintados;
vector<int> componentes;
vector<int> lista[40050];
void dfs(int a){
    int i;
    for(i=0;i<(int)lista[a].size();i++){
        int v=lista[a][i];
        if(componentes[v]==-1){
            componentes[v]=componentes[a];
            dfs(v);
        }
    }
}
int main(){
    int m,n,k,x,y,l,i,j,cont=0;
    freopen("input.txt", "r", stdin);
    scanf("%d%d%d%d%d", &n,&m,&x,&y,&k);
    for(l=1;l<=n*m+1;l++)componentes.push_back(-1);
    for(l=1;l<=k;l++){
        scanf("%d%d", &i,&j);
        pintados.insert((i-1)*m+j);
    }
    for(i=1;i<=n*m;i++){
        if(pintados.find(i)==pintados.end()){
            if(i>m){
                if(pintados.find(i-m)==pintados.end())
                    lista[i].push_back(i-m);
                if(i%m!=0&&pintados.find(i-m+1)==pintados.end())
                    lista[i].push_back(i-m+1);
                if(i%m!=1&&pintados.find(i-m-1)==pintados.end())
                    lista[i].push_back(i-m-1);
            }
            if(i<=(n-1)*m){
                if(pintados.find(i+m)==pintados.end())
                    lista[i].push_back(i+m);
                if(i%m!=0&&pintados.find(i+m+1)==pintados.end())
                    lista[i].push_back(i+m+1);
                if(i%m!=1&&pintados.find(i+m-1)==pintados.end())
                    lista[i].push_back(i+m-1);
            }
            if(i%m!=0&&pintados.find(i+1)==pintados.end())
                lista[i].push_back(i+1);
            if(i%m!=1&&pintados.find(i-1)==pintados.end())
                lista[i].push_back(i-1);
        }
    }
    componentes[(x-1)*m+y]=1;
    dfs((x-1)*m+y);
    for(i=1;i<=n*m;i++){
        if(componentes[i]==1){
            cont++;
        }
    }
    printf("%d\n", cont);
    return 0;
}
