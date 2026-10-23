#include<bits/stdc++.h>
using namespace std;
const int MAXN=2*(1e5)+10;
const int LOGN=19;
int m[MAXN][LOGN];
void pre_compute(int n){
    for(int k=1;k<LOGN;k++){
        int w=1<<k;
        for(int i=1;i<=n-w+1;i++)
            m[i][k]=min(m[i][k-1],m[i+w/2][k-1]);
    }
}
int main(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        scanf("%d", &m[i][0]);
    pre_compute(n);
    for(int i=0;i<q;i++){
        int a,b;
        scanf("%d%d", &a, &b);
        int tam=b-a+1,logt,ans,w;
        logt=log2(tam);
        w=1<<logt;
        ans=min(m[a][logt],m[b-w+1][logt]);
        cout<<ans<<endl;
    }
    return 0;
}