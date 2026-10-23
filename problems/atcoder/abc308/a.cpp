#include<bits/stdc++.h>
using namespace std;
int main(){
    int s[10]={-1};
    bool ans=true;
    for(int i=1;i<=8;i++){
        cin>>s[i];
        if(s[i]<s[i-1]||s[i]%25!=0||!(s[i]>=100&&s[i]<=675))ans=false;
    }
    if(ans)cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}