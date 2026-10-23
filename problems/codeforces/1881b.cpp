#include<bits/stdc++.h>
using namespace std;
void solve(){
    vector<int> v;
    for(int i=0;i<3;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    if(v[1]%v[0]==0&&v[2]%v[0]==0&&(v[1]/v[0]+v[2]/v[0]-2<=3))
        cout<<"YES\n";
    else
        cout<<"NO\n";
}
int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}