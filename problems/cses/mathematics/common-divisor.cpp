#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+50;
int freq[maxn];
int main(){
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        freq[x]++;
    }
    for(int ans=1e6;ans>=1;ans--){
        int cont=0;
        for(int i=ans;i<=1e6;i+=ans)
            cont+=freq[i];
        if(cont>=2){
            cout<<ans<<endl;
            return 0;
        }
    }
}