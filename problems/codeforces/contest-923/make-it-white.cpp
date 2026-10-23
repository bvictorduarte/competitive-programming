#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        string s;
        cin>>n;
        cin>>s;
        int a=-1,b=-1;
        for(int i=0;i<n;i++)
            if(s[i]=='B'){
                a=i;
                break;
            }
        if(a==-1){
            cout<<0<<endl;
            continue;
        }
        for(int i=0;i<n;i++)
            if(s[i]=='B'&&i!=a)
                b=i;
        if(b==-1){
            cout<<1<<endl;
            continue;
        }
        cout<<b-a+1<<endl;
    }
}