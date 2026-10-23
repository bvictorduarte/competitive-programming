#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,maxx=0,minx=0,maxy=0,miny=0,sumx=0,sumy=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int k;
        char op;
        scanf("%d %c", &k, &op);
        if(op=='L')
            sumx+=k;
        else if(op=='O')
            sumx-=k;
        else if(op=='N')
            sumy+=k;
        else if(op=='S')
            sumy-=k;
        minx=min(minx,sumx);
        maxx=max(maxx,sumx);
        miny=min(miny,sumy);
        maxy=max(maxy,sumy);
    }
    if(minx<0)maxx-=minx;
    if(miny<0)maxy-=miny;
    cout<<2*(maxx+maxy+4)<<endl;
    return 0;
}