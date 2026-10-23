#include <bits/stdc++.h>
using namespace std;
int main(){
    char c,c1;
    int cont, m=-1;
    scanf("%c", &c);
    c1=c;
    cont=1;
    while(1){
        if(m<cont)m=cont;
        scanf("%c", &c);
        if(c=='\n')break;
        else{
            if(c==c1)cont++;
            else cont=1;
            c1=c;
        }
    }
    cout<<m<<"\n";
}
