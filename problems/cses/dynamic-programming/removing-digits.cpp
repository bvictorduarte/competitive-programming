#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,cont=0;
    cin>>n;
    while(n!=0){
        int max_digit=0,aux=n;
        for(int i=0;i<=6;i++){
            max_digit=max(max_digit,aux%10);
            aux=aux/10;
        }
        n-=max_digit;
        cont++;
    }
    cout<<cont;
    return 0;
}
