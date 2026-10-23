#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string ans;
        int v[30];
        memset(v,0,sizeof(v));
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            for(int i=0;i<26;i++)
                if(v[i]==a){
                    ans.push_back('a'+i);
                    v[i]++;
                    break;
                }
        }
        cout<<ans<<endl;
    }
    return 0;
}