#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
    int n;
    cin>>n;
    int k;
    for(int i=0;i<n;i++){
        cin>>k;
        v.push_back(k);
    }
    sort(v.begin(),v.end());
    int cont=1,best=1,nota=v[0];
    for(int i=1;i<n;i++){
        if(v[i]==v[i-1])
            cont++;
        else
            cont=1;
        if(cont>=best){
            best=cont;
            nota=v[i];
        }
    }
    cout<<nota<<endl;
    return 0;
}
