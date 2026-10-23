#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> a;
    int n,i,k,tm;
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d", &k);
        a.push_back(k);
    }
    tm=a[(int)a.size()-1]-a[0]+10;
    for(i=0;i<n-1;i++)
        if(a[i+1]-a[i]>10)tm+=(10-(a[i+1]-a[i]));
    printf("%d\n", tm);
    return 0;
}
