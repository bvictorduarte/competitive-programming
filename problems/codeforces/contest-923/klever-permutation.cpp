#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+50;
int ans[maxn];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        memset(ans,0,sizeof(ans));
        cin>>n>>k;
        int l=1,r=n;
        for(int i=1;i<=n;i++){
            int p=0;
            if(!ans[i]){
                while(i+p<=n){
                    if(i%2==1)
                        ans[i+p]=l++;
                    else
                        ans[i+p]=r--;
                    p+=k;
                }
            }
        }
        printf("%d", ans[1]);
        for(int i=2;i<=n;i++)
            printf(" %d", ans[i]);
        printf("\n");

    }
    return 0;
}