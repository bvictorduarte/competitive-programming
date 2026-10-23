#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin>>n&&n){
        vector<string> ans(n,"");
        int i=-1;
        for(int k=0;k<n;k++){
            string name, word;
            cin>>name>>word;
            int l=(int)word.size();
            while(l){
                i=(i+1)%n;
                if(ans[i]=="")
                    l--;
            }
            ans[i]=name;
        }
        cout<<ans[0];
        for(int i=1;i<n;i++)
            cout<<" "<<ans[i];
        cout<<endl;
    }
    return 0;
}