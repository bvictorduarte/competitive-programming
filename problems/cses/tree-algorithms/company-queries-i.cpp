#include<bits/stdc++.h>
using namespace std;
const int maxN=2e5+50;
const int maxLog=19;
int ancest[maxN][maxLog+3],p[maxN],n;
void pre_compute(){
    for(int i=1;i<=n;i++)
        ancest[i][0]=p[i];
    for(int k=1;k<=maxLog;k++){
        for(int i=1;i<=n;i++)
            ancest[i][k]=ancest[ancest[i][k-1]][k-1];
    }
}
int main(){
    int q;
    cin>>n>>q;
    p[1]=0;
    for(int i=2;i<=n;i++){
        int a;
        cin>>a;
        p[i]=a;
    }
    pre_compute();
    for(int o=0;o<q;o++){
        int p,k;
        cin>>p>>k;
        for(int i = 0; i < log2(k)+1; i++)
            if(k&(1<<i))
                p = ancest[p][i];
        printf("%d\n", p ? p : p-1);
    }
    return 0;
}