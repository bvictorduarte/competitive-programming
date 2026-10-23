#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> a;
    int n,m,i,k,s=0;
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>k;
        a.push_back(k);
    }
    for(i=0;i<n-1;i++){
        while(a[i]!=m){
            if(a[i]<m){
                a[i]++;
                a[i+1]++;
            }else{
                a[i]--;
                a[i+1]--;
            }
            s++;
        }
    }
    cout<<s;
    return 0;
}
