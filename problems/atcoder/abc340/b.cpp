#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v;
    v.push_back(0);
    int q,tam=0;
    cin>>q;
    for(int i=0;i<q;i++){
        int op,x;
        cin>>op>>x;
        if(op==1){
            tam++;
            v.push_back(x);
        }
        else
            cout<<v[tam-x+1]<<endl;
    }
    return 0;
}