#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+50;
int idx[maxn];
int main(){
    int n,q,cont=0;
    while(cin>>n>>q&&n&&q){
        vector<int> v;
        cont++;
        for(int i=0;i<=maxn;i++)
            idx[i]=0;
        printf("CASE# %d:\n", cont);
        for(int i=1;i<=n;i++){
            int a;
            cin>>a;
            v.push_back(a);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<(int)v.size();i++)
            if(idx[v[i]]==0)
                idx[v[i]]=i+1;
        for(int i=1;i<=q;i++){
            int a;
            cin>>a;
            if(idx[a]==0)
                printf("%d not found\n", a);
            else
                printf("%d found at %d\n", a, idx[a]);
        }
    }
    return 0;
}