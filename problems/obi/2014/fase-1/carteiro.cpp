#include <bits/stdc++.h>
using namespace std;
int main(){
    queue<int> a;
    map<int,int> c;
    int m,n,i,l,s=0,atual,aux;
    scanf("%d%d", &m,&n);
    for(i=1;i<=m;i++){
        scanf("%d", &l);
        if(i==1)atual=1;
        c.insert(make_pair(l,i));
    }
    for(i=1;i<=n;i++){
        scanf("%d", &l);
        a.push(l);
    }
    while(!a.empty()){
        s+=abs(atual-c[a.front()]);
        atual=c[a.front()];
        a.pop();
    }
    printf("%d\n",s);
}
