#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> a;
    int n,k,i;
    long long cont=0LL;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>k;
        a.push_back(k);
    }
    for(i=0;i<n-1;i++){
        while(a[i]>a[i+1]){
            a[i+1]++;
            cont++;
        }
    }
    cout<<cont<<endl;
    return 0;
}
