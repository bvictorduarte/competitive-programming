#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int op=1;
    for(auto u:s){
        if(u=='|')
            op=(op^1);
        if(op&&u!='|')
            cout<<u;
    }
    cout<<endl;
    return 0;
}