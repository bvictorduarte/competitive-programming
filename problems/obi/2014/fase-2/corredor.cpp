#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
    int n,k;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>k;
        v.push_back(k);
    }
    int sum=v[0],best=v[0];
    for(int i=1;i<n;i++){
        sum=max(sum+v[i],v[i]);
        best=max(sum,best);
    }
    cout<<best<<endl;
    return 0;
}