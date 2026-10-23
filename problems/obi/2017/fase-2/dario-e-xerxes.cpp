#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,cont=0;
    cin>>n;
    int ganha_de[4]={0},perde_de[4]={0};
    for(int i=0;i<n;i++){
        int d,x;
        cin>>d>>x;
        for(int j=1;j<=2;j++){
            ganha_de[j]=d+j;
            if(ganha_de[j]>4)
                ganha_de[j]%=5;
            perde_de[j]=d-j;
            if(perde_de[j]<0)
                perde_de[j]+=5;
        }
        for(int j=1;j<=2;j++){
            if(ganha_de[j]==x){
                cont++;
                break; 
            }else if(perde_de[j]==x){
                cont--;
                break;
            }
        }
    }
    if(cont>0)
        cout<<"dario\n";
    else
        cout<<"xerxes\n";
    return 0;
}