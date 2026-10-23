#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s,srev,aux;
        cin>>s;
        aux=s;
        sort(s.begin(),s.end());
        srev=s;
        sort(srev.rbegin(),srev.rend());
        if(s==srev)
            cout<<"NO\n";
        else{
            cout<<"YES\n";
            if(s!=aux)
                cout<<s<<endl;
            else
                cout<<srev<<endl;
        }
    }
}