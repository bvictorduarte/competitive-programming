#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+3;
typedef long long ll;
ll prefix[maxn];
vector<ll> t,f;
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        ll a;
        cin>>a;
        t.push_back(a);
    }
    for(int i=1;i<=m;i++){
        ll a;
        cin>>a;
        f.push_back(a);
    }
    if(m==1){
        sort(t.begin(),t.end());
        ll ans=0;
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+t[i-1]*f[0];
            ans+=prefix[i];
        }
        cout<<ans<<endl;
    }else{
        sort(t.begin(),t.end());
        int i=0;
        multiset<ll> tl;
        ll tc=0,ans=0;
        while(i<n){
            if(i==0){
                tc=t[0];
                for(int k=1;k<m;k++){
                    tc=min(tc,t[k]);
                    tl.insert(t[k]);
                }
                i=m;
            }else{
                ans+=tc;
                tl.insert(tc+t[i]);
                if(i!=0){
                    tc=*(tl.begin());
                    tl.erase(tl.begin());
                }else{
                    tl.erase(tl.begin());
                    tc=*(tl.begin());
                }
                i++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}