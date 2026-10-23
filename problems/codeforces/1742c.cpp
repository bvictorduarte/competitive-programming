#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string l[15],c[15];
        char ans;
        for(int i=0;i<8;i++){
            cin>>l[i];
            if(l[i]=="RRRRRRRR")
                ans='R';
        }
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++)
                c[i].push_back(l[j][i]);
        for(int i=0;i<8;i++)
            if(c[i]=="BBBBBBBB")
                ans='B';
        cout<<ans<<endl;
    }
    return 0;
}