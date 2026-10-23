#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+50;
typedef long long ll;
ll v[maxn],s[maxn],t[maxn];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=1;i<=n-1;i++)
        cin>>s[i]>>t[i];
    for(int i=1;i<=n-1;i++){
        v[i+1]+=(v[i]/s[i])*t[i];
        v[i]-=(v[i]/s[i])*t[i];
    }
    cout<<v[n]<<endl;
    return 0;
}