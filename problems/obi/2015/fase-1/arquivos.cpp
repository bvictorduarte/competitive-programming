#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,b,k,cont=0;
    deque<int>v;
    cin>>n>>b;
    for(int i=0;i<n;i++){
        cin>>k;
        v.push_back(k);
    }
    sort(v.begin(),v.end());
    while(!v.empty()){
        if(v.front()+v.back()<=b&&(int)v.size()!=1){
            v.pop_back();
            v.pop_front();
        }else
            v.pop_back();
        cont++;
    }
    cout<<cont<<endl;
    return 0;
}
