#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int v[maxn];
int main(){
    int n,g,cont=1,value;
    scanf("%d", &n);
    scanf("%d", &g);
    v[0]=g;
    for(int i=1;i<n;i++){
        scanf("%d", &value);
        if(value>g){
            v[cont]=value;
            g=value;
            cont++;
        }
    }
    cout<<cont<<endl;
    cout<<v[0];
    for(int i=1;i<cont;i++)
        cout<<" "<<v[i];
    cout<<endl;
}