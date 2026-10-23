#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n-52<=0){
            cout<<'a';
            --n;
            if(n-26<=0){
                cout<<'a';
                --n;
                cout<<(char)('a'+n-1)<<endl;
            }else{
                cout<<(char)('a'+n-27);
                n-=(n-26);
                cout<<(char)('a'+n-1)<<endl;
            }
        }
        else{
            cout<<(char)('a'+n-53);
            n-=(n-52);
            if(n-26<=0){
                cout<<'a';
                --n;
                cout<<(char)('a'+n-1)<<endl;
            }else{
                cout<<(char)('a'+n-27);
                n-=(n-26);
                cout<<(char)('a'+n-1)<<endl;
            }
        }
    }
}