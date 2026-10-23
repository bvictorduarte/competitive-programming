#include<bits/stdc++.h>
using namespace std;
const int MAXN=2*(1e4);
int pot(int x){
    int ans=1;
    for(int i=1;i<=x;i++)
        ans*=2;
    return ans;
}
int bin_dec(string num){
    int tam=(int)num.size();
    int k=0,ans=0;
    for(int i=tam-1;i>=0;i--){
        ans+=(num[i]-'0')*pot(k);
        k++;
    }
    return ans;
}
int numbers[MAXN];
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        string num;
        cin>>num;
        numbers[i]=bin_dec(num);
    }
    int ans=40;
    for(int i=0;i<n;i++)
        for(int k=i+1;k<n;k++)
            ans=min(ans,__builtin_popcount(numbers[i]^numbers[k]));
    cout<<ans<<endl;
    return 0;
}