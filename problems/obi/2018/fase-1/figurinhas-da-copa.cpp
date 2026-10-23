#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,c,m,i,k,v,cont=0;
    vector<int> a,b;
    cin>>n>>c>>m;
    for(i=0;i<c;i++){
        scanf("%d", &k);
        a.push_back(k);
    }
    for(i=0;i<m;i++){
        scanf("%d", &k);
        b.push_back(k);
    }
    for(i=0;i<(int)a.size();i++){
        v=0;
        for(k=0;k<(int)b.size();k++){
            if(a[i]==b[k]){
                v=1;
                break;
            }
        }
        if(v==1)cont++;
        v=0;
    }
    printf("%d\n", (int)a.size()-cont);
}
