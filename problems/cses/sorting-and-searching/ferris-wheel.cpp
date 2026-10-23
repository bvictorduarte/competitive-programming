#include <bits/stdc++.h>
using namespace std;
int main(){
    int l,r,cont=0,n,p;
    vector<int> v;
    cin>>n>>p;
    for(int i=0;i<n;i++){
        cin>>l;
        v.push_back(l);
    }
    sort(v.rbegin(),v.rend());
    l=0;
    r=n-1;
    while(l<=r){
        if(v[l]+v[r]<=p){
            cont++;
            l++;
            r--;
        }else{
            l++;
            cont++;
        }
    }
    cout<<cont<<endl;
    return 0;
}
