#include <bits/stdc++.h>
using namespace std;
int main(){
    string s,o;
    o.push_back('o');
    char k;
    cin>>k;
    cin>>s;
    do{
        if(k=='0'&&s==o)
            break;
        string ans;
        for(int i=0;i<(int)s.size();i++){
            if(s[i]!=k)
                ans.push_back(s[i]);
        }
        int i=0;
        if(!ans.empty()){
            while(i<(int)ans.size()&&ans[i]=='0')
                i++;
            if(i==(int)ans.size())
                i--;
            for(int m=i;m<(int)ans.size();m++)
                cout<<ans[m];
        }else{
            cout<<'0';
        }
        cout<<endl;
    cin>>k;
    cin>>s;
    }while(k!='0'&&s!=o);
    return 0;
}