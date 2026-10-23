#include<bits/stdc++.h>
using namespace std;
const int maxn=5e4+50;
int h[maxn],hdir[maxn],hesq[maxn];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>h[i];
        if(h[i]>=h[i-1]&&hesq[i-1]<h[i])
            hesq[i]=hesq[i-1]+1;
        else
            hesq[i]=min(h[i],i);
    }
    for(int i=n;i>=1;i--){
        if(h[i]>=h[i+1]&&hdir[i+1]<h[i])
            hdir[i]=hdir[i+1]+1;
        else
            hdir[i]=min(h[i],n-i+1);
    }
    int ans=-1;
    for(int i=1;i<=n;i++)
        ans=max(ans,min(hdir[i],hesq[i]));
    cout<<ans<<endl;
    return 0;
}