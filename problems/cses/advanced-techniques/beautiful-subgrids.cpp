#include<bits/stdc++.h>
#pragma GCC target("popcnt")
using namespace std;
const int MAXN=3001;
bitset<MAXN> row[MAXN];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n,cont=0,ans=0;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>row[i];
    for(int i=0;i<n;i++)
        for(int k=i+1;k<n;k++){
            cont=0;
            cont=(row[i]&row[k]).count();
            ans+=(cont*(cont-1))/2;
        }
    cout<<ans<<endl;
}