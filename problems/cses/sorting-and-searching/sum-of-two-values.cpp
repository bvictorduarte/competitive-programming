#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k,m;
    vector<int> x;
    vector< pair<int, int> > sx;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        x.push_back(k);
        sx.push_back(make_pair(k,i));
    }
    sort(sx.begin(),sx.end());
    int l=0,r=n-1;
    while(l!=r){
        if(sx[l].first+sx[r].first>m)
            r--;
        else if(sx[l].first+sx[r].first<m)
            l++;
        else
            break;
    }
    if(l==r)
        printf("IMPOSSIBLE\n");
    else
        printf("%d %d\n", sx[l].second+1, sx[r].second+1);
    return 0;
}
