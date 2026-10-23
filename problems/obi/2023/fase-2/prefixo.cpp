#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    string s1,s2;
    cin>>n>>s1;
    cin>>m>>s2;
    int k=0;
    while(k<m&&k<n&&s1[k]==s2[k])
        k++;
    cout<<k;
    return 0;
}