#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> prefix_sums,v;
ll sum(int a,int b){
    if(a==1)return prefix_sums[b];
    return sum(1,b)-sum(1,a-1);
}
int main(){
    int n,q;
    prefix_sums.push_back(0);
    scanf("%d %d", &n,&q);
    for(int i=1;i<=n;i++){
        int a;
        scanf("%d", &a);
        v.push_back(a);
        prefix_sums.push_back(prefix_sums[i-1]+a);
    }
    for(int i=0;i<q;i++){
        int a,b;
        scanf("%d%d", &a,&b);
        cout<<sum(a,b)<<endl;
    }
    return 0;
}