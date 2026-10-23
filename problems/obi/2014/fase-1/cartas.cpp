#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main(){
    int i,k,d=0,c=0;
    vector<int> n, a;
    for(i=0;i<5;i++){
        cin>>k;
        n.push_back(k);
        a.push_back(k);
    }
    sort(a.begin(),a.end());
    for(i=0;i<(int)a.size();i++){
        if(a[i]==n[i])c++;
        if(a[(int)a.size()-1-i]==n[i])d++;
    }
    if(c==5)cout<<"C\n";
    else if(d==5) cout<<"D\n";
    else cout<<"N\n";
    return 0;
}
