#include <bits/stdc++.h>
using namespace std;
int v[150][150];
int main(){
    int n;
    cin>>n;
    int xi,xf,yi,yf;
    for(int i=0;i<n;i++){
        cin>>xi>>xf>>yi>>yf;
        for(int j=xi;j<xf;j++)
            for(int k=yi;k<yf;k++)
                if(v[j][k]==0)
                    v[j][k]=1;
    }
    int cont=0;
    for(int i=1;i<100;i++)
        for(int j=1;j<100;j++)
            if(v[i][j]==1)
                cont++;
    cout<<cont<<endl;
    return 0;
}
