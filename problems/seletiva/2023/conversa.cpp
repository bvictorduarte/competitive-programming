#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int x,y;
    cin>>x>>y;
    int k;
    cin>>k;
    int i,j;
    i=0;
    j=0;
    int inil=x-1,fiml=x+1;
        int inic=y-1,fimc=y+1;
        if(inil<0)
            inil++;
        if(fiml>n)
            fiml--;
        if(inic<0)
            inic++;
        if(fimc>m)
            fimc--;
    int cont=0;
    while(k--){
        int op;
        scanf("%d", &op);
        if(op==1)
            j++;
        else if(op==2)
            j--;
        else if(op==3)
            i++;
        else
            i--;
        for(int q=inil;q<=fiml;q++)
            for(int w=inic;w<=fimc;w++)
                if(i==q&&j==w)
                    cont++;
    }
    /*int inil=x-1,fiml=x+1;
        int inic=y-1,fimc=y+1;
        if(inil<0)
            inil++;
        if(fiml>n-1)
            fiml--;
        if(inic<0)
            inic++;
        if(fimc>m-1)
            fimc--;
    for(int q=inil;q<=fiml;q++)
            for(int w=inic;w<=fimc;w++)
                if(x==q&&y==w)
                    cont++;
    */
    cout<<cont<<endl;
    return 0;
}