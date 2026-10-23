#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            int a,b;
            cin>>a>>b;
            if(a<=10)
                v.push_back(make_pair(b,i+1));
        }
        sort(v.rbegin(),v.rend());
        cout<<v[0].second<<endl;
    }
    return 0;
}