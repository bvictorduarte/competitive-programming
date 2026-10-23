#include<bits/stdc++.h>
using namespace std;
int soma(int a){
    int sum=0;
    while(a>0){
        sum+=a%10;
        a=a/10;
    }
    return sum;
}
int main(){
    int s,a,b,maior,menor;
    cin>>s>>a>>b;
    for(int i=a;i<=b;i++){
        if(soma(i)==s){
            menor=i;
            break;
        }
    }
    for(int i=b;i>=a;i--){
        if(soma(i)==s){
            maior=i;
            break;
        }
    }
    cout<<menor<<endl<<maior<<endl;
    return 0;
}