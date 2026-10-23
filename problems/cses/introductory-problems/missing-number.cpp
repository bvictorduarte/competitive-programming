#include <bits/stdc++.h>
using namespace std;
int a[200050];
int main(){
    int n,i,k;
    cin>>n;
    for(i=0;i<n-1;i++){
        cin>>k;
        a[k-1]=k;
    }
    for(i=0;i<n;i++)
        if(a[i]==0)
            k=i+1;
    cout<<k<<"\n";
    return 0;
}
