#include<bits/stdc++.h>
using namespace std;
#define MAXN 1050
#define F first
#define S second
#define PB push_back
vector<int> lista[MAXN];
int componente[MAXN];
void dfs(int x){
    for(int i=0;i<(int)lista[x].size();i++){
        if(componente[lista[x][i]]==-1){
            componente[lista[x][i]]=componente[x];
            dfs(lista[x][i]);
        }
    }
}
int main(){
    int n,d,x,y,cont=0,aux,i,k;
    pair<int , int> vertice[MAXN];
    bool v=true;
    scanf("%d%d", &n,&d);
    for(i=1;i<=n;i++){
        scanf("%d%d", &x, &y);
        vertice[i]=make_pair(x,y);
    }
    for(i=1;i<=n;i++){
        for(k=1;k<=n;k++){
            aux=(vertice[i].F-vertice[k].F)*(vertice[i].F-vertice[k].F)+(vertice[i].S-vertice[k].S)*(vertice[i].S-vertice[k].S);
            if(aux<=d*d){
                lista[i].PB(k);
                lista[k].PB(i);
            }
        }
    }
    for(i=1;i<=n;i++)componente[i]=-1;
    for(i=1;i<=n;i++){
        if(componente[i]==-1){
            cont++;
            if(cont==2){
                v=false;
                break;
            }
            componente[i]=cont;
            dfs(i);
        }
    }
    if(v)printf("S\n");
    else printf("N\n");
    return 0;
}
