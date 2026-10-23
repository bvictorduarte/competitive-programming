#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v;
    for(int i=1;i<=3;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    if(v[0]==v[1]||v[1]==v[2])
        cout<<"S\n";
    else if(v[2]==v[0]+v[1])
        cout<<"S\n";
    else
        cout<<"N\n";
}