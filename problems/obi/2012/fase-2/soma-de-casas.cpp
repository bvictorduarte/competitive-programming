#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
    int n,k;
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d", &k);
        v.push_back(k);
    }
    cin>>k;
    sort(v.begin(),v.end());
    int l=0,r=n-1;
    while(l<r){
        if(v[l]+v[r]==k){
            printf("%d %d\n", v[l],v[r]);
            break;
        }
        else if(v[l]+v[r]>k)
            r--;
        else
            l++;
    }
    return 0;
}