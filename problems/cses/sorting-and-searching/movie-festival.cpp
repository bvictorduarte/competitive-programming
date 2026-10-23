#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<pair<int,int> > times;
    for(int i=0;i<n;i++){
        int a,l;
        cin>>a>>l;
        times.push_back(make_pair(l,a));
    }
    sort(times.begin(),times.end());
    int cont=1,i=0,tfat=times[0].first;
    while(i<=n-1){
        if(tfat<=times[i].second){
            cont++;
            tfat=times[i].first;
        }
        i++;
    }
    cout<<cont<<endl;
    return 0;
}
