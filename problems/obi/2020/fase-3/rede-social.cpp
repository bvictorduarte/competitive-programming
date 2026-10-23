#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.rbegin(),v.rend());
    for(int i=n;i>=0;i--)
        if(v[i-1]>=i){
            cout<<i<<endl;
            return 0;
        }
}