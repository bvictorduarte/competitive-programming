#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> a,b,p;
    p.resize(100050,0);
    int i,n,m,j,k;
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d", &k);
        a.push_back(k);
    }
    scanf("%d", &m);
    for(i=0;i<m;i++){
        scanf("%d", &k);
        p[k]=1;
    }
    for(i=0;i<n;i++){
        if(p[a[i]]==1)
            continue;
        if(i!=n-1)
            printf("%d ", a[i]);
        else
            printf("%d\n", a[i]);
    }
}
