#include <bits/stdc++.h>
using namespace std;
int infec[1050];
set<int> cadeia[1050],resposta;
int main(){
    int n,c,x,k;
    freopen("input.txt", "r", stdin);
    bool lider=true;
    scanf("%d%d", &n, &c);
    for(int i=1;i<=c;i++){
        scanf("%d", &infec[i]);
        scanf("%d", &x);
        for(int j=1;j<=x;j++){
            scanf("%d", &k);
            cadeia[i].insert(k);
        }
    }
    for(int i=1;i<=c;i++){
        lider=true;
        for(int j=1;j<=c;j++){
            if(i!=j&&cadeia[j].find(infec[i])!=cadeia[j].end()){
                lider=false;
                break;
            }
        }
        if(lider)
            resposta.insert(infec[i]);
    }
    set<int> ::iterator it;
    for(it=resposta.begin();it!=resposta.end();it++)
        printf("%d\n", *it);
    return 0;
}
