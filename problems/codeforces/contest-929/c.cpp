#include<bits/stdc++.h>
using namespace std;
int exp(int a,int b){
    int ans=1;
    for(int i=1;i<=b;i++)
        ans*=a;
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        set<int> s;
        int a,b,l,ans=0;
        cin>>a>>b>>l;
        int auxl=l;
        int xm=0;
        while(auxl%a==0){
            auxl/=a;
            xm++;
        }
        for(int i=0;i<=xm;i++)
            for(int j=0;exp(a,i)*exp(b,j)<=l;j++){
                int u=exp(a,i)*exp(b,j);
                if(l%u==0&&s.find(l/u)==s.end()){
                    s.insert(l/u);
                    ans++;
                }
            }
        cout<<ans<<endl;
    }
    return 0;
}