#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        vector<int> zeros,uns;
        string s;
        cin>>s;
        bool menos=false;
        int l=0,r=0;
        while(l<=(int)s.size()-1){
            while(r+1<=(int)s.size()-1&&s[l]==s[r+1]){
                r++;
            }
            if(s[l]=='0')
                zeros.push_back(1);
            else{
                if(!zeros.empty())
                    menos=true;
                uns.push_back(1);
            }
            l=r=r+1;
        }
        if(menos)
            cout<<(int)zeros.size()+(int)uns.size()-1<<endl;
        else
            cout<<(int)zeros.size()+(int)uns.size()<<endl;
    }
    return 0;
}