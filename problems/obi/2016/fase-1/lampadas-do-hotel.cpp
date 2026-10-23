#include<bits/stdc++.h>
using namespace std;
int main(){
    int i1,i2,f1,f2;
    cin>>i1>>i2>>f1>>f2;
    if(f1==f2&&i1==i2){
        if(i1!=f1)printf("1\n");
        else printf("0\n");
    }else if(f1==f2){
        if(f1==i1)printf("2\n");
        else printf("1\n");
    }else if(i1==i2){
        if(i1==f1)printf("2\n");
        else printf("1\n");
    }else printf("1\n");
    return 0;
}
