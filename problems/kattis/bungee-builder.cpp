#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+50;
int v[maxn];
int main(){
    vector<pair<int,int>> vp;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        v[i]=k;
    }
    int j=1;
    for(int i=2;i<=n;i++)
        if(v[j]<=v[i]&&i>j+1){
            vp.push_back(make_pair(j,i));
            j=i;
        }else if(v[j]<=v[i])
            j=i;
    j=n;
    for(int i=n-1;i>=1;i--)
        if(v[j]<=v[i]&&j-i>1){
            vp.push_back(make_pair(i,j));
            j=i;
        }else if(v[j]<=v[i])
            j=i;
    int ans=0;
    for(auto u:vp){
        int a=u.first,b=u.second;
        int m=min(v[a],v[b]);
        for(int i=a+1;i<b;i++)
            ans=max(m-v[i],ans);
    }
    cout<<ans;
    return 0;
}