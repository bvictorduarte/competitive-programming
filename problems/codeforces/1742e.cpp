#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+50;
ll h[maxn],maxv[maxn];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        h[0]=0;
        maxv[0]=0;
        for(int i=1;i<=n;i++){
            ll k;
            cin>>k;
            h[i]=h[i-1]+k;
            maxv[i]=max(k,maxv[i-1]);
        }
        for(int i=1;i<=q;i++){
            ll k;
            cin>>k;
            int j=0;
            for(int b=(n+1)/2;b>=1;b/=2)
                while(j+b<=n&&maxv[j+b]<=k)
                    j+=b;
            if(i==1)
                cout<<h[j];
            else
                cout<<" "<<h[j];
        }
        cout<<endl;
    }
    return 0;
}