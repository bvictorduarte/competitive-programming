#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        int cont=0;
        multiset<int> d,e;
        for(int i=0;i<n;i++){
            char op;
            int p;
            scanf("%d %c", &p, &op);
            if(op=='E'){
                if(!d.empty()&&d.find(p)!=d.end()){
                    d.erase(d.find(p));
                    cont++;
                }else
                    e.insert(p);
            }
            if(op=='D'){
                if(!e.empty()&&e.find(p)!=e.end()){
                    e.erase(e.find(p));
                    cont++;
                }else
                    d.insert(p);
            }
        }
        printf("%d\n", cont);
    }
    return 0;
}