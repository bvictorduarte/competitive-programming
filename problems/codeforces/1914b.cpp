#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> v;
        for(int i=1;i<=n;i++)
            v.push_back(i);
        if(k==0)
            sort(v.rbegin(),v.rend());
        else if(k==n-1)
            sort(v.begin(),v.end());
        else{
            sort(v.rbegin(),v.rend());
            sort(v.begin(),v.begin()+k+1);
        }
        cout<<v[0];
        for(int i=1;i<n;i++)
            cout<<" "<<v[i];
        cout<<endl;
    }
    return 0;
}