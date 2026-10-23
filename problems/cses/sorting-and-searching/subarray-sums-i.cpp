#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    vector<int> v,sv;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        v.push_back(k);
        if(i==0)
            sv.push_back(k);
        else
            sv.push_back(sv[i-1]+k);
    }
    int l=0,r=0,cont=0;
    for(r=0;r<n;r++){
        while(l<=r){
            if(sv[r]-sv[l]+v[l]>x)
                l++;
            else if(sv[r]-sv[l]+v[l]<x)
                break;
            else{
                cont++;
                l++;
            }
        }
    }
    cout<<cont<<endl;
    return 0;
}