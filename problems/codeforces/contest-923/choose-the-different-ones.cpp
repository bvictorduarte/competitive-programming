#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        set<int> a,b;
        vector<int> va,vb;
        for(int i=0;i<n;i++){
            int q;
            cin>>q;
            if(a.find(q)==a.end()&&q<=k)
                va.push_back(q);
            a.insert(q);
        }
        for(int i=0;i<m;i++){
            int q;
            cin>>q;
            if(b.find(q)==b.end()&&q<=k)
                vb.push_back(q);
            b.insert(q);
        }
        sort(va.begin(),va.end());
        sort(vb.begin(),vb.end());
        int dista=0,distb=0,eq=0;
        for(auto u:va)
            if(b.find(u)==b.end())
                dista++;
            else
                eq++;
        for(auto u:vb)
            if(a.find(u)==a.end())
                distb++;
        if(dista+distb+eq==k&&dista<=k/2&&distb<=k/2)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}