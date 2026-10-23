#include <bits/stdc++.h>
using namespace std;
int main(){
    string p1, p2;
    int cont=0;
    cin>>p1>>p2;
    for(int i=0;i<(int)p1.size();i++){
        for(int k=0;k<(int)p1.size();k++){
            if(p1[i]==p2[k]){
                p2[k]='1';
                cont++;
                break;
            }
        }
    }
    for(int i=0;i<(int)p1.size();i++){
        if(p2[i]=='*')
            cont++;
    }
    if(cont==(int)p1.size())
        printf("S\n");
    else
        printf("N\n");
    return 0;
}
