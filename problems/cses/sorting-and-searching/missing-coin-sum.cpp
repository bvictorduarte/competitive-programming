#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    vector<ll> x;
    ll sum=1;
    cin>>n;
    for(int i=0;i<n;i++){
        int c;
        cin>>c;
        x.push_back(c);
    }
    sort(x.begin(),x.end());
    sum=1;
    for(int i=0;i<n&&x[i]<=sum;i++)
        sum+=x[i];
    cout<<sum<<endl;
}