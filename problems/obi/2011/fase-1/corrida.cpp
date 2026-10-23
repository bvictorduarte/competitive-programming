#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,cont,a;
    vector<pair <int, int> > c;
    freopen("in1.txt","r",stdin);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cont=0;
        for(int k=0;k<m;k++){
            cin>>a;
            cont+=a;
        }
        c.push_back(make_pair(cont,i+1));
    }
    sort(c.begin(),c.end());
    for(int i=0;i<3;i++)
        cout<<c[i].second<<endl;
    return 0;
}
