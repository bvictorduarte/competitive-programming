#include<bits/stdc++.h>
using namespace std;
int main(){
    int c,t,cont=0;
    set<int> tacos;
    scanf("%d", &c);
    while(c--){
        scanf("%d", &t);
        if(tacos.find(t)==tacos.end()){
            cont=cont+2;
            tacos.insert(t);
        }else
            tacos.erase(t);
    }
    printf("%d\n", cont);
    return 0;
}
