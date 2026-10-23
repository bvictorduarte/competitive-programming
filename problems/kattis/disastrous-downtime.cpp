#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+50;
ll processes_in[maxn],processes_out[maxn];
int main(){
    int n,k;
    ll cont=0,ans=0;
    scanf("%d%d", &n, &k);
    for(int i=0;i<n;i++){
        cin>>processes_in[i];
        processes_out[i]=processes_in[i]+1000;
    }
    int ii=0,io=0;
    for(int i=0;i<2*n&&ii<n;i++){
        if(processes_out[io]<processes_in[ii]){
            cont--;
            io++;
        }else if(processes_out[io]>processes_in[ii]){
            cont++;
            ii++;
        }else{
            ii++;
            io++;
            i++;
        }
        ans=max(ans,cont);
    }
    if(ans%k)
        cout<<(ans/k)+1<<endl;
    else
        cout<<ans/k<<endl;
    return 0;
}