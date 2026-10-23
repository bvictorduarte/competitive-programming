#include<bits/stdc++.h>
using namespace std;
int q[27];
int main(){
    int n;
    string s;
    cin>>n>>s;
    for(int i=0;i<n;i++)
        q[s[i]-'a']++;
    int m=1e9;
    for(int i=0;i<26;i++)
        m=min(m,q[i]);
    int i=n,ans=-1;
    while(i>=1&&ans==-1){
        for(int j=0;j<26;j++){
            if(q[j]%i!=0)break;
            if(j==25&&q[j]%i==0){
                ans=i;
                break;
            }
        }
        i--;
    }
    if(ans==-1||ans==1){
        cout<<"*"<<endl;
        return 0;
    }
    string s_ans;
    for(int i=0;i<26;i++){
        for(int j=1;j<=q[i]/ans;j++)s_ans.push_back(i+'a');
    }
    for(int i=0;i<(int)s_ans.size();i++)
        cout<<s[i];
    cout<<endl;
    return 0;
}