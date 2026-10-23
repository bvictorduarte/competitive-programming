#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
    int n,l;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>l;
        v.push_back(l);
    }
    sort(v.begin(),v.end());
    l=v[0];
    int cont=1;
    for(int i=1;i<n;i++)
        if(v[i]!=l){
            cont++;
            l=v[i];
        }
    cout<<cont<<endl;
    return 0;
}
