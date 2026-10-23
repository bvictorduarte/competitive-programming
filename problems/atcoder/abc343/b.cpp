#include<bits/stdc++.h>
using namespace std;
int adj_matrix[105][105];
vector<int> v[105];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>adj_matrix[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            if(adj_matrix[i][j]){
                v[i].push_back(j);
                v[j].push_back(i);
            }
    for(int i=1;i<=n;i++)
        sort(v[i].begin(),v[i].end());
    for(int i=1;i<=n;i++){
        if(!v[i].empty())
            cout<<v[i][0];
        for(int j=1;j<(int)v[i].size();j++)
            cout<<" "<<v[i][j];
        cout<<endl;
    }
    return 0;
}