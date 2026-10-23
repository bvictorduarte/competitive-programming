#include<bits/stdc++.h>
using namespace std;
int modulo (int a){
    if(a>=0)return a;
    return -a;
}
int main(){
    vector<int> v;
    int a;
    for(int i=0;i<4;i++){
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    cout<<modulo(v[3]-v[2]+v[0]-v[1])<<endl;
    return 0;
}