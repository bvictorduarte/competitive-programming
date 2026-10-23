#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,s=0;
    vector<int> v;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        s+=a;
        v.push_back(a);
    } 
    s/=n;
    for(int i=0;i<n;i++)
        cout<<s-v[i]<<endl;
    return 0;
}