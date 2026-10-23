#include<bits/stdc++.h>
using namespace std;
int main(){
    int tam;
    int n;
    vector<int> v;
    v.push_back(0);
    cin>>tam>>n;
    v.push_back(tam);
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    float m=v[1]-v[0]+(v[2]-v[1])/2.0;
    for(int i=2;i<(int)v.size()-2;i++){
        if((v[i]-v[i-1])/2.0+(v[i+1]-v[i])/2.0<=m)
            m=(v[i]-v[i-1])/2.0+(v[i+1]-v[i])/2.0;
    }
    if(m>=v[(int)v.size()-1]-v[(int)v.size()-2]+(v[(int)v.size()-2]-v[(int)v.size()-3])/2.0)
        m=v[(int)v.size()-1]-v[(int)v.size()-2]+(v[(int)v.size()-2]-v[(int)v.size()-3])/2.0;
    printf("%.2f", m);
    return 0;
}