#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin>>n&&n){
        string names[1050];
        for(int i=1;i<=n;i++)
            cin>>names[i];
        sort(names+1,names+n+1);
        string name1,name2,ans;
        name1=names[n/2];
        name2=names[(n/2)+1];
        int rep_max=(int)name1.size();
        for(int i=0;i<rep_max;i++)
            if(name1[i]!=name2[i]){
                ans.push_back(name1[i]+1);
                break;
            }
            else
                ans.push_back(name1[i]);
        cout<<ans<<endl;
    }
    return 0;
}