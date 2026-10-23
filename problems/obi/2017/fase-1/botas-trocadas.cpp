#include<bits/stdc++.h>
using namespace std;
#define rep(i,n,k) for(i=n;i<k;i++)
int main(){
    vector<int> d,e;
    int n, i, tm, j, s=0;
    string op;
    scanf("%d", &n);
    rep(i,0,n){
        cin>>tm>>op;
        if(op=="E")e.push_back(tm);
        else d.push_back(tm);
    }
    rep(i,0,(int)d.size()){
        rep(j,0,(int)e.size()){
            if(d[i]==e[j]){
                s++;
                e[j]=-1;
                break;
            }
        }
    }
    printf("%d\n", s);
    return 0;
}
