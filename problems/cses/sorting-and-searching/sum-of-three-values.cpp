#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<ll,int>> v;
int main(){
    int n;
    ll x;
    bool ver=false;
    cin>>n>>x;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        v.push_back(make_pair(a,i));
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)
        if(!ver){
            for(int j=i+1;j<n;j++)
                if(j-i>=2){
                    int l=i+1,r=j-1,tam=r-l+1,k=0,f=x-v[i].first-v[j].first;
                    for(int b=tam/2;b>=1;b/=2)
                        while(l+k+b<=r&&v[l+k+b].first<=f)
                            k+=b;
                    if(v[l+k].first==f){
                        ver=true;
                        cout<<v[i].second<<" "<<v[j].second<<" "<<v[l+k].second;
                        break;
                    }
                }
        }
    if(!ver)
        cout<<"IMPOSSIBLE\n";
    return 0;
}