#include<bits/stdc++.h>
using namespace std;
set<string> suf, pref;
int main(){
    int n;
    string ans;
    cin>>n;
    for(int p=0;p<n;p++){
        string s;
        cin>>s;
        if(ans.empty()&&suf.find(s)!=suf.end())
            ans=s;
        for(int i=0;i<9;i++){
            string sufix,prefix;
            for(int k=0;k<i+1;k++)
                prefix.push_back(s[k]);
            for(int k=i+1;k<10;k++)
                sufix.push_back(s[k]);
            if(ans.empty()&&suf.find(prefix)!=suf.end()&&pref.find(sufix)!=pref.end())
                ans=s;
        }
        if(ans.empty()){
            suf.insert(s);
            pref.insert(s);
            for(int i=0;i<9;i++){
                string sufix,prefix;
                for(int k=0;k<i+1;k++)
                    prefix.push_back(s[k]);
                for(int k=i+1;k<10;k++)
                    sufix.push_back(s[k]);
                suf.insert(sufix);
                pref.insert(prefix);
            }
        }
    }
    if(!ans.empty())
        cout<<ans<<endl;
    else
        cout<<"ok\n";
}