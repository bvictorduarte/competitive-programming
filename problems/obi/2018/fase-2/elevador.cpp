#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
    int n;
    cin>>n;
    v.push_back(0);
    for(int i=0;i<n;i++){
        int a;
        scanf("%d", &a);
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    for(int i=1;i<=n;i++){
        if(v[i]-v[i-1]>8){
            printf("N\n");
            return 0;
        }
    }
    printf("S\n");
    return 0;
}