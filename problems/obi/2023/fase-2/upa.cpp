#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+50;
int v[MAXN];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        scanf("%d %d", &a, &b);
        v[a]++;
        v[b]--;
    }
    int ans=0,sum=0;
    for(int i=0;i<1e5;i++){
        if(v[i]==0)continue;
        sum+=v[i];
        ans=max(sum,ans);
    }
    cout<<ans*20<<endl;
    return 0;
}