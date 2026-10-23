#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k,sum1=0,sum2=0,ans;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        cin>>k;
        v.push_back(k);
        sum1+=k;
    }
    for(int i=0;i<n;i++){
        sum2+=v[i];
        if(2*sum2==sum1){
            ans=i+1;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}