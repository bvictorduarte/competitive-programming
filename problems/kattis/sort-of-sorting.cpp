#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<string,int> a, pair<string,int> b){
    if(a.first[0]!=b.first[0])
        return a.first[0]<b.first[0];
    if((int)a.first.size()==1)
        return true;
    if((int)b.first.size()==1)
        return false;
    if(a.first[1]!=b.first[1])
        return a.first[1]<b.first[1];
    return a.second<b.second;
}
int main(){
    int n,m=0;
    while(cin>>n && n){
        if(m)
            cout<<endl;
        vector<pair<string,int>> names; 
        string p;
        for(int i=1;i<=n;i++){
            cin>>p;
            names.push_back(make_pair(p,i));
        }
        sort(names.begin(),names.end(),cmp);
        for(int i=0;i<n;i++)
            cout<<names[i].first<<endl;
        ++m;
    }
    return 0;
}