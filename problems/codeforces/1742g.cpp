#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,p=0;
        vector<int> v;
        cin>>n;
        for(int i=0;i<n;i++){
            int k;
            cin>>k;
            p=max(p,k);
            v.push_back(k);
        }
        int p1=p;
        for(int i=0;i<n;i++)
            if(v[i]==p){
                swap(v[0],v[i]);
                break;
            }
        int j=0;
        do{
            ++j;
            int y=j;
            p=p1;
            for(int i=j;i<n;i++){
                if(p1<(p|v[i])){
                    p1=p|v[i];
                    y=i;
                }
            }
            if(p1!=p)
                swap(v[j],v[y]);
        }while(p1!=p);
        cout<<v[0];
        for(int i=1;i<(int)v.size();i++)
            cout<<" "<<v[i];
        cout<<endl;
    }
    return 0;
}